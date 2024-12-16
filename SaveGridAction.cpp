#include "SaveGridAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"


SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
	pGrid = pManager->GetGrid();
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter Name of Grid To Be Saved : ");
	fileName = pIn->GetSrting(pOut);

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void SaveGridAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	
	ofstream OutFile(fileName);

	if (OutFile.is_open())
	{
		OutFile << Ladder::GetNumLadders() << endl;
		// Problem SaveAll
		pGrid->SaveAll(OutFile, LADDER);
		OutFile << Snake::GetNumSnakes() << endl;
		// Problem SaveAll
		pGrid->SaveAll(OutFile, SNAKE);
		// OutFile << Card::GetNumCards() << endl;
		// pGrid->SaveAll(OutFile, CARD);
	}

	OutFile.close();

	pGrid->PrintErrorMessage("Grid Successfully Saved! Click anywhere to continue ...");

}