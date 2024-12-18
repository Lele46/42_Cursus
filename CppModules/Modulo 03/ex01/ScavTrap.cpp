/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:49 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:37:49 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor called" << std::endl;
}

unsigned int ScavTrap::Get_Attack_damage()
{
    std::cout << "Getting ScavTrap Attack Damage" << std::endl;
    return this->Attack_damage;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
    std::cout << "SC4V-TP: Ok ok STOP! You won but I can't let you pass this gate because... I was fiddling with the controls and got something stuck in them, so, the door's not working right now..." << std::endl;
    std::cout << "SC4V-TP: But you can still go through the side door." << std::endl;
    std::cout << "SC4V-TP: Just give them the password, \"Arrr!\"" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->Hitpoints > 0)
    {
        if (this->Energy_points > 0)
        {
            this->Energy_points -= 1;
            std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
        }
    }
}