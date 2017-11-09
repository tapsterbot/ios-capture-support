// capturesupport.h
#ifndef CAPTURESUPPORT_H
#define CAPTURESUPPORT_H

#include <node.h>
#include <node_object_wrap.h>
#include "plugin/PluginHeader.h"

namespace capturesupport {

class CaptureSupport : public node::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);

 private:
   explicit CaptureSupport();
  ~CaptureSupport();

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void AllowScreenCaptureDevices(const v8::FunctionCallbackInfo<v8::Value>& args);  
  static void StartScreenCapturePlugin(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void StopScreenCapturePlugin(const v8::FunctionCallbackInfo<v8::Value>& args);    
  static v8::Persistent<v8::Function> constructor;
  MyInterfaceStruct** interface_;
};

}  // namespace capturesupport

#endif
