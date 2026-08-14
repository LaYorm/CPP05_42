/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:39:27 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/05 16:35:07 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main()
{
	std::cout << "\033[1;31m\n----------Test for all Constructor and check valid arguments--------\n\033[0m";
	try
	{
		Form NoNothing;
		std::cout << NoNothing;
		Form Valid_name("Jean-Mi");
		std::cout << Valid_name;
		Form Valid_grade(1, 1);
		std::cout << Valid_grade;
		Form Valide_both("Josianne", 149, 15);
		std::cout << Valide_both;
		Form Invalid("Gaston", -5, 145);
	}
	catch (std::exception &e)
	{	
		std::cerr << "\033[1;33mException caught: " << e.what() << "\033[0m";
	}
	try
	{
		Form Invalid("Gaston", 159, 10);
	}
	catch (std::exception &e)
	{	
		std::cerr << "\033[1;33mException caught: " << e.what() << "\n\033[0m";
	}
	std::cout << "\033[1;31m----------Test for signing and executing--------\n\033[0m";
	try 
	{
		Bureaucrat Valide_sign("Josianne", 10);
		Form permis("permis", 50, 50);
		std::cout << Valide_sign;
		std::cout << permis;
		Valide_sign.signForm(permis);
		std::cout << permis;
		Bureaucrat Invalid_sign("Marcel", 145);
		Form permis_2("permis_2", 50, 50);
		std::cout << Invalid_sign;
		std::cout << permis_2;
		Invalid_sign.signForm(permis_2);
		std::cout << permis_2;
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[1;33mException caught: " << e.what() << "\n\033[0m";
	}
}
