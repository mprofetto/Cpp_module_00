/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:09:16 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/26 09:32:35 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	this->_first_name = std::string();
	this->_nickname = std::string();
	this->_phone_number = std::string();
	this->_darkest_secret = std::string();
	return;
}

Contact::~Contact(void)
{
	return;
}

int	Contact::assign_first_name(std::string	f_name)
{
	if (f_name.empty() || f_name.size() == 0)
	{
		std::cout << "First Name cannot be empty" << std::endl;
		return (1);
	}
	this->_first_name = f_name;
	return (0);
}

int	Contact::assign_nickname(std::string	nickname)
{
	if (nickname.empty() || nickname.size() == 0)
	{
		std::cout << "Nickname cannot be empty" << std::endl;
		return (1);
	}
	this->_nickname = nickname;
	return (0);
}

int	Contact::assign_phone_number(std::string	phone)
{
	std::string::size_type found;

	if ((phone.empty() || phone.size() == 0))
	{
		std::cout << "Phone Number cannot be empty" << std::endl;
		return (1);
	}
	found = phone.find_first_not_of("0123456789");
	if (found != std::string::npos)
	{
		std::cout << "Phone number needs to be numeric" << std::endl;
		return (1);
	}
	this->_phone_number = phone;
	return (0);
}

int	Contact::assign_darkest_secret(std::string	secret)
{
	if (secret.empty() || secret.size() == 0)
	{
		std::cout << "Darkest Secret cannot be empty" << std::endl;
		return (1);
	}
	this->_darkest_secret = secret;
	return (0);
}

std::string Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}
