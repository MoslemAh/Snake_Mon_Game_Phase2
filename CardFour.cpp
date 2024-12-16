#pragma once
#include "CardFour.h"
#include "Snake.h"

void CardFour::movePlayerToNextSnake(Grid* pGrid) {
		Player* currentPlayer = pGrid->GetCurrentPlayer();
		Cell* currentPlayerCell = currentPlayer->GetCell();
		CellPosition currentPlayerCellPosition = currentPlayerCell->GetCellPosition();
		Snake* nextSnake = pGrid->GetNextSnake(currentPlayerCellPosition);
		if (nextSnake != NULL) {
			Cell* nextSnakeCell = nextSnake->GetStartPosition();
			currentPlayer->Move(pGrid); // what should be the value of diceNumber?
		}
}