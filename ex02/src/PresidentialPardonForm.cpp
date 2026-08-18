/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:45:12 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/18 14:37:52 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "Presidential Default Constructor Called\n";
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Destructor Called\n";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential Constructor Called for " << target << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):AForm(copy)
{
	*this = copy;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute_action()const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox !\n";
}
