#include <iostream>
#include <cstdlib>  // library for clearing screen
#include "rlutil.h" // library for colors
#include <windows.h> // library for sound
#include <mmsystem.h> // library for sound

using namespace std;
using namespace rlutil;

const int rows=6;
const int cols=7;
int player=1;
int moveno;
char p1='+';
char p2='o';
bool Gameend= false;
char board[rows][cols];
int arrcols[7]={5,5,5,5,5,5,5};


void startboard(); //initializes the board with blanks
void view(); // displays the board
void play(); // Places counter on the board
void turn(int place, int &player); // switches turn to other player
void instructions(); // displays instructions
void names(string &first, string &second); // Takes players names

void checkhorizontal(int moveno, string FPlayer, string SPlayer); // checks horizontal win
void checkvertical(int moveno, string FPlayer, string SPlayer); // checks vertical win
bool check_draw(); // checks draw
void checkdiagright(string FPlayer, string SPlayer); // checks diagonal (/) win
void checkdiagleft(string FPlayer, string SPlayer); // checks diagonal (\) win


int main()
{
string FirstPlayer;
string SecondPlayer;
names(FirstPlayer,SecondPlayer);
system ("cls"); // clears screen
instructions();
startboard();
view();

while (Gameend==false)
{
play();

bool Gdraw= check_draw();
if (Gdraw==true)
{
    cout<< "----GAME IS A DRAW---"<<endl;
    //PlaySound(TEXT("buzzer.wav"),NULL,SND_SYNC);
    break;
}

checkhorizontal(moveno, FirstPlayer, SecondPlayer);

if (Gameend==true)
{
    cout<<"----GAME HAS ENDED----";
    break;}

checkvertical(moveno, FirstPlayer, SecondPlayer);

if (Gameend==true)
{
    cout<<"----GAME HAS ENDED----";
    break;}

checkdiagright(FirstPlayer, SecondPlayer);
if (Gameend==true)
{
    cout<<"----GAME HAS ENDED----";
    break;}

checkdiagleft(FirstPlayer, SecondPlayer);
if (Gameend==true)
{
    cout<<"----GAME HAS ENDED----";
    break;}

}


return 0;
}





void startboard()
{
    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<cols; c++)
        {
            board[r][c]='-';
        }
    }
return;
}
void view()
{
    cout<< "0  1  2  3  4  5  6"<<endl<<endl;
    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<cols; c++)
        {
            if (board[r][c]=='-')
            {
                setColor(15); //white
                cout<<board[r][c]<<"  ";
            }
            else if (board[r][c]==p1)
            {
                setColor(14); //yellow
                cout<<board[r][c]<<"  ";
            }
            else if (board[r][c]==p2)
            {
                setColor(13); //purple
                cout<<board[r][c]<<"  ";
            }
        }
        cout<< endl;
        setColor(15); //white
    }
return;
}

void play()
{

cout<< "Player"<<player <<" enter a value between 0-6 OR 99 to Quit: ";
cin>> moveno;
  if (moveno==99)
      {Gameend= true; return;}
  else if(moveno>6 || moveno<0)
       {cout<< "---INVALID VALUE. Try again---"<<endl;
        play();
       }
  else
       {turn(moveno,player);
        return;
       }
}


  void turn(int place, int &player)
  {

      if (arrcols[place]<0)

      {
          cout<< "---This column is FULL---"<<endl;
          play();
      }
        else if (player==1)

      {
          board[arrcols[place]][place]= p1;
          arrcols[place]--;
          system("cls");
          view();

          player++;
          return;
      }
       else if (player==2)

      {
          board[arrcols[place]][place]=p2;
          arrcols[place]--;
          system("cls");
          view();

          player--;
          return;
      }
  }


  void names(string &first,string &second)
  {
      cout<< "Enter your Name"<<endl;
      cin>> first;
      cout<< first<< " you are player1"<<endl<<endl;

      cout<< "Enter your Name"<<endl;
      cin>> second;
      cout<< second<< " you are player2"<<endl<<endl;

      return;
  }





