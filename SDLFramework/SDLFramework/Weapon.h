#pragma once
#include "IGameObject.h"
#include "Node.h"
class Weapon :
	public IGameObject
{
public:
	Node* currentNode;
	bool isPickedUp;

	Weapon(uint32_t _x, uint32_t _y);
	~Weapon();
	void Update(float deltaTime) override;
	void Draw() override;
	void SetCurrentNode(Node* newNode);
	Node* GetCurrentNode() { return currentNode; }
	void PutOnRandomLocation();
};
