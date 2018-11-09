//
// Created by willworthington on 11/4/2018.
//
#include <istream>
#include <time.h>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;


//adds a card to the hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    //Loops from back to front, so that it will check the most likely case first,
    //which is that the newest card (at the end) matches a card earlier in the deck
    for (int i=myHand.size()-1; i>=1; i--){
        for (int j=i-1; j>=0; j--){
            if(myHand[i].getRank()==myHand[j].getRank()){
                c1=myHand[i];
                c2=myHand[j];
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{

    for (int i=0; i<myHand.size(); i++){
        if (myHand[i].getRank()==c.getRank()) return true;
    }
    return false;

}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    //No strategy yet
    //Strategize later, this is just a simple guesser
    int length = myHand.size();
    srand(time(NULL));
    int index = rand() % length;
    return myHand[index];

}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for (int i=0; i<myHand.size(); i++){
        if (myHand[i]==c) return true;
    }
    return false;
}

//Remove the card c (with matching rank) from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card tmp=c;
    Card errorCard(0,Card::spades);
    for (int i=0; i<myHand.size(); i++){
        if (myHand[i]==c){
            //tmp = myHand[i];
            myHand.erase(myHand.begin()+i);
            return tmp;
        }
    }
    return errorCard;
}

//Remove the card c (with matching rank) from the hand and return it to the caller
Card Player::removeRankFromHand(Card c){
    Card tmp;
    Card errorCard(0,Card::spades);
    for (int i=0; i<myHand.size(); i++){
        if (myHand[i].getRank()==c.getRank()){
            tmp = myHand[i];
            myHand.erase(myHand.begin()+i);
            return tmp;
        }
    }
    return errorCard;
}

string Player::showHand() const{
    string hand;
    for (int i=0; i<myHand.size(); i++){
        if (i!=myHand.size()-1){
            hand += myHand[i].toString() + " ";
        }
        else{
            hand += myHand[i].toString();
        }
    }
    return hand;
}

string Player::showBooks() const{
    string books;
    for (int i=0; i<myBook.size(); i++){
        if (i!=myBook.size()-1){
            books += myBook[i].toString() + " ";
        }
        else{
            books += myBook[i].toString();
        }
    }
    return books;
}

int Player::getHandSize() const{
    return myHand.size();

}

int Player::getBookSize() const{
    return myBook.size();

}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
/*
bool Player::checkHandForPair(Card &c1, Card &c2){

}*/

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c
/*
bool Player::sameRankInHand(Card c) const{

}*/
