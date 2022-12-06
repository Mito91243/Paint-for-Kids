#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.png";  //Select And Shapes
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpeg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpeg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.png";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circ.jpg";
	
	MenuItemImages[ITM_FILLCOLOR] = "images\\MenuItems\\Menu_Fill.png";  //FILL&DRAW And their colors
	MenuItemImages[ITM_DRAWCOLOR] = "images\\MenuItems\\Menu_Draw.png";
	MenuItemImages[ITM_Black] = "images\\MenuItems\\Menu_Black.jpeg";
	MenuItemImages[ITM_Yellow] = "images\\MenuItems\\Menu_Yellow.jpeg";
	MenuItemImages[ITM_Orange] = "images\\MenuItems\\Menu_Orange.jpeg";
	MenuItemImages[ITM_Red] = "images\\MenuItems\\Menu_Red.jpeg";
	MenuItemImages[ITM_Green] = "images\\MenuItems\\Menu_Green.jpeg";
	MenuItemImages[ITM_Blue] = "images\\MenuItems\\Menu_Blue.jpeg";

	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.png";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.png";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.png";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.png";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_Clear.png";
	
	MenuItemImages[ITM_STARTRECORDING] = "images\\MenuItems\\Menu_Startrecording.jpeg";  //Saving&Loading And Recording
	MenuItemImages[ITM_STOPRECORDING] = "images\\MenuItems\\Menu_Stoprecording.png";
	MenuItemImages[ITM_PLAYRECORDING] = "images\\MenuItems\\Menu_playrecording.png";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\Menu_Save.png";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\Menu_Load.png";
	MenuItemImages[ITM_ADDVOICE] = "images\\MenuItems\\Menu_Voice.png";

	MenuItemImages[ITM_SWITCHTOPLAYMODE] = "images\\MenuItems\\Menu_Switch.png";  //Exit And Switch
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list(DONE)

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	
	MenuItemImages[ITM_FIGURETYPE] = "images\\MenuItems\\Menu_Figures.png";              //Play Mode Types
	MenuItemImages[ITM_FIGUREFILLCOLOR] = "images\\MenuItems\\Menu_Colors.png";
	MenuItemImages[ITM_FIGURETYPEANDCOLOR] = "images\\MenuItems\\Menu_Figuresandcolors.png";
	MenuItemImages[ITM_SWITCHTODRAW] = "images\\MenuItems\\Menu_Switchtodraw.png";

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int Radi = 0.0;
	Radi = sqrt((pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2)));
	pWind->DrawCircle(P1.x, P1.y, Radi, style);

}
void Output::DrawHexagon(Point P1, GfxInfo hexagonGfxInfo, bool selected)const//side lenght =40
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = hexagonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (hexagonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(hexagonGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int px[6];
		px[0] = P1.x + 40;
		px[1] = P1.x + 20;
		px[2] = P1.x - 20;
		px[3] = P1.x - 40;
		px[4] = P1.x - 20;
		px[5] = P1.x + 20;
 int py[6];
		py[0] = P1.y;
		py[1] = P1.y -(20* sqrt(3));
		py[2] = P1.y - (20*sqrt(3));
		py[3] = P1.y;
		py[4] = P1.y +(20*sqrt(3));
		py[5] = P1.y +(20* sqrt(3));

		pWind->DrawPolygon(px, py, 6, style);

}
void Output::DrawSquare(Point P1, GfxInfo squareGfxInfo, bool selected)const //side length =40
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = squareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (squareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(squareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int px[4];
		px[0] = P1.x + 20;
		px[1] = P1.x - 20;
		px[2] = P1.x - 20;
		px[3] = P1.x + 20;

	int py[4];
	    py[0] = P1.y - 20;
		py[1] = P1.y - 20;
		py[2] = P1.y + 20;
		py[3] = P1.y + 20;


	pWind->DrawPolygon(px, py, 4, style);


}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

