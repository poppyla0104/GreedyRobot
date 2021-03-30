/*Poppy La
Program 2 GreedyRobot: Design a program that determines all the unique shortest possible paths from the robot to the treasure,
            Robot never move in the same direction more than MaxDistance times in a row.
*/


#include "MyPoint.h"
#include <iostream>
#include <cmath>

using namespace std;

MyPoint::MyPoint()
{
    x_=0;
    y_=0;
}

MyPoint::MyPoint(int x1, int y1)
{
    x_ = x1;
    y_ = y1;
}

MyPoint& MyPoint::GetPoint()
{
    return *this;
}

void MyPoint::SetX(int x1)
{
    x_ = x1;
}

void MyPoint::SetY(int y1)
{
    y_ = y1;
}

int MyPoint::GetX()
{
    return x_;
}

int MyPoint::GetY()
{
    return y_;
}

//calculate distant between 2 points
int MyPoint::CalculateDistant(MyPoint& other){
    return abs(other.GetX()-GetX()) + abs(other.GetY()-GetY()); 
}

bool MyPoint::MoveNorth() 
{
    y_++;
    return true;
}

bool MyPoint::MoveSouth()
{
    y_--;
    return true;
}

bool MyPoint::MoveEast()
{
    x_++;
    return true;
}

bool MyPoint::MoveWest()
{
    x_--;
    return true;
}


MyPoint MyPoint::operator+(const MyPoint &other) const
{
  MyPoint a;
  a.x_ = x_ + other.x_;
  a.y_ = y_ + other.y_;
  return a;
}

MyPoint MyPoint::operator-(const MyPoint &other) const
{
  MyPoint a;
  a.x_ = x_ + other.x_;
  a.y_ = y_ + other.y_;
  return a;
}

MyPoint& MyPoint::operator=(const MyPoint &other)
{
  x_ = other.x_;
  y_ = other.y_;
  return *this;
}

ostream& operator<<(ostream &outStream, const MyPoint &point)
{
  outStream << "(" << point.x_ << ", " << point.y_ << ")";
  return outStream;
}

//input then adjust the input value
istream& operator>>(istream &inStream, MyPoint &point)
{
  inStream >> point.x_ >> point.y_;
  return inStream;
}

MyPoint::~MyPoint(){};
