/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:12:02 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/05 16:27:21 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(): _name("F_Default"), _gradeSign(150), _gradeExec(150), _signed(false)
{
	std::cout << "Form Default Constructor Called\n";
	return ;
}

Form::~Form()
{
	std::cout << "Form Destructor Called\n";
	return ;
}

Form::Form(std::string name): _name(name), _gradeSign(150), _gradeExec(150), _signed(false)
{
	std::cout << "Form Name Constructor Called\n";
	return ;
}

Form::Form(int gradeSign, int gradeExec): _name("F_Default"), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	std::cout << "Form Grade Constructor Called\n";
	if (gradeExec > 150 || gradeSign > 150)
		throw GradeTooLowException();
	else if (gradeExec < 1 || gradeSign < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	std::cout << "Form Name and Grade Constructor Called\n";
	if (gradeExec > 150 || gradeSign > 150)
		throw GradeTooLowException();
	else if (gradeExec < 1 || gradeSign < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form(const Form &copy): _name(copy.getName()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec()), _signed(copy._signed)
{
	std::cout << "Form Copy Constructor Called\n";
	return ;
}

Form	&Form::operator=(Form const &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

std::string	Form::getName()const
{
	return (this->_name);
}

int	Form::getGradeSign()const
{
	return (this->_gradeSign);
}

int	Form::getGradeExec()const
{
	return (this->_gradeExec);
}

bool		Form::getSigned()const
{
	return (this->_signed);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw GradeTooLowException();
	return ;
}

std::ostream	&operator<<(std::ostream &o, Form const &other)
{
	o << other.getName() << " || Form gradeExec " << other.getGradeExec() << " || Form gradeSign " << other.getGradeSign() << " || Form signed " << other.getSigned() << ".\n";
	return (o);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High !\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low !\n");
}
