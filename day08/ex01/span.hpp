#ifndef SPAN_H
# define SPAN_H
# include <vector>
# include <iostream>
# include <algorithm>
# include <iterator>

class Span {
	private:
		unsigned int		_n;
		unsigned int		_count;
		std::vector<int>	*_ints;
		unsigned int		_shortestSpan;
		unsigned int		_longestSpan;

	public:
		Span	&operator = (const Span &cpy);

		~Span();
		Span(unsigned int n = 0);
		Span(const Span & rhs);
		unsigned int	getN() const;
		unsigned int	getC() const;
		void			addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		int				at(unsigned int index);

		template <typename T>
		void			addRange(T & c) {
			typename T::iterator it;
			for (it = c.begin(); it != c.end(); ++it) {
				if (_count == _n) {
					throw std::range_error("Stack overflow!");
				}
				else {
					_count++;
					_ints->insert(_ints->begin(), *it);
					std::sort(_ints->begin(), _ints->begin() + _count);
					if (_count >= 2) {
						_longestSpan = _ints->at(_count - 1) - _ints->at(0);
						unsigned int pos = std::find(_ints->begin(), _ints->begin() + _count, *it) - _ints->begin();
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
		};
};

std::ostream	&operator << (std::ostream &o, const Span &cpy);

#endif