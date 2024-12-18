/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:35 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:37:35 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int Hitpoints;
        unsigned int Energy_points;
        unsigned int Attack_damage;
        unsigned int Max_Hitpoints;
        unsigned int Max_Energy_points;
    public:
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void set_Max_Hitpoints();
        void set_Max_Energy_points();
        unsigned int Get_Attack_damage();
        ClapTrap(std::string name);
        ~ClapTrap();
};