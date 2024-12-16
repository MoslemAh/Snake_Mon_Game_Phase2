#include "SwitchToPlayMode.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToPlayMode::ReadActionParameters()
{
}

void SwitchToPlayMode::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	pGrid->ResetPlayersInfo();

	// Create Toolbar
	pOut->CreatePlayModeToolBar();
}

SwitchToPlayMode::~SwitchToPlayMode()
{
}