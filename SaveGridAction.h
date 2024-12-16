#pragma once

#include "Action.h"
#include "GameObject.h"

class SaveGridAction : public Action
{
	Grid* pGrid;
	string fileName;

public:

	SaveGridAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
	// (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)

	virtual ~SaveGridAction();  // Virtual Destructor

};

