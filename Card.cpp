//
//  Card.cpp
//  project4
//
//  Created by Alec Malstrom on 11/18/13.
//  Copyright (c) 2013 Alec Malstrom. All rights reserved.
//

#include "Card.h"
#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

Card::Card()
: rank(TWO), suit(SPADES) {}

Card::Card(Rank rank_in, Suit suit_in)
: rank(rank_in), suit(suit_in) {}

Card::Rank Card::get_rank() const {
    return this->rank;
}

Card::Suit Card::get_suit() const {
    return this->suit;
}

std::ostream& operator<< (std::ostream& os, const Card& c) {
    if (c.get_rank() == Card::TWO) {
        os << "Two";
    } else if (c.get_rank() == Card::THREE) {
        os << "Three";
    } else if (c.get_rank() == Card::FOUR) {
        os <<  "Four";
    } else if (c.get_rank() == Card::FIVE) {
        os <<  "Five";
    } else if (c.get_rank() == Card::SIX) {
        os << "Six";
    } else if (c.get_rank() == Card::SEVEN) {
        os << "Seven";
    } else if (c.get_rank() == Card::EIGHT) {
        os << "Eight";
    } else if (c.get_rank() == Card::NINE) {
        os << "Nine";
    } else if (c.get_rank() == Card::TEN) {
        os << "Ten";
    } else if (c.get_rank() == Card::JACK) {
        os << "Jack";
    } else if (c.get_rank() == Card::QUEEN) {
        os << "Queen";
    } else if (c.get_rank() == Card::KING) {
        os << "King";
    } else if (c.get_rank() == Card::ACE) {
        os << "Ace";
    }
    
    os << " of ";
    
    if (c.get_suit() == Card::SPADES) {
        os << "Spades";
    } else if (c.get_suit() == Card::HEARTS) {
        os << "Hearts";
    } else if (c.get_suit() == Card::CLUBS) {
        os << "Clubs";
    } else if (c.get_suit() == Card::DIAMONDS) {
        os << "Diamonds";
    }
    
    return os;
}