#pragma once
#include "CardFive.h"

void moveForwardByTheStepsJustMoved(Grid* pGrid) {
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	int currentPlayerJustMovedSteps = currentPlayer->getJustRolledDiceNumber();
	currentPlayer->Move(pGrid, currentPlayerJustMovedSteps);
}