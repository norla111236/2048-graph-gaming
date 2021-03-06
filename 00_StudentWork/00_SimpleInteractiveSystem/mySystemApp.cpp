//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#include "mySystemApp.h"

using namespace std;

void MY_SYSTEM_APP::showStudentInfo( ) const
{
	cout << "*******************************" << endl;
	cout << "Student ID:\t" << endl;
	cout << "Student Name:\t" << endl;
	cout << "Student Email:\t" << endl;
	cout << "*******************************" << endl;
}

void MY_SYSTEM_APP::showMenu( ) const
{
    cout << "Welcome to our mini-galaxy!" << endl;
    cout << "Menu----------------------" << endl;
    cout << "Key usage:" << endl;
    cout << "F1: Monte Carlo Simulation" << endl;
    cout << "F2: Galaxy" << endl;
    cout << "F3: Painter" << endl;
    cout << "F4: Visualization of Bubble Sort" << endl;
    cout << "F5: Simple File Reader" << endl;
    cout << endl;
    cout << "r: reset" << endl;

    cout << "--------------------------" << endl;

}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
    mCurSystem = 0;
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = false;
    showMenu( );
    //
    mGraphSystem = new GRAPH_SYSTEM;
    mMy2048 = new MY_2048;
    //
    mCurSystem = mMy2048;
    //mCurSystem = mTrafficSystem;

    ////////////////////////////////////////////
    ((MY_2048*)mMy2048)->setPosition( 30.0, 0);

    mPrev_2048 = new MY_2048;
    mPrev_2048->setPosition( 0.0, 0);
    mPrev_2048->setFocus( false );
    //
    mImageSystem = new IMAGE_SYSTEM;

    mCurSystem = mImageSystem;
    //
    specialFunc(GLUT_KEY_F1, 0, 0);
}

void MY_SYSTEM_APP::update( )
{
    mCurSystem->update( );
    return;
}




