#ifndef __GAME_H__
#define __GAME_H__
#include "Player.hpp"

class Game {

private:

    Player** players;
    size_t numOfPlayers;

    void copy(const Game&);
    void deleteGame();

    bool isGameOver() const;

    void clearInactivePlayers();
    void playerTurn(Player*);

    Player* findByID(const unsigned long) const;

public:

    Game(const size_t numOfPlayers = 0, Player** players);
    Game(const Game&);
    Game& operator=(const Game&);
    ~Game();

    void play();

};

void Game::copy(const Game& other) {

    this->numOfPlayers = other.numOfPlayers;
    this->players = new Player*[numOfPlayers];

    for (size_t i = 0; i < numOfPlayers; i++) {

        this->players[i] = new Player(*(other.players[i]));

    }

}

void Game::deleteGame() {

    for (size_t i = 0; i < numOfPlayers; i++) {

        delete this->players[i];

    }

    delete[] this->players;

}

Game::Game(const size_t numOfPlayers, Player** players) {

    this->numOfPlayers = numOfPlayers;
    this->players = new Player*[numOfPlayers];

    for (size_t i = 0; i < numOfPlayers; i++) {

        this->players[i] = new Player(*(players[i]));

    }
    
}

Game::Game(const Game& other) {

    copy(other);

}

Game::~Game() {

    deleteGame();

}

Game& Game::operator=(const Game& other) {

    if (this != &other) {

        deleteGame();
        copy(other);

    }

    return *this;

}

Player* Game::findByID(const unsigned long id) const {

    for (size_t i = 0; i < numOfPlayers; i++) {

        if (players[i]->getID() == id) return players[i];

    }

    return nullptr;

}

bool Game::isGameOver() const {

    int good = 0;
    int bad = 0;

    for (size_t i = 0; i < numOfPlayers; i++) {

        if (this->players[i]->getAlliance() == GOOD) {

            good++;
        
        } else bad++;

    }

    if (good && bad) return false; // ako ima jivi igrachi ot good i bad oshte ne e svurshila igrata
    if (good) { // ako ima jivi samo ot good -> good pechelqt

        std::cout << "Good alliance won!";
        return true;

    }
    // bad pechelqt
    if (bad) {
        std::cout << "Bad alliance won!";
        return true;
    }
    // ako vsichki sa umreli
    std::cout << "Everybody died!";
    return true;

}

void Game::clearInactivePlayers() {

    // chistim umrelite kato pravim nov masiv
    size_t newNumOfPlayers = numOfPlayers;

    for (size_t i = 0; i < numOfPlayers; i++) {

        if (!players[i]->isActive()) {

            delete players[i];
            players[i] = nullptr;
            newNumOfPlayers--;

        }

    }

    Player** tmp = new Player*[newNumOfPlayers];
    size_t index = 0;

    for (size_t i = 0; i < numOfPlayers; i++) {

        if (players[i]->isActive()) {

            tmp[index] = players[i];
            index++;

        }

    }

    deleteGame();
    players = tmp; // prisvoqvame temprary masiva koito ima samo jivite na nashata chlen-danna s igrachi

}

void Game::playerTurn(Player* player) {

    player->print();

    std::cout << "Your opponents are: " << std::endl;
    for (size_t i = 0; i < numOfPlayers; i++) {

        if (this->players[i]->getID() != player->getID()) {

            this->players[i]->print(); // printirame vsichki opcii koito moje da atakuva igracha

        }

    }

    unsigned long opponentID;
    std::cout << "Enter the ID of the player you want to make an act on: ";
    std::cin >> opponentID;

    Player* opponent = findByID(opponentID); // pravim pointer kum oponenta, koito sme namerili po id
    if (opponent) {

        player->play(*opponent);

    }

}

void Game::play() {

    do {

        for (size_t i = 0; i < numOfPlayers; i++) {

            playerTurn(this->players[i]);
            clearInactivePlayers();

        }

    } while(!isGameOver());
    
}

#endif // __GAME_H__