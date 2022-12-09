#include "util.h"



// face values 
int Ace = 1;
int J = 10;
int Q = 10;
int K = 10;
vector<int>deck;

//instantiate deck 
void MakeDeck() {
	deck = { Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
	         Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
	         Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
	         Ace,2,3,4,5,6,7,8,9,10,J,Q,K };
}

//shuffle the deck
void Shuffle()
{
  srand((unsigned)time(0));

	for (int i = 0; i < 52; i++)
    {
        swap(deck[i], deck[rand() % 52]);
    }
		
	cout << "Shuffled Deck" << endl;
}

//display deck
void Show()
{
	int t=0;
	for (auto i : deck) 
    {
		cout << i << " ,";
		t++;
		if (t % 13 == 0) cout << endl;
	}
}


//player hand

//dealer hand




//give cards to each person //add to remove them from the deck
int Deal()
{

	int card=deck.front();
	deck.erase(deck.begin());
	return card;

}



//add card totals, see who won, and give them a point 
void Add()
{

}


//function for displaying the amount of wins and losses for both

//game keeps going until the deck is empty 

// win conditions:
//Get 21 points on the player's first two cards (called a "blackjack" or "natural"), without a dealer blackjack
//Reach a final score (3 cards) higher than the dealer without exceeding 21
//Let the dealer draw additional cards until his or her hand exceeds 21


