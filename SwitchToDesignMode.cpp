#include "SwitchToDesignMode.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDesignMode::ReadActionParameters()
{
}

void SwitchToDesignMode::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	// Call for End Game
	pGrid->ResetPlayersInfo();

	// Create Toolbar
	pOut->CreateDesignModeToolBar();
}

SwitchToDesignMode::~SwitchToDesignMode()
{
}