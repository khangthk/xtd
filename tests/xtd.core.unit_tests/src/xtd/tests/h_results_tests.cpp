#include <xtd/as>
#include <xtd/interface>
#include <xtd/string>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(h_results_tests) {
    void test_method_(S_OK) {
      assert::are_equal(static_cast<int32>(0x00000000), h_results::S_OK, csf_);
    }

    void test_method_(S_FALSE) {
      assert::are_equal(static_cast<int32>(0x00000001), h_results::S_FALSE, csf_);
    }

    void test_method_(COR_E_ABANDONEDMUTEX) {
      assert::are_equal(static_cast<int32>(0x8013152D), h_results::COR_E_ABANDONEDMUTEX, csf_);
    }

    void test_method_(COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal(static_cast<int32>(0x8013106A), h_results::COR_E_AMBIGUOUSIMPLEMENTATION, csf_);
    }

    void test_method_(COR_E_AMBIGUOUSMATCH) {
      assert::are_equal(static_cast<int32>(0x8000211D), h_results::COR_E_AMBIGUOUSMATCH, csf_);
    }

    void test_method_(COR_E_APPDOMAINUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131014), h_results::COR_E_APPDOMAINUNLOADED, csf_);
    }

    void test_method_(COR_E_APPLICATION) {
      assert::are_equal(static_cast<int32>(0x80131600), h_results::COR_E_APPLICATION, csf_);
    }

    void test_method_(COR_E_ARGUMENT) {
      assert::are_equal(static_cast<int32>(0x80070057), h_results::COR_E_ARGUMENT, csf_);
    }

    void test_method_(COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131502), h_results::COR_E_ARGUMENTOUTOFRANGE, csf_);
    }

    void test_method_(COR_E_ARITHMETIC) {
      assert::are_equal(static_cast<int32>(0x80070216), h_results::COR_E_ARITHMETIC, csf_);
    }

    void test_method_(COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131503), h_results::COR_E_ARRAYTYPEMISMATCH, csf_);
    }

    void test_method_(COR_E_BADEXEFORMAT) {
      assert::are_equal(static_cast<int32>(0x800700C1), h_results::COR_E_BADEXEFORMAT, csf_);
    }

    void test_method_(COR_E_BADIMAGEFORMAT) {
      assert::are_equal(static_cast<int32>(0x8007000B), h_results::COR_E_BADIMAGEFORMAT, csf_);
    }

    void test_method_(COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal(static_cast<int32>(0x80131015), h_results::COR_E_CANNOTUNLOADAPPDOMAIN, csf_);
    }

    void test_method_(COR_E_CODECONTRACTFAILED) {
      assert::are_equal(static_cast<int32>(0x80131542), h_results::COR_E_CODECONTRACTFAILED, csf_);
    }

    void test_method_(COR_E_CONTEXTMARSHAL) {
      assert::are_equal(static_cast<int32>(0x80131504), h_results::COR_E_CONTEXTMARSHAL, csf_);
    }

    void test_method_(COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal(static_cast<int32>(0x80131605), h_results::COR_E_CUSTOMATTRIBUTEFORMAT, csf_);
    }

    void test_method_(COR_E_DATAMISALIGNED) {
      assert::are_equal(static_cast<int32>(0x80131541), h_results::COR_E_DATAMISALIGNED, csf_);
    }

    void test_method_(COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070003), h_results::COR_E_DIRECTORYNOTFOUND, csf_);
    }

    void test_method_(COR_E_DIVIDEBYZERO) {
      assert::are_equal(static_cast<int32>(0x80020012), h_results::COR_E_DIVIDEBYZERO, csf_);
    }

    void test_method_(COR_E_DLLNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131524), h_results::COR_E_DLLNOTFOUND, csf_);
    }

    void test_method_(COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131529), h_results::COR_E_DUPLICATEWAITOBJECT, csf_);
    }

    void test_method_(COR_E_ENDOFSTREAM) {
      assert::are_equal(static_cast<int32>(0x80070026), h_results::COR_E_ENDOFSTREAM, csf_);
    }

    void test_method_(COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131523), h_results::COR_E_ENTRYPOINTNOTFOUND, csf_);
    }

    void test_method_(COR_E_EXCEPTION) {
      assert::are_equal(static_cast<int32>(0x80131500), h_results::COR_E_EXCEPTION, csf_);
    }

    void test_method_(COR_E_EXECUTIONENGINE) {
      assert::are_equal(static_cast<int32>(0x80131506), h_results::COR_E_EXECUTIONENGINE, csf_);
    }

    void test_method_(COR_E_FAILFAST) {
      assert::are_equal(static_cast<int32>(0x80131623), h_results::COR_E_FAILFAST, csf_);
    }

    void test_method_(COR_E_FIELDACCESS) {
      assert::are_equal(static_cast<int32>(0x80131507), h_results::COR_E_FIELDACCESS, csf_);
    }

    void test_method_(COR_E_FILELOAD) {
      assert::are_equal(static_cast<int32>(0x80131621), h_results::COR_E_FILELOAD, csf_);
    }

    void test_method_(COR_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070002), h_results::COR_E_FILENOTFOUND, csf_);
    }

    void test_method_(COR_E_FORMAT) {
      assert::are_equal(static_cast<int32>(0x80131537), h_results::COR_E_FORMAT, csf_);
    }

    void test_method_(COR_E_INDEXOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131508), h_results::COR_E_INDEXOUTOFRANGE, csf_);
    }

    void test_method_(COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal(static_cast<int32>(0x80131578), h_results::COR_E_INSUFFICIENTEXECUTIONSTACK, csf_);
    }

    void test_method_(COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal(static_cast<int32>(0x8013153D), h_results::COR_E_INSUFFICIENTMEMORY, csf_);
    }

    void test_method_(COR_E_INVALIDCAST) {
      assert::are_equal(static_cast<int32>(0x80004002), h_results::COR_E_INVALIDCAST, csf_);
    }

    void test_method_(COR_E_INVALIDCOMOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131527), h_results::COR_E_INVALIDCOMOBJECT, csf_);
    }

    void test_method_(COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal(static_cast<int32>(0x80131601), h_results::COR_E_INVALIDFILTERCRITERIA, csf_);
    }

    void test_method_(COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal(static_cast<int32>(0x80131531), h_results::COR_E_INVALIDOLEVARIANTTYPE, csf_);
    }

    void test_method_(COR_E_INVALIDOPERATION) {
      assert::are_equal(static_cast<int32>(0x80131509), h_results::COR_E_INVALIDOPERATION, csf_);
    }

    void test_method_(COR_E_INVALIDPROGRAM) {
      assert::are_equal(static_cast<int32>(0x8013153A), h_results::COR_E_INVALIDPROGRAM, csf_);
    }

    void test_method_(COR_E_IO) {
      assert::are_equal(static_cast<int32>(0x80131620), h_results::COR_E_IO, csf_);
    }

    void test_method_(COR_E_KEYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131577), h_results::COR_E_KEYNOTFOUND, csf_);
    }

    void test_method_(COR_E_MARSHALDIRECTIVE) {
      assert::are_equal(static_cast<int32>(0x80131535), h_results::COR_E_MARSHALDIRECTIVE, csf_);
    }

    void test_method_(COR_E_MEMBERACCESS) {
      assert::are_equal(static_cast<int32>(0x8013151A), h_results::COR_E_MEMBERACCESS, csf_);
    }

    void test_method_(COR_E_METHODACCESS) {
      assert::are_equal(static_cast<int32>(0x80131510), h_results::COR_E_METHODACCESS, csf_);
    }

    void test_method_(COR_E_MISSINGFIELD) {
      assert::are_equal(static_cast<int32>(0x80131511), h_results::COR_E_MISSINGFIELD, csf_);
    }

    void test_method_(COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal(static_cast<int32>(0x80131532), h_results::COR_E_MISSINGMANIFESTRESOURCE, csf_);
    }

    void test_method_(COR_E_MISSINGMEMBER) {
      assert::are_equal(static_cast<int32>(0x80131512), h_results::COR_E_MISSINGMEMBER, csf_);
    }

    void test_method_(COR_E_MISSINGMETHOD) {
      assert::are_equal(static_cast<int32>(0x80131513), h_results::COR_E_MISSINGMETHOD, csf_);
    }

    void test_method_(COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal(static_cast<int32>(0x80131536), h_results::COR_E_MISSINGSATELLITEASSEMBLY, csf_);
    }

    void test_method_(COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131514), h_results::COR_E_MULTICASTNOTSUPPORTED, csf_);
    }

    void test_method_(COR_E_NOTFINITENUMBER) {
      assert::are_equal(static_cast<int32>(0x80131528), h_results::COR_E_NOTFINITENUMBER, csf_);
    }

    void test_method_(COR_E_NOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131515), h_results::COR_E_NOTSUPPORTED, csf_);
    }

    void test_method_(COR_E_OBJECTDISPOSED) {
      assert::are_equal(static_cast<int32>(0x80131622), h_results::COR_E_OBJECTDISPOSED, csf_);
    }

    void test_method_(COR_E_OPERATIONCANCELED) {
      assert::are_equal(static_cast<int32>(0x8013153B), h_results::COR_E_OPERATIONCANCELED, csf_);
    }

    void test_method_(COR_E_OUTOFMEMORY) {
      assert::are_equal(static_cast<int32>(0x8007000E), h_results::COR_E_OUTOFMEMORY, csf_);
    }

    void test_method_(COR_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x80131516), h_results::COR_E_OVERFLOW, csf_);
    }

    void test_method_(COR_E_PATHTOOLONG) {
      assert::are_equal(static_cast<int32>(0x800700CE), h_results::COR_E_PATHTOOLONG, csf_);
    }

    void test_method_(COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131539), h_results::COR_E_PLATFORMNOTSUPPORTED, csf_);
    }

    void test_method_(COR_E_RANK) {
      assert::are_equal(static_cast<int32>(0x80131517), h_results::COR_E_RANK, csf_);
    }

    void test_method_(COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131602), h_results::COR_E_REFLECTIONTYPELOAD, csf_);
    }

    void test_method_(COR_E_RUNTIMEWRAPPED) {
      assert::are_equal(static_cast<int32>(0x8013153E), h_results::COR_E_RUNTIMEWRAPPED, csf_);
    }

    void test_method_(COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131538), h_results::COR_E_SAFEARRAYRANKMISMATCH, csf_);
    }

    void test_method_(COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131533), h_results::COR_E_SAFEARRAYTYPEMISMATCH, csf_);
    }

    void test_method_(COR_E_SECURITY) {
      assert::are_equal(static_cast<int32>(0x8013150A), h_results::COR_E_SECURITY, csf_);
    }

    void test_method_(COR_E_SERIALIZATION) {
      assert::are_equal(static_cast<int32>(0x8013150C), h_results::COR_E_SERIALIZATION, csf_);
    }

    void test_method_(COR_E_STACKOVERFLOW) {
      assert::are_equal(static_cast<int32>(0x800703E9), h_results::COR_E_STACKOVERFLOW, csf_);
    }

    void test_method_(COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal(static_cast<int32>(0x80131518), h_results::COR_E_SYNCHRONIZATIONLOCK, csf_);
    }

    void test_method_(COR_E_SYSTEM) {
      assert::are_equal(static_cast<int32>(0x80131501), h_results::COR_E_SYSTEM, csf_);
    }

    void test_method_(COR_E_TARGET) {
      assert::are_equal(static_cast<int32>(0x80131603), h_results::COR_E_TARGET, csf_);
    }

    void test_method_(COR_E_TARGETINVOCATION) {
      assert::are_equal(static_cast<int32>(0x80131604), h_results::COR_E_TARGETINVOCATION, csf_);
    }

    void test_method_(COR_E_TARGETPARAMCOUNT) {
      assert::are_equal(static_cast<int32>(0x8002000E), h_results::COR_E_TARGETPARAMCOUNT, csf_);
    }

    void test_method_(COR_E_THREADABORTED) {
      assert::are_equal(static_cast<int32>(0x80131530), h_results::COR_E_THREADABORTED, csf_);
    }

    void test_method_(COR_E_THREADINTERRUPTED) {
      assert::are_equal(static_cast<int32>(0x80131519), h_results::COR_E_THREADINTERRUPTED, csf_);
    }

    void test_method_(COR_E_THREADSTART) {
      assert::are_equal(static_cast<int32>(0x80131525), h_results::COR_E_THREADSTART, csf_);
    }

    void test_method_(COR_E_THREADSTATE) {
      assert::are_equal(static_cast<int32>(0x80131520), h_results::COR_E_THREADSTATE, csf_);
    }

    void test_method_(COR_E_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x80131505), h_results::COR_E_TIMEOUT, csf_);
    }

    void test_method_(COR_E_TYPEACCESS) {
      assert::are_equal(static_cast<int32>(0x80131543), h_results::COR_E_TYPEACCESS, csf_);
    }

    void test_method_(COR_E_TYPEINITIALIZATION) {
      assert::are_equal(static_cast<int32>(0x80131534), h_results::COR_E_TYPEINITIALIZATION, csf_);
    }

    void test_method_(COR_E_TYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131522), h_results::COR_E_TYPELOAD, csf_);
    }

    void test_method_(COR_E_TYPEUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131013), h_results::COR_E_TYPEUNLOADED, csf_);
    }

    void test_method_(COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal(static_cast<int32>(0x80070005), h_results::COR_E_UNAUTHORIZEDACCESS, csf_);
    }

    void test_method_(COR_E_VERIFICATION) {
      assert::are_equal(static_cast<int32>(0x8013150D), h_results::COR_E_VERIFICATION, csf_);
    }

    void test_method_(COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal(static_cast<int32>(0x8013152C), h_results::COR_E_WAITHANDLECANNOTBEOPENED, csf_);
    }

    void test_method_(CO_E_NOTINITIALIZED) {
      assert::are_equal(static_cast<int32>(0x800401F0), h_results::CO_E_NOTINITIALIZED, csf_);
    }

    void test_method_(DISP_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x8002000A), h_results::DISP_E_OVERFLOW, csf_);
    }

    void test_method_(E_ABORT) {
      assert::are_equal(static_cast<int32>(0x80004004), h_results::E_ABORT, csf_);
    }

    void test_method_(E_BOUNDS) {
      assert::are_equal(static_cast<int32>(0x8000000B), h_results::E_BOUNDS, csf_);
    }

    void test_method_(E_CHANGED_STATE) {
      assert::are_equal(static_cast<int32>(0x8000000C), h_results::E_CHANGED_STATE, csf_);
    }

    void test_method_(E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070002), h_results::E_FILENOTFOUND, csf_);
    }

    void test_method_(E_FAIL) {
      assert::are_equal(static_cast<int32>(0x80004005), h_results::E_FAIL, csf_);
    }

    void test_method_(E_HANDLE) {
      assert::are_equal(static_cast<int32>(0x80070006), h_results::E_HANDLE, csf_);
    }

    void test_method_(E_INVALIDARG) {
      assert::are_equal(static_cast<int32>(0x80070057), h_results::E_INVALIDARG, csf_);
    }

    void test_method_(E_NOTIMPL) {
      assert::are_equal(static_cast<int32>(0x80004001), h_results::E_NOTIMPL, csf_);
    }

    void test_method_(E_POINTER) {
      assert::are_equal(static_cast<int32>(0x80004003), h_results::E_POINTER, csf_);
    }

    void test_method_(E_UNEXPECTED) {
      assert::are_equal(static_cast<int32>(0x8000FFFF), h_results::E_UNEXPECTED, csf_);
    }

    void test_method_(ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal(static_cast<int32>(0x80073B1F), h_results::ERROR_MRM_MAP_NOT_FOUND, csf_);
    }

    void test_method_(ERROR_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x800705B4), h_results::ERROR_TIMEOUT, csf_);
    }

    void test_method_(RO_E_CLOSED) {
      assert::are_equal(static_cast<int32>(0x80000013), h_results::RO_E_CLOSED, csf_);
    }

    void test_method_(RPC_E_CHANGED_MODE) {
      assert::are_equal(static_cast<int32>(0x80010106), h_results::RPC_E_CHANGED_MODE, csf_);
    }

    void test_method_(TYPE_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80028CA0), h_results::TYPE_E_TYPEMISMATCH, csf_);
    }

    void test_method_(STG_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80030003), h_results::STG_E_PATHNOTFOUND, csf_);
    }

    void test_method_(CTL_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A004C), h_results::CTL_E_PATHNOTFOUND, csf_);
    }

    void test_method_(CTL_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A0035), h_results::CTL_E_FILENOTFOUND, csf_);
    }

    void test_method_(FUSION_E_INVALID_NAME) {
      assert::are_equal(static_cast<int32>(0x80131047), h_results::FUSION_E_INVALID_NAME, csf_);
    }

    void test_method_(FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131040), h_results::FUSION_E_REF_DEF_MISMATCH, csf_);
    }

    void test_method_(ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal(static_cast<int32>(0x80070004), h_results::ERROR_TOO_MANY_OPEN_FILES, csf_);
    }

    void test_method_(ERROR_SHARING_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070020), h_results::ERROR_SHARING_VIOLATION, csf_);
    }

    void test_method_(ERROR_LOCK_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070021), h_results::ERROR_LOCK_VIOLATION, csf_);
    }

    void test_method_(ERROR_OPEN_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007006E), h_results::ERROR_OPEN_FAILED, csf_);
    }

    void test_method_(ERROR_DISK_CORRUPT) {
      assert::are_equal(static_cast<int32>(0x80070571), h_results::ERROR_DISK_CORRUPT, csf_);
    }

    void test_method_(ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal(static_cast<int32>(0x800703ED), h_results::ERROR_UNRECOGNIZED_VOLUME, csf_);
    }

    void test_method_(ERROR_DLL_INIT_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007045A), h_results::ERROR_DLL_INIT_FAILED, csf_);
    }

    void test_method_(MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal(static_cast<int32>(0x80131016), h_results::MSEE_E_ASSEMBLYLOADINPROGRESS, csf_);
    }

    void test_method_(ERROR_FILE_INVALID) {
      assert::are_equal(static_cast<int32>(0x800703EE), h_results::ERROR_FILE_INVALID, csf_);
    }
  };
}
