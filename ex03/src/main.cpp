/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:39:27 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/18 14:34:30 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int	main()
{
	srand(time(0));
	Bureaucrat	Boss("Big Boss", 1);
	AForm* rrf = NULL;
	try
	{
		Intern other_intern = Intern();
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->beSigned(Boss);
		rrf->execute(Boss);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		if (rrf)
			delete rrf;
		std::cerr << e.what();
	}
}
