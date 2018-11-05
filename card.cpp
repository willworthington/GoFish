//
// Created by willworthington on 11/4/2018.
//
#include <iostream>
#include "card.h"

using namespace std;

// default, ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;

}

// return string version e.g. Ac 4h Js
string Card::toString()const{
    return (rankString(myRank)+suitString(mySuit));
}


// true if suit same as c
bool Card::sameSuitAs(const Card& c) const{
    return (mySuit==c.mySuit);
}

// return rank, 1..13
int  Card::getRank() const{
    return myRank;
}

// return "s", "h",...
string Card::suitString(Suit s) const{
    switch (s){
        case spades: return  "s";
        case hearts: return "h";
        case diamonds: return "d";
        case clubs: return "c";
    }

}

// return "A", "2", ..."Q"
string Card::rankString(int r) const{
    switch (r){
        case 1: return "A";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "10";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
    }
}


bool Card::operator == (const Card& rhs) const{
    return ((myRank==rhs.myRank)&&(mySuit==rhs.mySuit));

}

bool Card::operator != (const Card& rhs) const{
    return !((myRank==rhs.myRank)&&(mySuit==rhs.mySuit));

}
