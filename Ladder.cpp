#include "Ladder.h"

int Ladder::numberOfLadders = 0;

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

	numberOfLadders++;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	
	// Get a Pointer to the Input / Output Interfaces
	/*
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	int x, y;
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetPointClicked(x, y);
	*/

	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
	
}

// ===================== Additional Functions ===================== //

// Problem IsOverlapping
bool Ladder::IsOverlapping(GameObject* newObj) const
{
	Ladder* IsLadder = dynamic_cast<Ladder*>(newObj);
	if (!IsLadder) return false;
	CellPosition Start1 = IsLadder->GetPosition();
	CellPosition End1 = IsLadder->GetEndPosition();
	CellPosition Start2 = this->GetPosition();
	CellPosition End2 = this->GetEndPosition();

	// 1- Check if Start2.VCell between Start1 & End1 or if End2.VCell between Start1 & End1 --> Return true
	if ((Start2.VCell() < Start1.VCell() && Start2.VCell() > End1.VCell()) || (End2.VCell() < Start1.VCell() && End2.VCell() > End1.VCell()))
		return true;
	else if (Start2.VCell() == End1.VCell()) return true;
}

// Problem Save
void Ladder::Save(ofstream& OutFile, ObjectType Type)
{
	
	if (Type != LADDER) return;
	int StartCell = (this->GetPosition()).GetCellNum();
	int EndCell = (this->GetEndPosition()).GetCellNum();

	OutFile << StartCell << ' ' << EndCell << endl;

}

/*
void Ladder::Load(ifstream& Infile, ObjectType Type)
{
	if (Type != LADDER) return;

}
*/

int Ladder::GetNumLadders() 
{
	return numberOfLadders;
}

// =============================================================== //

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
