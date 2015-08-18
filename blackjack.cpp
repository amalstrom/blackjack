//
//  blackjack.cpp
//  project4
//
//  Created by Alec Malstrom on 11/18/13.
//  Copyright (c) 2013 Alec Malstrom. All rights reserved.
//

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "rand.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

int main(int argc, const char * argv[])
{
    Deck deck;
    Player *player = player_factory(argv[3]);
    Hand hand;
    
    cout << "Shuffling the deck\n";
    for (int counter = 0; counter < 7; counter++) {
        int num = get_cut();
        cout << "cut at " << num << endl;
        deck.shuffle(num);
        player->shuffled();
    }
    
    int minBet = 5;
    int bankroll = atoi(argv[1]);
    int totalHands = atoi(argv[2]);
    int handsPlayed = 1;
    
    while ((bankroll >= minBet) & (handsPlayed <= totalHands)) {
        cout << "Hand " << handsPlayed << " bankroll " << bankroll << endl;
        if (deck.cards_remaining() < 20) {
            int cutNum = get_cut();
            cout << "cut at " << cutNum << endl;
            deck.shuffle(cutNum);
            player->shuffled();
        }
        
        
        int wager = player->bet(bankroll, minBet);
        cout << "Player bets " << wager << endl;

        Hand dealerHand;
        
        Card p1;
        Card p2;
        Card d1;
        Card d2;
        p1 = deck.deal();
        d1 = deck.deal();
        p2 = deck.deal();
        d2 = deck.deal();
        hand.add_card(p1);
        hand.add_card(p2);
        dealerHand.add_card(d1);
        dealerHand.add_card(d2);
        
        cout << "Player dealt " << p1 << endl;
        player->expose(p1);
        cout << "Dealer dealt " << d1 << endl;
        player->expose(d1);
        cout << "Player dealt " << p2 << endl;
        player->expose(p2);
        
        if (hand.hand_value() == 21) {
            bankroll += (3/2)*wager;
            cout << "Player dealt natural 21\n";
            handsPlayed++;
            hand.discard_all();
        } else {
        
        cout << "Player's total is " << hand.hand_value() << endl;
        while (player->draw(d1, hand)) {
            Card c1 = deck.deal();
            hand.add_card(c1);
            player->expose(c1);
            cout << "Player dealt " << c1 << endl;
            cout << "Player's total is " << hand.hand_value() << endl;
        }
        
        if ((hand.hand_value() > 21) & (!hand.hand_is_soft())) {
            cout << "Player busts!" << endl;
            bankroll -= wager;
            handsPlayed++;
            hand.discard_all();
        } else {
            cout << "Dealer's hole card is " << d2 << endl;
            player->expose(d2);
            
            while (dealerHand.hand_value() < 17) {
                Card c1 = deck.deal();
                dealerHand.add_card(c1);
                player->expose(c1);
                cout << "Dealer dealt " << c1 << endl;
            }
            cout << "Dealer's total is " << dealerHand.hand_value() << endl;
        
            if ((dealerHand.hand_value() > 21) & (!dealerHand.hand_is_soft())) {
                cout << "Dealer busts!" << endl;
                bankroll += wager;
                handsPlayed++;
                hand.discard_all();
            } else {
        
                if (dealerHand.hand_value() > hand.hand_value()) {
                    cout << "Dealer wins\n";
                    bankroll -= wager;
                    handsPlayed++;
                    hand.discard_all();
                } else if (dealerHand.hand_value() < hand.hand_value()) {
                    cout << "Player wins\n";
                    bankroll += wager;
                    handsPlayed++;
                    hand.discard_all();
                } else {
                    cout << "Push\n";
                    handsPlayed++;
                    hand.discard_all();
                }
            }
        }
    }
}
    
    cout << "Player has " << bankroll << " after " << handsPlayed-1 << " hands\n";
}













































