#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SELECT,           //Select

	DRAW_RECT,		  //Draw Shapes
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_HEXAGON,
	DRAW_CIRCLE,

	COLOR_FILL,      //Color Actions
	COLOR_DRAW,
	BLACK_,           //DOuble CHeck COLORS ARE ACTIONTYPES
	ORANGE_,
	YELLOW_,
	RED_,
	GREEN_,
	BLUE_,

	MOVE,            //Various Functions
	TO_DELETE,
	UNDO,
	REDO,
	CLEARALL,
	STARTRECORDING,
	PAUSERECORDING,
	PLAYRECORDING,
	SAVE,
	LOAD,
	ADDVOICE,

	PLAY_FIGURES,     //Play Mode Actions
	PLAY_COLORS,
	PLAY_COLORSANDFIGURES,


	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar


	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif
