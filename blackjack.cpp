#include"util.h"


// show your cards and dealer's cards
// add the total and say who won 
// keep track of wins and losses

int main()
{
    MakeDeck();
    //Show();
    Shuffle();
    //Show();
    makeDealer();
    makePlayer();
    Start();
    Add();
}
