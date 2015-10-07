#include "Weapon.h"
#include "Graph.h"
#include "RabbitWanderingState.h"

Weapon::Weapon(uint32_t _x, uint32_t _y)
{
	
	mTexture = mApplication->LoadTexture("gun-metal.png");

	mX = _x;
	mY = _y;
	mApplication->AddRenderable(this);
}

Weapon::~Weapon()
{
}

void Weapon::Update(float deltaTime)
{

}

void Weapon::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 50, 50);
};

// Put the weapon at a new location
void Weapon::SetCurrentNode(Node* newNode)
{

}

void Weapon::PutOnRandomLocation()
{

}