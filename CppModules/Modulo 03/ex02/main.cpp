/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:38:17 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:38:17 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "FragTrap.h"

int main()
{
    std::string claptrap_name;
    std::cout << "Enter a name for your ClapTrap and fight angainst youself to regain control" << std::endl;
    std::cin >> claptrap_name;
    ClapTrap claptrap(claptrap_name);
    FragTrap fragtrap("5H4D0W-TP");
    claptrap.attack("5H4D0W-TP");
    fragtrap.takeDamage(claptrap.Get_Attack_damage());
    fragtrap.attack(claptrap_name);
    claptrap.takeDamage(fragtrap.Get_Attack_damage());
    claptrap.beRepaired(10);
    claptrap.attack("5H4D0W-TP");
    fragtrap.takeDamage(claptrap.Get_Attack_damage());
    claptrap.attack("5H4D0W-TP");
    fragtrap.takeDamage(claptrap.Get_Attack_damage());
    fragtrap.attack(claptrap_name);
    claptrap.takeDamage(fragtrap.Get_Attack_damage());
    fragtrap.attack(claptrap_name);
    claptrap.takeDamage(fragtrap.Get_Attack_damage());
    claptrap.attack("5H4D0W-TP");
    fragtrap.takeDamage(claptrap.Get_Attack_damage());
    fragtrap.highFivesGuys();
    std::cout << claptrap_name <<": ALL those guys die?" << std::endl;
    std::cout << "5H4D0W-TP: I promise... they ALL will die." << std::endl;
    return 0;
}