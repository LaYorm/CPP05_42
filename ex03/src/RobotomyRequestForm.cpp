/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:45:16 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/17 15:25:25 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "Robot Default Constructor Called\n";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robot Destructor Called\n";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robot Constructor Called for " << target << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):AForm(copy)
{
	*this = copy;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->_target = other._target;
	return (*this);
}

void	RobotomyRequestForm::execute_action()const
{
	int	random_n = rand();
	if (random_n % 2)
		std::cout << "Zzz Zzzzz Zzzz :" << this->_target << " has been robotomized successfully!!\n";
	else
		throw RobotisationFailed();
	return ;
}

const char *RobotomyRequestForm::RobotisationFailed::what() const throw()
{
	return ("Robotomy failed !\n");
}