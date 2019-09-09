// CS 31 - Project 3
// Tanvi Pati - 104901736

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

bool isValidEbayListingString(string auctionstring);
bool listingSold(string auctionstring);
int howMuch(string auctionstring);
int watchers(string auctionstring);
int getVal(string auctionstring, int & i);

int main()
{
    string s = "l10WwB11b+9U";
    string s1 = "L20.0WWB11B+4B+7U";
    string s2 = "";
    string s3 = "L0020";
    string s4 = "L20B10B+05";
    string s5 = "L20B10UB+5W";
    string s6 = "L20B10WB+5B+10UUU";
    string s7 = "L20B10WB+5WB+10UUB3";
    string s8 = "L20 B10 W B 5 WB+1 0UU B+3";
    string s9 = "Wl20B10UB+5W";
    string s10 = "L100L50";
    
    assert(isValidEbayListingString(s) == true);
    assert(listingSold(s) == true);
    assert(howMuch(s) == 20);
    assert(watchers(s) == 1);
    assert(isValidEbayListingString(s1) == false); // same result for s2, s3, s4, s5, s6, s7, s8, s9, s10
    assert(listingSold(s1) == false); // same result for s2, s3, s4, s5, s6, s7, s8, s9, s10
    assert(howMuch(s1) == -1); // same result for s2, s3, s4, s5, s6, s7, s8, s9, s10
    assert(watchers(s1) == -1); // same result for s2, s3, s4, s5, s6, s7, s8, s9, s10
    
    cerr << "All tests passed!" << endl;
    
    return (0);
}





