/*
* This is the main function for the Football Guessing Gauntlet. This game is run through
* terminal. This file uses functions and structs stored in FootballTrivia.cpp.
* 
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstring>
#include <limits>
#include <algorithm>
#include "FootballTrivia.cpp"

using namespace std;
using std::vector;

const int STARTING_VALUE = 100; 

int main()
{
    bool playAgain = true;

    while (playAgain)
    {

        printWelcomeScreen();
        bool toAsk = true;
        int res = CLEAR_RES;  // value to depict that the user has not inputted anything yetf
        int numPlayersGuessed = 0;

        askOneTwo(res, "Press 1 to start and press 2 for the instructions! ");

            if (res == 1)
            {
                toAsk = false;
            } 
            else if (res == 2)
            {
                cout << "**********************************" << endl; 
                for (string s : instructions)
                {
                    cout << s << endl;
                }
                toAsk = false;
            }
            else if (cin.fail())
            {
                res = CLEAR_RES;
            }

        askOneTwo(res, "Choose your level: Press 1 for Easy (just QBs), press 2 for Hard (QBs, RBs, WRs): "); 

        if (res == 2){
            playerList.insert( playerList.end(), skillposList.begin(), skillposList.end());
            
        }

        bool continueGame = true;

        int score = STARTING_VALUE;

        bool playerGuessed = false;
        fillHintValuePairs(hintValues, sortedPairValues);

        while (continueGame)
        {
            srand(time(0));
            int randNum = (rand() % playerList.size());
            Player randPlayer = playerList[randNum];
            playerList.erase(playerList.begin() + randNum);  // delete this player from the vector so that they can't be guessed again

            string playerName = randPlayer.name;
            transform(playerName.begin(), playerName.end(), playerName.begin(), ::toupper);  // put playerName in all caps to evaluate because we don't care about the capitalization
            string guess = "";

            while (playerGuessed == false)
            {  // do this until the name is correct

                if (score <= 0)
                    score = 0;  // make sure the player's score doesn't go negative

                printScoreScreen(score);

                if (score == 0)
                {
                    cout << "You are out of points. Make one last guess for this player: ";
                    cin.ignore();
                    getline(cin, guess);
                    transform(guess.begin(), guess.end(), guess.begin(), ::toupper);  // put the guess in all uppercase to evaluate 


                    if (guess == playerName)
                    {
                        cout << "Correct! The player is " << playerName << endl;
                        printScoreScreen(score);
                        numPlayersGuessed++;

                        playerGuessed = true;
                    }
                    else
                    {
                        cout << "Incorrect guess." << endl;
                        cout << "The final player was " << playerName << endl; 
                        break;
                    }
                }
                else
                {
                    askOneTwo(res, "Press 1 to get a hint and press 2 to make a guess (cost 1 point if wrong): ");

                    if (res == 1)  // user wants to get a hint
                    {

                        cout << "**********************************" << endl; 
                        printHints(sortedPairValues);

                        cout << "Above are the hints and the point total cost to get that hint. \nSelect which hint you would like: ";
                        cin >> res;
                        if (cin.fail() || res >= sortedPairValues.size())
                            failInput(res);

                        if (res >= 0 && res < sortedPairValues.size())
                        {  // checking if user input is one of the hints

                            HintValuePair selectedHint = sortedPairValues[res];

                            string hintToRelease = hintToPlayerStruct(randPlayer, res);
                            int value = selectedHint.hintValue;

                            if (value > score)
                            {
                                cout << "**********************************" << endl;
                                cout << "You do not have enough points to choose this hint." << endl;
                            } 
                            else
                            {
                                cout << "**********************************" << endl;
                                cout << selectedHint.hintName << ": " << hintToRelease << endl;
                                score -= selectedHint.hintValue;
                            }
                        }
                    }
                    else if (res == 2) // user has selected to make a guess
                    {
                        cout << "Guess the player (first and last name): ";
                        cin.ignore();
                        getline(cin, guess);
                        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

                        if (guess == playerName)
                        {
                            cout << "Correct! The player is " << playerName << endl;
                            numPlayersGuessed++;
                            playerGuessed = true;
                        }
                        else
                        {
                            cout << "Incorrect guess (score -1)." << endl;
                            score--;
                        }
                    }
                }
            }

            if (score == 0)
            {
                continueGame = false;
            }
            else
            {
                if (numPlayersGuessed == 1) {
                    cout << "You have now guessed " << numPlayersGuessed << " player. Keep on going!" << endl;

                }
                 else {
                    cout << "You have now guessed " << numPlayersGuessed << " players. Keep on going!" << endl;
                    }
                playerGuessed = false;
            }
        } 

        printFinalPlayersGuessed(numPlayersGuessed); //TODO!: GAME OVER 

        cout << "Do you want to play again?\nPress 1 to play again, press anything else to quit: ";
        cin >> res;

        if (cin.fail() || res != 1)
        {
            cin.clear();
            playAgain = false;
        }
        res = CLEAR_RES;

    } 
}
