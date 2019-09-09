//
//  main.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Cell.h"
#include "Board.h"
#include "NumberSet.h"
#include "Game.h"
using namespace cs31;
using namespace std;

void clearScreen( );
void beep();

int main()
{
    using namespace cs31;
    using namespace std;
    
   clearScreen();
    
    Game game;
    game.buildRandomBoard();

    int row, column, value;
    bool result = true;
    std::string action, message = "(s)et (e)valuate (q)uit: ";
    cout << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                beep( );  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'S':
            case 's':
                cout << "row:";
                cin >> row;
                cout << "column:";
                cin >> column;
                cout << "value:";
                cin >> value;
                cout << endl;
                
                result = game.acceptValue( value, row, column );
                if (!result)
                    beep();  // beep
                cout << game.display( message ) << endl;
                break;
            case 'E':
            case 'e':
                cout << "evaluate:" << game.evaluate() << endl;
                cout << game.display( message ) << endl;
                break;
        }
        
    } while( !game.completed()  ); /*
    
    NumberSet ns( 1, 2, 3, 4, 5, 6, 7, 8 );
    assert( ns.notFound( 0 ) );
    assert( !ns.notFound( 1 ) );
    assert( !ns.notFound( 2 ) );
    assert( !ns.notFound( 3 ) );
    assert( !ns.notFound( 4 ) );
    assert( !ns.notFound( 5 ) );
    assert( !ns.notFound( 6 ) );
    assert( !ns.notFound( 7 ) );
    assert( !ns.notFound( 8 ) );
    assert( ns.notFound( 9 ) );
    
    Cell c;
    c.setValue(1);
    assert( c.getValue() == 1 );
    assert( !c.isImmutable() );
    c.setValue(2);
    c.setImmutable( true );
    assert( c.getValue() == 2 );
    assert( c.isImmutable() );
    // isValueOK does not check immutability
    assert( c.isValueOK( 0, ns, ns, ns ) );
    assert( !c.isValueOK( 1, ns, ns, ns ) );
    assert( !c.isValueOK( 2, ns, ns, ns ) );
    assert( !c.isValueOK( 3, ns, ns, ns ) );
    assert( !c.isValueOK( 4, ns, ns, ns ) );
    assert( !c.isValueOK( 5, ns, ns, ns ) );
    assert( !c.isValueOK( 6, ns, ns, ns ) );
    assert( !c.isValueOK( 7, ns, ns, ns ) );
    assert( !c.isValueOK( 8, ns, ns, ns ) );
    assert( c.isValueOK( 9, ns, ns, ns ) );
    // isOKToSetValue does check immutability
    assert( !c.isOKToSetValue( 0, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 1, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 2, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 3, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 4, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 5, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 6, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 7, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 8, ns, ns, ns ) );
    assert( !c.isOKToSetValue( 9, ns, ns, ns ) );
    
    Game g;
    g.cheat("123456789|.........|987321456|456987123|.........|312645978|.........|.........|.........");
    assert(g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
    assert(g.evaluate() == 36);
    assert(!g.completed());
    // all the cheated values are immutable
    assert(!g.acceptValue(0, 1, 1));
    assert(!g.acceptValue(7, 1, 1));
    assert( g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
    assert( g.evaluate() == 36 );
    assert(!g.completed());
    
    Game g1;
    g1.cheat("53..7....|6..195...|.98....6.|8...6...3|4..8.3..1|7...2...6|.6....28.|...419..5|....8..79");
    assert(g1.display() == "53.|.7.|...\n6..|195|...\n.98|...|.6.\n-----------\n8..|.6.|..3\n4..|8.3|..1\n7..|.2.|..6\n-----------\n.6.|...|28.\n...|419|..5\n...|.8.|.79\n");
    assert(g1.evaluate() == 30);
    assert(!g1.completed());
    
    assert(g1.acceptValue(4, 1, 3));
    assert(g1.acceptValue(6, 1, 4));
    assert(g1.acceptValue(8, 1, 6));
    assert(g1.acceptValue(9, 1, 7));
    assert(g1.acceptValue(1, 1, 8));
    assert(g1.acceptValue(2, 1, 9));
    
    assert(g1.acceptValue(7, 2, 2));
    assert(g1.acceptValue(2, 2, 3));
    assert(g1.acceptValue(3, 2, 7));
    assert(g1.acceptValue(4, 2, 8));
    assert(g1.acceptValue(8, 2, 9));
    
    assert(g1.acceptValue(1, 3, 1));
    assert(g1.acceptValue(3, 3, 4));
    assert(g1.acceptValue(4, 3, 5));
    assert(g1.acceptValue(2, 3, 6));
    assert(g1.acceptValue(5, 3, 7));
    assert(g1.acceptValue(7, 3, 9));
    
    assert(g1.acceptValue(5, 4, 2));
    assert(g1.acceptValue(9, 4, 3));
    assert(g1.acceptValue(7, 4, 4));
    assert(g1.acceptValue(1, 4, 6));
    assert(g1.acceptValue(4, 4, 7));
    assert(g1.acceptValue(2, 4, 8));
    
    assert(g1.acceptValue(2, 5, 2));
    assert(g1.acceptValue(6, 5, 3));
    assert(g1.acceptValue(5, 5, 5));
    assert(g1.acceptValue(7, 5, 7));
    assert(g1.acceptValue(9, 5, 8));
    
    assert(g1.acceptValue(1, 6, 2));
    assert(g1.acceptValue(3, 6, 3));
    assert(g1.acceptValue(9, 6, 4));
    assert(g1.acceptValue(4, 6, 6));
    assert(g1.acceptValue(8, 6, 7));
    assert(g1.acceptValue(5, 6, 8));
    
    assert(g1.acceptValue(9, 7, 1));
    assert(g1.acceptValue(1, 7, 3));
    assert(g1.acceptValue(5, 7, 4));
    assert(g1.acceptValue(3, 7, 5));
    assert(g1.acceptValue(7, 7, 6));
    assert(g1.acceptValue(4, 7, 9));
    
    assert(g1.acceptValue(2, 8, 1));
    assert(g1.acceptValue(8, 8, 2));
    assert(g1.acceptValue(7, 8, 3));
    assert(g1.acceptValue(6, 8, 7));
    assert(g1.acceptValue(3, 8, 8));
    
    assert(g1.acceptValue(3, 9, 1));
    assert(g1.acceptValue(4, 9, 2));
    assert(g1.acceptValue(5, 9, 3));
    assert(g1.acceptValue(2, 9, 4));
    assert(g1.acceptValue(6, 9, 6));
    assert(g1.acceptValue(1, 9, 7));
    
    assert(g1.display() == "534|678|912\n672|195|348\n198|342|567\n-----------\n859|761|423\n426|853|791\n713|924|856\n-----------\n961|537|284\n287|419|635\n345|286|179\n");
    assert(g1.evaluate() == 100);
    assert(g1.completed());
    
    cout << "all tests passed!" << endl; */
    
    return( 0 );
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen and beep implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

void beep()
{
    cout << '\a' << endl;
}

#endif

#ifdef __APPLE__

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

void beep()
{
    // system( "/usr/bin/osascript -e  \"beep 1\"" );
    // printf("%c", 7);
    // system( "echo $'\\a'" );
    // NSBeep();
}

#endif

#if __unix__ // not Microsoft Visual C++, not Mac, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

void beep()
{
    cout << '\a' << endl;
}

#endif

