#pragma once

#include <iostream>
#include <vector>
#include <random>
#include<string>

using namespace std;

class Shoe {
private:
    vector<int> cards;
    int card_count;

public:
    Shoe() {
        card_count = 0;
        for (int i = 0; i < 24; i++) {
            //generate the cards of a single deck
            for (int j = 1; j <= 13; j++) {
                cards.push_back(j);
            }
        }
    }
    Shoe(int num_decks) {
        card_count = 0;
        for (int i = 0; i < num_decks * 4; i++) {
            //generate the cards of a single deck
            for (int j = 1; j <= 13; j++) {
                cards.push_back(j);
            }
        }
    }
    // shuffles the shoe
    void shuffle() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
        card_count = 0;
    }

    // draws a card from the shoe
    int drawCard() {
        card_count++;
        // reshuffle the shoe if the card count is less than 100
        if (card_count > 100) {
            shuffle();
        }
        return cards[card_count - 1];
    }

    // returns the card count
    int getCardCount() {
        return card_count;
    }

    // reset the card count
    void resetCardCount() {
        card_count = 0;
    }
};
