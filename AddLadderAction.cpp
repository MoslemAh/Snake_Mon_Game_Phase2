#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters

	// 1- Checking if IsValidCell Clicked
	// 2- Checking if both cells are in the same column
	// 3- Checking that the endPos is above the startPos
	
	if (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cells Clicked!");
		return;
	}
	else if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("End cell and Start cell are not in the same column!");
		return;
	}
	else if (endPos.VCell() > startPos.VCell())
	{
		pGrid->PrintErrorMessage("End cell cannot be smaller than Start cell!");
		return;
	}
	// ============= Overlapping & Other Validations remaining ============= //

	// Clear messages
	pOut->ClearStatusBar();
}

// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	
	/*
	if (pGrid->IsOverlapping(pLadder))
	{
		pGrid->PrintErrorMessage("Invalid! Ladders will overlap! Click anywhere to continue ...");
		return;
	}
	*/

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
