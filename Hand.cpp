//
//  Hand.cpp
//  project4
//
//  Created by Alec Malstrom on 11/18/13.
//  Copyright (c) 2013 Alec Malstrom. All rights reserved.
//

#include "Hand.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

Hand::Hand ()
: value(0), soft(false) {}

void Hand::discard_all() {
    this->value = 0;
    this->soft = false;
}

void Hand::add_card(Card c) {
    int newValue = 0;
    if (c.get_rank() == Card::TWO) {
        newValue = 2;
    } else if (c.get_rank() == Card::THREE) {
        newValue = 3;
    } else if (c.get_rank() == Card::FOUR) {
        newValue = 4;
    } else if (c.get_rank() == Card::FIVE) {
        newValue = 5;
    } else if (c.get_rank() == Card::SIX) {
        newValue = 6;
    } else if (c.get_rank() == Card::SEVEN) {
        newValue = 7;
    } else if (c.get_rank() == Card::EIGHT) {
        newValue = 8;
    } else if (c.get_rank() == Card::NINE) {
        newValue = 9;
    } else if (c.get_rank() == Card::TEN) {
        newValue = 10;
    } else if (c.get_rank() == Card::JACK) {
        newValue = 10;
    } else if (c.get_rank() == Card::QUEEN) {
        newValue = 10;
    } else if (c.get_rank() == Card::KING) {
        newValue = 10;
    } else if (c.get_rank() == Card::ACE) {
        if (this->hand_value() <= 10) {
            newValue = 11;
            this->soft = true;
        } else {
            newValue = 1;
        }
    }
    this->value += newValue;
    
    if ((this->hand_value() > 21) & (this->hand_is_soft())) {
        this->value -= 10;
        this->soft = false;
    }
}

int Hand::hand_value() const {
    return this->value;
}

bool Hand::hand_is_soft() const {
    return this->soft;
}

