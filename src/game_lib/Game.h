#pragma once

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Game
{
  public:
    Game();

    bool   isPlayable ();
    bool   add (string playerName);
    void   roll (int roll);
    bool   wasCorrectlyAnswered ();
    bool   wrongAnswer ();

  private:
    void   askQuestion ();
    string currentCategory ();
    bool   stillNoWinner ();

  private:
    vector<string> players;
    vector<int>    places;
    vector<int>    purses;
    vector<bool>   inPenaltyBox;

    list<string> popQuestions;
    list<string> scienceQuestions;
    list<string> sportsQuestions;
    list<string> rockQuestions;

    unsigned int currentPlayer;
    bool isGettingOutOfPenaltyBox;
};

