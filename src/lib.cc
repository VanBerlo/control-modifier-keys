#include <napi.h>
#include <windows.h>
#include <iostream>
using namespace std;

Napi::Value GetModifierState(const Napi::CallbackInfo &args)
{
  Napi::Env env = args.Env();
  Napi::Boolean state;

  if (!args[0].IsString() || args.Length() != 1)
  {
    Napi::TypeError::New(env, "Wrong arguments provided to getModifierState").ThrowAsJavaScriptException();
    return env.Null();
  }

  string modifierKey = args[0].ToString();

  if (modifierKey == "capslock")
  {
    return Napi::Boolean::New(env, (GetKeyState(VK_CAPITAL) & 0x0001) != 0);
  }
  else if (modifierKey == "numlock")
  {
    return Napi::Boolean::New(env, (GetKeyState(VK_NUMLOCK) & 0x0001) != 0);
  }
  else if (modifierKey == "scrolllock")
  {
    return Napi::Boolean::New(env, (GetKeyState(VK_SCROLL) & 0x0001) != 0);
  }
  else
  {
    Napi::TypeError::New(env, "Wrong arguments provided to getModifierState").ThrowAsJavaScriptException();
    return env.Null();
  }
}

Napi::Value SetModifierState(const Napi::CallbackInfo &args)
{
  Napi::Env env = args.Env();
  Napi::Boolean result;

  if (!args[0].IsString() || !args[1].IsBoolean() || args.Length() != 2)
  {
    Napi::TypeError::New(env, "Wrong arguments provided to setModifierState").ThrowAsJavaScriptException();
    return env.Null();
  }

  string modifierKey = args[0].ToString();
  bool desiredState = args[1].ToBoolean();

  if (modifierKey == "capslock")
  {
    if ((((GetKeyState(VK_CAPITAL) & 0x0001) == 0) && desiredState) || (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) && !desiredState))
    {
      keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
      keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
      return Napi::Boolean::New(env, true);
    }
  }
  else if (modifierKey == "numlock")
  {
    if ((((GetKeyState(VK_NUMLOCK) & 0x0001) == 0) && desiredState) || (((GetKeyState(VK_NUMLOCK) & 0x0001) != 0) && !desiredState))
    {
      keybd_event(VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
      keybd_event(VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
      return Napi::Boolean::New(env, true);
    }
  }
  else if (modifierKey == "scrolllock")
  {
    if ((((GetKeyState(VK_SCROLL) & 0x0001) == 0) && desiredState) || (((GetKeyState(VK_SCROLL) & 0x0001) != 0) && !desiredState))
    {
      keybd_event(VK_SCROLL, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
      keybd_event(VK_SCROLL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
      return Napi::Boolean::New(env, true);
    }
  }
  else
  {
    Napi::TypeError::New(env, "Wrong arguments provided to setModifierState").ThrowAsJavaScriptException();
    return env.Null();
  }

  return Napi::Boolean::New(env, false);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "getModifierState"),
              Napi::Function::New(env, GetModifierState));
  exports.Set(Napi::String::New(env, "setModifierState"),
              Napi::Function::New(env, SetModifierState));
  return exports;
}

NODE_API_MODULE(control_modifiers, Init)
