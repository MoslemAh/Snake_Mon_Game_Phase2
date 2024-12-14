#pragma once
#include "CardSeven.h"
#include "RollDiceAction.h"

void CardSeven::givePlayerDiceRoll(Grid* pGrid, ApplicationManager* pApp) {
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	RollDiceAction* rollDiceAction = new RollDiceAction(pApp);
	rollDiceAction->Execute();
}