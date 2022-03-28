
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;
using std::vector;

// some gueses will take away more points than others (ie number vs pass yards)

const int CLEAR_RES = -137;


struct Player
{
    string name;
    string team;
    string college;
    string position;
    string jerseyNumber;
    string division;
    string passingTouchdowns2020;
    string receivingTouchdowns2020;
    string rushingTouchdowns2020;
    string proBowls;
};

/**
 * @brief  function to be run when cin.fail() is true 
 * @param  &res: the user's response that will be changed back to a CLEAR_RES value
 * @retval None
 */
void failInput(int &res)
{
    cout << "ERROR -- Improper input \n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    res = CLEAR_RES;
}

/**
 * @brief Several times this program asks the user to choose between 
 * 1 and 2 on several occasions. this function checks to make sure the input is valid 
 * and will reset the value of res 
 * @param  &res: the user's response
 * @param  str: the question that the program will ask the computer 
 * @retval None
 */
void askOneTwo(int &res, string str)
{
    res = CLEAR_RES;

    while (res != 1 && res != 2)
    {

        cout << str;
        cin >> res;

        if (cin.fail() || (res != 1 && res != 2))
            failInput(res);
    }
}

/**
 * @brief  function to print the welcome screen on for the user in the terminal 
 * @retval None
 */
void printWelcomeScreen()
{
    for (int i = 0; i <= 6; i++)
    {
        if (i == 0 || i == 6)
        {
            // length 50
            cout << "**************************************************" << endl;
        }
        else if (i == 2)
        { // first line length 39 Gauntlet
            cout << "*   Welcome to the Football Guessing Gauntlet!   *" << endl;
            cout << "*             by Peter Ling                      *" << endl;
        }
        else
        {
            cout << "*                                                *" << endl;
        }
    }
}

/**
 * @brief  function to print out the score for the user 
 * @note   
 * @param  score: the user's score 
 * @retval None
 */
void printScoreScreen(int score)
{
    for (int i = 0; i <= 4; i++)
    {
        if (i == 0 || i == 4)
        { // top or bottom LENGTH 30
            cout << "**********************************" << endl;
        }
        else if (i == 2)
        {
            if (score >= 100)
            {
                cout << "*      Points Remaining: " << score << "     *" << endl;
            }
            else if (score >= 10)
            {
                cout << "*      Points Remaining: " << score << "      *" << endl;
            }
            else
            {
                cout << "*      Points Remaining: " << score << "       *" << endl;
            }
        }
        else
        {
            cout << "*                                *" << endl;
        }
    }
}

void printFinalPlayersGuessed(int numPlayersGuessed)
{

    for (int i = 0; i <= 5; i++)
    {
        if (i == 0 || i == 5)
        { // top or bottom // 40 stars
            cout << "**************************************************" << endl;
        } else if (i == 2){
            cout << "*        Game over. Thank you for playing!       *" << endl; 
        }
        else if (i == 3)
        {

            if (numPlayersGuessed >= 100)
            { // 36
                cout << "*     Unbeleivable! You guessed " << numPlayersGuessed << " Players!     *" << endl;
            }
            else if (numPlayersGuessed == 0)
            {
                cout << "*  You failed to guess any players. Try again    *" << endl;
            }

            else if (numPlayersGuessed >= 10)
            {
                cout << "*   Amazing job! You guessed " << numPlayersGuessed << " Players!  *" << endl;
            }
            else
            {
                cout << "*        Great job! You guessed " << numPlayersGuessed << " Players!       *" << endl;
            }
        }
        else
        {
            cout << "*                                                *" << endl;
        }
    }
}

/**
 * @brief  function to print out the screen that thanks the user for playing the game 
 * @retval None
 */
void printEndingScreen()
{
    cout << endl;
    cout << endl;
    for (int i = 0; i <= 4; i++)
    {
        if (i == 0 || i == 4)
        {
            cout << "*******************************" << endl;
        }
        else if (i == 2)
        {
            cout << "*     Thanks for playing!     *" << endl;
        }
        else
        {
            cout << "*                             *" << endl;
        }
    }
}

