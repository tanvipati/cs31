//  AppleStore.cpp

#include "AppleStore.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

namespace cs31 {
    
    AppleStore::AppleStore()
    {
        // empty but should exist
    }
    
    AppleProduct AppleStore::buyWatch1( string color )
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2); // cost up to 2 decimal places
        
        string versionOfWatch = "1";
        AppleProduct::Kind kind = AppleProduct::WATCH;
        double costOfWatch = 249.00;
        
        return AppleProduct(kind, versionOfWatch, color, costOfWatch);
    }
    
    AppleProduct AppleStore::buyWatch3(string color)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        string versionOfWatch = "3";
        AppleProduct::Kind kind = AppleProduct::WATCH;
        double costOfWatch = 329.00;
        
        return AppleProduct(kind, versionOfWatch, color, costOfWatch);
    }
    
    AppleProduct AppleStore::buyiPad(string color, int gigabytes)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        string versionOfiPad = "";
        AppleProduct::Kind kind = AppleProduct::IPAD;
        
        double costOfiPad = 0.00;
        if (gigabytes == 32)
        {
            costOfiPad = 329.00;
        }
        else if (gigabytes == 128)
        {
            costOfiPad = 429.00;
        }
        else // if the number of gigabytes is invalid, an error is thrown which is caught by main.cpp
        {
            logic_error error ("The number of gigabytes is invalid");
            throw (error);
        }
        return AppleProduct(kind, versionOfiPad, color, costOfiPad);
    }
    
    AppleProduct AppleStore::buyiPadPro(string color, int gigabytes)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        string versionOfiPad = "Pro";
        AppleProduct::Kind kind = AppleProduct::IPAD;
        
        double costOfiPad = 0.00;
        if (gigabytes == 64)
        {
            costOfiPad = 649.00;
        }
        else if (gigabytes == 256)
        {
            costOfiPad = 799.00;
        }
        else if (gigabytes == 512)
        {
            costOfiPad = 999.00;
        }
        else // if the number of gigabytes is invalid, an error is thrown which is caught by main.cpp
        {
            logic_error error ("The number of gigabytes is invalid");
            throw(error);
        }
        
        return AppleProduct(kind, versionOfiPad, color, costOfiPad);
    }
    
    AppleProduct AppleStore::buyiPhone8(string color, int gigabytes)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        string versionOfiPhone = "8";
        AppleProduct::Kind kind = AppleProduct::IPHONE;
        
        double costOfiPhone = 0.00;
        if (gigabytes == 64)
        {
            costOfiPhone = 699.00;
        }
        else if (gigabytes == 256)
        {
            costOfiPhone = 849.00;
        }
        else // if the number of gigabytes is invalid, an error is thrown which is caught by main.cpp
        {
            logic_error error ("The number of gigabytes is invalid");
            throw(error);
        }
        
        return AppleProduct(kind, versionOfiPhone, color, costOfiPhone);
    }
    
    AppleProduct AppleStore::buyiPhone8Plus(string color, int gigabytes)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        string versionOfiPhone = "8Plus";
        AppleProduct::Kind kind = AppleProduct::IPHONE;
        
        double costOfiPhone = 0.00;
        if (gigabytes == 64)
        {
            costOfiPhone = 799.00;
        }
        else if (gigabytes == 256)
        {
            costOfiPhone = 949.00;
        }
        else // if the number of gigabytes is invalid, an error is thrown which is caught by main.cpp
        {
            logic_error error ("The number of gigabytes is invalid");
            throw(error);
        }
        
        return AppleProduct(kind, versionOfiPhone, color, costOfiPhone);
    }
    
    AppleProduct AppleStore::buyiPhoneX(string color, int gigabytes)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        string versionOfiPhone = "X";
        AppleProduct::Kind kind = AppleProduct::IPHONE;
        
        double costOfiPhone = 0.00;
        if (gigabytes == 64)
        {
            costOfiPhone = 999.00;
        }
        else if (gigabytes == 256)
        {
            costOfiPhone = 1149.00;
        }
        else // if the number of gigabytes is invalid, an error is thrown which is caught by main.cpp
        {
            logic_error error ("The number of gigabytes is invalid");
            throw(error);
        }
        
        return AppleProduct(kind, versionOfiPhone, color, costOfiPhone);
    }
}
