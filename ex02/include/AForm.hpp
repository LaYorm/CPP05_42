/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:11:59 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/17 16:43:44 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		virtual void		execute_action()const = 0;
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name);
		AForm(int gradeSign, int gradeExec);
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &copy);
		AForm	&operator=(AForm const &other);

		std::string	getName()const;
		int			getGradeSign()const;
		int			getGradeExec()const;
		bool		getSigned()const;
		void		beSigned(const Bureaucrat &bureaucrat);
		void		execute(const Bureaucrat &executor)const;

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
		
		class NotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, AForm const &other);

#endif