#include "util.h"



vector<int>deck;
vector<Dealer*>dSet;
vector<Player*>pSet;

// face values 
int Ace = 1;
int J = 10;
int Q = 10;
int K = 10;


//instantiate deck 
void MakeDeck() 
{
	deck = 
	{ 
		Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
	    Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
	    Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
	    Ace,2,3,4,5,6,7,8,9,10,J,Q,K 
	};
}

//shuffle the deck
void Shuffle()
{
  srand((unsigned)time(0));

	for (int i = 0; i < 52; i++)
    {
        swap(deck[i], deck[rand() % 52]);
    }
}

//display deck
/*void Show()
{
	int t=0;

	for (auto i : deck) 
    {
		cout << i << " ,";
		t++;
		if (t % 13 == 0) cout << endl;
	}
} */

//add cards to hands
int Draw()
{
	int card = deck.front();
	deck.erase(deck.begin());
	return card;
}




//add card to player hand
void Player::Add() 
{
	this->hand.push_back(Draw());
}

//check player's hand
int Player::Scan() 
{
	int sum = 0;

	for (auto i : this->hand) 
	{
		if (i == 1 && sum + 11 <= 21) 
		i = 11;
		cout << i << endl;
		sum += i;
	}

	return sum;
}

//add player to game
void makePlayer()
{
	Player* d = new Player();
	pSet.push_back(d);
}






void Dealer::setPSet(vector<Player*>& pSet) 
{
	this->pSet = pSet;
} 

vector<Player*> Dealer::getPSet() 
{
	return this->pSet;
}

 //add card to dealer hand
void Dealer::Add() 
{
	this->hand.push_back(Draw());
}

//give a card to each person and remove from deck
void Dealer::Deal() 
{
	
	this->Add();

	for (auto p : this->pSet) 
	{
		p->Add();
	}
}

//check dealer's hand
int Dealer::Scan() 
{
	int sum = 0;

	cout << "Dealer's Hand:" << endl;

	for (auto i : this->hand) 
	{
		if (i == 1 && sum + 11 <= 21) 
		i = 11;
		cout << i << endl;
		sum += i;
	}

	return sum;
}

//add dealer to game
void makeDealer()
{
	Dealer* d = new Dealer();
	dSet.push_back(d);
}





void Begin()
{
	Dealer* d = dSet.front();
    d->setPSet(pSet);
    d->Deal();
	d->Deal();
}

//add card totals, see who won, and give them a point 
void Result()
{
	Dealer* d = dSet.front();
	int dHand = d -> Scan();

	string score = "";

	for (auto p : d -> getPSet()) 
	{
	
		cout << "Player's Hand" << endl;
		int pHand = p -> Scan();

		if (pHand < 21 && dHand < 21)
		{
			//ADD ANOTHER CARD TO BOTH
			//THEN SCAN AGAIN
		}
        else
		{
			if (pHand == dHand) 
			{
				score += "Tie\n";
			}
			if (pHand == 21 && dHand == 21) 
			{
				score += "Tie\n";
			}
			if (pHand == 21 && dHand != 21) 
			{
				score += "Player Wins!\n";
			}
			if (pHand < 21 && pHand > dHand) 
			{
				score += "Player Wins!\n";
			}
			if (dHand > 21) 
			{
				score += "Player Wins!\n";
			}
			if (pHand > 21) 
			{
				score += "Player Lose!\n";
			}
			if(pHand != 21 && dHand == 21) 
			{
				score += "Dealer Wins!\n";
			}
			
		} 
	}
		cout << score << endl;

}


//function for displaying the amount of wins and losses for both

//make game keep going until the deck is empty 



