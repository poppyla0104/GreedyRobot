/*Poppy La

GreedyRobot: Design a program that determines all the unique shortest possible paths from the robot to the treasure,
            Robot never move in the same direction more than MaxDistance times in a row.
*/


#include <iostream>
#include "MyRobot.h"

using namespace std;


MyRobot::MyRobot() : MyPoint()
{
    SetX(0);
    SetY(0);
}

MyRobot::MyRobot(int x1, int y1) : MyPoint(x1,y1)
{
    SetX(x1);
    SetY(y1);
}


void MyRobot::SetDistance(int n)
{
    distance_ = n;
}

int MyRobot::GetDistance()
{
    return distance_;
}


//move robot point, then return the robot with a new point
MyRobot& MyRobot::MoveNorth() 
{
    MyPoint::MoveNorth();
    return *this;
}

MyRobot& MyRobot::MoveSouth()
{
    MyPoint::MoveSouth();
    return *this;
}

MyRobot& MyRobot::MoveEast()
{
    MyPoint::MoveEast();
    return *this;
}

MyRobot& MyRobot::MoveWest()
{
    MyPoint::MoveWest();
    return *this;
}


MyRobot& MyRobot::operator=(MyRobot &other)
{
  SetX(other.GetX());
  SetY(other.GetY());
  return *this;
}


MyRobot::~MyRobot(){};
