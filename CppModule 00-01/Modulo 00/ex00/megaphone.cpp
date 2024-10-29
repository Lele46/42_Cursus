/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:13:40 by espinell          #+#    #+#             */
/*   Updated: 2024/10/28 12:13:40 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int j = 1; j < argc; j++)
	{
		int i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
				std::cout << (char)toupper(argv[j][i]);
			else
				std::cout << argv[j][i];
			i++;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
