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
// Date: 2018/02
//
#include <sstream>
#include "mySystemApp.h"

using namespace std;

#define cn_StudentInfo "Student Name:xyz. ID:012345678"

void MY_SYSTEM_APP::askForInput( )
{
}

void MY_SYSTEM_APP::updateMonteCarloTitle( )
{
}
void MY_SYSTEM_APP::reset( )
{
}

void MY_SYSTEM_APP::clickAt(float x, float y )
{
    if ( mCurSystem ) {
        mCurSystem->clickAt( x, y );
    }
}

bool MY_SYSTEM_APP::specialFunc(int key, int x, int y)
{
    //cout << "special key:" << key << endl;

    bool flgHandled = false;

    if ( mCurSystem == mGraphSystem) {
        mGraphSystem->stopAutoNodeDeletion();
    }
    switch( key ) {
    case GLUT_KEY_F1:
        glutSetWindowTitle("Graph System");
        flgHandled = true;
        mCurSystem = mGraphSystem;
         mCamera->setZoom(53.0);
        mCamera->set( vec3(-22.8, -23.4, 0.0) );
    break;
    case GLUT_KEY_F2:
        glutSetWindowTitle("2048. Dimension=4x4");
        flgHandled = true;
        mMy2048->setPosition( 30.0, 0);
        mMy2048->setDimension(4,4);
        mPrev_2048->setDimension(4,4);
        mCurSystem = mMy2048;
        mCamera->setZoom(69.0);
        mCamera->set( vec3(-23.8, -11.4, 0.0) );
    break;
    case GLUT_KEY_F3:
        glutSetWindowTitle("2048. Dimension=6x6");

        flgHandled = true;
        mMy2048->setPosition( 40.0, 0);
        mMy2048->setDimension(6,6);
        mPrev_2048->setDimension(6,6);
        mCurSystem = mMy2048;
        mCamera->setZoom(52.0);
        mCamera->set( vec3(-35.3, -16.7, 0.0) );
        /*
        mCurSystem = mTrafficSystem;
        mCamera->setZoom(-119.0);
        mCamera->set( vec3(-202.8, -125.4, 0.0) );
        flgHandled = true;
        */
        break;
case GLUT_KEY_F4:
        glutSetWindowTitle("Image System");
        mCurSystem = mImageSystem;
        mCamera->setZoom(-289);
        mCamera->set( vec3(-241.3, -255.6, 0.0) );

         break;
        case GLUT_KEY_F5:
        glutSetWindowTitle(cn_StudentInfo);

        flgHandled = true;
        break;
    };

     if ( flgHandled == false && mCurSystem == mMy2048 ) {
         //mPrev_2048->copy( mCurSystem );
         *mPrev_2048 = *(static_cast<MY_2048*>(mCurSystem));
        mCurSystem->handleSpecialKeyPressedEvent( key );
     return true;
     }


    //string title;

    /*
    switch( key ) {
    case GLUT_KEY_F1:
        //title = "SYSTEM_TYPE_MONTE_CARLO_SIMULATION";
        //glutSetWindowTitle(title.data( ));
        mFlgShow_Grid = true;
        mSystemType = SYSTEM_TYPE_MONTE_CARLO_SIMULATION;
        mCamera->setZoom(94.0);
        mCamera->set( vec3(-5.3, -0.1, 0.0) );
        updateMonteCarloTitle( );
        cout << "mSystemType = SYSTEM_TYPE_MONTE_CARLO_SIMULATION" << endl;
        break;
    case GLUT_KEY_F2:
        title = "SYSTEM_TYPE_GALAXY_SYSTEM";
        glutSetWindowTitle(title.data( ));
        mFlgShow_Grid = false;
        mSystemType = SYSTEM_TYPE_GALAXY_SYSTEM;
        mCamera->setZoom(-68.0);
        mCamera->set( vec3(-0.0, -0.0, 0.0) );
        cout << "mSystemType = SYSTEM_TYPE_GALAXY_SYSTEM" << endl;

        break;
    case GLUT_KEY_F3:
        title = "SYSTEM_TYPE_SIMPLE_PAINTER";
        glutSetWindowTitle(title.data( ));
        mFlgShow_Grid = false;
        mSystemType = SYSTEM_TYPE_SIMPLE_PAINTER;
        mCamera->setZoom(-94.0);
        mCamera->set( vec3(-188.0, -126.0, 0.0) );
        cout << "mSystemType = SYSTEM_TYPE_SIMPLE_PAINTER" << endl;
        break;
    case GLUT_KEY_F4:
        title = "SYSTEM_TYPE_SIMPLE_FILE_EDITOR";
        glutSetWindowTitle(title.data( ));
        mFlgShow_Grid = false;
        mSystemType = SYSTEM_TYPE_SIMPLE_FILE_EDITOR;
        mCamera->setZoom(-37.0);
        mCamera->set( vec3(-50.05, -50.17, 0.0) );
        cout << "mSystemType = SYSTEM_TYPE_SIMPLE_FILE_EDITOR" << endl;

        break;
    case GLUT_KEY_F5:
        title = "SYSTEM_TYPE_SORTING_VISUALIZATION";
        glutSetWindowTitle(title.data( ));
        mFlgShow_Grid = true;
        mSystemType = SYSTEM_TYPE_SORTING_VISUALIZATION;
        mCamera->setZoom(73.0);
        mCamera->set( vec3(-26.42, -17.999, 0.0) );
        cout << "mSystemType = SYSTEM_TYPE_STUDENT_RECORD_MANAGER" << endl;
        cout << "Press SPACEBAR to visualize the process..." << endl;

        break;
    }
    */
    return true;
}

