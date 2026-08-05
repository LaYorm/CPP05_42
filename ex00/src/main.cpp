/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:39:27 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/05 15:53:28 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main()
{
	std::cout << "\033[1;31m\n----------Test for all Constructor and check valid arguments--------\n\033[0m";
	try
	{
		Bureaucrat NoName_NoGrade;
		std::cout << NoName_NoGrade;
		Bureaucrat Valid_name("Jean-Mi");
		std::cout << Valid_name;
		Bureaucrat Valid_grade(1);
		std::cout << Valid_grade;
		Bureaucrat Valide_both("Josianne", 140);
		std::cout << Valide_both;
		Bureaucrat copy(Valide_both);
		std::cout << copy;
		// Bureaucrat Invalid("Gaston", -5);
	}
	catch (std::exception &e)
	{	
		std::cerr << "\033[1;33mException caught: " << e.what() << "\033[0m";
	}
	try
	{
		Bureaucrat Invalid("Gaston", 159);
	}
	catch (std::exception &e)
	{	
		std::cerr << "\033[1;33mException caught: " << e.what() << "\n\033[0m";
	}
	std::cout << "\033[1;31m----------Test for increment and increment exception--------\n\033[0m";
	try 
	{
		Bureaucrat Valide_both("Josianne", 10);
		std::cout << Valide_both;
		for (size_t i = 0; i < 15; i++)
		{
			Valide_both.incrementGrade();
			std::cout << Valide_both;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[1;33mException caught: " << e.what() << "\n\033[0m";
	}
	std::cout << "\033[1;31m----------Test for decrement and decrement exception--------\n\033[0m";
	try 
	{
		Bureaucrat Valide_both("Josianne", 140);
		std::cout << Valide_both;
		for (size_t i = 0; i < 15; i++)
		{
			Valide_both.decrementGrade();
			std::cout << Valide_both;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[1;33mException caught: " << e.what() << "\n\033[0m";
	}
}
