#include <iostream>

template <typename T>
void iter(T* x, size_t length, void (*f)(T& e)) {
    for (size_t i = 0; i < length; ++i) {
		f(x[i]);
	}
}

template <typename T>
void f(T& a) {
	a++;
}

template <typename T>
void f1(T& a) {
	std::cout << a << std::endl;
}

int	main() {
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	iter(a, 10, f1);
	iter(a, 10, f);
	iter(a, 10, f1);
	return 0;
}