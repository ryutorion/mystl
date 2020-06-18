#include <iostream>
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

	return 0;
}
