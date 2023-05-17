#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
#include "Role.hpp"

class Vampire : public Role {

public:

    Vampire();

    void play(Role* other) const;

    Role* clone() const {return new Vampire{*this};}

};

Vampire::Vampire() : Role(BAD){}

// vampires only injure, they don't kill
void Vampire::play(Role* other) const {

    other->injure();
    
}

#endif // __VAMPIRE_H__