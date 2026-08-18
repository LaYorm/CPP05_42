/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:39:31 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/18 12:51:13 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called\n";
	return ;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat Name Constructor Called\n";
	return ;
}

Bureaucrat::Bureaucrat(int grade): _name("Default")
{
	std::cout << "Bureaucrat Grade Constructor Called\n";
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Name and Grade Constructor Called\n";
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor Called\n";
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor Called\n";
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &other)
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
	return (o);
}

std::string	Bureaucrat::getName()const
{
	return (this->_name);
}

int	Bureaucrat::getGrade()const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	return ;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because: " << e.what();
		return ;
	}
	std::cout << this->getName() << " sign " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName() << " because: " << e.what();
		return ;
	}
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (" Grade too High !\n");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (" Grade too Low !\n");
}
