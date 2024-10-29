/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:14:10 by espinell          #+#    #+#             */
/*   Updated: 2024/10/28 12:14:10 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
}

std::string resize(std::string str)
{
    if (str.length() > 10)
    {
        str.erase(str.begin() + 9, str.end());
        str.append(".");
    }
    return str;
}

void PhoneBook::add_contact()
{
    if (std::cin.eof())
    {
        std::cin.clear();
        return ;
    }
    std::string tmp;
    Contact *contact = new Contact();
    std::cout << "Enter first name: ";
    std::getline(std::cin, tmp);
    if (std::cin.eof()) 
    {
        std::cout << std::endl;
        return;
    }
    if (tmp.empty())
    {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        return ;
    }
    contact->set_first_name(tmp);
    std::cout << "Enter last name: ";
    std::getline(std::cin, tmp);
    if (std::cin.eof())
    {
        std::cout << std::endl;
        return;
    }
    if (tmp.empty())
    {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        return ;
    }
    contact->set_last_name(tmp);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, tmp);
    if (std::cin.eof())
    {
        std::cout << std::endl;
        return;
    }
    if (tmp.empty())
    {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        return ;
    }
    contact->set_nickname(tmp);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, tmp);
    if (std::cin.eof())
    {
        std::cout << std::endl;
        return;
    }
    if (tmp.empty())
    {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        return ;
    }
    contact->set_phone_number(tmp);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, tmp);
    if (std::cin.eof())
    {
        std::cout << std::endl;
        return;
    }
    if (tmp.empty())
    {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        return ;
    }
    contact->set_darkest_secret(tmp);
    if (this->contacts.size() == 8)
        this->contacts.erase(this->contacts.begin());
    this->contacts.push_back(*contact);
}

void PhoneBook::search_contact()
{
    if (std::cin.eof())
    {
        std::cin.clear();
        return ;
    }
    if (this->contacts.size() == 0)
    {
        std::cout << "No contacts available" << std::endl;
        return;
    }
    for (int i = 0; i < (int)this->contacts.size(); i++)
    {
        std::cout << "| " << "Index: " << i << " | "
        << "First name: " << std::setw(10) << resize(this->contacts[i].get_first_name()) << " | "
        << "Last name: " << std::setw(10) << resize(this->contacts[i].get_last_name()) << " | "
        << "Nickname: " << std::setw(10) << resize(this->contacts[i].get_nickname()) << " |" 
        << std::endl;
    }
    unsigned int i;
    std::cout << "Enter contact index: ";
    std::cin >> i;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        return ;
    }
    if (std::cin.fail() || std::cin.peek() != '\n')
        std::cout << "Invalid index" << std::endl;
    else
    { 
        if (i < (unsigned int)this->contacts.size())
        {
            std::cout << "Index: " << i << std::endl;
            std::cout << "First name: " << this->contacts[i].get_first_name() << std::endl;
            std::cout << "Last name: " << this->contacts[i].get_last_name() << std::endl;
            std::cout << "Nickname: " << this->contacts[i].get_nickname() << std::endl;
            std::cout << "Phone number: " << this->contacts[i].get_phone_number() << std::endl;
            std::cout << "Darkest secret: " << this->contacts[i].get_darkest_secret() << std::endl;
        }
        else
            std::cout << "Invalid index" << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}
