#include "Game.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game()
  : currentPlayer(0)
{
  // BUG: preserving existing behavior (for noe)
  inPenaltyBox.push_back(true);

  for (int i = 0; i < 50; i++)
  {
    {
      ostringstream oss (ostringstream::out);
      oss << "Pop Question " << i;
      popQuestions.push_back(oss.str());
    }

    {
      ostringstream oss (ostringstream::out);
      oss << "Science Question " << i;
      scienceQuestions.push_back(oss.str());
    }

    {
      ostringstream oss (ostringstream::out);
      oss << "Sports Question " << i;
      sportsQuestions.push_back(oss.str());
    }

    {
      ostringstream oss (ostringstream::out);
      oss << "Rock Question " << i;
      rockQuestions.push_back(oss.str());
   }
  }
}

bool Game::isPlayable()
{
  return (players.size() >= 2);
}

bool Game::add(string playerName)
{
  players.push_back(playerName);
  places.push_back(0);
  purses.push_back(0);
  inPenaltyBox.push_back(false);

  cout << playerName << " was added" << endl;
  cout << "They are player number " << players.size() << endl;
  return true;
}

void Game::roll(int roll)
{
  auto updatePosition = [this](int roll)
  {
    places[currentPlayer] = (places[currentPlayer] + roll) % 12;

    cout << players[currentPlayer]
         << "'s new location is "
         << places[currentPlayer]
         << endl;
    cout << "The category is "
         << currentCategory()
         << endl;
  };

  cout << players[currentPlayer] << " is the current player" << endl;
  cout << "They have rolled a " << roll << endl;

  bool should_move_and_ask_question = true;

  if (inPenaltyBox[currentPlayer])
  {
    isGettingOutOfPenaltyBox = (roll % 2);

    string modifier = isGettingOutOfPenaltyBox ? "" : "not ";
    cout << players[currentPlayer]
         << " is " << modifier
         << "getting out of the penalty box"
         << endl;

    should_move_and_ask_question = isGettingOutOfPenaltyBox;
  }

  if (should_move_and_ask_question) { 
    updatePosition(roll);
    askQuestion();
  }
}

void Game::askQuestion()
{
  if (currentCategory() == "Pop")
  {
    cout << popQuestions.front() << endl;
    popQuestions.pop_front();
  }

  if (currentCategory() == "Science")
  {
    cout << scienceQuestions.front() << endl;
    scienceQuestions.pop_front();
  }

  if (currentCategory() == "Sports")
  {
    cout << sportsQuestions.front() << endl;
    sportsQuestions.pop_front();
  }

  if (currentCategory() == "Rock")
  {
    cout << rockQuestions.front() << endl;
    rockQuestions.pop_front();
  }
}

string Game::currentCategory()
{
  vector<string> categories = { "Pop", "Science", "Sports", "Rock" };
  return  categories[places[currentPlayer] % 4];
}

bool Game::handleCorrectAnswer ()
{
  auto award_points = [this]() -> bool
  {
    cout << "Answer was correct!!!!" << endl;

    purses[currentPlayer]++;

    cout << players[currentPlayer]
         << " now has "
         << purses[currentPlayer]
         <<  " Gold Coins."
         << endl;

    return stillNoWinner();
  };

  bool still_no_winner = true;

  if (!inPenaltyBox[currentPlayer] || isGettingOutOfPenaltyBox) {
    still_no_winner = award_points();
  }

  return still_no_winner;
}

bool Game::handleIncorrectAnswer ()
{
  cout << "Question was incorrectly answered" << endl;
  cout << players[currentPlayer] + " was sent to the penalty box" << endl;

  inPenaltyBox[currentPlayer] = true;

  bool still_no_winner = true;

  return still_no_winner;
}

bool Game::stillNoWinner()
{
  return purses[currentPlayer] < 6;
}

void Game::advanceCurrentPlayer ()
{
  currentPlayer = (currentPlayer + 1) % players.size();
}
