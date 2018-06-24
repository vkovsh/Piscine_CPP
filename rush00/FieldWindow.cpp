#include "FieldWindow.hpp"

const std::string FieldWindow::cell[]= {"____", "|  |", " - "};

FieldWindow::FieldWindow(int row, int col, int y, int x): Window(row, col, y, x) {
	_width = 26;
	_height = 12;
}

int		FieldWindow::getFieldWidth(void) {
	return (_width);
}

int		FieldWindow::getFieldHeight(void) {
	return (_height);
}

FieldWindow::~FieldWindow(void) {}

FieldWindow	&FieldWindow::operator = (const FieldWindow &cpy) {
	if (this == &cpy) {
		return (*this);
	}
	_rows = cpy._rows;
	_columns = cpy._columns;
	_window = cpy._window;
	_width = cpy._width;
	_height = cpy._height;
	return (*this);
}

bool	FieldWindow::drawCell(int y, int x) {
	bool success = true;
	int y1 = y * 2 + 1;
	int x1 = x * 2 + 1;
	int y2 = y1 + 2;
    int x2 = x1 + 2;
    mvwhline(_window, y1, x1, 0, x2 - x1);
    mvwhline(_window, y2, x1, 0, x2 - x1);
    mvwvline(_window, y1, x1, 0, y2 - y1);
    mvwvline(_window, y1, x2, 0, y2 - y1);
    mvwaddch(_window, y1, x1, ACS_ULCORNER);
    mvwaddch(_window, y2, x1, ACS_LLCORNER);
    mvwaddch(_window, y1, x2, ACS_URCORNER);
    mvwaddch(_window, y2, x2, ACS_LRCORNER);
	return (success);
}

bool	FieldWindow::drawField(void) {
	std::string name("Retro game");
	for (int i = 0; i < (int)name.size(); ++i) {
		PutChar(name[i] | A_BOLD | A_UNDERLINE, 1, i + 25);
	}
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
    wattron(_window, COLOR_PAIR(2));
	wattron(_window, A_BOLD);
	for (int i = 1; i <= _height; ++i) {
		for (int j = 1; j <= _width; ++j) {
			drawCell(i, j);
		}
	}
	wattroff(_window, A_BOLD);
	wattroff(_window, COLOR_PAIR(2));
	return (true);
}