//
// Created by willworthington on 11/4/2018.
//
#include <iostream>
#include <time.h>
#include "deck.h"
#include "card.h"
using namespace std;

// pristine, sorted deck
Deck::Deck(){
    myIndex = 51;
    Card::Suit currentSuit;
    int shift;
    //Card c1;
    for (int i=1; i<=4; i++){
        if (i==1) currentSuit = Card::spades;
        else if (i==2) currentSuit = Card::hearts;
        else if (i==3) currentSuit = Card::diamonds;
        else currentSuit = Card::clubs;

        for (int j=1; j<=13; j++){
            shift = (i-1)*13-1;
            Card c1(j,currentSuit);
            myCards[shift+j] = c1;
            //myCards[shift+j].setRank(j);
            //myCards[shift+j].setSuit(currentSuit);
        }


    }

}

// shuffle the deck, all 52 cards present
void Deck::shuffle(){
    int length = size();
    if (length <2){
        //Don't do shit
    }
    else{
        srand(time(NULL));
        int index1, index2;
        Card tmp;
        for (int i=0; i<length; i++){
            index1 = rand() % length;
            index2 = rand() % length;
            tmp = myCards[index1];
            myCards[index1] = myCards[index2];
            myCards[index2] = tmp;
        }

    }
}

// get a card, after 52 are dealt, fail
Card Deck::dealCard(){
    Card temp = myCards[myIndex];
    myIndex--;
    return temp;

}

// current state of deck
void Deck::showDeck(){
    for (int i=0; i<myIndex+1; i++){
        cout << myCards[i].toString() << " ";
    }
    cout << endl;
}

// # cards left in the deck
int  Deck::size() const{
    return myIndex+1;
}