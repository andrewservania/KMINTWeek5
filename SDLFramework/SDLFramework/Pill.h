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
	void SetColor(Color* _color){ color = _color; }
	void Respawn() { 
		SetPos(Vector2D(200 + rand() % 600, rand() % 800));
		
	
	}


	Color* GetColor() { return color; }
	Node* GetCurrentNode() { return currentNode; }
};
