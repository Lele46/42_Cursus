/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:24 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:37:24 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
    std::string claptrap_name;
    std::cout << "Enter a name for your Claptrap: " << "and begin a magical adventure!" << std::endl;
    std::cin >> claptrap_name;
    ClapTrap claptrap(claptrap_name);
    std::cout << claptrap_name << " was found by Captain Flint. Now he is forced to \"play\" with him and his FleshRipper bandit gang." << std::endl;
    claptrap.beRepaired(10);
    claptrap.takeDamage(5);
    claptrap.attack("random bandit");
    claptrap.beRepaired(5);
    claptrap.takeDamage(5);
    claptrap.takeDamage(4);
    claptrap.attack("random tinks");
    claptrap.takeDamage(5);
    claptrap.takeDamage(5);
    claptrap.beRepaired(10);
    return 0;
}