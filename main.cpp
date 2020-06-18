#include <iostream>
#include <cstdint>
#include <typeinfo>
#include <type_traits>
#include "my_type_traits"

using namespace std;

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

	cout << endl;

	cout << my::is_integral_v<float> << endl;
	cout << my::is_integral_v<double> << endl;
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
	return 0;
}
