/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:14:13 by espinell          #+#    #+#             */
/*   Updated: 2024/10/28 12:14:13 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>

class PhoneBook
{
    private:
        std::vector<Contact> contacts;
    public:
        void add_contact();
        void search_contact();
        PhoneBook();
};