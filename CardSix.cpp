#pragma once
#include "CardSix.h"

void CardSix::moveBackwardByStepsJustMoved(Grid* pGrid) {
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	int currentPlayerJustMovedSteps = currentPlayer->getJustRolledDiceNumber();
	currentPlayer->Move(pGrid, -currentPlayerJustMovedSteps);
}