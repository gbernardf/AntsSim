#ifndef DIRECTION_H
#define DIRECTION_H

class Direction
{
public:
    Direction(int x, int y);
    int getX();
    int getY();
private:
    int dirX;
    int dirY;
};

#endif // DIRECTION_H
