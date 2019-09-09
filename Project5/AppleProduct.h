// AppleProduct.h

#ifndef APPLEPROD_H
#define APPLEPROD_H

#include <iostream>
#include <string>

using namespace std;

namespace cs31 // making AppleProduct a part of namespace cs31
{
    class AppleProduct
    {
    public:
        enum Kind {NOTSPECIFIED, IPHONE, IPAD, WATCH};
        
        // constructors:
        
        AppleProduct(); // no parameters
        
        AppleProduct(Kind kind, string version, string color, double cost); // with parameters
        
        // modifiers:
        
        string getVersion() const;
        string getColor() const;
        Kind getKind() const;
        double getCost() const;
        
    private: // only AppleProduct can use the declarations below
        string mVersion;
        string mColor;
        Kind mKind;
        double mCost;
    };
}
#endif /* ifndef APPLEPROD_H */
