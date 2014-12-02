#ifndef CASE_H
#define CASE_H

class Case
{
public:
    Case();
    bool isFood();
    bool isColony();
    int getPheromoneFoodLevel();
    int getPheromoneTravelLevel();
    void setPheromoneFoodLevel(int level);
    void setPheromoneTravelLevel(int pheromoneTravelLevel);
    void setFood(bool food);
    void setColony(bool colony);

private:
    int pheromoneFoodLevel;
    int pheromoneTravelLevel;
    bool food;
    bool colony;
};

#endif // CASE_H
