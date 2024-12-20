/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:13:51 by espinell          #+#    #+#             */
/*   Updated: 2024/10/28 12:13:51 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

void Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}
void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}
void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}
void Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}
void Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}
std::string Contact::get_first_name()
{
    return this->first_name;
}
std::string Contact::get_last_name()
{
    return this->last_name;
}
std::string Contact::get_nickname()
{
    return this->nickname;
}
std::string Contact::get_phone_number()
{
    return this->phone_number;
}
std::string Contact::get_darkest_secret()
{
    return this->darkest_secret;
}

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}