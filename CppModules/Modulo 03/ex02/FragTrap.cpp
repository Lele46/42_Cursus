/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:38:07 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:38:07 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Constructor called" << std::endl;
    this->Hitpoints = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
}

unsigned int FragTrap::Get_Attack_damage()
{
    std::cout << "Getting FragTrap Attack Damage" << std::endl;
    return this->Attack_damage;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
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

void FragTrap::highFivesGuys(void)
{
    std::cout << "5H4D0W-TP: We shall destroy our enemies! Your false friends who mock you at every turn and plot your destruction." << std::endl;
    std::cout << "5H4D0W-TP: they all shall die. A simple high-five will seal the deal!" << std::endl;
}