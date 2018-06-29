#include "span.hpp"

Span::~Span() {
	delete _ints;
}

Span::Span(unsigned int n): _n(n), _count(0), _shortestSpan(0), _longestSpan(0) {
	if (n == 0) {
		_ints = NULL;
	}
	else {
		_ints = new std::vector<int>(n);
	}
}

unsigned int	Span::getN() const {
	return _n;
}

unsigned int	Span::getC() const {
	return _count;
}

unsigned int	Span::shortestSpan() const {
	if (_count <= 1) {
		throw std::range_error("There is no span!");
	}
	return _shortestSpan;
}

unsigned int	Span::longestSpan() const {
	if (_count <= 1) {
		throw std::range_error("There is no span!");
	}
	return _longestSpan;
}

int				Span::at(unsigned int index) {
	if (index >= _count) {
		throw std::range_error("Too big index!");
	}
	return _ints->at(index);
}

void			Span::addNumber(int number) {
	if (_count == _n) {
		throw std::range_error("Stack overflow!");
	}
	else {
		_count++;
		_ints->insert(_ints->begin(), number);
		std::sort(_ints->begin(), _ints->begin() + _count);
		if (_count >= 2) {
			_longestSpan = _ints->at(_count - 1) - _ints->at(0);
			unsigned int pos = std::find(_ints->begin(), _ints->begin() + _count, number) - _ints->begin();
			if (_count == 2) {
				_shortestSpan = _longestSpan;
			}
			else if (_shortestSpan > 0) {
				if (pos > 0) {
					unsigned int comp = static_cast<unsigned int>(_ints->at(pos) - _ints->at(pos - 1));
					if (comp < _shortestSpan) {
						_shortestSpan = comp;
					}
				}
				if (pos < _count - 1) {
					unsigned int comp = static_cast<unsigned int>(_ints->at(pos + 1) - _ints->at(pos));
					if (comp < _shortestSpan) {
						_shortestSpan = comp;
					}
				}
			}
		}
	}
}

Span	&Span::operator = (const Span & cpy) {
	_n = cpy._n;
	_count = cpy._count;
	if (_ints != NULL) {
		delete _ints;
	}
	_shortestSpan = cpy._shortestSpan;
	_longestSpan = cpy._longestSpan;
	_ints = new std::vector<int>(_n);
	std::copy(cpy._ints, cpy._ints + _count, _ints);
	return *this;
}

Span::Span(const Span & rhs) {
	*this = rhs;
}

std::ostream	&operator << (std::ostream &o, const Span &cpy) {
	std::cout << "Span of size " << cpy.getN() << "filled by " << cpy.getC() << std::endl; 
	return o;
}