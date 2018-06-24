#include "Window.hpp"

int		Window::getRows(void) {
	return _rows;
}

int		Window::getColumns(void) {
	return _columns;
}

WINDOW	*Window::getWindow(void) {
	return _window;
}

void	Window::setColumns(int cols) {
	_columns = cols;
}

void	Window::setRows(int rows) {
	_rows = rows;
}

void	Window::setWindow(WINDOW *window) {
	_window = window;
}

bool	Window::PutChar(chtype c, int y, int x) {
	bool success = true;
	if (y >= 0 && x >= 0 && y < _rows && x < _columns) {
		wmove(_window, y, x);
		waddch(_window, c);
	}
	else
		success = false;
	return success;
}

bool	Window::PutStr(std::string str, int y, int x) {
	bool success = true;
	int length = (int)str.length();
	if (y < 0 || y >= _rows) {
		success = false;
	}
	else if (x < 0 || x + length >= _columns) {
		success = false;
	}
	else {
		mvwprintw(_window, y, x, str.c_str());
	}
	return success;
}

Window::Window(int rows, int cols, int y, int x){
	_window = newwin(rows, cols , 1, 1);
	getmaxyx(_window, _rows, _columns);
	mvwin(_window, y, x);
}

Window::~Window(void) {}

int		Window::GetChar(void) {
	return wgetch(_window);
}

Window::Window(const Window & cpy) {
	if (this != &cpy)
		*this = cpy;
}

Window	&Window::operator = (const Window &cpy) {
	if (this == &cpy) {
		return *this;
	}
	_rows = cpy._rows;
	_columns = cpy._columns;
	_window = cpy._window;
	return *this;
}

bool	Window::DrawBox(chtype v, chtype h) {
	init_pair(1, COLOR_YELLOW, COLOR_MAGENTA);
    wattron(_window, COLOR_PAIR(1));
	box(_window, v, h);
	wattroff(_window, COLOR_PAIR(1));
	return true;
}

void	Window::Refresh() {
	wrefresh(_window);
}

void	Window::Clear() {
	wclear(_window);
}

void	Window::Resize(int y, int x) {
	_rows = y;
	_columns = x;
}