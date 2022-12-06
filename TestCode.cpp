#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Square, Normal and Highlighted
	// 2.2.1 - Drawing non-filled square
	pOut->PrintMessage("Drawing a square ==> non-filled,  Click one points");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawSquare(P1, gfxInfo, false);

	// 2.2.2 - Drawing highlighted non-filled square
	pOut->PrintMessage("Drawing a square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(P1, gfxInfo, true);


	// 2.2.3 - Drawing a filled square
	pOut->PrintMessage("Drawing a square ==> filled,  Click 0ne points");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawSquare(P1, gfxInfo, false);


	// 2.2.4 - Drawing a highlighted filled square
	pOut->PrintMessage("Drawing a square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(P1, gfxInfo, true);



	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Triangle in all possible states
	// 2.3.1 - Drawing non-filled triangle
	pOut->PrintMessage("Drawing a triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawTri(P1, P2,P3, gfxInfo, false);

	// 2.3.2 - Drawing highlighted non-filled triangle
	pOut->PrintMessage("Drawing a triangle==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTri(P1, P2,P3, gfxInfo, true);


	// 2.3.3 - Drawing a filled triangle
	pOut->PrintMessage("Drawing a triangle ==> filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);


	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawTri(P1, P2,P3, gfxInfo, false);


	// 2.3.4 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Drawing a triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTri(P1, P2,P3, gfxInfo, true);




	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states
	// 2.4.1 - Drawing non-filled hexagon
	pOut->PrintMessage("Drawing a hexagon ==> non-filled,  Click one points");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawHexagon(P1, gfxInfo, false);

	// 2.4.2 - Drawing highlighted non-filled Hexagon
	pOut->PrintMessage("Drawing a hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHexagon(P1, gfxInfo, true);


	// 2.4.3 - Drawing a filled Hexagon
	pOut->PrintMessage("Drawing a hexagon ==> filled,  Click 0ne points");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawHexagon(P1, gfxInfo, false);


	// 2.4.4 - Drawing a highlighted filled Hexagon
	pOut->PrintMessage("Drawing a hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHexagon(P1,  gfxInfo, true);



	


	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states
	// 2.5.1 - Drawing non-filled Circle
	pOut->PrintMessage("Drawing a circle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawCircle(P1, P2, gfxInfo, false);

	// 2.5.2 - Drawing highlighted non-filled Circle
	pOut->PrintMessage("Drawing a circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCircle(P1, P2, gfxInfo, true);


	// 2.5.3 - Drawing a filled Circle
	pOut->PrintMessage("Drawing a circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawCircle(P1, P2, gfxInfo, false);


	// 2.5.4 - Drawing a highlighted filled Circle
	pOut->PrintMessage("Drawing a circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCircle(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
		do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case SELECT:
			    pOut->PrintMessage("Action: Select a Figure ");
			    break;

		case DRAW_RECT:
			  pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			  break;
		
		case DRAW_SQUARE:
			    pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			    break;

		case DRAW_TRIANGLE:
			   pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			   break;

		case DRAW_HEXAGON:
			  pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			  break;

		case DRAW_CIRCLE:
			  pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			  break;

		
		
		case COLOR_FILL:
			  pOut->PrintMessage("Action: Choose a Color For Shape Fill ");
			  break;

		case COLOR_DRAW:
			  pOut->PrintMessage("Action: Choose a Color For Drawing ");
			  break;

		case BLACK:
			  pOut->PrintMessage("BLACK");
			  break;

		case ORANGE:
			  pOut->PrintMessage("ORANGE");
			  break;

		case YELLOW:
			  pOut->PrintMessage("YELLOW");
			  break;

		case RED:
			  pOut->PrintMessage("RED");
			  break;

		case GREEN:
			  pOut->PrintMessage("GREEN");
			  break;

		case BLUE:
			  pOut->PrintMessage("BLUE");
			  break;

		
		case MOVE:
			  pOut->PrintMessage("Action: Move Selected Shape ");
			  break;

		case TO_DELETE:
			  pOut->PrintMessage("Action: Delete Selected Shape ");
			  break;

		case UNDO:
			  pOut->PrintMessage("Action: Undo Last Action ");
			  break;

		case REDO:
			  pOut->PrintMessage("Action: Redo Last Action ");
			  break;

		case CLEARALL:
			  pOut->PrintMessage("Action: Clear All Figures ");
			  break;

		case STARTRECORDING:
			  pOut->PrintMessage("Action: Start Recording ");
			  break;

		case PAUSERECORDING:
			  pOut->PrintMessage("Action: Pause Recording ");
			  break;

		case PLAYRECORDING:
			  pOut->PrintMessage("Action: Play Recording ");
			  break;

		case SAVE:
			  pOut->PrintMessage("Action: Save Current Drawings ");
			  break;

		case LOAD:
			  pOut->PrintMessage("Action: Load Existing Drawings ");
			  break;

		case ADDVOICE:
			  pOut->PrintMessage("Action: Enable Voice Mode ");
			  break;

		case PLAY_FIGURES:
			  pOut->PrintMessage("Action: Figure Types ");
			  break;

		case PLAY_COLORS:
			  pOut->PrintMessage("Action: Figure Colors ");
			  break;

		case PLAY_COLORSANDFIGURES:
			  pOut->PrintMessage("Action: Figure Types and Colors ");
			  break;


		
		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				pOut->CreatePlayToolBar();
				break;


		///TODO: Add more cases for the other action types


		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


