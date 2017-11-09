// addon.cc
#include <node.h>
#include "capturesupport.h"

namespace capturesupport {

using v8::Local;
using v8::Object;

void InitAll(Local<Object> exports) {
  CaptureSupport::Init(exports);  
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

}  // namespace capturesupport
