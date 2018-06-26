#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
#include <exception>

class Bureaucrat {
	private:
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
		void				promote(unsigned int count = 1);
		void				demote(unsigned int count = 1);
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