#ifndef SPAN_H
# define SPAN_H
# include <vector>
# include <iostream>
# include <algorithm>

class Span {
	private:
		unsigned int		_n;
		unsigned int		_count;
		std::vector<int>	*_ints;
		unsigned int		_shortestSpan;
		unsigned int		_longestSpan;

	public:
		~Span();
		Span(unsigned int n = 0);
		unsigned int	getN() const;
		unsigned int	getC() const;
		void			addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		int				at(unsigned int index);
};

#endif