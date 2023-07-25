/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:07:23 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/25 16:17:19 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact(void);
		~Contact(void);
		std::string	get_first_name() const;
		std::string	get_nickname() const;
		std::string	get_phone_number() const;
		std::string	get_darkest_secret() const;
		int	assign_first_name(std::string f_name);
		int	assign_nickname(std::string nickname);
		int	assign_phone_number(std::string phone);
		int	assign_darkest_secret(std::string secret);
};

#endif
