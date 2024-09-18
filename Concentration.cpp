#include "RandomInt.hpp"
#include <array>
#include <iostream>
using namespace std;
struct Card {
  string Phrase;
  bool Matched = false;
};
Random::RandomInt randomIntGenerator(0, 3, 2);
void buildRandomCardPointerArray(array<Card, 4> &cards,
                                 array<Card *, 8> &list) {

  for (int i = 0; i < 8; i++) {
    list.at(i) = &cards.at(randomIntGenerator.get());
    // cout << i + 1 << ". " << list.at(i)->Phrase << endl;
  }
}
void displayGameBoard(array<Card *, 8> list) {
  for (int i = 0; i < 8; i++) {
    cout << "Card " << i + 1 << ": ";
    if (list.at(i)->Matched == true) {
      cout << list.at(i)->Phrase << endl;
    } else {
      cout << "?" << endl;
    }
  }
  cout << endl;
}
bool allCardsMatched(array<Card, 4> &cards) {
  if (cards.at(0).Matched && cards.at(1).Matched && cards.at(2).Matched &&
      cards.at(3).Matched == true) {
    return true;
  } else {
    return false;
  }
}
int main() {
  string clearCLI;
  int guess = 0;
  int choice1, choice2;
  array<Card, 4> cards;
  array<Card *, 8> animalList;
  cards.at(0).Phrase = "Flying Monkey";
  cards.at(1).Phrase = "Mad Cow";
  cards.at(2).Phrase = "Magic Genie";
  cards.at(3).Phrase = "Great Pumpkin";
  cout << "Welcome to Memory game!\n\nTotal Guesses: " << guess << endl << endl;
  buildRandomCardPointerArray(cards, animalList);
  displayGameBoard(animalList);
  for (guess = 0; allCardsMatched(cards) != true; guess++) {
    cout << "Select two different cards between 1 and 8:\n";
    cin >> choice1-1 >> choice2-1;
    if (animalList.at(choice1)->Phrase == animalList.at(choice2)->Phrase) {
      cout << "You found a matching pair!\n";
      cout << "Both cards say \"" << animalList.at(choice1)->Phrase << "\""
           << endl;
      cout << "PRESS ENTER KEY TO CONTINUE...\n";
      cin >> clearCLI;
      if (clearCLI == "") {
        system("cls||clear");
      }
    }
      }
     return 0;
    }
  
 
