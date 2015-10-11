#include "Pill.h"
#include "Graph.h"
#include "RabbitWanderingState.h"

Pill::Pill(uint32_t _x, uint32_t _y) :
	Vehicle(1,
	Vector2D(_x, _y), 0,
	Vector2D(0, 0),
	0,
	0,
	0,
	0,
	1)
{
	mTexture = mApplication->LoadTexture("pill.png");
	mX = _x;
	mY = _y;

	// Initialize with 'no' color
	color = new Color(0, 0, 0, 255);

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
	mApplication->DrawTexture(mTexture, mX, mY, 50, 50,Color(color->r, color->b, color->g, 255));
	
};

// Put the pill at a new location
void Pill::SetCurrentNode(Node* newNode)
{

}

// Respawn the pill somewhere else, aslong its not at the same place as the cow, the rabbit or the weapon
void Pill::PutOnRandomLocation()
{

}