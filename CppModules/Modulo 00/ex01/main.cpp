/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:13:59 by espinell          #+#    #+#             */
/*   Updated: 2024/10/28 12:13:59 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>

int main()
{
    std::string command;
    PhoneBook phonebook;
    while (1)
    {
        std::cout << "Enter ADD, SEARCH or EXIT: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cin.clear();
            break ;
        }
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            return (0);
        if (std::cin.eof())
        {
            std::cin.clear();
            break ;
        }
        std::cin.clear();
    }
    return (0);
}