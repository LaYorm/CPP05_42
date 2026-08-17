/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:00:54 by yorimek           #+#    #+#             */
/*   Updated: 2026/08/17 15:34:13 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALFORM_HPP
# define PRESIDENTIALFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);

		void execute_action()const;
};

#endif