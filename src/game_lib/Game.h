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
    int    howManyPlayers ();
    void   roll (int roll);
    bool   wasCorrectlyAnswered ();
    bool   wrongAnswer ();

  private:
    void   askQuestion();
    string currentCategory();
    bool   didPlayerWin();

  private:
    vector<string> players;

    int places[6];
    int purses[6];

    bool inPenaltyBox[6];

    list<string> popQuestions;
    list<string> scienceQuestions;
    list<string> sportsQuestions;
    list<string> rockQuestions;

    unsigned int currentPlayer;
    bool isGettingOutOfPenaltyBox;
};

