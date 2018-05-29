
#include "mpir/common.h"

#include "all.h"

using namespace craft;
using namespace craft::lisp;
using namespace craft::types;
using namespace cultlang::mpir;


#define lMM sem->builtin_implementMultiMethod
#define MoD "mpir"

void cultlang::mpir::make_bindings(instance<lisp::Module> ret)
{
  auto semantics = ret->require<lisp::CultSemantics>();

  semantics->builtin_implementMultiMethod("<", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<bool> { return instance<bool>::make(*a < *b); });
  semantics->builtin_implementMultiMethod("<", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<bool> { return instance<bool>::make(*a < *b); });
  semantics->builtin_implementMultiMethod("<", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<bool> { return instance<bool>::make(*a < *b); });

  semantics->builtin_implementMultiMethod("<=", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<bool> { return instance<bool>::make(*a <= *b); });
  semantics->builtin_implementMultiMethod("<=", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<bool> { return instance<bool>::make(*a <= *b); });
  semantics->builtin_implementMultiMethod("<=", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<bool> { return instance<bool>::make(*a <= *b); });

  semantics->builtin_implementMultiMethod("==", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<bool> { return instance<bool>::make(*a == *b); });
  semantics->builtin_implementMultiMethod("==", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<bool> { return instance<bool>::make(*a == *b); });
  semantics->builtin_implementMultiMethod("==", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<bool> { return instance<bool>::make(*a == *b); });

  semantics->builtin_implementMultiMethod("!=", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<bool> { return instance<bool>::make(*a != *b); });
  semantics->builtin_implementMultiMethod("!=", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<bool> { return instance<bool>::make(*a != *b); });
  semantics->builtin_implementMultiMethod("!=", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<bool> { return instance<bool>::make(*a != *b); });

  semantics->builtin_implementMultiMethod(">=", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<bool> { return instance<bool>::make(*a >= *b); });
  semantics->builtin_implementMultiMethod(">=", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<bool> { return instance<bool>::make(*a >= *b); });
  semantics->builtin_implementMultiMethod(">=", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<bool> { return instance<bool>::make(*a >= *b); });

  semantics->builtin_implementMultiMethod(">", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<bool> { return instance<bool>::make(*a > *b); });
  semantics->builtin_implementMultiMethod(">", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<bool> { return instance<bool>::make(*a > *b); });
  semantics->builtin_implementMultiMethod(">", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<bool> { return instance<bool>::make(*a > *b); });
  
  semantics->builtin_implementMultiMethod("float32", [](instance<uint32_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<uint32_t> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<uint32_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<uint32_t> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<uint32_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<uint32_t> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<uint32_t> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<uint32_t> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<uint32_t> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<uint32_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<uint32_t> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<uint32_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<float> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<float> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<float> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<float> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<float> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<float> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<float> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<float> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<float> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<float> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<float> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<float> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<int64_t> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<int64_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<int64_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<int64_t> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<int64_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<int64_t> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<int64_t> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<int64_t> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<int64_t> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<int64_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<int64_t> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<int64_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<mpq_class> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float32", [](instance<mpq_class> a) -> instance<float> { return instance<float>::make(float(a->get_d())); });
  semantics->builtin_implementMultiMethod("int64", [](instance<mpq_class> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<mpq_class> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float64", [](instance<mpq_class> a) -> instance<double> { return instance<double>::make(double(a->get_d())); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<mpq_class> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int32", [](instance<mpq_class> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int8", [](instance<mpq_class> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int16", [](instance<mpq_class> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float", [](instance<mpq_class> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<mpq_class> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int", [](instance<mpq_class> a) -> instance<mpz_class> { return instance<mpz_class>::make(a->get_d()); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<uint8_t> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<uint8_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<uint8_t> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<uint8_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<uint8_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<uint8_t> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<uint8_t> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<uint8_t> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<uint8_t> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<uint8_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<uint8_t> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<uint8_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<double> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<double> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<double> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<double> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<double> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<double> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<double> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<double> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<double> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<double> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<double> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<double> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<uint16_t> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<uint16_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<uint16_t> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<uint16_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<uint16_t> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<uint16_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<uint16_t> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<uint16_t> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<uint16_t> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<uint16_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<uint16_t> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<uint16_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<int32_t> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<int32_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<int32_t> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<int32_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<int32_t> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<int32_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<int32_t> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<int32_t> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<int32_t> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<int32_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<int32_t> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<int32_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<int8_t> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<int8_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<int8_t> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<int8_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<int8_t> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<int8_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<int8_t> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<int8_t> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<int8_t> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<int8_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<int8_t> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<int8_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<int16_t> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<int16_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<int16_t> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<int16_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<int16_t> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<int16_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<int16_t> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<int16_t> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<int16_t> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<int16_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<int16_t> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<int16_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<mpf_class> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float32", [](instance<mpf_class> a) -> instance<float> { return instance<float>::make(float(a->get_d())); });
  semantics->builtin_implementMultiMethod("int64", [](instance<mpf_class> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<mpf_class> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<mpf_class> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float64", [](instance<mpf_class> a) -> instance<double> { return instance<double>::make(a->get_d()); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<mpf_class> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int32", [](instance<mpf_class> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int8", [](instance<mpf_class> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int16", [](instance<mpf_class> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<mpf_class> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int", [](instance<mpf_class> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(a->get_d())); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<uint64_t> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(*a)); });
  semantics->builtin_implementMultiMethod("float32", [](instance<uint64_t> a) -> instance<float> { return instance<float>::make(float(*a)); });
  semantics->builtin_implementMultiMethod("int64", [](instance<uint64_t> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(*a)); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<uint64_t> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<uint64_t> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(*a)); });
  semantics->builtin_implementMultiMethod("float64", [](instance<uint64_t> a) -> instance<double> { return instance<double>::make(double(*a)); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<uint64_t> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(*a)); });
  semantics->builtin_implementMultiMethod("int32", [](instance<uint64_t> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(*a)); });
  semantics->builtin_implementMultiMethod("int8", [](instance<uint64_t> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(*a)); });
  semantics->builtin_implementMultiMethod("int16", [](instance<uint64_t> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<uint64_t> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<uint64_t> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });
  semantics->builtin_implementMultiMethod("uint32", [](instance<mpz_class> a) -> instance<uint32_t> { return instance<uint32_t>::make(uint32_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float32", [](instance<mpz_class> a) -> instance<float> { return instance<float>::make(float(a->get_d())); });
  semantics->builtin_implementMultiMethod("int64", [](instance<mpz_class> a) -> instance<int64_t> { return instance<int64_t>::make(int64_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("decimal", [](instance<mpz_class> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("uint8", [](instance<mpz_class> a) -> instance<uint8_t> { return instance<uint8_t>::make(uint8_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float64", [](instance<mpz_class> a) -> instance<double> { return instance<double>::make(double(a->get_d())); });
  semantics->builtin_implementMultiMethod("uint16", [](instance<mpz_class> a) -> instance<uint16_t> { return instance<uint16_t>::make(uint16_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int32", [](instance<mpz_class> a) -> instance<int32_t> { return instance<int32_t>::make(int32_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int8", [](instance<mpz_class> a) -> instance<int8_t> { return instance<int8_t>::make(int8_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("int16", [](instance<mpz_class> a) -> instance<int16_t> { return instance<int16_t>::make(int16_t(a->get_d())); });
  semantics->builtin_implementMultiMethod("float", [](instance<mpz_class> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("uint64", [](instance<mpz_class> a) -> instance<uint64_t> { return instance<uint64_t>::make(uint64_t(a->get_d())); });

  semantics->builtin_implementMultiMethod("decimal", [](instance<std::string> a) -> instance<mpq_class> { return instance<mpq_class>::make(mpq_class(*a)); });
  semantics->builtin_implementMultiMethod("float", [](instance<std::string> a) -> instance<mpf_class> { return instance<mpf_class>::make(mpf_class(*a)); });
  semantics->builtin_implementMultiMethod("int", [](instance<std::string> a) -> instance<mpz_class> { return instance<mpz_class>::make(mpz_class(*a)); });

  semantics->builtin_implementMultiMethod("+", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<mpz_class> { return instance<mpz_class>::make(*a + *b); });
  semantics->builtin_implementMultiMethod("+", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<mpq_class> { return instance<mpq_class>::make(*a + *b); });
  semantics->builtin_implementMultiMethod("+", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<mpf_class> { return instance<mpf_class>::make(*a + *b); });
  semantics->builtin_implementMultiMethod("/", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<mpz_class> { return instance<mpz_class>::make(*a / *b); });
  semantics->builtin_implementMultiMethod("/", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<mpq_class> { return instance<mpq_class>::make(*a / *b); });
  semantics->builtin_implementMultiMethod("/", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<mpf_class> { return instance<mpf_class>::make(*a / *b); });
  semantics->builtin_implementMultiMethod("-", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<mpz_class> { return instance<mpz_class>::make(*a - *b); });
  semantics->builtin_implementMultiMethod("-", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<mpq_class> { return instance<mpq_class>::make(*a - *b); });
  semantics->builtin_implementMultiMethod("-", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<mpf_class> { return instance<mpf_class>::make(*a - *b); });
  semantics->builtin_implementMultiMethod("*", [](instance<mpz_class> a, instance<mpz_class> b) -> instance<mpz_class> { return instance<mpz_class>::make(*a * *b); });
  semantics->builtin_implementMultiMethod("*", [](instance<mpq_class> a, instance<mpq_class> b) -> instance<mpq_class> { return instance<mpq_class>::make(*a * *b); });
  semantics->builtin_implementMultiMethod("*", [](instance<mpf_class> a, instance<mpf_class> b) -> instance<mpf_class> { return instance<mpf_class>::make(*a * *b); });
}

BuiltinModuleDescription cultlang::mpir::BuiltinMpir("cultlang/mpir", cultlang::mpir::make_bindings);


#include "types/dll_entry.inc"