bool isValidEbayListingString(string auctionstring) // checks if the listing string is valid
{
    bool isValid = true; // boolean to return after checking all conditions
    int numBids = 0; // int value to keep track of the number of bids
    int numWatchers = 0; // int value to keep track of the number of watchers
    if (auctionstring == "")
    {
        isValid = false;
    }
    for (int i = 0; i < auctionstring.size(); i++) // loop over the string to check conditions for each character
    {
        char c = auctionstring[i]; // character at the index i
        char d = auctionstring[i + 1]; // character following c
        char e = auctionstring[i - 1]; // character preceding c
        char f = auctionstring[i + 2]; // character 2 places ahead of c
        
        if (i == 0) // checks if the first character is 'L' or 'l'
        {
            if (c == 'L' or c == 'l')
            {
                if (isdigit(d) and d != '0') // checks if there is a leading zero
                {
                    isValid = true;
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else
            {
                isValid = false;
                break;
            }
        }
        else if (i > 0) // checks conditions for the second character till the end
        {
            /* if (c == 'L' or c == 'l')
            {
                isValid = false;
                break;
            } */
            if (c == 'B' or c == 'b')
            {
                numBids += 1; // increment number of bids
                if (numBids == 1 && isdigit(d) && d != '0') // only the first bid has a digit character following it
                {
                    isValid = true;
                }
                else if (numBids > 1 && d == '+' && isdigit(f) && f != '0' ) // all other bids are followed by '+'
                {
                    isValid = true;
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if (c == '+')
            {
                if (numBids > 1 && (e == 'b' || e == 'B') && isdigit(d) && d != '0') // c can be '+' only after the first bid
                {
                    isValid = true;
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if (c == 'W' or c == 'w')
            {
                 numWatchers++; // increment number of watchers
                if (numWatchers >= 0) // number of watchers can only be greater than 0
                {
                    isValid = true;
                }
            }
            else if (c == 'U' or c == 'u')
            {
                numWatchers--; // decrement number of watchers
                if (numWatchers >= 0) // there can only be an unwatcher if there was initially a watcher
                {
                    isValid = true;
                }
                else if (numWatchers < 0)
                {
                    isValid = false;
                    break;
                }
            }
            else if (c == ' ') // spaces make a string invalid
            {
                isValid = false;
                break;
            }
            else if (isdigit(c))
            {
                if (e != '.' && d != '.') // string can't have decimal numbers so check if it is followed or preceded by a decimal point
                {
                    isValid = true;
                }
            }
            else
            {
                isValid = false;
                break;
            }
        }
    }
    return isValid;
}





bool listingSold(string auctionstring) // checks if the listing sold or not
{
    bool sold = false; // boolean expression to return after all conditions are checked
    int listPrice = 0; // declaration and initialization of list price
    int bidPrice = 0; // declaration and initialization of bid price
    size_t length = auctionstring.size(); // length of the string
    
    if (isValidEbayListingString(auctionstring))
    {
        for (int index = 0; index < length; index++) // loop over the string to find 'L', 'l', 'B' or 'b'
        {
            int index1 = index + 1;
            int index2 = index1 + 1;
            char c = auctionstring[index]; // character at index
            char d = auctionstring[index1]; // character at index1
            if (c == 'L' || c == 'l')
            {
                listPrice += getVal(auctionstring, index1); // converts the value of characters following 'L' or 'l' by calling the getVal function until the character is not a digit; index1 gets updated to the new index at which the list price ends
            }
            else if (c == 'B' || c == 'b')
            {
                if (isdigit(d)) // gets value of first bid
                {
                    bidPrice += getVal(auctionstring, index1); // digit characters following 'B' or 'b' get converted to a number by calling the getVal function and update bidPrice; index1 gets updated to new index after all the digit characters
                }
                else if (d == '+') // gets value of following bids
                {
                    bidPrice += getVal(auctionstring, index2); // digit characters following '+' get converted to a number by calling the getVal function and update bidPrice; index2 gets updated to the new index after all the digit characters
                }
                else // take no action if there is any other character following 'B' or 'b'
                {
                    
                }
            }
            else // take no action if there is a character other than 'L', 'l', 'B' or 'b'
            {
                
            }
        }

        if (bidPrice > listPrice)
        {
            sold = true;
        }
        else
        {
            sold = false;
        }
    }
    else // if string is invalid
    {
        sold = false;
    }
    return sold;
}





int howMuch(string auctionstring)
{
    int bidPrice = 0; // declare and initialize bidPrice
    size_t length = auctionstring.size(); // length of the string
    
    if (isValidEbayListingString(auctionstring) && listingSold(auctionstring)) // if string is valid and the listing sold
    {
        for (int index = 0; index < length; index++) // loop over string to search for 'B' or 'b'
        {
            int index1 = index + 1;
            int index2 = index1 + 1;
            char c = auctionstring[index]; // character at index
            char d = auctionstring[index1]; // character following index
            
            if (c == 'B' || c == 'b')
            {
                if (isdigit(d))
                {
                    bidPrice += getVal(auctionstring, index1); // update bidPrice to value of first bid
                }
                else if (d == '+') // update bidPrice to values of following bids
                {
                    bidPrice += getVal(auctionstring, index2);
                }
                else // take no action if d is not a digit or '+'
                {
                    
                }
            }
            else // take no action if c is not 'B' or 'b'
            {
                
            }
        }
    }
    else if (isValidEbayListingString(auctionstring) && !(listingSold(auctionstring))) // if string is valid but listing didn't sell
    {
        bidPrice = 0;
    }
    else // if string is invalid
    {
        bidPrice = -1;
    }
    return (bidPrice);
}





int watchers(string auctionstring) // counts the number of watchers
{
    int numWatchers = 0; // declare and initialize int value to return after counting the number of watchers
    if (isValidEbayListingString(auctionstring)) // if string is valid
    {
        for (int i(0); i < auctionstring.size(); i++) // loop over string to find 'W', 'w', 'U' or 'u'
        {
            if (auctionstring[i] == 'W' or auctionstring[i] == 'w')
            {
                numWatchers++; // increment numWatchers
            }
            else if (auctionstring[i] == 'U' or auctionstring[i] == 'u')
            {
                numWatchers--; // decrement numWatchers
            }
            else // take no action if character is not 'W', ''w', 'U' or 'u'
            {
                
            }
        }
    }
    else // if string is invalid
    {
        numWatchers = -1;
    }
    return(numWatchers);
}





int getVal(string auctionstring, int & i) // converts string to number
{
    int result = 0; // declare and initialize value of the converted number
    if (auctionstring[i] >= '1' && auctionstring[i] <= '9') // doesn't allow leading zeroes
        {
            while (isdigit(auctionstring[i]) && auctionstring[i] >= 0)
            {
                result = (result * 10) + (auctionstring[i] - '0'); // converts character to number and adds it to number that result holds
                i++;
            }
        }
    return result;
}
