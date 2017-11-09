// capturesupport.cc
#include "capturesupport.h"
#include "plugin/PluginHeaderHelper.h"
#include <CoreMediaIO/CMIOHardware.h>

namespace capturesupport {

using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Persistent;
using v8::String;
using v8::Value;

Persistent<Function> CaptureSupport::constructor;

CaptureSupport::CaptureSupport() {
}

CaptureSupport::~CaptureSupport() {
}

void CaptureSupport::Init(Local<Object> exports) {
  Isolate* isolate = exports->GetIsolate();

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
  tpl->SetClassName(String::NewFromUtf8(isolate, "CaptureSupport"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "allow", AllowScreenCaptureDevices);  
  NODE_SET_PROTOTYPE_METHOD(tpl, "startPlugin", StartScreenCapturePlugin);
  NODE_SET_PROTOTYPE_METHOD(tpl, "stopPlugin", StopScreenCapturePlugin);

  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "CaptureSupport"),
               tpl->GetFunction());
}

void CaptureSupport::New(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new CaptureSupport(...)`
    CaptureSupport* obj = new CaptureSupport();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `CaptureSupport(...)`, turn into construct call.
    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    Local<Context> context = isolate->GetCurrentContext();
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    Local<Object> result =
        cons->NewInstance(context, argc, argv).ToLocalChecked();
    args.GetReturnValue().Set(result);
  }
}

void CaptureSupport::AllowScreenCaptureDevices(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  CMIOObjectPropertyAddress prop = { kCMIOHardwarePropertyAllowScreenCaptureDevices,
                                     kCMIOObjectPropertyScopeGlobal,
                                     kCMIOObjectPropertyElementMaster };
  UInt32 allow = 1;
  CMIOObjectSetPropertyData( kCMIOObjectSystemObject, &prop, 0, NULL, sizeof(allow), &allow );
  
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Allowed!"));
}

void CaptureSupport::StartScreenCapturePlugin(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  CaptureSupport* obj = ObjectWrap::Unwrap<CaptureSupport>(args.Holder());
  obj->interface_ = startScreenCapturePlugin();

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Starting!"));
}

void CaptureSupport::StopScreenCapturePlugin(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  CaptureSupport* obj = ObjectWrap::Unwrap<CaptureSupport>(args.Holder());
  stopScreenCapturePlugin(obj->interface_);

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Stopping!"));
}

}  // namespace capturesupport
