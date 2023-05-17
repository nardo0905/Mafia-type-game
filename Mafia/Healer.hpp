#ifndef __HEALER_H__
#define __HEALER_H__
#include "Role.hpp"

class Healer : public Role {

public:

    Healer();

    void play(Role* other) const;

    Role* clone() const {return new Healer{*this};}

};

Healer::Healer() : Role(GOOD){}

// healva samo injured igrachi
void Healer::play(Role* other) const {

    if (other->isInjured()) {

        other->heal();

    }
    
}


#endif // __HEALER_H__