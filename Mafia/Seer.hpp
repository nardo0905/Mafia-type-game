#ifndef __SEER_H__
#define __SEER_H__
#include "Role.hpp"

class Seer : public Role {

public:

    Seer();

    void play(Role* other) const;

    Role* clone() const {return new Seer{*this};}

};

Seer::Seer() : Role(GOOD){}

// seera gleda rolqta i ako e losh go ubiva
void Seer::play(Role* other) const {

    if (other->getAlliance() == BAD) {

        other->kill();

    }
    
}

#endif // __SEER_H__