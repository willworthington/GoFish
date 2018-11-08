// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void testCard();
void testDeckInit();
void testDeckShuffle();
void testGame();
bool roundOfGame(Player &p1, Player &p2, Deck &d1);
void gameResults(Player &p1, Player &p2);
void emptyHanded(Player &p, Deck &d1);
bool moreCards(Player &p1, Player &p2, Deck &d1);
void stateOfGame(Player &p1, Player &p2, Deck d1);

int main (){
    //testCard();
    //testDeckInit();
    //testDeckShuffle();
    testGame();


    return 0;
}


void testCard(){
    Card c1;
    Card c2(13,Card::hearts);
    Card c3 = c2;
    cout << "Card 1: " << c1.toString() << endl;
    cout << "Card 2: " << c2.toString() << endl;
    cout << "Card 3: " << c3.toString() << endl;
    if (c1==c2){
        cout << "Card 1 == Card 2: TRUE" << endl;
    }
    else if (c1!=c2){
        cout << "Card 1 != Card 2: TRUE" << endl;
    }
    else {
        cout << "Something is seriously wrong here" << endl;
    }

    if (c2==c3){
        cout << "Card 2 == Card 3: TRUE" << endl;
    }
    else if (c2!=c3){
        cout << "Card 2 != Card 3: TRUE" << endl;
    }
    else {
        cout << "Something is seriously wrong here" << endl;
    }

}

void testDeckInit(){
    Deck d1;
    cout << "Starting size: " << d1.size() << endl;
    d1.showDeck();
    //cout << "Ending size: " << d1.size() << endl;
}

void testDeckShuffle(){
    cout << endl << "*** TESTING Deck::shuffle() ***" << endl;

    Deck d1;

    cout << "Original Deck:" << endl;
    d1.showDeck();

    d1.shuffle();
    cout << "Shuffled Deck:" << endl;
    d1.showDeck();

    d1.shuffle();
    cout << "Shuffled again:" << endl;
    d1.showDeck();
}

void testGame(){
    Deck d1;
    Player john("John");
    Player bob("Bob");

    d1.shuffle();

    for (int i=0; i<7; i++){
        john.addCard(d1.dealCard());
        bob.addCard(d1.dealCard());
    }
    cout << "John's Initial Hand: " << john.showHand() << endl;
    cout << "Bob's Initial Hand: " << bob.showHand() << endl << endl;
    Card j1, j2, b1, b2;

    while(john.checkHandForBook(j1,j2)){
        john.bookCards(j1,j2);
        john.removeCardFromHand(j1);
        john.removeCardFromHand(j2);
    }
    while(bob.checkHandForBook(b1,b2)){
        bob.bookCards(b1,b2);
        bob.removeCardFromHand(b1);
        bob.removeCardFromHand(b2);
    }
    if (john.getBookSize()>0){
        cout << "John Books: " << john.showBooks() << endl;
    }
    else {
        cout << "John Books: no cards." << endl;

    }
    if (bob.getBookSize()>0){
        cout << "Bob Books: " << bob.showBooks() << endl;
    }
    else{
        cout << "Bob Books: no cards" << endl;
    }

    cout << endl;

    //Main loop of game
    while (moreCards(john,bob,d1)){
        while((moreCards(john,bob,d1))&&(roundOfGame(john,bob,d1)));
        while((moreCards(john,bob,d1))&&(roundOfGame(bob,john,d1)));

    }

    //Printing the results of the game to the screen
    gameResults(john, bob);


}

bool roundOfGame(Player &p1, Player &p2, Deck &d1){
    bool guessedRight;
    Card guess;
    Card returnedCard;
    Card drawnCard;
    guess = p1.chooseCardFromHand();
    cout << p1.getName() << " asks - Do you have a " << guess.rankString(guess.getRank()) << "?" << endl;
    if(p2.rankInHand(guess)){
        //they will get another turn since they guessed right
        guessedRight = true;

        cout << p2.getName() << " says - Yes.  I have a " << guess.rankString(guess.getRank()) << "." << endl;
        returnedCard = p2.removeRankFromHand(guess);
        p1.bookCards(guess,returnedCard);
        p1.removeCardFromHand(guess);
        cout << p1.getName() << " books " << guess.toString() << " and " << returnedCard.toString() << "." << endl;

        //Checking if either player's hand is empty, and if deck is not empty
        //If yes, will draw a new card for them
        emptyHanded(p1,d1);
        emptyHanded(p2,d1);
    }
    else{
        guessedRight = false;
        cout << p2.getName() << " says - Go Fish." << endl;
        if (d1.size()!=0){
            drawnCard = d1.dealCard();
            cout << p1.getName() << " draws " << drawnCard.toString() << "." << endl;
            if (p1.rankInHand(drawnCard)){
                Card matchingCard = p1.removeRankFromHand(drawnCard);
                p1.bookCards(drawnCard, matchingCard);
                cout << p1.getName() << " has a pair. " << p1.getName() << " books " << drawnCard.toString() << " and " << matchingCard.toString() << "." << endl;

                //If hand is empty after booking, draw another card
                emptyHanded(p1,d1);
            }
            else{
                p1.addCard(drawnCard);
            }
        }
        else{
            cout << "Deck is empty. No card is drawn." << endl;
        }
    }

    cout << endl;
    //stateOfGame(p1,p2,d1);

    return guessedRight;
}




void gameResults(Player &p1, Player &p2){
    cout << "RESULTS:" << endl;
    cout << p1.getName() << " has " << p1.getBookSize() << " cards booked." << endl;
    cout << p2.getName() << " has " << p2.getBookSize() << " cards booked." << endl;
    if (p1.getBookSize()>p2.getBookSize()){
        cout << p1.getName() << " wins!" << endl;
    }
    else if (p1.getBookSize()<p2.getBookSize()){
        cout << p2.getName() << " wins!" << endl;
    }
    else{
        cout << "It's a tie!" << endl;
    }
}




//Checks if the player is empty handed
//Draws a new card for them if they are empty handed and the deck has more cards remaining
void emptyHanded(Player &p, Deck &d1) {
    if (p.getHandSize() == 0) {
        //If the deck has 1 or less cards, the game will end
        if (d1.size() == 0) {
            //Done
            //********************************************
            //guessedRight = false;
        } else {
            Card drawnCard = d1.dealCard();
            p.addCard(drawnCard);
            cout << p.getName() << "'s hand is empty. " << p.getName() << " draws " << drawnCard.toString() << endl;
        }
    }
}

//Checks if there are more cards (can the game be continued?)
//returns true if the sum of all the cards in the deck and players' hands is > 0
//returns false if the sum is 0
bool moreCards(Player &p1, Player &p2, Deck &d1){
    if ((d1.size()+p1.getHandSize()+p2.getHandSize())!=0) return true;
    else return false;
}

//For testing purposes, shows the current state of the game and players' hands
void stateOfGame(Player &p1, Player &p2, Deck d1){
    cout << "Deck: ";
    d1.showDeck();
    cout << p1.getName() << "'s hand: " << p1.showHand() << endl;
    cout << p1.getName() << "'s book size: " << p1.getBookSize() << endl;
    cout << p2.getName() << "'s hand: " << p2.showHand() << endl;
    cout << p2.getName() << "'s book size: " << p2.getBookSize() << endl;
    cout << endl;
}