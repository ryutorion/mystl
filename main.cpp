#include <iostream>
#include <cstdint>
#include <typeinfo>
#include <type_traits>
#include "my_type_traits"

using namespace std;

struct Struct
{
	int i;

	int f() { return 1; }
	int fc() const { return 2; }
	int fv() volatile { return 2; }
	int fcv() const volatile { return 2; }
	int fr() & { return 1; }
	int fcr() const & { return 2; }
	int fvr() volatile & { return 2; }
	int fcvr() const volatile & { return 2; }
	int frr() && { return 1; }
	int fcrr() const && { return 2; }
	int fvrr() volatile && { return 2; }
	int fcvrr() const volatile && { return 2; }
	int fn() noexcept { return 1; }
	int fcn() const noexcept { return 2; }
	int fvn() volatile noexcept { return 2; }
	int fcvn() const volatile noexcept { return 2; }
	int frn() & noexcept { return 1; }
	int fcrn() const & noexcept { return 2; }
	int fvrn() volatile & noexcept { return 2; }
	int fcvrn() const volatile & noexcept { return 2; }
	int frrn() && noexcept { return 1; }
	int fcrrn() const && noexcept { return 2; }
	int fvrrn() volatile && noexcept { return 2; }
	int fcvrrn() const volatile && noexcept { return 2; }
};

class Class
{
public:
	int i;

	int f() { return 1; }
	int fc() const { return 2; }
	int fv() volatile { return 2; }
	int fcv() const volatile { return 2; }
	int fr() & { return 1; }
	int fcr() const & { return 2; }
	int fvr() volatile & { return 2; }
	int fcvr() const volatile & { return 2; }
	int frr() && { return 1; }
	int fcrr() const && { return 2; }
	int fvrr() volatile && { return 2; }
	int fcvrr() const volatile && { return 2; }
	int fn() noexcept { return 1; }
	int fcn() const noexcept { return 2; }
	int fvn() volatile noexcept { return 2; }
	int fcvn() const volatile noexcept { return 2; }
	int frn() & noexcept { return 1; }
	int fcrn() const & noexcept { return 2; }
	int fvrn() volatile & noexcept { return 2; }
	int fcvrn() const volatile & noexcept { return 2; }
	int frrn() && noexcept { return 1; }
	int fcrrn() const && noexcept { return 2; }
	int fvrrn() volatile && noexcept { return 2; }
	int fcvrrn() const volatile && noexcept { return 2; }
};




union Union
{
	char u;
	short s;
	int i;
	float f;
	double d;
};

enum Enum
{
	A,
	B,
	C,
	D
};

enum class EnumClass
{
	CA,
	CB,
	CC,
	CD
};

