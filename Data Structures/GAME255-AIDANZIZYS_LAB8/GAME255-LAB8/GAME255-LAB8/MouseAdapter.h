#ifndef MOUSEADAPTER_H
#define MOUSEADAPTER_H

#include <iostream>
#include <string>

#include "MouseEvent.h"

using namespace std;

class MouseAdapter
{
	public:
		//Mouse Click Adapter Method
		//INSERT CODE HERE
		static void mouseClicked(int button, int state, int x, int y)
		{
			//Declare a string button state
			string buttonState;
			//Set the mouse state to the button and state method parameters
			_mouse->setState(button, state);
			//Set the mouse new position to the x and y coordinate parameters
			_mouse->setNewPos(x, y);
			
			if (state == GLUT_DOWN)				//If state is equal to GLUT_DOWN
				buttonState = "Down";			//Set the button state to Down
			else								//Else
				buttonState = "Up";				//Set the button state to Up
			
			//Print output similar to mine!
			cout << "Mouse " << buttonState << " at " << _mouse->getX() << " " << _mouse->getY() << endl;
		}

		//Mouse Move Adapter Method
		//INSERT CODE HERE
		static void mouseMoved(int x, int y)
		{
			//Set the mouse old position to be the "new" position, which is stored in _mouse
			_mouse->setOldPos(_mouse->getX(), _mouse->getY());
			//Set the new mouse position to the x and y coodinate parameters
			_mouse->setNewPos(x, y);
			//Print Mouse Drag Button
			cout << "Mouse Drag Button";
			
			if (_mouse->isLeft())				//If _mouse button clicked is left
				cout << " Left" << endl;		//Print left
			else if (_mouse->isRight())			//Else if _mouse button clicked is right
				cout << " Right" << endl;		//Print right
			else								//Else
				cout << " Middle" << endl;		//Print Middle

			//Print output similar to mine!
			cout << "\t\tFrom\t" << _mouse->getOldX() << " " << _mouse->getOldY() << endl;
			cout << "\t\tTo\t" << _mouse->getX() << " " << _mouse->getY() << endl;
			cout << "\t\tChange\t" << _mouse->getX() - _mouse->getOldX() << " " << _mouse->getY() - _mouse->getOldY() << endl;
		}

	private:
		static MouseEvent* _mouse;
};

//Instantiate the MouseEvent _mouse instance variable
//INSERT CODE HERE
MouseEvent* MouseAdapter::_mouse = new MouseEvent();
#endif