void instructions()
{

    cout<<" ----INSTRUCTIONS:---- \n 1) The board is a grid of 7 columns and 6 rows \n 2) Each Player will drop in one counter at a time. \n 3) Enter the column number to place counter in the lowest available row. \n 4) Connect four of your counters horizontally,vertically or diagonally to win \n 5) Stop your opponent from getting 4 in a row. \n 6) First player to get 4 in a row, WINS the game"<< endl<<endl<<endl ;
    return;
 }


void checkhorizontal(int moveno, string FPlayer, string SPlayer)
{
    for(int ch=0; ch<4; ch++)
    {

        if(board[arrcols[moveno]+1][ch]==p1 && board[arrcols[moveno]+1][ch+1]==p1 && board[arrcols[moveno]+1][ch+2]==p1 && board[arrcols[moveno]+1][ch+3]==p1)
            {

                cout<< "****CONGRATULATIONS "<< FPlayer<< " WINS THE GAME****"<<endl;
                //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
                Gameend= true;
            }


         else if(board[arrcols[moveno]+1][ch]==p2 && board[arrcols[moveno]+1][ch+1]==p2 && board[arrcols[moveno]+1][ch+2]==p2 && board[arrcols[moveno]+1][ch+3]==p2)
            {

                cout<< "****CONGRATULATIONS "<< SPlayer<< " WINS THE GAME****"<<endl;
                //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
                Gameend= true;
            }

    }
return;
}

void checkvertical(int moveno, string FPlayer, string SPlayer)

{
    for(int rch=0; rch<3; rch++)
    {

            if(board[rch][moveno]==p1 && board[rch+1][moveno]==p1 && board[rch+2][moveno]==p1 && board[rch+3][moveno]==p1)
             {

               cout<< "****CONGRATULATIONS "<< FPlayer<< " WINS THE GAME****"<<endl;
               //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
               Gameend= true;
            }


            else if(board[rch][moveno]==p2 && board[rch+1][moveno]==p2 && board[rch+2][moveno]==p2 && board[rch+3][moveno]==p2)
            {

                cout<< "****CONGRATULATIONS "<< SPlayer<< " WINS THE GAME****"<<endl;
                //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
                Gameend= true;
            }

    }

return;
}



void checkdiagright(string FPlayer, string SPlayer)
{
    for(int drr=3; drr<6; drr++)
    {
          for(int drc=0;drc<4;drc++)
          {
               if(board[drr][drc]==p1 && board[drr-1][drc+1]==p1 && board[drr-2][drc+2]==p1 && board[drr-3][drc+3]==p1)
               {

                cout<< "****CONGRATULATIONS "<< FPlayer<< " WINS THE GAME****"<<endl;
                //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
                Gameend= true;
                }


                else if(board[drr][drc]==p2 && board[drr-1][drc+1]==p2 && board[drr-2][drc+2]==p2 && board[drr-3][drc+3]==p2)
                {

                cout<< "****CONGRATULATIONS "<< SPlayer<< " WINS THE GAME****"<<endl;
                //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
                Gameend= true;
                 }

           }
    }
return;
}

void checkdiagleft(string FPlayer, string SPlayer)
{
    for(int drr=0; drr<3; drr++)
    {
          for(int drc=0;drc<4;drc++)
          {

               if(board[drr][drc]==p1 && board[drr+1][drc+1]==p1 && board[drr+2][drc+2]==p1 && board[drr+3][drc+3]==p1)
               {

                cout<< "****CONGRATULATIONS "<< FPlayer<< " WINS THE GAME****"<<endl;
                //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
                Gameend= true;
                }


                else if(board[drr][drc]==p2 && board[drr+1][drc+1]==p2 && board[drr+2][drc+2]==p2 && board[drr+3][drc+3]==p2)
                {

                cout<< "****CONGRATULATIONS "<< SPlayer<< " WINS THE GAME****"<<endl;
                //PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);
                Gameend= true;
                 }

           }
    }
return;
}


bool check_draw()
{
bool Gamedraw=true;
    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<cols; c++)
        {
           if (board[r][c]=='-')
           {
               Gamedraw= false;
               return Gamedraw;
           }
        }
    }
}