int main()
{
	static_assert(integral_constant<int, 1>::value == 1);
	static_assert(integral_constant<bool, false>::value == false);

	static_assert(my::is_same_v<int, int>);
	static_assert(!my::is_same_v<int, const int>);

	static_assert(my::is_same_v<my::remove_const_t<int>, int>);
	static_assert(my::is_same_v<my::remove_const_t<const int>, int>);
	static_assert(my::is_same_v<my::remove_const_t<volatile int>, volatile int>);
	static_assert(my::is_same_v<my::remove_const_t<const volatile int>, volatile int>);
	static_assert(my::is_same_v<my::remove_const_t<volatile const int>, volatile int>);
	static_assert(my::is_same_v<my::remove_const_t<int *>, int *>);
	static_assert(my::is_same_v<my::remove_const_t<const int *>, const int *>);
	static_assert(my::is_same_v<my::remove_const_t<volatile int *>, volatile int *>);
	static_assert(my::is_same_v<my::remove_const_t<const volatile int *>, const volatile int *>);
	static_assert(my::is_same_v<my::remove_const_t<volatile const int *>, volatile const int *>);
	static_assert(my::is_same_v<my::remove_const_t<int * const>, int *>);
	static_assert(my::is_same_v<my::remove_const_t<int * const volatile>, int * volatile>);
	static_assert(my::is_same_v<my::remove_const_t<int * volatile const>, int * volatile>);
	static_assert(my::is_same_v<my::remove_const_t<int [3]>, int [3]>);
	static_assert(my::is_same_v<my::remove_const_t<const int [3]>, int [3]>);

	static_assert(my::is_same_v<my::add_const_t<int>, const int>);
	static_assert(my::is_same_v<my::add_const_t<const int>, const int>);
	static_assert(my::is_same_v<my::add_const_t<volatile int>, const volatile int>);
	static_assert(my::is_same_v<my::add_const_t<const volatile int>, const volatile int>);
	static_assert(my::is_same_v<my::add_const_t<int *>, int * const>);
	static_assert(my::is_same_v<my::add_const_t<const int *>, const int * const>);
	static_assert(my::is_same_v<my::add_const_t<volatile int *>, volatile int * const>);
	static_assert(my::is_same_v<my::add_const_t<const volatile int *>, const volatile int * const>);

	static_assert(my::is_same_v<my::remove_volatile_t<int>, int>);
	static_assert(my::is_same_v<my::remove_volatile_t<const int>, const int>);
	static_assert(my::is_same_v<my::remove_volatile_t<volatile int>, int>);
	static_assert(my::is_same_v<my::remove_volatile_t<const volatile int>, const int>);
	static_assert(my::is_same_v<my::remove_volatile_t<volatile const int>, const int>);
	static_assert(my::is_same_v<my::remove_volatile_t<int *>, int *>);
	static_assert(my::is_same_v<my::remove_volatile_t<const int *>, const int *>);
	static_assert(my::is_same_v<my::remove_volatile_t<volatile int *>, volatile int *>);
	static_assert(my::is_same_v<my::remove_volatile_t<const volatile int *>, const volatile int *>);
	static_assert(my::is_same_v<my::remove_volatile_t<volatile const int *>, volatile const int *>);
	static_assert(my::is_same_v<my::remove_volatile_t<int * const>, int * const>);
	static_assert(my::is_same_v<my::remove_volatile_t<int * const volatile>, int * const>);
	static_assert(my::is_same_v<my::remove_volatile_t<int * volatile const>, int * const>);

	static_assert(my::is_same_v<my::add_volatile_t<int>, volatile int>);
	static_assert(my::is_same_v<my::add_volatile_t<const int>, const volatile int>);
	static_assert(my::is_same_v<my::add_volatile_t<volatile int>, volatile int>);
	static_assert(my::is_same_v<my::add_volatile_t<const volatile int>, const volatile int>);
	static_assert(my::is_same_v<my::add_volatile_t<int *>, int * volatile>);
	static_assert(my::is_same_v<my::add_volatile_t<const int *>, const int * volatile>);
	static_assert(my::is_same_v<my::add_volatile_t<volatile int *>, volatile int * volatile>);
	static_assert(my::is_same_v<my::add_volatile_t<const volatile int *>, const volatile int * volatile>);

	static_assert(my::is_same_v<my::remove_cv_t<int>, int>);
	static_assert(my::is_same_v<my::remove_cv_t<const int>, int>);
	static_assert(my::is_same_v<my::remove_cv_t<volatile int>, int>);
	static_assert(my::is_same_v<my::remove_cv_t<const volatile int>, int>);
	static_assert(my::is_same_v<my::remove_cv_t<volatile const int>, int>);
	static_assert(my::is_same_v<my::remove_cv_t<int *>, int *>);
	static_assert(my::is_same_v<my::remove_cv_t<const int *>, const int *>);
	static_assert(my::is_same_v<my::remove_cv_t<volatile int *>, volatile int *>);
	static_assert(my::is_same_v<my::remove_cv_t<const volatile int *>, const volatile int *>);
	static_assert(my::is_same_v<my::remove_cv_t<volatile const int *>, volatile const int *>);
	static_assert(my::is_same_v<my::remove_cv_t<int * const>, int *>);
	static_assert(my::is_same_v<my::remove_cv_t<int * const volatile>, int *>);
	static_assert(my::is_same_v<my::remove_cv_t<int * volatile const>, int *>);

	static_assert(my::is_same_v<my::add_cv_t<int>, const volatile int>);
	static_assert(my::is_same_v<my::add_cv_t<const int>, const volatile int>);
	static_assert(my::is_same_v<my::add_cv_t<volatile int>, const volatile int>);
	static_assert(my::is_same_v<my::add_cv_t<const volatile int>, const volatile int>);
	static_assert(my::is_same_v<my::add_cv_t<volatile const int>, const volatile int>);
	static_assert(my::is_same_v<my::add_cv_t<int *>, int * const volatile >);
	static_assert(my::is_same_v<my::add_cv_t<const int *>, const int * const volatile>);
	static_assert(my::is_same_v<my::add_cv_t<volatile int *>, volatile int * const volatile>);
	static_assert(my::is_same_v<my::add_cv_t<const volatile int *>, const volatile int * const volatile>);
	static_assert(my::is_same_v<my::add_cv_t<volatile const int *>, volatile const int * const volatile>);
	static_assert(my::is_same_v<my::add_cv_t<int * const>, int * const volatile>);
	static_assert(my::is_same_v<my::add_cv_t<int * const volatile>, int * const volatile>);
	static_assert(my::is_same_v<my::add_cv_t<int * volatile const>, int * const volatile>);

	static_assert(!my::is_void_v<int>);
	static_assert(my::is_void_v<void>);
	static_assert(my::is_void_v<const void>);
	static_assert(my::is_void_v<volatile void>);
	static_assert(my::is_void_v<const volatile void>);
	static_assert(!my::is_void_v<void *>);

	static_assert(my::is_null_pointer_v<nullptr_t>);
	static_assert(my::is_null_pointer_v<const nullptr_t>);
	static_assert(my::is_null_pointer_v<volatile nullptr_t>);
	static_assert(my::is_null_pointer_v<const volatile nullptr_t>);

	static_assert(my::is_integral_v<bool>);
	static_assert(my::is_integral_v<char>);
	static_assert(my::is_integral_v<unsigned char>);
	static_assert(my::is_integral_v<char16_t>);
	static_assert(my::is_integral_v<char32_t>);
	static_assert(my::is_integral_v<short>);
	static_assert(my::is_integral_v<unsigned short>);
	static_assert(my::is_integral_v<int>);
	static_assert(my::is_integral_v<unsigned int>);
	static_assert(my::is_integral_v<long>);
	static_assert(my::is_integral_v<unsigned long>);
	static_assert(my::is_integral_v<long long>);
	static_assert(my::is_integral_v<unsigned long long>);
	static_assert(my::is_integral_v<int8_t>);
	static_assert(my::is_integral_v<uint8_t>);
	static_assert(my::is_integral_v<int16_t>);
	static_assert(my::is_integral_v<uint16_t>);
	static_assert(my::is_integral_v<int32_t>);
	static_assert(my::is_integral_v<uint32_t>);
	static_assert(my::is_integral_v<int64_t>);
	static_assert(my::is_integral_v<uint64_t>);
	static_assert(my::is_integral_v<size_t>);
	static_assert(!my::is_integral_v<float>);
	static_assert(!my::is_integral_v<double>);
	static_assert(!my::is_integral_v<long double>);
	static_assert(!my::is_integral_v<bool *>);
	static_assert(!my::is_integral_v<char *>);
	static_assert(!my::is_integral_v<unsigned char *>);
	static_assert(!my::is_integral_v<char16_t *>);
	static_assert(!my::is_integral_v<char32_t *>);
	static_assert(!my::is_integral_v<short *>);
	static_assert(!my::is_integral_v<unsigned short *>);
	static_assert(!my::is_integral_v<int *>);
	static_assert(!my::is_integral_v<unsigned int *>);
	static_assert(!my::is_integral_v<long *>);
	static_assert(!my::is_integral_v<unsigned long *>);
	static_assert(!my::is_integral_v<long long *>);
	static_assert(!my::is_integral_v<unsigned long long *>);
	static_assert(!my::is_integral_v<int8_t *>);
	static_assert(!my::is_integral_v<uint8_t *>);
	static_assert(!my::is_integral_v<int16_t *>);
	static_assert(!my::is_integral_v<uint16_t *>);
	static_assert(!my::is_integral_v<int32_t *>);
	static_assert(!my::is_integral_v<uint32_t *>);
	static_assert(!my::is_integral_v<int64_t *>);
	static_assert(!my::is_integral_v<uint64_t *>);

	static_assert(!my::is_floating_point_v<bool>);
	static_assert(!my::is_floating_point_v<char>);
	static_assert(!my::is_floating_point_v<unsigned char>);
	static_assert(!my::is_floating_point_v<char16_t>);
	static_assert(!my::is_floating_point_v<char32_t>);
	static_assert(!my::is_floating_point_v<short>);
	static_assert(!my::is_floating_point_v<unsigned short>);
	static_assert(!my::is_floating_point_v<int>);
	static_assert(!my::is_floating_point_v<unsigned int>);
	static_assert(!my::is_floating_point_v<long>);
	static_assert(!my::is_floating_point_v<unsigned long>);
	static_assert(!my::is_floating_point_v<long long>);
	static_assert(!my::is_floating_point_v<unsigned long long>);
	static_assert(!my::is_floating_point_v<int8_t>);
	static_assert(!my::is_floating_point_v<uint8_t>);
	static_assert(!my::is_floating_point_v<int16_t>);
	static_assert(!my::is_floating_point_v<uint16_t>);
	static_assert(!my::is_floating_point_v<int32_t>);
	static_assert(!my::is_floating_point_v<uint32_t>);
	static_assert(!my::is_floating_point_v<int64_t>);
	static_assert(!my::is_floating_point_v<uint64_t>);
	static_assert(my::is_floating_point_v<float>);
	static_assert(my::is_floating_point_v<double>);
	static_assert(my::is_floating_point_v<long double>);

	static_assert(!my::is_array_v<int *>);
	static_assert(my::is_array_v<int []>);
	static_assert(my::is_array_v<int [5]>);
	static_assert(!my::is_array_v<const int *>);
	static_assert(my::is_array_v<const int []>);
	static_assert(my::is_array_v<const int [5]>);

	static_assert(!my::is_pointer_v<int>);
	static_assert(my::is_pointer_v<int *>);
	static_assert(my::is_pointer_v<const int *>);
	static_assert(my::is_pointer_v<volatile int *>);
	static_assert(my::is_pointer_v<const volatile int *>);
	static_assert(my::is_pointer_v<int * const>);
	static_assert(my::is_pointer_v<int * volatile>);
	static_assert(my::is_pointer_v<int * const volatile>);
	static_assert(my::is_pointer_v<const int * const>);
	static_assert(my::is_pointer_v<const int * volatile>);
	static_assert(my::is_pointer_v<const int * const volatile>);
	static_assert(my::is_pointer_v<volatile int * const>);
	static_assert(my::is_pointer_v<volatile int * volatile>);
	static_assert(my::is_pointer_v<volatile int * const volatile>);
	static_assert(my::is_pointer_v<const volatile int * const>);
	static_assert(my::is_pointer_v<const volatile int * volatile>);
	static_assert(my::is_pointer_v<const volatile int * const volatile>);

	static_assert(!my::is_lvalue_reference_v<int>);
	static_assert(my::is_lvalue_reference_v<int &>);
	static_assert(!my::is_lvalue_reference_v<int &&>);
	static_assert(!my::is_lvalue_reference_v<const int>);
	static_assert(my::is_lvalue_reference_v<const int &>);
	static_assert(!my::is_lvalue_reference_v<const int &&>);
	static_assert(!my::is_lvalue_reference_v<volatile int>);
	static_assert(my::is_lvalue_reference_v<volatile int &>);
	static_assert(!my::is_lvalue_reference_v<volatile int &&>);
	static_assert(!my::is_lvalue_reference_v<const volatile int>);
	static_assert(my::is_lvalue_reference_v<const volatile int &>);
	static_assert(!my::is_lvalue_reference_v<const volatile int &&>);

	static_assert(!my::is_rvalue_reference_v<int>);
	static_assert(!my::is_rvalue_reference_v<int &>);
	static_assert(my::is_rvalue_reference_v<int &&>);
	static_assert(!my::is_rvalue_reference_v<const int>);
	static_assert(!my::is_rvalue_reference_v<const int &>);
	static_assert(my::is_rvalue_reference_v<const int &&>);
	static_assert(!my::is_rvalue_reference_v<volatile int>);
	static_assert(!my::is_rvalue_reference_v<volatile int &>);
	static_assert(my::is_rvalue_reference_v<volatile int &&>);
	static_assert(!my::is_rvalue_reference_v<const volatile int>);
	static_assert(!my::is_rvalue_reference_v<const volatile int &>);
	static_assert(my::is_rvalue_reference_v<const volatile int &&>);

	static_assert(!my::is_reference_v<int>);
	static_assert(my::is_reference_v<int &>);
	static_assert(my::is_reference_v<int &&>);
	static_assert(!my::is_reference_v<const int>);
	static_assert(my::is_reference_v<const int &>);
	static_assert(my::is_reference_v<const int &&>);
	static_assert(!my::is_reference_v<volatile int>);
	static_assert(my::is_reference_v<volatile int &>);
	static_assert(my::is_reference_v<volatile int &&>);
	static_assert(!my::is_reference_v<const volatile int>);
	static_assert(my::is_reference_v<const volatile int &>);
	static_assert(my::is_reference_v<const volatile int &&>);

	static_assert(my::is_arithmetic_v<char>);
	static_assert(my::is_arithmetic_v<int>);
	static_assert(my::is_arithmetic_v<float>);
	static_assert(my::is_arithmetic_v<double>);
	static_assert(my::is_arithmetic_v<const int>);
	static_assert(my::is_arithmetic_v<const float>);
	static_assert(my::is_arithmetic_v<const double>);
	static_assert(my::is_arithmetic_v<const volatile int>);
	static_assert(my::is_arithmetic_v<const volatile float>);
	static_assert(my::is_arithmetic_v<const volatile double>);
	static_assert(!my::is_arithmetic_v<int *>);
	static_assert(!my::is_arithmetic_v<float *>);
	static_assert(!my::is_arithmetic_v<double *>);
	static_assert(!my::is_arithmetic_v<int []>);

	static_assert(!my::is_union_v<char>);
	static_assert(!my::is_union_v<int>);
	static_assert(!my::is_union_v<Struct>);
	static_assert(my::is_union_v<Union>);

	static_assert(!my::is_enum_v<char>);
	static_assert(!my::is_enum_v<Struct>);
	static_assert(!my::is_enum_v<Union>);
	static_assert(my::is_enum_v<Enum>);
	static_assert(my::is_enum_v<EnumClass>);

	static_assert(!my::is_const_v<int>);
	static_assert(!my::is_const_v<int *>);
	static_assert(!my::is_const_v<int &>);
	static_assert(my::is_const_v<const int>);
	static_assert(!my::is_const_v<const int *>);
	static_assert(!my::is_const_v<const int &>);
	static_assert(my::is_const_v<const int * const>);

	typedef void f();
	typedef void fc() const;
	typedef void fv() volatile;
	typedef void fcv() const volatile;
	typedef void fr() &;
	typedef void fcr() const &;
	typedef void fvr() volatile &;
	typedef void fcvr() const volatile &;
	typedef void frr() &&;
	typedef void fcrr() const &&;
	typedef void fvrr() volatile &&;
	typedef void fcvrr() const volatile &&;
	typedef void fn() noexcept;
	typedef void fcn() const noexcept;
	typedef void fvn() volatile noexcept;
	typedef void fcvn() const volatile noexcept;
	typedef void frn() & noexcept;
	typedef void fcrn() const & noexcept;
	typedef void fvrn() volatile & noexcept;
	typedef void fcvrn() const volatile & noexcept;
	typedef void frrn() && noexcept;
	typedef void fcrrn() const && noexcept;
	typedef void fvrrn() volatile && noexcept;
	typedef void fcvrrn() const volatile && noexcept;

#ifdef _MSC_VER
	typedef void __vectorcall vf();
	typedef void __vectorcall vfc() const;
	typedef void __vectorcall vfv() volatile;
	typedef void __vectorcall vfcv() const volatile;
	typedef void __vectorcall vfr() &;
	typedef void __vectorcall vfcr() const &;
	typedef void __vectorcall vfvr() volatile &;
	typedef void __vectorcall vfcvr() const volatile &;
	typedef void __vectorcall vfrr() &&;
	typedef void __vectorcall vfcrr() const &&;
	typedef void __vectorcall vfvrr() volatile &&;
	typedef void __vectorcall vfcvrr() const volatile &&;
	typedef void __vectorcall vfn() noexcept;
	typedef void __vectorcall vfcn() const noexcept;
	typedef void __vectorcall vfvn() volatile noexcept;
	typedef void __vectorcall vfcvn() const volatile noexcept;
	typedef void __vectorcall vfrn() & noexcept;
	typedef void __vectorcall vfcrn() const & noexcept;
	typedef void __vectorcall vfvrn() volatile & noexcept;
	typedef void __vectorcall vfcvrn() const volatile & noexcept;
	typedef void __vectorcall vfrrn() && noexcept;
	typedef void __vectorcall vfcrrn() const && noexcept;
	typedef void __vectorcall vfvrrn() volatile && noexcept;
	typedef void __vectorcall vfcvrrn() const volatile && noexcept;
#else
	typedef void vf() __attribute__((vectorcall));
	typedef void vfc() const __attribute__((vectorcall));
	typedef void vfv() volatile __attribute__((vectorcall));
	typedef void vfcv() const volatile __attribute__((vectorcall));
	typedef void vfr() & __attribute__((vectorcall));
	typedef void vfcr() const & __attribute__((vectorcall));
	typedef void vfvr() volatile & __attribute__((vectorcall));
	typedef void vfcvr() const volatile & __attribute__((vectorcall));
	typedef void vfrr() && __attribute__((vectorcall));
	typedef void vfcrr() const && __attribute__((vectorcall));
	typedef void vfvrr() volatile && __attribute__((vectorcall));
	typedef void vfcvrr() const volatile && __attribute__((vectorcall));
	typedef void vfn() noexcept __attribute__((vectorcall));
	typedef void vfcn() const noexcept __attribute__((vectorcall));
	typedef void vfvn() volatile noexcept __attribute__((vectorcall));
	typedef void vfcvn() const volatile noexcept __attribute__((vectorcall));
	typedef void vfrn() & noexcept __attribute__((vectorcall));
	typedef void vfcrn() const & noexcept __attribute__((vectorcall));
	typedef void vfvrn() volatile & noexcept __attribute__((vectorcall));
	typedef void vfcvrn() const volatile & noexcept __attribute__((vectorcall));
	typedef void vfrrn() && noexcept __attribute__((vectorcall));
	typedef void vfcrrn() const && noexcept __attribute__((vectorcall));
	typedef void vfvrrn() volatile && noexcept __attribute__((vectorcall));
	typedef void vfcvrrn() const volatile && noexcept __attribute__((vectorcall));
#endif

	static_assert(!my::is_function_v<int>);
	static_assert(!my::is_function_v<int *>);
	static_assert(!my::is_function_v<int &>);
	static_assert(!my::is_function_v<int &&>);
	static_assert(my::is_function_v<f>);
	static_assert(my::is_function_v<fc>);
	static_assert(my::is_function_v<fv>);
	static_assert(my::is_function_v<fcv>);
	static_assert(my::is_function_v<fr>);
	static_assert(my::is_function_v<fcr>);
	static_assert(my::is_function_v<fvr>);
	static_assert(my::is_function_v<fcvr>);
	static_assert(my::is_function_v<frr>);
	static_assert(my::is_function_v<fcrr>);
	static_assert(my::is_function_v<fvrr>);
	static_assert(my::is_function_v<fcvrr>);
	static_assert(my::is_function_v<fn>);
	static_assert(my::is_function_v<fcn>);
	static_assert(my::is_function_v<fvn>);
	static_assert(my::is_function_v<fcvn>);
	static_assert(my::is_function_v<frn>);
	static_assert(my::is_function_v<fcrn>);
	static_assert(my::is_function_v<fvrn>);
	static_assert(my::is_function_v<fcvrn>);
	static_assert(my::is_function_v<frrn>);
	static_assert(my::is_function_v<fcrrn>);
	static_assert(my::is_function_v<fvrrn>);
	static_assert(my::is_function_v<fcvrrn>);
	static_assert(my::is_function_v<vf>);
	static_assert(my::is_function_v<vfc>);
	static_assert(my::is_function_v<vfv>);
	static_assert(my::is_function_v<vfcv>);
	static_assert(my::is_function_v<vfr>);
	static_assert(my::is_function_v<vfcr>);
	static_assert(my::is_function_v<vfvr>);
	static_assert(my::is_function_v<vfcvr>);
	static_assert(my::is_function_v<vfrr>);
	static_assert(my::is_function_v<vfcrr>);
	static_assert(my::is_function_v<vfvrr>);
	static_assert(my::is_function_v<vfcvrr>);
	static_assert(my::is_function_v<vfn>);
	static_assert(my::is_function_v<vfcn>);
	static_assert(my::is_function_v<vfvn>);
	static_assert(my::is_function_v<vfcvn>);
	static_assert(my::is_function_v<vfrn>);
	static_assert(my::is_function_v<vfcrn>);
	static_assert(my::is_function_v<vfvrn>);
	static_assert(my::is_function_v<vfcvrn>);
	static_assert(my::is_function_v<vfrrn>);
	static_assert(my::is_function_v<vfcrrn>);
	static_assert(my::is_function_v<vfvrrn>);
	static_assert(my::is_function_v<vfcvrrn>);

	static_assert(!my::is_member_function_pointer_v<int>);
	static_assert(!my::is_member_function_pointer_v<const int>);
	static_assert(!my::is_member_function_pointer_v<volatile int>);
	static_assert(!my::is_member_function_pointer_v<const volatile int>);
	static_assert(!my::is_member_function_pointer_v<int *>);
	static_assert(!my::is_member_function_pointer_v<const int *>);
	static_assert(!my::is_member_function_pointer_v<volatile int *>);
	static_assert(!my::is_member_function_pointer_v<const volatile int *>);
	static_assert(!my::is_member_function_pointer_v<f>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::f)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fc)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fv)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcv)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fvr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcvr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::frr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcrr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fvrr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcvrr)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fvn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcv)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::frn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcrn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fvrn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcvrn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::frrn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcrrn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fvrrn)>);
	static_assert(my::is_member_function_pointer_v<decltype(&Struct::fcvrrn)>);

	static_assert(my::is_member_object_pointer_v<decltype(&Struct::i)>);
	static_assert(!my::is_member_object_pointer_v<decltype(&Struct::f)>);

	static_assert(!my::is_class_v<int>);
	static_assert(my::is_class_v<Struct>);
	static_assert(my::is_class_v<Class>);
	static_assert(!my::is_class_v<Union>);
	static_assert(!my::is_class_v<Enum>);
	static_assert(!my::is_class_v<EnumClass>);

	return 0;
}
