/*Poppy La

GreedyRobot: Design a program that determines all the unique shortest possible paths from the robot to the treasure,
            Robot never move in the same direction more than MaxDistance times in a row.
*/

#ifndef MYPOINT_H
#define MYPOINT_H

#include <iostream>

using namespace std;

class MyPoint
{
    public:

    MyPoint();
    MyPoint(int, int);
    ~MyPoint();

    void SetX(int);
    void SetY(int);
    int CalculateDistant(MyPoint&);
    int GetX();
    int GetY();
    MyPoint& GetPoint();

//move the point to different directions
    bool MoveNorth();
    bool MoveSouth();
    bool MoveEast();
    bool MoveWest();

    MyPoint operator+(const MyPoint &point) const;
    MyPoint operator-(const MyPoint &point) const;
    
    MyPoint& operator=(const MyPoint &point);

    friend ostream& operator<<(ostream &outStream, const MyPoint &point);
    friend istream& operator>>(istream &inStream, MyPoint &point);

    private:
    int x_,y_;

};
#endif
