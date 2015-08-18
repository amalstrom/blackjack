//
//  Player.cpp
//  project4
//
//  Created by Alec Malstrom on 11/18/13.
//  Copyright (c) 2013 Alec Malstrom. All rights reserved.
//

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>

//DECLARATIONS
class SimplePlayer : public Player {
public:
    
    virtual int bet (unsigned int bankroll, unsigned int minimum);
    
    virtual bool draw (Card dealer, const Hand &player);
    
    virtual void expose (Card c);
    
    virtual void shuffled();
};

class CountingPlayer : public SimplePlayer {
    int count;
public:
    
    virtual int bet (unsigned int bankroll, unsigned int minimum);
    
    virtual void expose (Card c);
    
    virtual void shuffled();
    
    int get_count();
    
    void set_count(int x);
};

class Competitor : public CountingPlayer {
public:
    
    virtual int bet (unsigned int bankroll, unsigned int minimum);
};

//GLOBAL INSTANTIATIONS
SimplePlayer sp;
CountingPlayer cp;
Competitor competitor;

//SIMPLE PLAYER DEFINITIONS
int SimplePlayer::bet (unsigned int bankroll, unsigned int minimum) {
    return minimum;
}

bool SimplePlayer::draw (Card dealer, const Hand &player) {
    if (player.hand_is_soft() == true) {
        if (player.hand_value() <= 17) {
            return true;
        } else if (player.hand_value() == 18) {
            if (dealer.get_rank() == Card::TWO || dealer.get_rank() == Card::SEVEN || dealer.get_rank() == Card::EIGHT) {
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    } else {
        if (player.hand_value() <= 11) {
            return true;
        } else if (player.hand_value() == 12) {
            if (dealer.get_rank() == Card::FOUR || dealer.get_rank() == Card::FIVE || dealer.get_rank() == Card::SIX) {
                return false;
            } else {
                return true;
            }
        } else if ((player.hand_value() >= 13) & (player.hand_value() <= 16)) {
            if ((dealer.get_rank() >= Card::TWO) & (dealer.get_rank() <= Card::SIX)) {
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
}

void SimplePlayer::expose (Card c) {
    
}

void SimplePlayer::shuffled() {
    
}

//COUNTING PLAYER DEFINITIONS
int CountingPlayer::bet (unsigned int bankroll, unsigned int minimum) {
    if (this->count >= 2) {
        if (bankroll > 2*minimum) {
            return minimum*2;
        } else {
            return bankroll;
        }
    } else {
        return minimum;
    }
}

void CountingPlayer::expose(Card c) {
    if (c.get_rank() >= Card::TEN) {
        this->count--;
    } else if (c.get_rank() <= Card::SIX) {
        this->count++;
    }
}

void CountingPlayer::shuffled() {
    this->count = 0;
}

int CountingPlayer::get_count() {
    return this->count;
}

void CountingPlayer::set_count(int x) {
    this->count = x;
}

//COMPETITOR
int Competitor::bet(unsigned int bankroll, unsigned int minimum) {
    if (this->get_count() < 0) {
        return minimum;
    } else if ((this->get_count() >= 0) & (this->get_count()<2)) {
        return minimum*2;
    } else {
        return get_count()*minimum;
    }
}


//PLAYER FACTORY
Player* player_factory(const char * s) {
    if (strcmp(s, "simple") == 0) {
        Player *result = &sp;
        return result;
    } else if (strcmp(s, "counting") == 0) {
        Player *result = &cp;
        return result;
    } else {
        Player *result = &competitor;
        return result;
    }
}






































