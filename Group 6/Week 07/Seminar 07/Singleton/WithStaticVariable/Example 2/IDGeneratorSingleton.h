#pragma once
#include <iostream>
using namespace std;
class IDGeneratorSingleton {
    int nextID=1;

    IDGeneratorSingleton();

    IDGeneratorSingleton(const IDGeneratorSingleton&) = delete;
    IDGeneratorSingleton& operator=(const IDGeneratorSingleton&) = delete;

public:
    
    static IDGeneratorSingleton& getInstance();

    int generate();
    void print() const;
    int getId() const;
};