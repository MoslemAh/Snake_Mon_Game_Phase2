#pragma once

#include "GameObject.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	static int numberOfLadders;

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	// ===================== Additional Functions ===================== //

	virtual bool IsOverlapping(GameObject* newObj) const;

	void Save(ofstream& OutFile, ObjectType Type);

	// void Load(ifstream& Infile, ObjectType Type);

	static int GetNumLadders();

	// =============================================================== //

	virtual ~Ladder(); // Virtual destructor
};

