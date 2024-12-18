/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:38:11 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:38:11 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
    public:
        void highFivesGuys(void);
        void attack(const std::string &target);
        unsigned int Get_Attack_damage();
        FragTrap(std::string name);
        ~FragTrap();
};