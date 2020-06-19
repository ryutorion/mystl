#include <iostream>
#include <cstdint>
#include <typeinfo>
#include <type_traits>
#include "my_type_traits"

using namespace std;

template <typename T, size_t N>
void f()
{
	cout << my::is_array_v<T[N]> << endl;
	cout << typeid(T[N]).name() << endl;
}

int main()
{
	cout << my::is_same_v<my::remove_const_t<int>, int> << endl;
	cout << my::is_same_v<my::remove_const_t<const int>, int> << endl;
	cout << my::is_same_v<my::remove_const_t<volatile int>, volatile int> << endl;
	cout << my::is_same_v<my::remove_const_t<const volatile int>, volatile int> << endl;
	cout << my::is_same_v<my::remove_const_t<volatile const int>, volatile int> << endl;
	cout << my::is_same_v<my::remove_const_t<int *>, int *> << endl;
	cout << my::is_same_v<my::remove_const_t<const int *>, const int *> << endl;
	cout << my::is_same_v<my::remove_const_t<volatile int *>, volatile int *> << endl;
	cout << my::is_same_v<my::remove_const_t<const volatile int *>, const volatile int *> << endl;
	cout << my::is_same_v<my::remove_const_t<volatile const int *>, volatile const int *> << endl;
	cout << my::is_same_v<my::remove_const_t<int * const>, int *> << endl;
	cout << my::is_same_v<my::remove_const_t<int * const volatile>, int * volatile> << endl;
	cout << my::is_same_v<my::remove_const_t<int * volatile const>, int * volatile> << endl;

	cout << endl;

	cout << my::is_same_v<my::remove_volatile_t<int>, int> << endl;
	cout << my::is_same_v<my::remove_volatile_t<const int>, const int> << endl;
	cout << my::is_same_v<my::remove_volatile_t<volatile int>, int> << endl;
	cout << my::is_same_v<my::remove_volatile_t<const volatile int>, const int> << endl;
	cout << my::is_same_v<my::remove_volatile_t<volatile const int>, const int> << endl;
	cout << my::is_same_v<my::remove_volatile_t<int *>, int *> << endl;
	cout << my::is_same_v<my::remove_volatile_t<const int *>, const int *> << endl;
	cout << my::is_same_v<my::remove_volatile_t<volatile int *>, volatile int *> << endl;
	cout << my::is_same_v<my::remove_volatile_t<const volatile int *>, const volatile int *> << endl;
	cout << my::is_same_v<my::remove_volatile_t<volatile const int *>, volatile const int *> << endl;
	cout << my::is_same_v<my::remove_volatile_t<int * const>, int * const> << endl;
	cout << my::is_same_v<my::remove_volatile_t<int * const volatile>, int * const> << endl;
	cout << my::is_same_v<my::remove_volatile_t<int * volatile const>, int * const> << endl;

	cout << endl;

	cout << my::is_same_v<my::remove_cv_t<int>, int> << endl;
	cout << my::is_same_v<my::remove_cv_t<const int>, int> << endl;
	cout << my::is_same_v<my::remove_cv_t<volatile int>, int> << endl;
	cout << my::is_same_v<my::remove_cv_t<const volatile int>, int> << endl;
	cout << my::is_same_v<my::remove_cv_t<volatile const int>, int> << endl;
	cout << my::is_same_v<my::remove_cv_t<int *>, int *> << endl;
	cout << my::is_same_v<my::remove_cv_t<const int *>, const int *> << endl;
	cout << my::is_same_v<my::remove_cv_t<volatile int *>, volatile int *> << endl;
	cout << my::is_same_v<my::remove_cv_t<const volatile int *>, const volatile int *> << endl;
	cout << my::is_same_v<my::remove_cv_t<volatile const int *>, volatile const int *> << endl;
	cout << my::is_same_v<my::remove_cv_t<int * const>, int *> << endl;
	cout << my::is_same_v<my::remove_cv_t<int * const volatile>, int *> << endl;
	cout << my::is_same_v<my::remove_cv_t<int * volatile const>, int *> << endl;

	cout << endl;

	cout << my::is_void_v<int> << endl;
	cout << my::is_void_v<void> << endl;
	cout << my::is_void_v<const void> << endl;
	cout << my::is_void_v<volatile void> << endl;
	cout << my::is_void_v<void *> << endl;

	cout << endl;

	cout << my::is_null_pointer_v<nullptr_t> << endl;
	cout << my::is_null_pointer_v<const nullptr_t> << endl;
	cout << my::is_null_pointer_v<volatile nullptr_t> << endl;
	cout << my::is_null_pointer_v<const volatile nullptr_t> << endl;

	cout << endl;

	cout << my::is_integral_v<bool> << endl;
	cout << my::is_integral_v<char> << endl;
	cout << my::is_integral_v<unsigned char> << endl;
	cout << my::is_integral_v<char16_t> << endl;
	cout << my::is_integral_v<char32_t> << endl;
	cout << my::is_integral_v<short> << endl;
	cout << my::is_integral_v<unsigned short> << endl;
	cout << my::is_integral_v<int> << endl;
	cout << my::is_integral_v<unsigned int> << endl;
	cout << my::is_integral_v<long> << endl;
	cout << my::is_integral_v<unsigned long> << endl;
	cout << my::is_integral_v<long long> << endl;
	cout << my::is_integral_v<unsigned long long> << endl;
	cout << my::is_integral_v<int8_t> << endl;
	cout << my::is_integral_v<uint8_t> << endl;
	cout << my::is_integral_v<int16_t> << endl;
	cout << my::is_integral_v<uint16_t> << endl;
	cout << my::is_integral_v<int32_t> << endl;
	cout << my::is_integral_v<uint32_t> << endl;
	cout << my::is_integral_v<int64_t> << endl;
	cout << my::is_integral_v<uint64_t> << endl;
	cout << my::is_integral_v<size_t> << endl;

	cout << endl;

	cout << my::is_integral_v<float> << endl;
	cout << my::is_integral_v<double> << endl;
	cout << my::is_integral_v<long double> << endl;
	cout << my::is_integral_v<bool *> << endl;
	cout << my::is_integral_v<char *> << endl;
	cout << my::is_integral_v<unsigned char *> << endl;
	cout << my::is_integral_v<char16_t *> << endl;
	cout << my::is_integral_v<char32_t *> << endl;
	cout << my::is_integral_v<short *> << endl;
	cout << my::is_integral_v<unsigned short *> << endl;
	cout << my::is_integral_v<int *> << endl;
	cout << my::is_integral_v<unsigned int *> << endl;
	cout << my::is_integral_v<long *> << endl;
	cout << my::is_integral_v<unsigned long *> << endl;
	cout << my::is_integral_v<long long *> << endl;
	cout << my::is_integral_v<unsigned long long *> << endl;
	cout << my::is_integral_v<int8_t *> << endl;
	cout << my::is_integral_v<uint8_t *> << endl;
	cout << my::is_integral_v<int16_t *> << endl;
	cout << my::is_integral_v<uint16_t *> << endl;
	cout << my::is_integral_v<int32_t *> << endl;
	cout << my::is_integral_v<uint32_t *> << endl;
	cout << my::is_integral_v<int64_t *> << endl;
	cout << my::is_integral_v<uint64_t *> << endl;

	cout << endl;

	cout << my::is_floating_point_v<bool> << endl;
	cout << my::is_floating_point_v<char> << endl;
	cout << my::is_floating_point_v<unsigned char> << endl;
	cout << my::is_floating_point_v<char16_t> << endl;
	cout << my::is_floating_point_v<char32_t> << endl;
	cout << my::is_floating_point_v<short> << endl;
	cout << my::is_floating_point_v<unsigned short> << endl;
	cout << my::is_floating_point_v<int> << endl;
	cout << my::is_floating_point_v<unsigned int> << endl;
	cout << my::is_floating_point_v<long> << endl;
	cout << my::is_floating_point_v<unsigned long> << endl;
	cout << my::is_floating_point_v<long long> << endl;
	cout << my::is_floating_point_v<unsigned long long> << endl;
	cout << my::is_floating_point_v<int8_t> << endl;
	cout << my::is_floating_point_v<uint8_t> << endl;
	cout << my::is_floating_point_v<int16_t> << endl;
	cout << my::is_floating_point_v<uint16_t> << endl;
	cout << my::is_floating_point_v<int32_t> << endl;
	cout << my::is_floating_point_v<uint32_t> << endl;
	cout << my::is_floating_point_v<int64_t> << endl;
	cout << my::is_floating_point_v<uint64_t> << endl;
	cout << my::is_floating_point_v<float> << endl;
	cout << my::is_floating_point_v<double> << endl;
	cout << my::is_floating_point_v<long double> << endl;

	cout << endl;

	typedef int b[5];
	using a = int[5];

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
	cout << my::is_array_v<a> << endl;
	cout << my::is_array_v<b> << endl;

	f<int, 5>();
	cout << typeid(array1).name() << endl;
	cout << typeid(array2).name() << endl;
	cout << typeid(array3).name() << endl;
	cout << typeid(array4).name() << endl;
	cout << typeid(array5).name() << endl;
	cout << typeid(array6).name() << endl;

	return 0;
}
