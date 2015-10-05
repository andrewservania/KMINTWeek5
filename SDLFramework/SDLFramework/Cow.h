#pragma once
#include "Node.h"

#include "Vehicle.h"
#include "StateMachine.h"
#include "Vector2D.h"
#include "SteeringBehaviors.h"
#include "Smoother.h"

class Cow :
	public Vehicle
{



public:
	Node* currentNode;
	StateMachine<Cow>* stateMachine;





	Cow(int id,
		Vector2D _position,
		double _rotation,
		Vector2D _velocity,
		double _mass,
		double _max_force,
		double _max_speed,
		double _max_turn_rate,
		double _scale);

	~Cow();
	virtual void Update(float deltaTime) override;
	virtual void Draw()override;
	//void OnClick(SDL_Event &event);
	//void OnLeftClick(SDL_Event &event);
	//void OnRightClick(SDL_Event &event);
	void setCurrentNode(Node* node);
	Node* getCurrentNode() { return currentNode; };
	StateMachine<Cow>* GetFSM() const { return stateMachine; }
	std::string GetCurrentState() { return stateMachine->CurrentState()->GetStateName(); }
	void PutOnRandomLocation();

	//// Accessor methods
	//SteeringBehavior* Steering() const { return steering; }
	//Vector2D SmoothingHeading() const { return smoothedHeading; }
	//bool isSmoothingOn() const { return smoothingOn; }
	//bool SmoothingOn() { smoothingOn = true; }
	//bool SmoothingOff() { smoothingOn = false; }
	//bool ToggleSmoothing() { return !smoothingOn; }
	//double TimeElapsed() const { return timeElapsed; }


};
