#pragma once
#include "IGameObject.h"
#include "Node.h"
#include "Vehicle.h"
class Pill :
	public Vehicle
{
public:

	Node* currentNode;
	bool isPickedUp;
	Color* color;

	Pill(uint32_t _x, uint32_t _y);
	~Pill();
	void Update(float deltaTime) override;
	void Draw() override;
	void SetCurrentNode(Node* newNode);
	void PutOnRandomLocation();
	void SetColor(Color* _color){ color = _color; }
	void Respawn() { 
		SetPos(Vector2D(rand() % 800, rand() % 600));
		mX = static_cast<uint32_t>(position.x);
		mY = static_cast<uint32_t>(position.y);
	}


	Color* GetColor() { return color; }
	Node* GetCurrentNode() { return currentNode; }
};
