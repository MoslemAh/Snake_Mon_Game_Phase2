#pragma once

#include "GameObject.h"

class Snake : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the snake's "Start Cell Position"

	CellPosition endCellPos; // here is the snake's End Cell Position
	static int numberOfSnakes;

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the snake by moving player to snake's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	// ===================== Additional Functions ===================== //

	virtual bool IsOverlapping(GameObject* newObj) const;

	virtual void Save(ofstream& OutFile, ObjectType Type);

	// virtual void Load(ifstream& Infile, ObjectType Type);

	static int GetNumSnakes();

	// =============================================================== //

	virtual ~Snake(); // Virtual destructor
};

