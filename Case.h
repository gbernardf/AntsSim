#ifndef CASE_H
#define CASE_H

class Case
{
public:
    Case();
    bool isFood();
    bool isColony();
    bool isWall();
    int getPheromoneFoodLevel();
    int getPheromoneTravelLevel();
    void setPheromoneFoodLevel(int level);
    void setPheromoneTravelLevel(int pheromoneTravelLevel);
    void setFood(bool food);
    void setColony(bool colony);
    void setWall(bool wall);

private:
    int pheromoneFoodLevel;
    int pheromoneTravelLevel;
    bool food;
    bool colony;
    bool wall;
};

#endif // CASE_H
