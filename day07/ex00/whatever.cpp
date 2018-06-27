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
void	swap(T* x, T* y) {
	T tmp = *x;
	*x = *y;
	*y = tmp;
}

int	main(void) {
	std::cout << max(3, 5) << std::endl;
	std::cout << min(5, 3) << std::endl;
	std::cout << max(42.0f, 42.1f) << std::endl;
	std::cout << min(42.0f, 42.1f) << std::endl;
	std::cout << max(42.0, 42.1) << std::endl;
	std::cout << min(42.0, 42.1) << std::endl;
	std::cout << max('a', 'z') << std::endl;
	std::cout << min('a', 'z') << std::endl;
	std::cout << max('*', static_cast<char>(42)) << std::endl;
	char a = 'a';
	char b = 'b';
	swap(&a, &b);
	std::cout << a << " " << b << std::endl;
	return 0;
}