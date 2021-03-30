
#include "MyRobot.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool totalPath(MyRobot& robot, MyPoint& treasure, int shortest, int& paths, string s, int max,int count);

void RunTotalPath(MyRobot& robot, MyPoint& treasure, int shortest, int max);

void Movement(MyPoint& copyRobot, MyPoint& treasure, char ch, bool MoveDirection, int shortest,int& path, string s,int max, int count);


int main(int argc, char* argv[])
{
     if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL || argv[5] == NULL)
    {
        cout<<"Please input 5 a number!"<<endl;
    } 
    else 
    {
        if (argc > 6)
        {
            cout<< "Only 5 number count."<<endl;
        }

        MyRobot my_robot(stoi(argv[1]),stoi(argv[2]));
        MyPoint treasure(stoi(argv[3]), stoi(argv[4]));
        int max = stoi(argv[5]);

        int shortest_distance = my_robot.CalculateDistant(treasure);

        RunTotalPath(my_robot,treasure,shortest_distance,max);
    }
}


//recursive function that counts unique shortest possible paths from the robot to treasure
//and print them out
bool totalPath(MyRobot& robot, MyPoint& treasure, int shortest, int& paths, string s, int max,int count)
{
    if (robot.CalculateDistant(treasure)==0 && shortest == 0 && count <=max )
    {
        //robot and treasure at the same position
        if(paths == 0 && s == "")
        {
            return true;
        }
        else 
        {
        cout<<s<<endl;
        paths++;
        return true;
        }
    }
    else
    {
        MyPoint copyRobot = robot.GetPoint();
        Movement(copyRobot, treasure, 'N', copyRobot.MoveNorth(), shortest,paths, s, max,count);

        copyRobot = robot.GetPoint();
        Movement(copyRobot, treasure, 'S', copyRobot.MoveSouth(), shortest,paths,s, max,count);

        copyRobot = robot.GetPoint();
        Movement(copyRobot, treasure, 'E', copyRobot.MoveEast(), shortest,paths, s,max,count);
        
        copyRobot = robot.GetPoint();
        Movement(copyRobot, treasure, 'W', copyRobot.MoveWest(), shortest,paths,s ,max,count);
    }

    return true;
}

//function includes recursive function which move robot to different direction 
void Movement(MyPoint& copyRobot, MyPoint& treasure, char ch, bool MoveDirection, int shortest,int& path, string s,int max, int count)
{
   if (MoveDirection && (copyRobot.CalculateDistant(treasure) < shortest) && count <= max)
        {
            MyRobot tempBot (copyRobot.GetX(),copyRobot.GetY());
            int n = count;

            //compare character ch with the previous character in s string
            //count if they are the same
            if(s.size() >0 && s.at(s.size()-1)==ch)
            {
                n++;
            }
            else 
            {
                n = 1;
            }
            totalPath(tempBot,treasure,shortest-1,path,s+ch,max,n);
        } 
}


//fuction includes recursive function and print the number of path
void RunTotalPath(MyRobot& robot, MyPoint& treasure, int shortest, int max)
{
    int count = 1;
    int path=0;
    string s ="";
    totalPath(robot,treasure,shortest,path,s,max,count);
    cout<<"Number of path: "<<path<<endl;
}
