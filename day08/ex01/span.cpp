#ifndef SPAN_H
# define SPAN_H
# include <vector>

class Span {
	private:
		unsigned int		_n;
		std::vector<int>	*_ints;

	public:
		unsigned int	getN() const;
		void			addNumber(int number);

};

#endif