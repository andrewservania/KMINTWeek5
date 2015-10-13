#include "Cow.h"
#include <string>
#include <memory>
#include <assert.h>
#include "CowGlobalState.h"
#include "Parameters.h"
#include "CowWanderingState.h"
#include "Dashboard.h"
using namespace std;

Cow::Cow(int id,
	Vector2D _position,
	double _rotation,
	Vector2D _velocity,
	double _mass,
	double _max_force,
	double _max_speed,
	double _max_turn_rate,
	double _scale, Rabbit* _enemy) : Vehicle(id,
					 _position,
					 _rotation,
					 _velocity,
					 _mass,
					 _max_force,
					 _max_speed,
					 _max_turn_rate,
					 _scale),
					 enemy(_enemy)
					
{

	score = 0;
	//smoothedHeading = Vector2D(0, 0);
	//smoothingOn = false ;
	//timeElapsed = 0.0;

	//Load the picture corresponding to the cow
	mTexture = mApplication->LoadTexture("cow-1.png");
	
	// set the location of the cow on the screen
	mX = static_cast<uint32_t>(position.x);
	mY = static_cast<uint32_t>(position.y);



	// set up the steering behavior class
	steeringBehavior = new SteeringBehavior(this);

	//set up the smoother
	headingSmoother = new Smoother<Vector2D>(Parameters::Instance()->NumSamplesForSmoothing, Vector2D(0.0, 0.0));

	//add cow to renderable objects

	// Add sample code here that is responsible for updating the cow
	// Set up the state machine
	stateMachine = new StateMachine<Cow>(this);
	stateMachine->SetCurrentState(CowGlobalState::Instance());

	// Initialize with 'no' color
	color = new Color(0, 0, 0, 255);
	mApplication->AddRenderable(this);

}

void Cow::Update(float deltaTime)
{
	stateMachine->Update();

	timeElapsed = static_cast<double>(deltaTime);

	// calculate the combined force from each steering behavior in the vehicle's list
	Vector2D SteeringForce = steeringBehavior->Calculate();

	// Accelaration = Force/Mass
	Vector2D acceleration = SteeringForce / mass;

	// update velocity
	velocity += acceleration * timeElapsed;

	// make sure vehicle does not exceed maximum velocity
	velocity.Truncate(maxSpeed);

	// update the position
	position += velocity * timeElapsed;

	// set the actual location of the vehicle in the arena
	mX = static_cast<uint32_t>(position.x);
	mY = static_cast<uint32_t>(position.y);

	//update the heading if the cow has a velocity greater than a very smal
	//value
	if (velocity.LengthSq() > 0.00000001)
	{
		heading = Vec2DNormalize(velocity);

		side = heading.Perp();
	}

	// treat the screen as a toroid. Current window resolution is 1300x700
	WrapAround(position, 800, 600);

	if (isSmoothingOn()) smoothedHeading = headingSmoother->Update(Heading());
	
}

Cow::~Cow()
{
	delete stateMachine;
	//delete color;
}

void Cow::setCurrentNode(Node* node)
{
	currentNode = node;
	mX = node->GetBoundingBox().x;
	mY = node->GetBoundingBox().y;
}

// Draw cow texture
void Cow::Draw()
{
	Dashboard::Instance()->comment4 = "Cow x: " + to_string(mX);
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100, Color(color->r,color->b,color->g,255));

}



// Put the cow at a random node that is not the same as the rabbit, weapon and pill
void Cow::PutOnRandomLocation()
{

}

void Cow::Respawn()
{
	position = Vector2D(200, rand() % 600);
	velocity = Vector2D(200, 100);
	Reset();
}

void Cow::Reset()
{
	stateMachine->SetCurrentState(CowWanderingState::Instance());
}