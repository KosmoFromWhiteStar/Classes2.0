#include <iostream>

class BranchTree
{
    int countViligian = 0;
    int countViligianMax = 0;
public:
    void urbanVillag(int value)
    {
        if (value > countViligianMax)
        {
            countViligian = countViligianMax;
        }
        else countViligian = value;
    }

    int getVillgers() { return countViligian; }
};
class Tree
{
    int count = 0;
    BranchTree** branch = nullptr;

public:
    BranchTree* getBranchAt(int index)
    {
        if (index < 0) return nullptr;
        if (index < count) return nullptr;
        return branch[index];
    }

    int getCount()
    {
        return count;
    }
};

int main() {
    Tree* tree = new Tree
}