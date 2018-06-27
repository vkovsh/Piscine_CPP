#include <iostream>

template <typename T>
const T& max(const T& x, const T& y) {
    return (x > y) ? x : y;
}

template <typename T>
const T& min(const T& x, const T& y) {
    return (x < y) ? x : y;
}

template <typename T>
void	swap(const T* x, const T* y) {
	T tmp = *x;
	*x = *y;
	*y = tmp;
}

int	main(void) {
	int a = 5;
	int b = 3;
	std::cout << min(a, b) << std::endl;
}