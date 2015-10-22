#include "Weapon.h"
#include "Graph.h"



Weapon::Weapon(uint32_t _x, uint32_t _y) : Vehicle(1,
	Vector2D(_x, _y),0,
	Vector2D(0, 0),
	0,
	0,
	0,
	0,
	1)
{
	mTexture = mApplication->LoadTexture("gun-metal.png");

	position = Vector2D(_x, _y);
	// Initialize with 'no' color
	color = new Color(0, 0, 0, 255);

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
	mApplication->DrawTexture(mTexture, static_cast<int>(position.x), static_cast<int>(position.y), 50, 50, Color(color->r, color->b, color->g, 255));
};

// Put the weapon at a new location
void Weapon::SetCurrentNode(Node* newNode)
{

}

void Weapon::PutOnRandomLocation()
{

}