/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:31 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:37:31 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap " << this->name << "Constructor called" << std::endl;
    this->name = name;
    this->Hitpoints = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
    this->set_Max_Hitpoints();
    this->set_Max_Energy_points();
}

unsigned int ClapTrap::Get_Attack_damage()
{
    std::cout << "Getting Attack Damage" << std::endl;
    return this->Attack_damage;
}

void ClapTrap::set_Max_Hitpoints()
{
    std::cout << "Setting Max Hitpoints" << std::endl;
    this->Max_Hitpoints = this->Hitpoints;
}

void ClapTrap::set_Max_Energy_points()
{
    std::cout << "Setting Max Energy points" << std::endl;
    this->Max_Energy_points = this->Energy_points;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->Hitpoints > 0)
    {
        if (this->Energy_points > 0)
        {
            this->Energy_points -= 1;
            std::cout << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
        }
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->Hitpoints > 0)
    {
        std::cout << this->name << " takes " << amount << " damage" << std::endl;
        if (amount >= this->Hitpoints)
        {
            this->Hitpoints = 0;
        }
        else
            this->Hitpoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Hitpoints > 0 && this->Hitpoints != this->Max_Hitpoints)
    {
        if (this->Energy_points > 0)
        {
            this->Energy_points -= 1;
            std::cout << this->name << " is being repaired for " << amount << " points!" << std::endl;
            if (this->Hitpoints + amount > this->Max_Hitpoints)
            {
                this->Hitpoints = this->Max_Hitpoints;
            }
            else
            {
                this->Hitpoints += amount;
            }
        }
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}