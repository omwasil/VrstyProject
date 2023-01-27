#pragma once
#include<string>
#include<vector>

using namespace std;

class Player {
    const double Bank_Roll = 100000;

private:
    string name;
    vector <int> hand;
    double bankRoll;
    int wins;
    int losses;
    int draws;


public:
    Player() { // add name empty string, hand empty vector, totalHandValue = 0
        name = "";
        bankRoll = Bank_Roll;
        wins = 0;
        losses = 0;
        draws = 0;
    } 


    Player(string name) {
        this->name = name;
        bankRoll = Bank_Roll;
        wins = 0;
        losses = 0;
        draws = 0;
    }

    Player(string name, int card1, int card2) {
        this->name = name;
        this->hand[0] = card1;
        this->hand[1] = card2;
        bankRoll = Bank_Roll;
        wins = 0;
        losses = 0;
        draws = 0;

    }

    // sets for wins losses draws    to reset player 
    //  get methods:

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    void hit(int hitCard) {
        hand.push_back(hitCard);
    }

    int getTotalHandValue() {
        int total = 0;
        for (int v : hand) {
            total += v;
        }
        return total;
    }
};











/*class BlackJack {
private:
    vector <Player> players;
    int dealer_score = 0;
    Shoe shoe;

public:
    BlackJack(vector <Player>& players) {
        this->players = players;
    }
    BlackJack(vector <Player>& players, Shoe& shoe) {
        this->players = players;
        this->shoe = shoe;
    }


    void startGame() {
        cout << "Welcome to Blackjack!" << endl;
        cout << "You will play against the dealer." << endl;        // deal the first two cards to the player     

        for (int i = 0; i < players.size(); i++) {
            players[i].hit(shoe.drawCard());
            players[i].hit(shoe.drawCard());
            cout << "Player: << players[i].getName() << " current score : : << players[i].getHandTotal() << endl;
        }

        dealer_score += show_drawCard();
        dealer_score += show_drawCard();

        cout << "The dealers total is " << dealer_score << endl;

    }

    void nextTurn() {
        char decision;
        for (int i = 0; i < players.size(); i++) {
            cout << "Hit again? (press 'y' or 'n') for " << players[i].getName() << ": ";
            cin >> decision;
            if (decision == 'y') {

                player[i].hit(shoe.drawCard());

            }

        }*/



    };