/**
 * @brief  Function to return the hint that the user asks for 
 * @param  randPlayer: the player that the user is trying to guess 
 * @param  input: the number response by the user signaling which hint they want 
 * @retval returns the desired hint to the user 
 */

string hintToPlayerStruct(Player randPlayer, int input)
{

    switch (input)
    {
    case 0:
        return randPlayer.name;

    case 1:
        return randPlayer.team;

    case 2:
        return randPlayer.college;

    case 3:
        return randPlayer.position;

    case 4:
        return randPlayer.jerseyNumber;

    case 5:
        return randPlayer.division;

    case 6:
        return randPlayer.passingTouchdowns2020;

    case 7:
        return randPlayer.receivingTouchdowns2020;

    case 8:
        return randPlayer.rushingTouchdowns2020;
        
    case 9: 
        return randPlayer.proBowls;

    default:
        return "Not a valid hint. Try again.";
    }

    return "Not a valid hint. Try again.";
}

vector<Player> qbList = {

// string name;
// string team;
// string college;
// string position;
// string jerseyNumber;
// string divison;
// string passingTouchdowns2020;
// string receivingTouchdowns2020;
// string rushingTouchdowns2020;
// string proBowls;
    {"Aaron Rodgers", "Packers", "California", "QB", "12", "NFC North", "48 (1st in NFL)", "0", "3 (T51st in NFL)", "9"},
    {"Tom Brady", "Bucaneers", "Michigan", "QB", "12", "NFC South", "40 (2nd in NFL)", "0", "3 (T51st in NFL)", "14"},
    {"Deshaun Watson", "Texans", "Clemson", "QB", "4", "AFC South", "33 (8th in NFL)", "0", "3 (T51st in NFL)", "3"},
    {"Patrick Mahomes", "Chiefs", "Texas Tech", "QB", "15", "AFC West", "38 (4th in NFL)", "0", "2 (T70th in NFL)", "3"},
    {"Josh Allen", "Bills", "Wyoming", "QB", "17", "AFC East", "37 (5th in NFL)", "0", "3 (T51st in NFL)", "0"},
    {"Russell Wilson", "Seahawks", "Wisconsin", "QB", "3", "NFC West", "40 (3rd in NFL)", "0", "2 (T70th in NFL)", "7"},
    {"Kyler Murray", "Cardinals", "Oklahoma", "QB", "1", "NFC West", "26 (13th in NFL)", "0", "11 (T8th in NFL)", "1"},
    {"Kirk Cousins", "Vikings", "Michigan State", "QB", "8", "NFC North", "35 (6th in NFL)", "0", "1 (T102nd in NFL)", "2"},
    {"Ryan Tannehill", "Titans", "Texas A&M", "QB", "17", "AFC South", "33 (9th in NFL)", "0", "7 (T24th in NFL)", "1"},
    {"Lamar Jackson", "Ravens", "Louisville", "QB", "8", "AFC North", "26 (16th in NFL)", "0", "7 (T19th in NFL)", "1"},
    {"Carson Wentz", "Colts", "North Dakota State", "QB", "2", "AFC South", "16 (21st in NFL)", "0", "5 (T34th in NFL)", "1"},
    {"Justin Herbert", "Chargers", "Oregon", "QB", "10", "AFC West", "31 (10th in NFL)", "0", "5 (T34th in NFL)", "0"},
    {"Matthew Stafford", "Rams", "Georgia", "QB", "9", "NFC West", "26 (14th in NFL)", "0", "0", "1"},
    {"Derek Carr", "Raiders", "Fresno State", "QB", "3", "AFC West", "27 (11th in NFL)", "0", "3 (T51st in NFL)", "3"},
    {"Dak Prescott", "Cowboys", "Mississippi State", "QB", "4", "NFC North", "9 (33rd in NFL)", "1", "3 (T51st in NFL)", "2"}

};

