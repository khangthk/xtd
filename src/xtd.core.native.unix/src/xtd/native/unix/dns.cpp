#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/dns.h>
#include <xtd/native/address_family_constants.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;
using namespace xtd::native;

namespace {
  mutex dns_mutex;
}

void dns::cleanup() {
  #if !defined(__ANDROID__)
  endhostent();
  #endif
}

void dns::destroy(intmax_t host) {
  delete reinterpret_cast<hostent*>(host);
}

intmax_t dns::get_host_by_address(const string& host_address, int_least32_t host_address_type) {
  lock_guard<mutex> lock(dns_mutex);
  int_least64_t internet_address = 0;
  inet_pton(host_address_type, host_address.c_str(), &internet_address);
  hostent* host = gethostbyaddr(reinterpret_cast<char*>(&internet_address), host_address_type == ADDRESS_FAMILY_INTER_NETWORK ? 4 : 16, host_address_type);
  if (host == nullptr) return 0;
  return reinterpret_cast<intmax_t>(new hostent(*host));
}

intmax_t dns::get_host_by_name(const string& host_name) {
  lock_guard<mutex> lock(dns_mutex);
  hostent* host = gethostbyname(host_name.c_str());
  if (host == nullptr) return 0;
  return reinterpret_cast<intmax_t>(new hostent(*host));
}

vector<string> dns::get_aliases(intmax_t host) {
  vector<string> aliases;
  size_t index = 0;
  while (reinterpret_cast<hostent*>(host)->h_aliases[index] != nullptr)
    aliases.push_back(reinterpret_cast<hostent*>(host)->h_aliases[index++]);
  return aliases;
}

vector<vector<uint_least8_t>> dns::get_addresses(intmax_t host) {
  size_t index = 0;
  vector<vector<uint_least8_t>> addresses;
  while (reinterpret_cast<hostent*>(host)->h_addr_list[index] != nullptr) {
    addresses.emplace_back(reinterpret_cast<const uint_least8_t*>(reinterpret_cast<hostent*>(host)->h_addr_list[index]), reinterpret_cast<const uint_least8_t*>(reinterpret_cast<hostent*>(host)->h_addr_list[index]) + (reinterpret_cast<hostent*>(host)->h_addrtype == ADDRESS_FAMILY_INTER_NETWORK ? 4 : 16));
    index++;
  }
  return addresses;
}

string dns::get_host_name(intmax_t host) {
  return reinterpret_cast<hostent*>(host)->h_name;
}

int_least32_t dns::get_host_name(string& host_name) {
  char name[1024];
  int_least32_t result = gethostname(name, 1024);
  host_name = name;
  return result;
}

void dns::startup() {
  #if !defined(__ANDROID__)
  sethostent(true);
  #endif
}
