#include <iostream>
#include <limits> 

using namespace std;
// c++ setup

//E = Empty plot, A = Accumulator, D = Drill, S = Squeezer
//Accumulator gives 10 beef
//Drill gives 15 salt
//Squeezer gives 10 fuel per 5 beef or 5 fuel per 5 jerky

bool win = false;
bool dayloop = true;
int beef;
int salt;
int jerky;
int fuel;
int day = 1;

char land[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void tutorial() 
{
  cout << "Hello user.\n";
  cout << "Welcome to Logan's Tycoon.\n";
  cout << "Type OK to continue. (Or anything really)\n";
  string userPut; 
  cin >> userPut;
  cout << "You find yourself crashlanded on MARS! Oh gosh! \nYour ship is intact but out of fuel.\n";
  cout << "You must utalize the land on this planet to amass fuel.\nWith enough fuel your ship can get back to Earth.\n";
  cout << "Type OK to continue.\n";
  cin >> userPut;
  cout << "The resources are Beef, Salt, Jerky, and Fuel.\n";
  cout << "Beef will spoil at the very end of the day.\n";
  cout << "Jerky will never spoil.\n";
  cout << "You need 200 Fuel to leave the planet.\n";
  cout << "Type OK to continue.\n";
  cin >> userPut;
  cout << "There are nine plots of land for you to build machines.\n";
  cout << "Each cost 10 salt.\n";
  cout << "Accumulators produce 5-10 Beef every day.\n";
  cout << "Drills produce 10-15 Salt every day.\n";
  cout << "Squeezers convert 5 Beef into 10 fuel every day.\n";
  cout << "Alternatively, Squeezers convert 5 Jerky into 8 fuel every day.\n";
  cout << "Type OK to continue.\n";
  cin >> userPut;
  cout << "Every day cycle you can do one of the following.\n";
  cout << "HUNT: Grants you 8 Beef and ends the day.\n";
  cout << "DIG: Grants you 12 Salt and ends the day.\n";
  cout << "PUMP: Grants you 4 Fuel and ends the day.\n";
  cout << "CURE: Applies Salt to Beef to create Jerky.\n";
  cout << "BUILD: Builds a machine on a specified plot of land.\n";
  cout << "Type OK to continue.\n";
  cin >> userPut;
}

void drawBoard() //Nested loop for each indices in 2d array
{
  cout << "-------------\n";
  for (int i = 0; i < 3; i++) 
  {
      cout << "| ";
      for (int j = 0; j < 3; j++) {
          cout << land[i][j] << " | ";
      }
      cout << "\n-------------\n";
  }
}

void cycle() //Updates all resources
{
  ++day;
  int vari = 0;
  for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) {
          if (land[i][j] == 'A')
          {
            vari = rand() % 5 + 5;
            beef += vari;
            cout << "\n+" << vari << " Beef";
          }
          if (land[i][j] == 'D')
          {
            vari = rand() % 5 + 10;
            salt += vari;
            cout << "\n+" << vari << " Salt";
            
          }
          if (land[i][j] == 'S')
          {
            if (beef >= 5)
            {
              beef -= 5;
              cout << "\n-5 Beef";
              fuel += 10;
              cout << "\n+10 Fuel";
            }
            else if (jerky >= 5)
            {
              jerky -= 5;
              cout << "\n-5 Jerky";
              fuel += 8;
              cout << "\n+8 Fuel";
            }
            
          }
        }
    }
}

int main() 
{
  string userPut; 
  tutorial();
  while (win == false)
  {
    while (dayloop == true)
    {
      cout << "\nIt is day: " << day << ".";
      cout << "\nYou have " << beef << " beef, " << salt << " salt, " << jerky << " jerky, and " << fuel << " fuel.\n";
      cout << "What would you like to do?\nHUNT\nDIG\nPUMP\nCURE\nBUILD\n";
      cin >> userPut;
      if (userPut == "HUNT")
      {
        cout << "\n+8 Beef!\n";
        beef += 8;
        dayloop = false;
      }
      if (userPut == "DIG")
        {
          cout << "\n+12 Salt!\n";
          salt += 12;
          dayloop = false;
        }
      if (userPut == "PUMP")
        {
          cout << "\n+4 Fuel!\n";
          fuel += 4;
          dayloop = false;
        }
      if (userPut == "CURE")
        {
          int applicableBeef = 0;
          if (beef >= salt)
          {
            applicableBeef = salt;
          }
          else
          {
            applicableBeef = beef;
          }
          if (applicableBeef == 0)
          {
            if (beef == 0)
            {
              cout << "\nYou have no Beef to cure!\n";
            }
            else
            {
              cout << "\nYou have no Salt to cure!\n";
            }
          }
          else
          {
            cout << "\n+" << applicableBeef << " Jerky!\n";
            jerky += applicableBeef;
            salt -= applicableBeef;
            beef -= applicableBeef;
          }
        }
      if (userPut == "BUILD")
        {
          if (salt >= 10)
          {
            drawBoard();
            cout << "\nWhere would you like to build?\n";
            cout << "Type 1 - 9;\n";
            char buildWhere;
            cin >> buildWhere;
            cout << "\nWhat would you like to build?\n";
            cout << "A = Accumulator\nD = Drill\nS = Squeezer\n";
            char buildWhat;
            cin >> buildWhat;
            for (int i = 0; i < 3; i++) 
              {
                  for (int j = 0; j < 3; j++) {
                    if (land[i][j] == buildWhere)
                    {
                      land[i][j] = buildWhat;
                      cout << "\nMachine built!\n";
                    } 
                  }
              }
          }
          else
          {
            cout << "\nYou need at least 10 Salt.\n";
          }
        }
    } //End of day loop
    if (fuel >= 200)
    {
      win = true;
    }
    else
    {
      userPut = "0";
      dayloop = true;
      cycle();
    }
  } //End game
  cout << "You've acculumated over 200 fuel! You get back into your spaceship and fly back home! Congratulations!\n";
  cout << "It took you " << day << " days to escape!";
  return 0;
}