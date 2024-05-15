#include <iostream>
#include "Game.h"
#include <vector>
int main()
{
    std::vector<float> v1;
    v1.insert(v1.begin(), 5);
    v1.insert(v1.begin(), 4);
    v1.insert(v1.begin(), 8);
    std::cout << v1.front();
}
