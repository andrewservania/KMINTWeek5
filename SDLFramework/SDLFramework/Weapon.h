#pragma once
#include "Node.h"
#include "Vehicle.h"

class Weapon :
	public Vehicle
{
public:
	Node* currentNode;
	bool isPickedUp;
	Color* color;

	Weapon(
		uint32_t _x,
		uint32_t _y);

	~Weapon();




	void Update(float deltaTime) override;
	void Draw() override;
	void SetCurrentNode(Node* newNode);
	Node* GetCurrentNode() { return currentNode; }
	void PutOnRandomLocation();

	void SetColor(Color* _color){ color = _color; }
	Color* GetColor() { return color; }
	
};
