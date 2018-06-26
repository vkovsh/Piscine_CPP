#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
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
		const std::string		_name;
		int						_rank;
		GradeTooHighException	_h;
		GradeTooLowException	_l;

	public:
		~Bureaucrat();
		void				executeForm(Form const & form);
		Bureaucrat(std::string name = "Archi", int grade = 150);
		Bureaucrat(const Bureaucrat & cpy);
		std::string			getName() const;
		int					getGrade() const;
		void				promote(unsigned int count = 1);
		void				demote(unsigned int count = 1);
		void				signForm(Form & form) const;
		Bureaucrat			&operator = (const Bureaucrat &cpy);
		Bureaucrat			&operator += (unsigned int count);
		Bureaucrat			&operator -= (unsigned int count);
		Bureaucrat			&operator++(void);  
   		Bureaucrat			operator++(int);
		Bureaucrat			&operator--(void);
		Bureaucrat			operator--(int);
};

std::ostream	&operator << (std::ostream &o, const Bureaucrat &cpy);

#endif