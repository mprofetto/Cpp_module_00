/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:18:21 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/25 17:05:18 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	my_phonebook;
	std::string	buffer;
	std::string	add("ADD");
	std::string	search("SEARCH");
	std::string	exit("EXIT");

	while(1)
	{
		ask_for_input(&buffer, "Please enter a command");
		if (!buffer.empty())
		{
			if (buffer.compare(add) == 0)
				my_phonebook.addcontact();
			else if (buffer.compare(search) == 0)
				my_phonebook.print_contact_list();
			else if (buffer.compare(exit) == 0)
				return (0);
			else
				std::cout << "Invalid command" << std::endl;
		}
	}
	return (0);
}
