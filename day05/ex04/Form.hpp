#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class Form	{
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

	struct ExecNotSignedException: public std::exception {
		const char * what () const throw () {
			return "Non-signed form executed!";
		}
	};

	private:
		const std::string		_target;
		const std::string		_name;
		bool					_signed;
		const int				_sign;
		const int				_exec;

	protected:
		GradeTooHighException	_h;
		GradeTooLowException	_l;
		ExecNotSignedException	_e;
		virtual ~Form();
		Form();
		Form(std::string name, std::string target, int sign = 150, int exec = 150, bool is_signed = false);
		Form(const Form & cpy);

	public:
		std::string		getName() const;
		std::string		getTarget() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		bool			getStatus() const;
		Form			&operator = (const Form &cpy);
		void			beSigned(const Bureaucrat & duty);
		virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream	&operator << (std::ostream &o, const Form &cpy);
#endif