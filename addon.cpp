#include <node.h>
#include <string>
#include <cstdlib>
#include <ctime>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::String;
using v8::Value;

std::string encrypt(const std::string& input) {
    std::string encrypted = "";
    srand(static_cast<unsigned int>(time(0))); 
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charactersLength = characters.length();
    int minLength = 8;
    int length = std::max(static_cast<int>(input.length()), minLength);
    
    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charactersLength;
        encrypted += characters[randomIndex];
    }
    
    return encrypted;
}

void Encrypt(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    
    if (args.Length() < 1 || !args[0]->IsString()) {
        isolate->ThrowException(String::NewFromUtf8(isolate, "Expected a string argument").ToLocalChecked());
        return;
    }
    
    String::Utf8Value str(isolate, args[0]);
    std::string input = std::string(*str);
    
    std::string encrypted = encrypt(input);
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, encrypted.c_str()).ToLocalChecked());
}

void Initialize(Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "encrypt", Encrypt);
}


NODE_MODULE(addon, Initialize)
