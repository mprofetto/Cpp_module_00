/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:45:30 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/25 16:48:41 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact_list[8];
		int		index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		addcontact(void);
		void	print_contact_list(void) const;
};

void	ask_for_input(std::string *buffer, const char *msg);
void	print_contact_line(const Contact *contact_to_print);
void	print_single_contact_infos(const Contact *contact_to_print);

#endif
