#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string M = "Male";
    const string F = "Female";
    const string TM = "Trans Male";
    const string TF = "Trans Female";
    const string Q = "Queer";
    const string D = "Different";
    string gender;
    string name;
    int age;
    int weight;
    int height;
    
    cout << "Donor Name: ";
    getline(cin, name);
  
    cout << "Gender: ";
    getline(cin, gender);
    
    cout << "Age: ";
    cin >> age;
    
    cout << "Weight: ";
    cin >> weight;
    
    cout << "Height: ";
    cin >> height;
    
    if (name == "")
    {
        cout << "--- You must enter a valid name." << endl;
    }
    
    else if (gender != M and gender != F and gender != TM and gender != TF and gender != Q and gender != D)
    {
        cout << "--- You must enter a valid gender." << endl;
    }
    
    else if (age <= 0)
    {
        cout << "--- You must enter a valid age." << endl;
    }
    
    else if (weight <= 0)
    {
        cout << "--- You must enter a valid weight." << endl;
    }
    
    else if (height <= 0)
    {
        cout << "--- You must enter a valid height." << endl;
    }
    
    else if (age < 16)
    {
        cout << "--- No, " << name << " you cannot donate blood." << endl;
    }
    
    else if (weight < 110)
    {
        cout << "--- No, " << name << " you cannot donate blood." << endl;
    }
        
    else if (age >= 16 and age <= 22 )
    {
        if (gender == M)
        {
            if (height < 60)
            {
                cout << "--- No, " << name << " you cannot donate blood." << endl;
            }
            else
            {
                cout << "--- Yes, " << name << " you can donate blood." << endl;
            }
        }
        else if (gender == F)
        {
            if (height < 58)
            {
                cout << "--- No, " << name << " you cannot donate blood." << endl;
            }
            else if (height == 58)
            {
                if (weight >= 146)
                {
                    cout << "--- Yes, " << name << " you can donate blood." << endl;
                }
                else
                {
                    cout << "--- No, " << name << " you cannot donate blood." << endl;
                }
            }
            else if (height == 59)
            {
                if (weight >= 142)
                {
                    cout << "--- Yes, " << name << " you can donate blood." << endl;
                }
                else
                {
                    cout << "--- No, " << name << " you cannot donate blood." << endl;
                }
            }
            else
            {
                cout << "--- Yes, " << name << " you can donate blood." << endl;
            }
        }
        else
        {
            cout << "--- No, " << name << " you cannot donate blood." << endl;
        }
    }
    
    else
    {
        cout << "--- Yes, " << name << " you can donate blood." << endl;
    }
    return (0);
}
