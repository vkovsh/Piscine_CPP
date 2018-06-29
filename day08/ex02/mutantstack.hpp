#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <list>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack
{
	public:
		typedef T										container_type;
		typedef	typename std::list<T>::size_type		size_type;
		typedef typename std::list<T>::iterator			iterator;
		typedef typename std::list<T>::const_iterator	const_iterator;

	private:
		std::list<T>			_data;
		size_type				_count;

	public:
		MutantStack<T>(void): _data(), _count(0) {}

		~MutantStack<T>(void) {}
		
		MutantStack<T>(MutantStack<T> const &src) {
			*this = src;
		}

		MutantStack<T>	&operator = (MutantStack<T> const &rhs)
		{
			_data = rhs._data;
			_count = rhs._count;
			return *this;
		}

		bool					empty(void) const { return _count == 0; }

		size_type				size(void) const { return _count; }

		T const					&top(void) const { return _data.front(); }

		T 						&top(void) { return _data.front(); }

		void					push(T const &value) {
			if (_count >= 0) {
				_data.push_front(value);
				_count++;
			}
		}

		void					pop(void) {
			if (_count > 0) {
				_data.pop_front();
				_count--;
			}
		}

		operator std::stack<T>(void) {
			std::stack<T> stack;
			typename std::list<T>::reverse_iterator	rb = _data.rbegin();
			typename std::list<T>::reverse_iterator	re = _data.rend();
			while (rb != re) {
				stack.push(*rb);
				++rb;
			}
			return stack;
		}

		iterator				begin(void) { return _data.begin();	}

		const_iterator			begin(void) const {	return _data.begin(); }

		iterator				end(void) { return _data.end();	}

		const_iterator			end(void) const { return _data.end(); }
};

#endif