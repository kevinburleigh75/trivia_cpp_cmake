#pragma once

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Game
{
  public:
    Game();

    bool   addPlayer (string playerName);
    bool   continuePlaying ();

    bool   isPlayable ();
    void   roll (int roll);
    void   handleCorrectAnswer ();
    void   handleIncorrectAnswer ();
    void   advanceCurrentPlayer ();

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

    bool m_continuePlaying;
    unsigned int currentPlayer;
    bool isGettingOutOfPenaltyBox;
};

