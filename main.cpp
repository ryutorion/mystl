#include <iostream>
#include <cstdint>
#include <typeinfo>
#include <type_traits>
#include "my_type_traits"

using namespace std;

struct Struct
{
	int i;

	int n() { return 1; }
	int c() const { return 2; }
	int cn() const noexcept { return 3; }
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

	cout << my::is_rvalue_reference_v<int> << endl;
	cout << my::is_rvalue_reference_v<int &> << endl;
	cout << my::is_rvalue_reference_v<int &&> << endl;
	cout << my::is_rvalue_reference_v<const int> << endl;
	cout << my::is_rvalue_reference_v<const int &> << endl;
	cout << my::is_rvalue_reference_v<const int &&> << endl;
	cout << my::is_rvalue_reference_v<volatile int> << endl;
	cout << my::is_rvalue_reference_v<volatile int &> << endl;
	cout << my::is_rvalue_reference_v<volatile int &&> << endl;
	cout << my::is_rvalue_reference_v<const volatile int> << endl;
	cout << my::is_rvalue_reference_v<const volatile int &> << endl;
	cout << my::is_rvalue_reference_v<const volatile int &&> << endl;

	cout << endl;

	cout << my::is_reference_v<int> << endl;
	cout << my::is_reference_v<int &> << endl;
	cout << my::is_reference_v<int &&> << endl;
	cout << my::is_reference_v<const int> << endl;
	cout << my::is_reference_v<const int &> << endl;
	cout << my::is_reference_v<const int &&> << endl;
	cout << my::is_reference_v<volatile int> << endl;
	cout << my::is_reference_v<volatile int &> << endl;
	cout << my::is_reference_v<volatile int &&> << endl;
	cout << my::is_reference_v<const volatile int> << endl;
	cout << my::is_reference_v<const volatile int &> << endl;
	cout << my::is_reference_v<const volatile int &&> << endl;

	cout << endl;

	cout << my::is_arithmetic_v<char> << endl;
	cout << my::is_arithmetic_v<int> << endl;
	cout << my::is_arithmetic_v<float> << endl;
	cout << my::is_arithmetic_v<double> << endl;
	cout << my::is_arithmetic_v<const int> << endl;
	cout << my::is_arithmetic_v<const float> << endl;
	cout << my::is_arithmetic_v<const double> << endl;
	cout << my::is_arithmetic_v<const volatile int> << endl;
	cout << my::is_arithmetic_v<const volatile float> << endl;
	cout << my::is_arithmetic_v<const volatile double> << endl;
	cout << my::is_arithmetic_v<int *> << endl;
	cout << my::is_arithmetic_v<float *> << endl;
	cout << my::is_arithmetic_v<double *> << endl;

	cout << endl;

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


	return 0;
}
