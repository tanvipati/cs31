// Project 4
// Tanvi Pati - UID: 104901736

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

int findMinimum( const string array[ ],int n );
int countAllPunctuation( const string array[ ], int n );
int countFloatingPointValues( const string array[ ],int   n );
int removeDuplicatedValues( string array[ ], int  n );
int replaceAll( string array1[ ], int n, char letterToReplace, char letterToFill );
int shiftRight( string array[ ], int n, int amount, string   placeholder );

int main ()
{
    string a[6] = {"beta", "gamma", "gamma", "alpha", "beta", "delta" };
    string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
    string c[3] = {"a", "b", "aa"};
    
    string data[ 4 ] = { "howard-", "ucla.", "howard", "ucla." };
    string punct[4] = { "h.", "i/", "jk", "l'" };
    string punct2[3] = {"a", "b", "c"};
    
    string data1[ 4 ] = { "4.4.3.3", "44", "33.09e8", "33.098" };
    string floatingData[ 3 ] = {"4.4.3.3", "44,", "33.09a"};
    
    string people[ 5 ] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    string data2[ 4 ] = { "happy", "days", "are here", "again" };
    
    string data3[4] = {"happy", "happy", "days", "days"};
    string data4[4] = {"happy", "days", "are here", "again"};
    
    assert(findMinimum(a, 4) == 3);
    assert(findMinimum(b, 6) == 5);
    assert(findMinimum(b, -9) == -1);
    assert(findMinimum(c, 3) == 0);
    
    assert(countAllPunctuation( data, 4 ) == 3);
    assert(countAllPunctuation(data, -14) == -1);
    assert(countAllPunctuation(punct, 4) == 3);
    assert(countAllPunctuation(punct, -1) == -1);
    assert(countAllPunctuation(punct2, 3) == 0);
    
    assert(countFloatingPointValues(data1, 4) == 2);
    assert(countFloatingPointValues(data1, 3) == 1);
    assert(countFloatingPointValues(data1, -9) == -1);
    assert(countFloatingPointValues(floatingData, 3) == 0);
    
    assert(replaceAll(people, 5, 'z', 'a') == 0);
    assert(replaceAll(people, 5, 'a', 'z') == 4);
    assert(replaceAll(people, -5, 'a', 'z') == -1);
    assert(replaceAll(data2, 3, 'a', 'z') == 3);
    
 // assert(removeDuplicatedValues( data3, 4 ) == 2);
    assert(removeDuplicatedValues(data4, 4) == 0);
    assert(removeDuplicatedValues(data4, -5) == -1);
    assert(removeDuplicatedValues(data3, 3) == 1);
    
    // assert(shiftRight( people, 5, 3, "foo" ) == 3);
    assert(shiftRight(people, 5, 25, "foo") == 5);
    
    cerr << "All tests succeeded" << endl;
    return( 0 );
}

int findMinimum( const string array[ ], int n )
{
    int result = 0;
    if (n > 0)
    {
        string min = array[0];
        for (int i = 1; i < n; i++)
        {
            if (min > array[i])
            {
                result = i;
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        result = -1;
    }
    return (result);
}





int countAllPunctuation( const string array[ ], int n )
{
    int result = 0;
    
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            string s = array[i];
            size_t length = s.size();
            for (int j = 0; j < length; j++)
            {
                char c = s[j];
                if (c == '.' || c == ',' || c == '!' || c == ';' || c == '-' || c == '/' || c == ':' || c == '?' || c == '"' || c == '\'')
                    {
                        result++;
                    }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        result = -1;
    }
    return (result);
}




int countFloatingPointValues( const string array[ ],int   n )
{
    int result = 0;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            int decimalPoints = 0;
            int notDigits = 0;
            string s = array[i];
            size_t length = s.size();
            
            for (int j = 0; j < length; j++)
            {
                char c = s[j];
                if (c == '.')
                {
                    decimalPoints++;
                }
                else if (!isdigit(c))
                {
                    notDigits++;
                }
                else
                {
                    continue;
                }
            }
            if (decimalPoints <= 1 && notDigits == 0)
            {
                result++;
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        result = -1;
    }
    return(result);
}





int removeDuplicatedValues( string array[ ], int  n )
{
    int result = 0;
    
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            string s1 = array[i];
            if (s1 == "")
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                string s2 = array[j];
                if (s1 == s2)
                {
                    array[j] = "";
                    result++;
                    s2 = array[j];
                }
                else
                {
                    continue;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (array [i] == "")
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (array[j] != "")
                    {
                        string temp;
                        temp = array[j];
                        array[j] = array[i];
                        array[i] = temp;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        result = -1;
    }
    return (result);
}




int replaceAll( string array1[ ], int n, char letterToReplace, char letterToFill )
{
    int result = 0;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            string s = array1[i];
            size_t length = s.size();
            for (int j = 0; j < length; j++)
            {
                char c = s[j];
                if (c == letterToReplace)
                {
                    c = letterToFill;
                    result++;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        result = -1;
    }
    return (result);
}





int shiftRight( string array[ ], int n, int amount, string placeholder )
{
    int result = 0;
    
    if (n > 0)
    {
        for (int i = 0; i < amount; i++)
        {
            if (amount <= n)
            {
                array[i + amount] = array[i];
                array[i] = placeholder;
                result++;
            }
            else if (amount > n)
            {
                array[i] = placeholder;
                result = n;
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        result = -1;
    }

    return(result);
}
