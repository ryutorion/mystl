﻿#include <iostream>
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

	int array1[]{ 1, 2, 3 };
	int array2[2];
	int array3[5];
	const int array4[]{ 1, 2, 3 };
	const int array5[2]{ 1, 2, };
	const int array6[5]{ 1, 2, 3, 4, 5, };

	cout << my::is_array_v<decltype(array1)> << endl;
	cout << my::is_array_v<decltype(array2)> << endl;
	cout << my::is_array_v<decltype(array3)> << endl;
	cout << my::is_array_v<decltype(array4)> << endl;
	cout << my::is_array_v<decltype(array5)> << endl;
	cout << my::is_array_v<decltype(array6)> << endl;
	cout << my::is_array_v<int *> << endl;
	cout << my::is_array_v<int []> << endl;
	cout << my::is_array_v<int [5]> << endl;
	cout << my::is_array_v<const int *> << endl;
	cout << my::is_array_v<const int []> << endl;
	cout << my::is_array_v<const int [5]> << endl;

	cout << endl;

	cout << my::is_pointer_v<int> << endl;
	cout << my::is_pointer_v<int *> << endl;
	cout << my::is_pointer_v<const int *> << endl;
	cout << my::is_pointer_v<volatile int *> << endl;
	cout << my::is_pointer_v<const volatile int *> << endl;
	cout << my::is_pointer_v<int * const> << endl;
	cout << my::is_pointer_v<int * volatile> << endl;
	cout << my::is_pointer_v<int * const volatile> << endl;
	cout << my::is_pointer_v<const int * const> << endl;
	cout << my::is_pointer_v<const int * volatile> << endl;
	cout << my::is_pointer_v<const int * const volatile> << endl;
	cout << my::is_pointer_v<volatile int * const> << endl;
	cout << my::is_pointer_v<volatile int * volatile> << endl;
	cout << my::is_pointer_v<volatile int * const volatile> << endl;
	cout << my::is_pointer_v<const volatile int * const> << endl;
	cout << my::is_pointer_v<const volatile int * volatile> << endl;
	cout << my::is_pointer_v<const volatile int * const volatile> << endl;

	cout << endl;

	cout << my::is_lvalue_reference_v<int> << endl;
	cout << my::is_lvalue_reference_v<int &> << endl;
	cout << my::is_lvalue_reference_v<int &&> << endl;
	cout << my::is_lvalue_reference_v<const int> << endl;
	cout << my::is_lvalue_reference_v<const int &> << endl;
	cout << my::is_lvalue_reference_v<const int &&> << endl;
	cout << my::is_lvalue_reference_v<volatile int> << endl;
	cout << my::is_lvalue_reference_v<volatile int &> << endl;
	cout << my::is_lvalue_reference_v<volatile int &&> << endl;
	cout << my::is_lvalue_reference_v<const volatile int> << endl;
	cout << my::is_lvalue_reference_v<const volatile int &> << endl;
	cout << my::is_lvalue_reference_v<const volatile int &&> << endl;

	cout << endl;

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

	cout << my::is_union_v<char> << endl;
	cout << my::is_union_v<int> << endl;
	cout << my::is_union_v<Struct> << endl;
	cout << my::is_union_v<Union> << endl;

	cout << endl;

	cout << my::is_enum_v<char> << endl;
	cout << my::is_enum_v<Struct> << endl;
	cout << my::is_enum_v<Union> << endl;
	cout << my::is_enum_v<Enum> << endl;
	cout << my::is_enum_v<EnumClass> << endl;

	cout << endl;

	typedef void fc() const;

	cout << my::is_const_v<int> << endl;
	cout << my::is_const_v<int *> << endl;
	cout << my::is_const_v<int &> << endl;
	cout << my::is_const_v<const int> << endl;
	cout << my::is_const_v<const int *> << endl;
	cout << my::is_const_v<const int &> << endl;
	cout << my::is_const_v<const int * const> << endl;
	cout << my::is_const_v<fc> << endl;

	return 0;
}
