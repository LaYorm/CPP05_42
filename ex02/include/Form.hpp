/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:11:59 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/05 16:24:33 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
	public:
		Form();
		~Form();
		Form(std::string name);
		Form(int gradeSign, int gradeExec);
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form &copy);
		Form	&operator=(Form const &other);

		std::string	getName()const;
		int			getGradeSign()const;
		int			getGradeExec()const;
		bool		getSigned()const;
		void		beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};

std::ostream	&operator<<(std::ostream &o, Form const &other);

#endif