#ifndef __ROLE_H__
#define __ROLE_H__

const bool GOOD = true;
const bool BAD = false;

const short ALIVE = 1;
const short INJURED = 0; // not yet dead, vampires leave people injured
const short DEAD = -1;

class Role {

private:

    bool alliance;
    short condition;

public:

    Role(const bool);

    short getAlliance() const;
    bool isAlive() const;
    bool isInjured() const;

    void injure();
    void kill();
    void heal();

    virtual void play(Role* other) const = 0;
    virtual Role* clone() const = 0;

    virtual ~Role() = default; // tva trqbva da go ima vuv vseki klas koito ima naslednici

};

Role::Role(const bool alliance) : alliance(alliance), condition(ALIVE){}

short Role::getAlliance() const {

    return alliance;
    
}

bool Role::isAlive() const {

    return condition == ALIVE;
    
}

bool Role::isInjured() const {

    return condition == INJURED;
    
}

void Role::injure() {

    if (this->isInjured()) throw "Already injured!";

    this->condition = INJURED;
    
}

void Role::kill() {

    if (!this->isAlive()) throw "Already dead!";

    this->condition = DEAD;
     
}

void Role::heal() {

    if (this->isAlive()) throw "Already healed!";

    this->condition = ALIVE;
    
}

#endif // __ROLE_H__