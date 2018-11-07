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

int main (){
    testCard();
    //testDeckInit();
    //testDeckShuffle();


    return 0;
}


/*
int main( )
{
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
*/

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