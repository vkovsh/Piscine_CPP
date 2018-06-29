#include "span.hpp"

int	main(void) {
	Span sp = Span(10000);

	for (unsigned int i = 0; i < sp.getN(); i++) {
		sp.addNumber(rand() % 100000);
	}
	for (unsigned int i = 0; i < sp.getN(); i++) {
		std::cout << sp.at(i) << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}