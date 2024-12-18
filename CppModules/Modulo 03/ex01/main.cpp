/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:39 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:37:39 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

int main()
{
    std::string claptrap_name;
    std::cout << "Enter a name for your ClapTrap and begin an adventure on Elpis, the Pandora's moon!" << std::endl;
    std::cin >> claptrap_name;
    ClapTrap claptrap(claptrap_name);
    ScavTrap scavtrap("SC4V-TP");
    std::cout << claptrap_name << " talk to SC4V-TP to open the gate and find RedBelly." << std::endl;
    std::cout << "SC4V-TP: You can't pass this gate, You're not a real SCAV." << std::endl;
    std::cout << "SC4V-TP: Prove me wrong!" << std::endl;
    claptrap.attack("SC4V-TP");
    scavtrap.takeDamage(claptrap.Get_Attack_damage());
    std::cout << "SC4V-TP: This's not what I meant! But you chose WAR!!" << std::endl;
    scavtrap.attack(claptrap_name);
    claptrap.takeDamage(scavtrap.Get_Attack_damage());
    scavtrap.attack(claptrap_name);
    claptrap.takeDamage(scavtrap.Get_Attack_damage());
    scavtrap.attack(claptrap_name);
    claptrap.takeDamage(scavtrap.Get_Attack_damage());
    claptrap.beRepaired(1);
    claptrap.attack("SC4V-TP");
    scavtrap.takeDamage(claptrap.Get_Attack_damage());
    claptrap.attack("SC4V-TP");
    scavtrap.takeDamage(claptrap.Get_Attack_damage());
    claptrap.attack("SC4V-TP");
    scavtrap.takeDamage(claptrap.Get_Attack_damage());
    scavtrap.attack(claptrap_name);
    claptrap.takeDamage(claptrap.Get_Attack_damage());
    claptrap.attack("SC4V-TP");
    scavtrap.takeDamage(claptrap.Get_Attack_damage());
    scavtrap.guardGate();
    return 0;
}