#ifndef WINDOW_HPP
# define WINDOW_HPP
# include <iostream>
# include "ft_retro.h"

class	Window	{
	protected:
		int		_rows;
		int		_columns;
		WINDOW	*_window;
	
	public:
		int		getRows(void);
		int		getColumns(void);
		WINDOW	*getWindow(void);

		void	setColumns(int cols);
		void	setRows(int rows);
		void	setWindow(WINDOW *window);

		bool	PutChar(chtype c, int y, int x);
		bool	PutStr(std::string str, int y, int x);
		bool	DrawBox(chtype v, chtype h);
		int		GetChar();
		void	Refresh();
		void	Clear();
		void	Resize(int y, int x);

		Window(int row = -1, int col = -1, int y = 0, int x = 0);
		Window(const Window & cpy);
		~Window();

		Window	&operator = (const Window &cpy);
};

#endif