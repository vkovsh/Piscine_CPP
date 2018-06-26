#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form	{
	class GradeTooHighException: public std::exception {
		const char * what () const throw () {
				return "Grade too high!";
		}
	};

	class GradeTooLowException: public std::exception {
		const char * what () const throw () {
			return "Grade too low!";
		}
	};

	private:
		const std::string		_name;
		bool					_signed;
		const int				_grade;
		GradeTooHighException	_h;
		GradeTooLowException	_l;

	public:
		~Form();
		Form();
		Form(std::string name, int grade = 150, bool is_signed = false);
		Form(const Form & cpy);
		std::string	getName() const;
		int			getGrade() const;
		bool		getStatus() const;
		Form		&operator = (const Form &cpy);
		void		beSigned(const Bureaucrat & duty);		
};

std::ostream	&operator << (std::ostream &o, const Form &cpy);
#endif