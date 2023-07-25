/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:14:43 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/25 17:20:07 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void	ask_for_input(std::string *buffer, const char *msg)
{
	std::cout << msg << std::endl;
	std::getline(std::cin, *buffer);
	clearerr(stdin);
	std::cin.clear();
}

void	print_column(std::string str, int last_column)
{
	if (str.size() < 10)
	{
		std::cout.width(10);
		std::cout << str;
	}
	else
	{
		std::cout.width(9);
		std::cout << str.substr(0, 9) << ".";
	}
	if (last_column == 0)
		std::cout << "|";
}

void	print_contact_line(const Contact *contact_to_print)
{
	print_column(contact_to_print->get_first_name(), 0);
	print_column(contact_to_print->get_nickname(), 0);
	print_column(contact_to_print->get_phone_number(), 0);
	print_column(contact_to_print->get_darkest_secret(), 1);
	std::cout << std::endl;
}

void	print_single_contact_infos(const Contact *contact_to_print)
{
	std::cout << "First name: " << contact_to_print->get_first_name() << std::endl;
	std::cout << "Nickname: " << contact_to_print->get_nickname() << std::endl;
	std::cout << "Phone number: " << contact_to_print->get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contact_to_print->get_darkest_secret() << std::endl << std::endl;
}
