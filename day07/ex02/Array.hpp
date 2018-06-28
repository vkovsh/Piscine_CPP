#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>
#include <iostream>

template< typename T = int>
class Array
{
	public:
		Array<T>(): _array(NULL), _size(0) {};
		
		Array<T>(unsigned int n): _size(n) {
			_array = (_size) ? new T[n] : 0; 
		};
		
		Array<T>(Array<T> const & src): _array(NULL), _size(0) {
			*this = src;
		};
		
		~Array<T>() {};
		
		unsigned int	size() const {
			return ( this->_size );
		};
		
		Array<T> &	operator=( Array<T> const & rhs ) {
			if ( this != &rhs ) {
				if (_array) {
					delete [] _array;
				}
				this->_size = rhs._size;
				this->_array = new T[rhs._size];
				std::copy(rhs._array, rhs._array + rhs.size(), _array);
			}
			return *this;
		};
		
		T &	operator[]( unsigned int num ) {
			if (num < this->_size)
				return (this->_array[num]);
			else
				throw std::range_error("class Array: Out of bound!");
		};
	
	private:
		T*				_array;
		unsigned int	_size;
};
#endif