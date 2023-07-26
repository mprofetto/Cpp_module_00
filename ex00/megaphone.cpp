/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:01:31 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/26 09:31:05 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	std::string	buffer;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (argv[++i])
		{
			buffer = std::string(argv[i]);
			buffer = buffer.substr(buffer.find_first_not_of(" "),
				buffer.find_last_not_of(" ") - buffer.find_first_not_of(" ") + 1);
			j = 0;
			while (buffer[j])
				std::cout << (char)std::toupper(buffer[j++]);
			if (argv[i + 1])
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
