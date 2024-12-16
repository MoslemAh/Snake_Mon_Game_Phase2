#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	// no parameters to read from user
}

void InputDiceValueAction::Execute()
{

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	int x, y;
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game Has Ended! Click Anywhere to Continue ...");
		return;
	}

	// Getting dice value from user
	pOut->PrintMessage("Please enter a dice value between 1-6 : ");
	int diceNumber = pIn->GetInteger(pOut);

	if (diceNumber < 1 || diceNumber > 6)
	{
		pGrid->PrintErrorMessage("Invalid dice number! Click Anywhere to Continue ...");
		return;
	}



	// 2- Get the "current" player from pGrid
	Player* currentPlayer = pGrid->GetCurrentPlayer();

	// 3- Check if player has reached / passed cell 99 , if true then SetEndGame

	// 4- Move the currentPlayer using function Move of class player
	currentPlayer->Move(pGrid, diceNumber);

	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// 6- Check if the player has stepped on an object

	// 7- Apply the object function if true

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	

}

InputDiceValueAction::~InputDiceValueAction()
{
}
