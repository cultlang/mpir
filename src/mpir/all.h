
#pragma once
#include "mpir/common.h"

namespace cultlang {
namespace mpir 
{
  extern craft::lisp::BuiltinModuleDescription BuiltinMpir;

  CULTLANG_MPIR_EXPORTED craft::instance<craft::lisp::Module> make_bindings(craft::instance<craft::lisp::Namespace> ns, craft::instance<> loader);
}}  
