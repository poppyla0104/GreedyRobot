/*Poppy La
Instructor: Dr.Dimpsey
Course 342 B
Program 2 GreedyRobot: Design a program that determines all the unique shortest possible paths from the robot to the treasure,
            Robot never move in the same direction more than MaxDistance times in a row.
*/

#ifndef MyRobot_H
#define MyRobot_H

#include <iostream>
#include "MyPoint.h"

using namespace std;

class MyRobot: public MyPoint
{   
    public:
    MyRobot();
    MyRobot(int, int);
    ~MyRobot();

    void SetDistance(int); 
    int GetDistance();

//move the robot to 4 different directions
    MyRobot& MoveNorth();
    MyRobot& MoveSouth();
    MyRobot& MoveEast();
    MyRobot& MoveWest();

    MyRobot& operator=(MyRobot &other);

    private:
    int distance_;

};
#endif