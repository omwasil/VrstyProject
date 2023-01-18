#pragma once

//Part 2 - Blackjack game using classes and user input
#include <iostream>
#include <string>
#include"Shoe.h"


class Blackjack {
private:
    int player_score;
    int dealer_score;
    Shoe shoe;

public:
    Blackjack(Shoe shoe) {
        player_score = 0;
        dealer_score = 0;
        this->shoe = shoe;
    }

    // start the game
    void startGame() {
        cout << "Welcome to Blackjack!" << endl;
        cout << "You will play against the dealer." << endl;

        // deal the first two cards to the player
        int card1 = shoe.drawCard();
        int card2 = shoe.drawCard();
        player_score = card1 + card2;
        cout << "You were dealt " << card1 << " and " << card2 << endl;
        cout << "Your total is " << player_score << endl;

        // deal the first two cards to the dealer
        card1 = shoe.drawCard();
        card2 = shoe.drawCard();
        dealer_score = card1 + card2;
        cout << "The dealer was dealt " << card1 << " and " << card2 << endl;
        cout << "The dealers total is " << dealer_score << endl;
    }

    // hit - the player takes another card
    void hit() {
        int card = shoe.drawCard();
        player_score += card;
        cout << "You were dealt a " << card << endl;
        cout << "Your total is " << player_score << endl;
    }

    // stand - the player stands pat
    void stand() {
        cout << "You stand." << endl;
        // the dealer will take cards until their total is 17 or greater
        while (dealer_score < 17) {
            int card = shoe.drawCard();
            dealer_score += card;
            cout << "The dealer was dealt a " << card << endl;
            cout << "The dealers total is " << dealer_score << endl;
        }
    }

    // end the game and determine the winner
    void endGame() {
        cout << "The game is over." << endl;
        if (player_score == 21 && dealer_score == 21) {
            cout << "It's a draw!" << endl;
        }
        else if (player_score == 21) {
            cout << "You win!" << endl;
        }
        else if (dealer_score == 21) {
            std::cout << "You lose!" << endl;
        }
        else if (player_score > 21) {
            cout << "You lose!" << endl;
        }
        else if (dealer_score > 21) {
            cout << "You win!" << endl;
        }
        else if (player_score > dealer_score) {
            cout << "You win!" << endl;
        }
        else if (player_score < dealer_score) {
            cout << "You lose!" << endl;
        }
        else {
            cout << "It's a draw!" << endl;
        }
    }
};

