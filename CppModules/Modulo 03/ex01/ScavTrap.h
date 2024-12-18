/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:53 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:37:53 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.h"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
    public:
        void guardGate();
        void attack(const std::string &target);
        unsigned int Get_Attack_damage();
        ScavTrap(std::string name);
        ~ScavTrap();
};