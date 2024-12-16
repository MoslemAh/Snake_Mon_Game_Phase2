#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

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

	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	
	// 4- Check if player has reached / passed cell 99 , if true then SetEndGame

	// 5- Move the currentPlayer using function Move of class player
	currentPlayer->Move(pGrid, diceNumber);

	// Another Method for 3 & 4
	// pGrid->GetCurrentPlayer()->Move(pGrid, diceNumber);


	// 6- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// 7- Check if the player has stepped on an object

	// 8- Apply the object function if true

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
