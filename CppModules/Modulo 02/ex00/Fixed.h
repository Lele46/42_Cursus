/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:36:28 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:36:28 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
    private:
        int _fixedvalue;
        static const int _fractionalbits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};