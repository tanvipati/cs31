// AppleStore.h

#ifndef APPLE_STORE_H
#define APPLE_STORE_H

#include <iostream>
#include <string>
#include "AppleProduct.h"

using namespace std;

namespace cs31 {
    
    class AppleStore {
        
    public:
        
        // constructor - no parameters as AppleStore uses AppleProduct
        AppleStore();
        
        // modifiers
        AppleProduct buyWatch1(string color);
        AppleProduct buyWatch3(string color);
        
        AppleProduct buyiPad(string color, int gigabytes);
        AppleProduct buyiPadPro(string color, int gigabytes);
        
        AppleProduct buyiPhoneX(string color, int gigabytes);
        AppleProduct buyiPhone8(string color, int gigabytes);
        AppleProduct buyiPhone8Plus(string color, int gigabytes);
        
    };
    
}



#endif /* APPLE_STORE_H */
