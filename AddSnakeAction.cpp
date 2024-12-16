#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters

	// 1- Checking if IsValidCell Clicked
	// 2- Checking if both cells are in the same column
	// 3- Checking that the endPos is below the startPos

	if (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cells Clicked!");
		return;
	}
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("End cell and Start cell are not in the same column!");
		return;
	}
	else if (endPos.VCell() < startPos.VCell())
	{
		pGrid->PrintErrorMessage("End cell cannot be larger than Start cell!");
		return;
	}
	// ============= Overlapping & Other Validations remaining ============= //

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	
	/*
	if (pGrid->IsOverlapping(pSnake))
	{
		pGrid->PrintErrorMessage("Invalid! Snakes will overlap! Click anywhere to continue ...");
		return;
	}
	*/

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction

}
