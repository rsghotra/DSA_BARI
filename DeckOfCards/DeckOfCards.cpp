#include"DeckOfCards.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;


DeckOfCards::DeckOfCards() {
    //initialize face array
    static string face[faces]{"Ace", "Deuce", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    //initialize suit array
    static string suit[suits]{"Clubs", "Diamonds", "Spades", "Hearts"};

    //initialize the deck array
    for(size_t i{0}; i < deck.size(); ++i) {
        deck[i].face = face[i % faces];
        deck[i].suit = suit[i % suits];
    }
    srand(static_cast<unsigned int>(time(0)));
}

void DeckOfCards::shuffle() {
    for(size_t i{0}; i < deck.size();++i) {
        Card temp =  deck[i];
        int j{rand() % numberOfCards};
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void DeckOfCards::deal() const {
    for(size_t i = 0; i < deck.size(); ++i) {
        cout << right << setw(5) << deck[i].face << " of "
            << left << setw(8) << deck[i].suit;
        cout << ((i+1)%2 == 0 ? '\n' : '\t');
    }
}