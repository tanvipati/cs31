#include "AppleProduct.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

namespace cs31 {
    
    AppleProduct::AppleProduct() // constructor with no parameters
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2); // This is because cost is always 2 decimal places
        
        mVersion = "";
        mColor = "";
        mKind = NOTSPECIFIED;
        mCost = 0.00;
    }
    
    AppleProduct::AppleProduct(Kind kind, string version, string color, double cost) // constructor with parameters
    {
        mKind = kind;
        mVersion = version;
        mColor = color;
        mCost = cost;
    }
    
    string AppleProduct::getVersion() const // gives the version entered in the parameters
    {
        return mVersion;
    }
    
    string AppleProduct::getColor() const // gives the color entered in the parameters
    {
        return mColor;
    }
    
    AppleProduct::Kind AppleProduct::getKind() const // gives the kind entered in the parameters
    {
        return mKind;
    }
    
    double AppleProduct::getCost() const // gives the cost entered in the parameters up to 2 decimal places
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        return mCost;
    }
}
