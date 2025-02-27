#pragma once
#include<iostream>
using namespace std;
// define a structure to hold bid information
struct Frag {
    string fragBrand;
    string fragName; //Unique Identifier
    double fragPrice;
    Frag() {
        fragPrice = 0.0;
    }
};