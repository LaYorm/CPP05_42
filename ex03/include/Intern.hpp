/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:58:34 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/18 12:27:18 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &other);
	
		AForm	*makeForm(std::string form_name, std::string target_name);

		class FormNotFoundException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif