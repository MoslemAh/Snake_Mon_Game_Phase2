#include "Snake.h"

int Snake::numberOfSnakes = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

	numberOfSnakes++;

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a sake. Click to continue ..." and wait mouse click
	
	// Get a Pointer to the Input / Output Interfaces
	/*
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	int x, y;
	pOut->PrintMessage("You have reached a snake. Click to continue ...");
	pIn->GetPointClicked(x, y);
	*/

	pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");

	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	pGrid->UpdatePlayerCell(pPlayer, this->GetEndPosition());

}

// ===================== Additional Functions ===================== //

// Problem IsOverlapping
bool Snake::IsOverlapping(GameObject* newObj) const
{
	Snake* IsSnake = dynamic_cast<Snake*>(newObj);
	if (!IsSnake) return false;
	CellPosition Start1 = IsSnake->GetPosition();
	CellPosition End1 = IsSnake->GetEndPosition();
	CellPosition Start2 = this->GetPosition();
	CellPosition End2 = this->GetEndPosition();

	// 1- Check if Start2.VCell between Start1 & End1 or if End2.VCell between Start1 & End1 --> Return true
	if ((Start2.VCell() < Start1.VCell() && Start2.VCell() > End1.VCell()) || (End2.VCell() < Start1.VCell() && End2.VCell() > End1.VCell()))
		return true;
	else if (Start2.VCell() == End1.VCell()) return true;
}

// Problem Save
void Snake::Save(ofstream& OutFile, ObjectType Type)
{
	if (Type != SNAKE) return;
	int StartCell = (this->GetPosition()).GetCellNum();
	int EndCell = (this->GetEndPosition()).GetCellNum();
	OutFile << StartCell << ' ' << EndCell << endl;
}

/*
void Snake::Load(ifstream& Infile, ObjectType Type)
{
	if (Type != SNAKE) return;

}
*/

int Snake::GetNumSnakes()
{
	return numberOfSnakes;
}

// =============================================================== //

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
