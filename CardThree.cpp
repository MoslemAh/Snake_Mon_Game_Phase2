#include "CardThree.h"
#include "Grid.h"
#include "Player.h"
#include "CellPosition.h"
#include "GameObject.h"
#include "Ladder.h"

CardThree::CardThree() {

}


void CardThree::MovePlayerToNextLadderInGrid(Player* player, Grid* pGrid) {
	CellPosition currentCellPosition = player->GetCell()->GetCellPosition();
	Ladder* nextLadder = pGrid->GetNextLadder(currentCellPosition);
	CellPosition nextLadderCellPosition = nextLadder->GetPosition();
	if (nextLadder != NULL) {
		pGrid->UpdatePlayerCell(player, nextLadderCellPosition);
	}
}