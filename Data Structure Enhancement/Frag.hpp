#pragma once
#include<iostream>
using namespace std;
// define a structure to hold bid information
struct Frag {
    string Brand;
    string Name; //Unique Identifier
    string Price;
    Frag() {
        amount = 0.0;
    }
};