/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:39:27 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/17 16:56:33 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main()
{
	srand(time(0));
	std::cout << "\n--- TEST 1: Le Boss ---" << std::endl;
	Bureaucrat Boss("Big Boss", 1);
	AForm	*MyForm[3];
	MyForm[0] = new ShrubberyCreationForm("Boss_S");
	MyForm[1] = new PresidentialPardonForm("Boss_P");
	MyForm[2] = new RobotomyRequestForm("Boss_R");
	for (size_t i = 0; i < 3; i++)
	{
		Boss.signForm(*MyForm[i]);
		Boss.executeForm(*MyForm[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		delete MyForm[i];
	}
	std::cout << "\n--- TEST 2: Intermediaire ---" << std::endl;
	Bureaucrat Middle("Middle", 50);
	MyForm[0] = new ShrubberyCreationForm("Mid_S");
	MyForm[1] = new PresidentialPardonForm("Mid_P");
	MyForm[2] = new RobotomyRequestForm("Mid_R");
	for (size_t i = 0; i < 3; i++)
	{
		Middle.signForm(*MyForm[i]);
		Middle.executeForm(*MyForm[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		delete MyForm[i];
	}
	std::cout << "\n--- TEST 3: Noob ---" << std::endl;
	Bureaucrat Stagiaire("Stagiaire", 150);
	MyForm[0] = new ShrubberyCreationForm("Stag_S");
	MyForm[1] = new PresidentialPardonForm("Stag_P");
	MyForm[2] = new RobotomyRequestForm("Stag_R");
	for (size_t i = 0; i < 3; i++)
	{
		Stagiaire.signForm(*MyForm[i]);
		Stagiaire.executeForm(*MyForm[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		delete MyForm[i];
	}
	std::cout << "\n--- TEST 4: Unsigned ---" << std::endl;
	PresidentialPardonForm	Pres_unsigned("Test_Unsigned");
	Boss.executeForm(Pres_unsigned);
}
