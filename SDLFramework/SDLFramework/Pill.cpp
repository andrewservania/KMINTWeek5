#include "Pill.h"
#include "Graph.h"
#include "RabbitWanderingState.h"

Pill::Pill(uint32_t _x, uint32_t _y)
{
	mTexture = mApplication->LoadTexture("pill.png");
	mX = _x;
	mY = _y;


	mApplication->AddRenderable(this);
}

Pill::~Pill()
{
}

// Check whether the cow has searching for the pill, if so make it chase the rabbit
void Pill::Update(float deltaTime)
{

}

// Draw the pill on screen
void Pill::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 50, 50);
};

// Put the pill at a new location
void Pill::SetCurrentNode(Node* newNode)
{

}

// Respawn the pill somewhere else, aslong its not at the same place as the cow, the rabbit or the weapon
void Pill::PutOnRandomLocation()
{

}