/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:58:30 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/18 12:53:30 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor Called\n";
	return ;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called\n";
	return ;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern Copy Constructor Called\n";
	*this = copy;
}

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called\n";
	if (this != &other)
	{
		
	}
	return (*this);
}

AForm	*Intern::makeForm(std::string form_name, std::string target_name)
{
	int	i = 0;

	std::string	tab[3] = {"presidential pardonForm", "robotomy request", "shrubbery creation"};
	while (i < 3 && tab[i] != form_name)
		i++;
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << form_name << " !\n";
		return (new PresidentialPardonForm(target_name));
		break;
	case 1:
		std::cout << "Intern creates " << form_name << " !\n";
		return (new RobotomyRequestForm(target_name));
		break;
	case 2:
		std::cout << "Intern creates " << form_name << " !\n";
		return (new ShrubberyCreationForm(target_name));
		break;
	default:
		throw FormNotFoundException();
		return (NULL);
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("The name doesn't match any Form. Please try with another one !\n");
}
