/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:01:31 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/22 12:03:04 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	str_start(char *str, char c)
{
	int	start;

	start = -1;
	while(str && str[++start] == c)
		;
	return (start);
}

int	str_end(char *str, char c)
{
	int		end;

	end = strlen(str) - 1;
	while(str && end >= 0 && str[end] == c)
		--end;
	return (end);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		end;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (argv[++i])
		{
			j = str_start(argv[i], ' ');
			end = str_end(argv[i], ' ');
			if (end != -1)
			{
				while (j <= end && argv[i][j])
				{
					std::cout << (char)std::toupper(argv[i][j]);
					++j;
				}
				std::cout << " ";
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
