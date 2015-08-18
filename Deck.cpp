//
//  Deck.cpp
//  project4
//
//  Created by Alec Malstrom on 11/18/13.
//  Copyright (c) 2013 Alec Malstrom. All rights reserved.
//

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

Deck::Deck() {
    for (int i = 0, counter = 0; i < 4; i++) {
        for (int j = 0; j<13; j++) {
            Card c(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
            this->deck[counter] = c;
            counter++;
        }
    }
    
    this->next = &this->deck[0];
}

void Deck::reset() {
    Deck temp;
    for (int x = 0; x < DECK_SIZE; x++) {
        this->deck[x] = temp.deck[x];
    }
    
    this->next = &this->deck[0];
}

void Deck::shuffle(int n) {
    Card temp[DECK_SIZE];
    if (this->cards_remaining()<52) {
        this->next = &this->deck[0];
    }
    
    if (n <= 26) {
        int counter = 0;
        
        for (int x = 0, y = n; x < n; x++, y++, counter += 2) {
            temp[counter] = this->deck[y];
            temp[counter+1] = this->deck[x];
        }
        
        for (int z = n*2; z<DECK_SIZE; z++, counter++) {
            temp[counter] = this->deck[z];
        }
    } else {
        int counter = 0;

        for (int x = 0, y = n; y < DECK_SIZE; x++, y++, counter += 2) {
            temp[counter] = this->deck[y];
            temp[counter+1] = this->deck[x];
        }
        
        int diff = DECK_SIZE - n;
        for (int z = diff; z < n; counter++, z++) {
            temp[counter] = this->deck[z];
        }
    }
    
    for (int i = 0; i < DECK_SIZE; i++) {
        this->deck[i] = temp[i];
    }
    
    this->next = &this->deck[0];
}

Card Deck::deal() {
    Card result;
    result = *this->next;
    this->next++;
    return result;
}

int Deck::cards_remaining() const {
    int nextIndex = 0;
    for (int x = 0; x < DECK_SIZE; x++) {
        if ((this->deck[x].get_rank() == this->next->get_rank()) & (this->deck[x].get_suit() == this->next->get_suit())) {
            nextIndex = x;
            break;
        }
    }
    return DECK_SIZE - nextIndex;
}





































