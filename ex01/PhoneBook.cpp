/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:56:11 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/25 17:08:04 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook as been created" << std::endl;
	this->index = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook as been destroyed" << std::endl;
	return;
}

int	PhoneBook::addcontact(void)
{
	std::string	buffer;

	ask_for_input(&buffer, "Please enter new contact first name");
	while (this->contact_list[this->index].assign_first_name(buffer))
		ask_for_input(&buffer, "Please enter new contact first name");
	ask_for_input(&buffer, "Please enter new contact nickname");
	while (this->contact_list[this->index].assign_nickname(buffer))
		ask_for_input(&buffer, "Please enter new contact nickname");
	ask_for_input(&buffer, "Please enter new contact phone number");
	while (this->contact_list[this->index].assign_phone_number(buffer))
		ask_for_input(&buffer, "Please enter new contact phone number");
	ask_for_input(&buffer, "Please enter new contact darkest secret");
	while (this->contact_list[this->index].assign_darkest_secret(buffer))
		ask_for_input(&buffer, "Please enter new contact darkest secret");
	++this->index;
	if (this->index == 8)
		this->index = 0;
	std::cout << "New contact has been created" << std::endl;
	std::cout << "Index is now: " << this->index << std::endl;
	return (0);
}

void	PhoneBook::print_contact_list(void) const
{
	std::string	buffer;
	int	i;
	int	index_to_print;

	i = -1;
	while (++i < 8)
		print_contact_line(&this->contact_list[i]);
	std::cout << std::endl;
	ask_for_input(&buffer, "Please enter a contact index to output the contact info");
	if (buffer.empty())
		return;
	try
	{
		index_to_print = std::stoi(buffer, NULL, 10);
	}
	catch (const std::invalid_argument &ia)
	{
		std::cerr << "Invalid argument: " << ia.what() << std::endl;
		return;
	}
	catch (const std::out_of_range &oor)
	{
		std::cerr << "Out of Range error: " << oor.what() << '\n';
		return;
	}
	if (!(index_to_print < 0 || index_to_print > 7))
		print_single_contact_infos(&this->contact_list[index_to_print]);
	else
		std::cout << "No contact at this index, only numbers from 0 to 7 are allowed" << std::endl;
}
