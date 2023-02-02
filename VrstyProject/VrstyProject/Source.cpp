//Part 3 - Build a results table to show what strategy loses the least money
#include <cstdlib>
#include <iostream>
#include <map>
#include <random>
#include<string>
#include"Blackjack.h"
#include "Player.h"
#include "Shoe.h"

using namespace std;


// simulate a single hand of blackjack
void simulateHand(Shoe& shoe, Player *players, int numPlayers) {
    // reset the card count

    //shoe.resetCardCount();
    srand((unsigned)time(NULL));

    // Get a random number
    int random = rand();
    // the player starts with the given score
    int player_score = 0;
    int dealer_score = 0;

    // deal the first two cards to the dealer
    int card1 = shoe.drawCard();
    int card2 = shoe.drawCard();
    dealer_score = card1 + card2;

    // hit if the player's score is less than 17
    for (int i = 0; i < numPlayers; i++) {
        players[i].hit(shoe.drawCard());
        players[i].hit(shoe.drawCard());
        int currentScore = players[i].getTotalHandValue();
        while (currentScore < 17) {
            players[i].hit(shoe.drawCard());
            currentScore = players[i].getTotalHandValue();
        }
    }
    while (player_score < 17) {
        int card = shoe.drawCard();
        player_score += card;
    }

    // the dealer will take cards until their total is 17 or greater
    while (dealer_score < 17) {
        int card = shoe.drawCard();
        dealer_score += card;
    }

    // determine the winner
    if (player_score == 21 && dealer_score == 21) {
        draws++;
    }
    else if (player_score == 21) {
        wins++;
    }
    else if (dealer_score == 21) {
        losses++;
    }
    else if (player_score > 21) {
        losses++;
    }
    else if (dealer_score > 21) {
        wins++;
    }
    else if (player_score > dealer_score) {
        wins++;
    }
    else if (player_score < dealer_score) {
        losses++;
    }
    else {
        draws++;
    }
   // results.insert({ starting_score, make_pair(wins, losses) });
    //if condition if no key(starting score)
    if (results.find(starting_score) != results.end()) {
        wins += results[starting_score].first;
        losses += results[starting_score].second;
    }

    results[starting_score] = make_pair(wins, losses);
}

int main() {
    // create a shoe of 6 decks
    Shoe shoe(6);
    shoe.shuffle();
    int numPlayers;
    cout << "Enter how many players do you wish to add: ";
    cin >> numPlayers;
    Player* players = new Player[numPlayers];
    string name;
    for(int i = 0; i < numPlayers; i++) {
        players[i] = new Player();
        cout << "Enter the name of player" << (i + 1) << ": ";
        cin >> name;
        players[i].setName(name);
    }
    // simulate 100,000 hands
    int num_hands = 100000;
    srand((unsigned)time(NULL));
    // Get a random number
    int random = rand();
    for (int i = 0; i < num_hands; i++) {
        simulateHand(shoe, players, numPlayers);

    }

    // display the results
    cout << "Starting Score | Wins | Losses" << endl;
    for (auto it = results.begin(); it != results.end(); it++) {
        int score = it->first;
        int wins = it->second.first;
        int losses = it->second.second;
        cout << score << " | " << wins << " | " << losses << endl;
    }
    return 0;
}