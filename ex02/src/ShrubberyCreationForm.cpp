/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:02:32 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/18 14:37:42 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery", 145, 137), _target("Default")
{
	std::cout << "Shrubb Default Constructor Called\n";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "Shrubb Constructor Called for " << target << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm(copy)
{
	*this = copy;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubb Destructor Called\n";
	return ;
}

void	ShrubberyCreationForm::execute_action()const
{
	std::ofstream MyFile((this->_target + "_shrubbery").c_str());
	if (MyFile)
	{
		MyFile << "      ccee88oo\n";
		MyFile << "  C8O8O8Q8PoOb o8oo\n";
		MyFile << " dOB69QO8PdUOpugoO9bD\n";
		MyFile << "CgggbU8OU qOp qOdoUOdcb\n";
		MyFile << "    6OuU  /p u gcoUodpP\n";
		MyFile << "      \\\\\\//  /douUP\n";
		MyFile << "        \\\\\\////\n";
		MyFile << "         |||/\n";
		MyFile << "         |||\\\n";
		MyFile << "         ||||\n";
		MyFile << "   .....//|||\\\\....\n";
	}
	MyFile.close();
}
