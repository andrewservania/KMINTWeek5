#pragma once
#include "Node.h"
#include "Vehicle.h"
#include "StateMachine.h"
#include "Vector2D.h"
#include "SteeringBehaviors.h"
#include "Smoother.h"
#include "Cow.h"
#include "Weapon.h"
#include "Pill.h"

#include <string>

class Rabbit :
	public Vehicle
{
private:
	int score;
	std::string instanceColor;
public:
	Node* currentNode;
	StateMachine<Rabbit>* stateMachine;
	SteeringBehavior* steeringBehavior;
	Cow& enemy;
	Color* color;
	Weapon* weapon;
	Pill* pill;
	bool pickedUpWeapon;
	bool pickedUpPill;

	Rabbit(int id,
		Vector2D _position,
		double _rotation,
		Vector2D _velocity,
		double _mass,
		double _max_force,
		double _max_speed,
		double _max_turn_rate,
		double _scale, 
		Cow& enemy);

	~Rabbit();
	virtual void Update(float deltaTime) override;
	virtual void Draw()override;
	void OnLeftClick();
	void OnRightClick();
	Node* getCurrentNode() { return currentNode; }
	std::string GetCurrentState() { return stateMachine->CurrentState()->GetStateName(); }
	StateMachine<Rabbit>* GetFSM() { return stateMachine; }
	SteeringBehavior* Steering() const { return steeringBehavior; }

	Cow& GetEnemy() { return enemy; }
	void SetEnemy(Cow& _val){ enemy = _val; }
	Color* GetColor(){ return color; }
	Weapon* GetWeapon() { return weapon; }
	Pill* GetPill() { return pill; }

	void SetColor(Color* _color) { color = _color; }
	void SetPill(Pill* _pill){ pill = _pill; }
	void SetWeapon(Weapon* _weapon) { weapon = _weapon; }
	void Respawn();
	void SetScore(int val){ score = val; }
	int GetScore(){ return score; }
	void Reset();

	std::string GetInstanceColor() { return instanceColor; }
	void SetInstanceColor(std::string val){ instanceColor = val; }

};
