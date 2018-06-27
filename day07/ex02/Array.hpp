#ifndef ARRAY_HPP
# define ARRAY_HPP
//# include <

template <typename T>
class	Array<T> {
	private:
		T				*_arrayPtr;
		unsigned int	_size;

	public:
		unsigned int	getSize() {
			return _size;
		};

		Array<T>() {
			_size = 0;
			_arrayPtr = NULL;
		};

		Array<T>(unsigned int n) {
			_size = n; 
			_arrayPtr = new T[_size];
		};

		~Array<T>() {
			delete [] _arrayPtr;
		};

		Array<T>(const Array<T> & cpy) {
			if (this != &cpy) {
				delete [] _arrayPtr;
				_arrayPtr = new T[cpy.getSize()];
				_size = cpy.getSize();
				for (unsigned int i = 0; i < getSize(); ++i){
					_arrayPtr[i] = cpy[i];
				}
			}

		};

		Array<T>	&operator = (const Array<T> & cpy) {
			*this = cpy;
			return *this;
		}

		T			&operator [] (const unsigned int index) {
			return _arrayPtr[index];
		};
};

#endif