#pragma once
#include "Node.h"
#include "Vehicle.h"
#include "StateMachine.h"
#include "Vector2D.h"
#include "SteeringBehaviors.h"
#include "Smoother.h"
#include "Pill.h"
#include "Weapon.h"
#include "ProbabilityDistribution.h"

#include <string>
class Rabbit;

class Cow :
	public Vehicle
{
private:
	int score;
	bool cowDoesNotMove;
	std::string instanceColor;

public:
	Node* currentNode;
	StateMachine<Cow>* stateMachine;
	SteeringBehavior* steeringBehavior;
	Rabbit* enemy;
	Color* color;
	Pill* pill;
	Weapon* weapon;
	ProbabilityDistribution* probabilityDistribution;

	Cow(int id,
		Vector2D _position,
		double _rotation,
		Vector2D _velocity,
		double _mass,
		double _max_force,
		double _max_speed,
		double _max_turn_rate,
		double _scale, 
		Rabbit* _enemy);

	~Cow();
	virtual void Update(float deltaTime) override;
	virtual void Draw()override;

	void setCurrentNode(Node* node);
	Node* getCurrentNode() { return currentNode; };
	StateMachine<Cow>* GetFSM() const { return stateMachine; }
	std::string GetCurrentState() { return stateMachine->CurrentState()->GetStateName(); }
	void PutOnRandomLocation();

	//// Accessor methods
	SteeringBehavior* Steering() const { return steeringBehavior; }
	Rabbit* GetEnemy() { return enemy; }
	Color* GetColor() { return color; }
	Weapon* GetWeapon() { return weapon; }
	Pill* GetPill() { return pill; }

	void SetEnemy(Rabbit* _enemy) { enemy = _enemy; }
	void SetColor(Color* _color){ color = _color; }
	void SetPill(Pill* _pill){ pill = _pill; }
	void SetWeapon(Weapon* _weapon) { weapon = _weapon; }
	void Respawn();
	//Vector2D SmoothingHeading() const { return smoothedHeading; }
	//bool isSmoothingOn() const { return smoothingOn; }
	//bool SmoothingOn() { smoothingOn = true; }
	//bool SmoothingOff() { smoothingOn = false; }
	//bool ToggleSmoothing() { return !smoothingOn; }
	//double TimeElapsed() const { return timeElapsed; }
	void SetScore(int val){ score = val; }
	int GetScore(){ return score; }
	void Reset();
	void DoesNotMove_On(){ cowDoesNotMove = true; };
	void DoesNotMove_Off(){ cowDoesNotMove = false; };
	ProbabilityDistribution* GetProbabilityDistribution() { return probabilityDistribution; }

	std::string GetInstanceColor() { return instanceColor; }
	void SetInstanceColor(std::string val){ instanceColor = val; }

};
