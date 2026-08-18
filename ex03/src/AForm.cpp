/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:12:02 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/18 12:49:10 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(): _name("F_Default"), _gradeSign(150), _gradeExec(150), _signed(false)
{
	std::cout << "AForm Default Constructor Called\n";
	return ;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called\n";
	return ;
}

AForm::AForm(std::string name): _name(name), _gradeSign(150), _gradeExec(150), _signed(false)
{
	std::cout << "AForm Name Constructor Called\n";
	return ;
}

AForm::AForm(int gradeSign, int gradeExec): _name("F_Default"), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	std::cout << "AForm Grade Constructor Called\n";
	if (gradeExec > 150 || gradeSign > 150)
		throw GradeTooLowException();
	else if (gradeExec < 1 || gradeSign < 1)
		throw GradeTooHighException();
	return ;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	std::cout << "AForm Name and Grade Constructor Called\n";
	if (gradeExec > 150 || gradeSign > 150)
		throw GradeTooLowException();
	else if (gradeExec < 1 || gradeSign < 1)
		throw GradeTooHighException();
	return ;
}

AForm::AForm(const AForm &copy): _name(copy.getName()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec()), _signed(copy._signed)
{
	std::cout << "AForm Copy Constructor Called\n";
	return ;
}

AForm	&AForm::operator=(AForm const &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

std::string	AForm::getName()const
{
	return (this->_name);
}

int	AForm::getGradeSign()const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExec()const
{
	return (this->_gradeExec);
}

bool		AForm::getSigned()const
{
	return (this->_signed);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw GradeTooLowException();
	return ;
}

void	AForm::execute(const Bureaucrat &executor)const
{
	if (this->_signed  == false)
		throw NotSignedException();
	else if (this->_gradeExec < executor.getGrade())
		throw GradeTooLowException();
	execute_action();
}

std::ostream	&operator<<(std::ostream &o, AForm const &other)
{
	o << other.getName() << " || AForm gradeExec " << other.getGradeExec() << " || AForm gradeSign " << other.getGradeSign() << " || AForm signed " << other.getSigned() << ".\n";
	return (o);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High !\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low !\n");
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ("Form can't be executed because it's not signed yet !\n");
}