vector<Player> skillposList = {
    {"Devante Adams", "Packers", "Fresno State", "WR", "17", "NFC North", "0", "18 (1st in NFL)", "0", "4"},
    {"Tyreek Hill", "Cheifs", "Oklahoma State", "WR", "10", "AFC West", "0", "15 (2nd in NFL", "2 (T70 in NFL)", "5"},
    {"Stefon Diggs", "Bills", "Maryland", "WR", "14", "AFC East", "0", "8 (T15 in NFL)", "0", "1"},
    {"Adam Thielen", "Vikings", "Minnesota State", "WR", "19", "NFC North", "0", "14 (3rd in NFL)", "0", "2"},
    {"Mike Evans", "Bucaneers", "Texas A&M", "WR", "13", "NFC South", "0", "13 (4th in NFL)", "0", "3"},
    {"Julio Jones", "Falcons", "Alabama", "WR", "11", "NFC South", "0", "3 (T87th in NFL)", "0", "7"},
    {"D.K. Metcalf", "Seahawks", "Mississippi", "WR", "14", "NFC West", "0", "10 (T8 in NFL)", "0", "1"},
    {"Calvin Ridley", "Falcons", "Alabama", "WR", "18", "NFC South", "0", "9 (T10th in NFL)", "0", "7"},
    {"Juju Smith-Schuster", "Steelers", "USC", "WR", "19", "AFC North", "0", "9 (T10th in NFL)", "0", "0"},
    {"DeAndre Hopkins", "Cardinals", "Clemson", "WR", "10", "NFC West", "0", "6 (T29th in NFL)", "0", "5"},

};

// TODO: Create vectors of players for other positions and add those to the playerList

 vector<Player> playerList = qbList;

string instructions[] = {
    "Welcome to the guessing game! ",
    "",
    "",
    "The goal here is to guess as many players as you can before you run out of points!" ,
    "When you start, you will be able to ask the computer for hints.", 
    "Each hint will cost a certain amount of points.",
    "When you guess a player correctly, you will be prompted to guess a new player with your remaining amount of points.",
    "Best of luck, and have fun!"

};

// first map: struct hint with value, second one is the value

// map of struct memeber, value of hint

struct HintValuePair
{
    string hintName;
    int hintValue;
};

// string name;
// string team;
// string college;
// string position;
// string jerseyNumber;
// string divison;
// string passingTouchdowns2020;
// string receivingTouchdowns2020;
// string rushingTouchdowns2020;
// string proBowls;
// Vector of the hint and how many points it should be worth when the user asks for it

vector<HintValuePair> hintValues = {
    {"Player Name", 75},
    {"Team", 50},
    {"College", 40},
    {"Position", 20},
    {"Jersey Number", 20},
    {"Divison", 15},
    {"Passing TDs in 2020", 10},
    {"Receiving TDs in 2020", 10},
    {"Rushing TDs in 2020", 10},
    {"Pro Bowl Appearences", 5}

};

map<int, HintValuePair> sortedPairValues;

/**
 * @brief  hintValues is in order from highest point value to lowest. This function puts those values 
 * in a map that directly puts htem
 * @note   
 * @param  hintValues: 
 * @param  &sortedPairValues: 
 * @retval None
 */
void fillHintValuePairs(vector<HintValuePair> hintValues, map<int, HintValuePair> &sortedPairValues)
{

    for (int i = 0; i < hintValues.size(); i++)
    {
        sortedPairValues[i] = hintValues[i];
    }
};

/**
 * @brief  function that prints out each hint and its point value for the user 
 * @param  sortedPairValues: 
 * @retval None
 */
void printHints(map<int, HintValuePair> sortedPairValues)
{

    for (int i = 0; i < sortedPairValues.size(); i++)
    {
        string hintName = sortedPairValues[i].hintName;
        int pointsCost = sortedPairValues[i].hintValue;

        cout << '[' << i << "]: " << hintName + "–" << " Points Cost: " << pointsCost << endl;
    }
};

// void printHints(vector<HintValuePair> hintValues)
// {

//     for (int i = 0; i < hintValues.size(); i++)
//     {
//         string hintName = hintValues[i].hintName;
//         int pointsCost = hintValues[i].hintValue;

//         cout << '[' << i << "]: " << hintName + "–"
//              << " Points Cost: " << pointsCost << endl;
//     }
// };
