// Tanvi Pati - UID: 104901736
// CS 31 - Project 5

#include <iostream>
#include <string>
#include <cassert>

#include "AppleProduct.h"
#include "AppleStore.h"

using namespace std;

int main()
{
    // test code
    
    // AppleProduct:
    
    cs31::AppleProduct p;
    assert( p.getCost() == 0.0 );
    assert( p.getKind() == cs31::AppleProduct::Kind::NOTSPECIFIED );
    assert( p.getColor() == "" );
    assert( p.getVersion() == "" );
    
    cs31::AppleProduct p1( cs31::AppleProduct::Kind::IPHONE, "8", "Space Grey", 699.00 );
    assert( std::to_string( p1.getCost() ) == "699.000000" );
    assert( p1.getKind() == cs31::AppleProduct::Kind::IPHONE );
    assert( p1.getColor() == "Space Grey" );
    assert( p1.getVersion() == "8" );
    
    cs31::AppleProduct p2( cs31::AppleProduct::Kind::IPAD, "Pro", "Pink", 699.00 );
    assert( std::to_string( p2.getCost() ) == "699.000000" );
    assert( p2.getKind() == cs31::AppleProduct::Kind::IPAD);
    assert( p2.getColor() == "Pink" );
    assert( p2.getVersion() == "Pro" );
    
    cs31::AppleProduct p3(cs31::AppleProduct::Kind::WATCH, "1", "White", 249.00);
    assert(std::to_string(p3.getCost() ) == "249.000000");
    assert(p3.getKind() == cs31::AppleProduct::Kind::WATCH);
    assert(p3.getColor() == "White");
    assert(p3.getVersion() == "1");
    
    // AppleStore:
    
    // iPhones:
    
    cs31::AppleStore store;
    cs31::AppleProduct iphone8_64 = store.buyiPhone8( "Space Grey", 64 );
    assert( std::to_string( iphone8_64.getCost()) == "699.000000" );
    assert( iphone8_64.getKind() == cs31::AppleProduct::Kind::IPHONE );
    assert( iphone8_64.getColor() == "Space Grey" );
    assert( iphone8_64.getVersion() == "8" );
    
    cs31::AppleProduct iphone8_256 = store.buyiPhone8( "Space Grey", 256 );
    assert( std::to_string( iphone8_256.getCost()) == "849.000000" );
    assert( iphone8_256.getKind() == cs31::AppleProduct::Kind::IPHONE );
    assert( iphone8_256.getColor() == "Space Grey" );
    assert( iphone8_256.getVersion() == "8" );
    
    cs31::AppleProduct iphone8Plus_64 = store.buyiPhone8Plus( "Silver", 64 );
    assert( std::to_string( iphone8Plus_64.getCost()) == "799.000000" );
    assert( iphone8Plus_64.getKind() == cs31::AppleProduct::Kind::IPHONE );
    assert( iphone8Plus_64.getColor() == "Silver" );
    assert( iphone8Plus_64.getVersion() == "8Plus" );
    
    cs31::AppleProduct iphone8Plus_256 = store.buyiPhone8Plus( "Silver", 256 );
    assert( std::to_string( iphone8Plus_256.getCost()) == "949.000000" );
    assert( iphone8Plus_256.getKind() == cs31::AppleProduct::Kind::IPHONE );
    assert( iphone8Plus_256.getColor() == "Silver" );
    assert( iphone8Plus_256.getVersion() == "8Plus" );
    
    cs31::AppleProduct iphoneX_64 = store.buyiPhoneX( "Rose Gold", 64 );
    assert( std::to_string( iphoneX_64.getCost()) == "999.000000" );
    assert( iphoneX_64.getKind() == cs31::AppleProduct::Kind::IPHONE );
    assert( iphoneX_64.getColor() == "Rose Gold" );
    assert( iphoneX_64.getVersion() == "X" );
    
    cs31::AppleProduct iphoneX_256 = store.buyiPhoneX( "Rose Gold", 256 );
    assert( std::to_string( iphoneX_256.getCost()) == "1149.000000" );
    assert( iphoneX_256.getKind() == cs31::AppleProduct::Kind::IPHONE );
    assert( iphoneX_256.getColor() == "Rose Gold" );
    assert( iphoneX_256.getVersion() == "X" );
    
    // iPads:
    
    cs31::AppleProduct ipad_32 = store.buyiPad("Black", 32);
    assert(std::to_string(ipad_32.getCost()) == "329.000000");
    assert(ipad_32.getColor() == "Black");
    assert(ipad_32.getKind() == cs31::AppleProduct::Kind::IPAD);
    assert(ipad_32.getVersion() == "");
    
    cs31::AppleProduct ipad_128 = store.buyiPad("Black", 128);
    assert(std::to_string(ipad_128.getCost()) == "429.000000");
    assert(ipad_128.getColor() == "Black");
    assert(ipad_128.getKind() == cs31::AppleProduct::Kind::IPAD);
    assert(ipad_128.getVersion() == "");

    cs31::AppleProduct ipadpro_64 = store.buyiPadPro("White", 64);
    assert( std::to_string(ipadpro_64.getCost()) == "649.000000");
    assert( ipadpro_64.getKind() == cs31::AppleProduct::Kind::IPAD);
    assert( ipadpro_64.getVersion() == "Pro" );
    assert( ipadpro_64.getColor() == "White");

    cs31::AppleProduct ipadpro_256 = store.buyiPadPro("White", 256);
    assert(std::to_string(ipadpro_256.getCost()) == "799.000000");
    assert(ipadpro_256.getColor() == "White");
    assert(ipadpro_256.getKind() == cs31::AppleProduct::Kind::IPAD);
    assert(ipadpro_256.getVersion() == "Pro");
    
    cs31::AppleProduct ipadpro_512 = store.buyiPadPro("White", 512);
    assert(std::to_string(ipadpro_512.getCost()) == "999.000000");
    assert(ipadpro_512.getColor() == "White");
    assert(ipadpro_512.getKind() == cs31::AppleProduct::Kind::IPAD);
    assert(ipadpro_512.getVersion() == "Pro");
    
    // Watches:
    
    cs31::AppleProduct watch_1 = store.buyWatch1("Jet Black");
    assert(std::to_string(watch_1.getCost()) == "249.000000");
    assert(watch_1.getColor() == "Jet Black");
    assert(watch_1.getKind() == cs31::AppleProduct::Kind::WATCH);
    assert(watch_1.getVersion() == "1");
    
    cs31::AppleProduct watch_3 = store.buyWatch3("Blue");
    assert(std::to_string(watch_3.getCost()) == "329.000000");
    assert(watch_3.getColor() == "Blue");
    assert(watch_3.getKind() == cs31::AppleProduct::Kind::WATCH);
    assert(watch_3.getVersion() == "3");
   
    // iPhones:
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct iphone8 = s.buyiPhone8( "Space Grey", 9999 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct iphone8 = s.buyiPhone8( "Space Grey", -128 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct iphone8Plus = s.buyiPhone8Plus( "Space Grey", 9999 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct iphone8Plus = s.buyiPhone8( "Rose Gold", -128 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct iphoneX = s.buyiPhoneX( "Space Grey", 9999 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct iphoneX = s.buyiPhoneX( "Space Grey", -128 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    // iPads:
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct ipad = s.buyiPad( "Space Grey", 9999 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct ipad = s.buyiPad( "Space Grey", -128 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct ipadpro = s.buyiPadPro( "Space Grey", 9999 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore s;
        cs31::AppleProduct ipadpro = s.buyiPadPro( "Space Grey", -128 );
        assert( false );
        
    }
    catch( std::logic_error )
    {
        assert( true );
    }

    cout << "all tests passed!" << endl ;
    
    return 0;
}
