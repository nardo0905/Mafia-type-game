#ifndef __VILLAGER_H__
#define __VILLAGER_H__
#include "Role.hpp"

class Villager : public Role {

public:

    Villager();

    // ne pravi nishto selqnina
    void play(Role* other) const;

    Role* clone() const {return new Villager{*this};}

};

Villager::Villager() : Role(GOOD){}

void Villager::play(Role* other) const{}

#endif // __VILLAGER_H__