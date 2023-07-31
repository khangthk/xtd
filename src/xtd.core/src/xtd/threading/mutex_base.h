#pragma once
#include "../../../include/xtd/threading/mutex.h"

class xtd::threading::mutex::mutex_base {
public:
  virtual ~mutex_base() = default;
  
  virtual intptr handle() const noexcept = 0;
  virtual void handle(intptr value) = 0;
  virtual bool create(bool initially_owned) = 0;
  virtual bool create(bool initially_owned, const ustring& name) = 0;
  virtual void destroy() = 0;
  virtual bool open(const ustring& name) = 0;
  virtual bool signal(bool& io_error) = 0;
  virtual bool wait(int32 milliseconds_timeout, bool& io_error) = 0;
};
