//Part 3 - Build a results table to show what strategy loses the least money
#include <iostream>
#include <map>
#include <random>
#include<string>
#include"Blackjack.h"

using namespace std;


// simulate a single hand of blackjack
void simulateHand(Shoe& shoe, int starting_score, int wins, int losses, int draws, map<int, std::pair<int, int>> &results) {
    // reset the card count
    shoe.resetCardCount();

    // the player starts with the given score
    int player_score = starting_score;
    int dealer_score = 0;

    // deal the first two cards to the dealer
    int card1 = shoe.drawCard();
    int card2 = shoe.drawCard();
    dealer_score = card1 + card2;

    // hit if the player's score is less than 17
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

    // simulate 100,000 hands
    int num_hands = 100000;
    map<int, std::pair<int, int>> results;
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> hit_or_stand(0, 1);
    for (int i = 0; i < num_hands; i++) {
        // pick a random starting score
        uniform_int_distribution<int> starting_score(2, 21);
        int score = starting_score(g);

        // randomly pick hit or stand
        int choice = hit_or_stand(g);
        if (choice == 0) {
            simulateHand(shoe, score, results[score].first, results[score].second, 0, results);
        }
        else {
            simulateHand(shoe, score, 0, results[score].second, results[score].first, results);
        }
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