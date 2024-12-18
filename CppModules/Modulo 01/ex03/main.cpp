#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        HumanB jim("Jim");
        Weapon club2 = Weapon("crude spiked club");
        jim.setWeapon(club2);
        jim.attack();
        club2.setType("some other type of club");
        jim.attack();
        return 0;
    }
}