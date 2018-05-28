
#pragma once
#include "mpir/common.h"
#include "mpir/default_types_mpir.h"

namespace cultlang {
namespace mpir 
{
  extern craft::lisp::BuiltinModuleDescription BuiltinMpir;

  CULTLANG_MPIR_EXPORTED void make_bindings(craft::instance<craft::lisp::Module>);
}}  


#include "mpir/default_types_mpir.h"