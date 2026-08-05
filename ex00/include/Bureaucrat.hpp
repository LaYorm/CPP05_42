/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:39:33 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/05 14:44:07 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat	&operator=(Bureaucrat const &other);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);


		std::string	getName()const;
		int	getGrade()const;
		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &other);

#endif