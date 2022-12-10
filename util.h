#pragma once
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;


void MakeDeck();

void Shuffle();

void Show();

int Draw();

void Result();

void Begin();

void makeDealer();

void makePlayer();


class Player
{
    private:
        vector<int>hand;

    public:
        int Scan();
        void Add();

};

class Dealer
{

    private:
        vector<int>hand;
        vector<Player*>pSet;

    public:
        void setPSet(vector<Player*>& pSet);
        vector<Player*> getPSet();
        void Deal();
        int Scan();
        void Add();

};


