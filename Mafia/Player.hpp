#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <ctime>
#include <iostream>
#include "Role.hpp"

class Player {

private:

    static unsigned long lastID; // tova e spodeleno za vseki klas, vzima nai-skoroshnoto vreme i go slaga kato id na player

    std::string username;
    unsigned long id;
    Role* role; // trqbva ni golqma chetvorka, no nqmame default constructor po uslovie

    void copy(const Player&);

public:

    Player(const std::string& username, Role* role);
    Player(const Player&);
    Player& operator=(const Player&);
    ~Player();

    bool isActive() const;
    bool getAlliance() const;
    unsigned long getID() const;
    const std::string getUsername() const;

    void play(Player&) const;

    void print() const;

};

void Player::copy(const Player& other) {

    this->username = other.username;
    this->id = other.id;
    this->role = other.role->clone();
    
}

Player::Player(const std::string& username, Role* role) {

    lastID = time(0);
    this->id = lastID;
    this->username = username;
    this->role = role->clone();
    
}

Player::Player(const Player& other) {

    copy(other);
    
}

Player& Player::operator=(const Player& other) {

    if (this != &other) {

        delete this->role;
        copy(other);

    }

    return *this;
    
}

Player::~Player() {

    delete this->role;
    
}

bool Player::isActive() const {

    return this->role->isAlive();
    
}

bool Player::getAlliance() const {

    return this->role->getAlliance();
    
}

unsigned long Player::getID() const {

    return id;
    
}

const std::string Player::getUsername() const {

    return username;
    
}

void Player::play(Player& other) const {

    this->role->play(other.role);
    
}

void Player::print() const {

    std::cout << "ID: " << this->id << ", username: " << this->username << std::endl;
    
}

#endif // __PLAYER_H__