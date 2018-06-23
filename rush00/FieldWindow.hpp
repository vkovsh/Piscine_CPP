#ifndef FIELD_WINDOW_HPP
# define FIELD_WINDOW_HPP
#include "Window.hpp"

class	FieldWindow: public Window	{
	private:
		const static std::string cell[3];

		int		_width;
		int		_height;
		bool	drawCell(int y, int x);

	public:
		bool	drawField(void);
		FieldWindow(int row = -1, int col = -1, int y = 0, int x = 0);
		FieldWindow(const Window & cpy);
		int		getFieldWidth(void);
		int		getFieldHeight(void);
		~FieldWindow(void);

		FieldWindow	&operator = (const FieldWindow &cpy);
};
#endif