#include <iostream>
#include <cmath>
#include <windows.h>
#include <conio.h>
using namespace std;
void mathlevel1(int difficulty)
{
    int i,answer,nrvar,result,retry;
    result=0;
    switch(difficulty)
        {
        case(1):
            {
               nrvar=2;
               break;
            }
        case(2):
            {
               nrvar=4;
               break;
            }
        case(3):
            {
               nrvar=6;
               break;
            }
        case(4):
            {
                nrvar=8;
                break;
            }
        case(5):
            {
                nrvar=18;
                break;
            }
        }
  // 3 steps : Creation, Output and Resolvation. First an exercise is made, then it's shown, then it's solved by both the user and the program,
 // if they both have the same result, the user wins
 int exercise[20];
 for(i=1;i<=nrvar+1;i++)
 {
   if(i%2==1)
   exercise[i]=rand()%100;
   else exercise[i]=rand()%2;
 }
   for(i=1;i<=nrvar+1;i++)
   {
     if(i%2==1)
        cout<<exercise[i];
     else if(exercise[i]==1)
        cout<<"+";
     else cout<<"-";
   }
   cout<<"=";
   cin>>answer;
   for(i=1;i<=nrvar+1;i++)
   {
    if(i<=3)
    {
        if(i%2==0)
        {
        if(exercise[i]==1)
            result=exercise[i-1]+exercise[i+1];
        else result=exercise[i-1]+exercise[i+1];
        }
    }
     if(i%2==0&&i>3)
     {
        if(exercise[i]==1)
            result=result+exercise[i+1];
        else result=result-exercise[i+1];
     }
   }
   cout<<"The result was:"<<result<<endl<<endl;
   if(answer==result)
    cout<<"Congratulations, you did it right! "<<endl<<endl;
   else cout<<"Wrong answer. . ."<<endl<<endl;
   cout<<"Would you like to play this level again?"<<endl<<endl;
   // Sleep(500);
   cout<<"[1] Yes"<<endl;
   // Sleep(500);
   cout<<"[2] No"<<endl;
   cin>>retry;
   if(retry==1)
    mathlevel1(difficulty);
   else cout<<"Returning to main menu"<<endl;
    Sleep(500);
    system("cls");
 }
void mathlevel2(int difficulty)
{

}
void mathlevel3(int difficulty)
{

}
int main()
{
    /*
        black=0,
		dark_blue=1,
		dark_green=2,
		dark_aqua,dark_cyan=3,
		dark_red=4,
		dark_purple=5,dark_pink=5,dark_magenta=5,
		dark_yellow=6,
		dark_white=7,
		gray=8,
		blue=9,
		green=10,
		aqua=11,cyan=11,
		red=12,
		purple=13,pink=13,magenta=13,
		yellow=14,
		white=15
		*/
    bool ProgramRunning=true;
    int col=0,exercise,difficulty;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, 15);
    while(ProgramRunning==true)
        {
            cout<<"Select what math skill you want to work on:"<<endl<<endl;
           // Sleep(1500);
            SetConsoleTextAttribute(hConsole, 9);
            cout<<"[1] Addition and subtraction"<<endl;
           // Sleep(500);
            SetConsoleTextAttribute(hConsole, 2);
            cout<<"[2] Multiplication and division"<<endl;
          //  Sleep(500);
            SetConsoleTextAttribute(hConsole, 4);
            cout<<"[3] Percentages"<<endl<<endl;
          //  Sleep(500);
            SetConsoleTextAttribute(hConsole, 5);
            cout<<"[4] Exit the program"<<endl;
            cin>>exercise;
            switch(exercise)
            {
            case(1):
                {
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"You have chosen the Addition and subtraction exercise. Select a difficulty:"<<endl;
               //     Sleep(2000);
                    SetConsoleTextAttribute(hConsole, 10);
                    cout<<"[1] Easy: 2 variables"<<endl;
                 //   Sleep(500);
                    SetConsoleTextAttribute(hConsole, 11);
                    cout<<"[2] Novice: 3 variables"<<endl;
                 //   Sleep(500);
                    SetConsoleTextAttribute(hConsole, 9);
                    cout<<"[3] Medium: 4 variables"<<endl;
                 //   Sleep(500);
                    SetConsoleTextAttribute(hConsole, 14);
                    cout<<"[4] Advanced: 5 variables"<<endl;
            //        Sleep(500);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"[5] Expert: 10 variables"<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    cin>>difficulty;
                    if(difficulty!=1&&difficulty!=2&&difficulty!=3&&difficulty!=4&&difficulty!=5)
                        break;
                    else
                    mathlevel1(difficulty);
                    break;
                }
            case(2):
                {
                    if(difficulty!=1&&difficulty!=2&&difficulty!=3&&difficulty!=4&&difficulty!=5)
                        break;
                    else
                    mathlevel2(difficulty);
                    break;
                }
            case(3):
                {
                  if(difficulty!=1&&difficulty!=2&&difficulty!=3&&difficulty!=4&&difficulty!=5)
                        break;
                  else
                  mathlevel3(difficulty);
                  break;
                }
            case(4):
                {
                  SetConsoleTextAttribute(hConsole, 15);
                  ProgramRunning=false;
                  break;
                }
            }

        }
    cout<<"Program has ended successfully";
    return 0;
}
