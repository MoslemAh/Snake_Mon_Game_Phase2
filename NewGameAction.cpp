#include "NewGameAction.h"

#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGameAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	pGrid->ResetPlayersInfo();
	pGrid->UpdateInterface();

}

NewGameAction::~NewGameAction()
{

}
