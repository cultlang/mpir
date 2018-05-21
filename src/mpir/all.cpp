
#include "mpir/common.h"

#include "all.h"

using namespace craft;
using namespace craft::lisp;
using namespace craft::types;
using namespace cultlang::mpir;


#define lMM sem->builtin_implementMultiMethod
#define MoD "mpir"

instance<Module> cultlang::mpir::make_bindings(instance<lisp::Namespace> ns, instance<> loader)
{
  auto ret = instance<Module>::make(ns, loader);
  auto sem = instance<CultSemantics>::make(ret);
  ret->builtin_setSemantics(sem);

  lMM(MoD, []() { return instance<bool>::make();});
  
  return ret;
}

BuiltinModuleDescription cultlang::mpir::BuiltinMpir("cultlang/mpir", cultlang::mpir::make_bindings);


#include "types/dll_entry.inc"
