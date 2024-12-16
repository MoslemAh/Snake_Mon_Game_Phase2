#pragma once
#include "CardEight.h"
#include "Grid.h"
#include "Player.h"

void CardEight::preventPlayerRollDiceNextTurn(Grid* pGrid) {
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	currentPlayer->Move(pGrid, 0);
}