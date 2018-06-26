#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
	struct GradeTooHighException: public std::exception {
		const char * what () const throw () {
			return "Grade too high!";
		}
	};
	struct GradeTooLowException: public std::exception {
		const char * what () const throw () {
			return "Grade too low!";
		}
	};

	private:
		const std::string		_name;
		int						_rank;
		GradeTooHighException	_h;
		GradeTooLowException	_l;

	public:
		~Bureaucrat();
		Bureaucrat(std::string name = "Archi", int grade = 150);
		Bureaucrat(const Bureaucrat & cpy);
		std::string			getName() const;
		int					getGrade() const;
		void				promote();
		void				demote();
		void				signForm(Form & form) const;
		Bureaucrat			&operator = (const Bureaucrat &cpy);
};
std::ostream	&operator << (std::ostream &o, const Bureaucrat &cpy);

#endif