bool MY_SYSTEM_APP::handleKeyEvent( unsigned char key )
{
    bool flgHandled = false;
    cout << "key:" << (int) key << endl;

    if ( key == 's' || key == 'S') {
        showStudentInfo();
        return true;
    }

    if ( key == 'i' || key == 'I') {
        mCurSystem->askForInput( );
        return true;
    }
    if ( mCurSystem ) {
        mPrev_2048->copy( mCurSystem );
        mCurSystem->handleKeyPressedEvent( key );
        return true;
    }
    return flgHandled;
}

bool MY_SYSTEM_APP::mouseMotionFunc( int mx, int my )
{
    static vector3 color( 1.0, 0.0, 0.0 );


    float x, y, z;
    mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

    mMouseX_2DSpace = x;
    mMouseY_2DSpace = z;

    if ( mMouseButton == GLUT_LEFT_BUTTON ) {
        //cout << "mouseMotionFunc GLUT_LEFT_BUTTON" << endl;


        float rf = (rand()%1000)/1000.0f*0.5f;
        color += vector3(0.1f, 0.07f, 0.11f*rf);
        //clickAt( (int) x, (int) z, color );
        clickAt( x, z );

    } else {
        //if ( mPickedObj == 0 ) {
        return FREE_CANVAS_2D::mouseMotionFunc( mx, my );
        //}
    }

    //cout << "here 5" << endl;

    //float x, y, z;
    //mCamera->getCoordinates( x, y, z, mx, my );
    //cout << "Set Position XZ:" << x << "\t" << z << endl;
    return true;
}

bool MY_SYSTEM_APP::mouseFunc( int button, int state, int mx, int my )
{
    //cout << "button:" << button << endl;
    //if ( mPickedObj == 0 || button == GLUT_MIDDLE_BUTTON ) {
    //if ( button == 3 || button == 4 ) {

    float x, y, z;
    mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

    vector3 color( 1.0, 0.0, 0.0 );
    mMouseButton = button;
    mMouseX = mx;
    mMouseY = mCanvasHeight - my;

    //cout << "mMouseX:" << mMouseX << endl;

    //cout << "mMouseY:" << mMouseY << endl;

    if ( button == GLUT_LEFT_BUTTON ) 
    {
        if ( state == GLUT_DOWN ) {
            clickAt( x, z );
        }   
    } else {
        return FREE_CANVAS_2D::mouseFunc( button, state, mx, my );
    }
    return true;
}


bool MY_SYSTEM_APP::passiveMouseFunc( int mx, int my )
{
    float x, y, z;
    mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

    mMouseX_2DSpace = x;
    mMouseY_2DSpace = z;
    if ( mCurSystem ) {
        mCurSystem->handlePassiveMouseEvent( x, z );
    }
    return true;
}