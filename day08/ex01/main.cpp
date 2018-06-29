#include "span.hpp"

int	main(void) {
	Span sp = Span(10000);
	std::vector<int> v(10000);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		*it = rand() % 255;
	}
	/*for (unsigned int i = 0; i < sp.getN(); i++) {
		sp.addNumber(rand() % 100000);
	}
	for (unsigned int i = 0; i < sp.getN(); i++) {
		std::cout << sp.at(i) << std::endl;
	}*/
	sp.addRange(v);
	for (unsigned int i = 0; i < sp.getC(); i++) {
		std::cout << sp.at(i) << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}