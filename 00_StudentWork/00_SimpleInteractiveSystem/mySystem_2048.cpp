//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2017/02
#include "mySystem_2048.h"
#include <iostream>

using namespace std;

MY_2048::MY_2048( )
{
    mNX = 4;
    mNZ = 4;
    reset( );

    mPositionX = 0;
    mPositionZ = 0;
    mFlgFocus = true;
}

MY_2048::MY_2048( int nx, int nz )
{
    mPositionX = 0;
    mPositionZ = 0;
    mFlgFocus = true;
    //
    // Implement your own stuff
    //
}

void MY_2048::setDimension(int nx, int nz)
{
    mFlgFocus = true;
    
    //
    // Implement your own stuff
    //
}


void MY_2048::setFocus( bool flg )
{
    mFlgFocus = flg;
}

void MY_2048::setPosition( int x, int z )
{
    mPositionX = x;
    mPositionZ = z;
}

//
//copy the data of the object by m to this object.
//
MY_2048 &MY_2048::operator=(const MY_2048 &m)
{
    //
    // Implement your own stuff
    //
    return (*this);
}

//
//reset the game board
//
void MY_2048::reset( )
{
    mEvent = 0;
    ///////////////////////////////////////
    //
    // Implement your own stuff
    //
}

//
// show messages and ask for input (if any)
//
void MY_2048::askForInput( )
{
    //
    // Implement your own stuff
    //
}

//
// randomly generate a new number
//
void MY_2048::generateNumber( )
{
    //
    // Implement your own stuff
    //
}

void MY_2048::moveDown( )
{
    //
    // Implement your own stuff
    //    

}

void MY_2048::moveUp( )
{
    //
    // Implement your own stuff
    //
}

void MY_2048::moveLeft( )
{
    //
    // Implement your own stuff
    //
}

void MY_2048::moveRight( )
{
    //
    // Implement your own stuff
    //
}

void MY_2048::generateNumbers_All_2to4( )
{
    //
    // Implement your own stuff
    //
}

void MY_2048::generateNumbers_All_2to8( )
{
    //
    // Implement your own stuff
    //
}

void MY_2048::generateNumbers_All( )
{
    //
    // Implement your own stuff
    //
}

void MY_2048::handleKeyPressedEvent( unsigned char key )
{
    switch( key ) {
    case 'r':
    case 'R':
        reset( );
        break;
    case '1':
        generateNumbers_All_2to4( );
        break;
    case '2':
        generateNumbers_All_2to8( );
        break;
    case '3':
        generateNumbers_All( );
        break;
    }
}

void MY_2048::handleSpecialKeyPressedEvent( unsigned char key )
{
    cout << "MY_2048::handleSpecialKeyPressedEvent:" << key << endl;
    bool flgDone = false;

    switch( key ) {
    case GLUT_KEY_UP:
        flgDone = true;
        moveUp( );
        mEvent = GLUT_KEY_UP;
        break;
    case GLUT_KEY_DOWN:
        flgDone = true;
        moveDown( );
        mEvent = GLUT_KEY_DOWN;

        break;
    case GLUT_KEY_LEFT:
        flgDone = true;
        moveLeft( );
        mEvent = GLUT_KEY_LEFT;

        break;
    case GLUT_KEY_RIGHT:
        flgDone = true;
        moveRight( );
        mEvent = GLUT_KEY_RIGHT;

        break;

    }

    if ( flgDone ) {
        generateNumber( );
    }
}
