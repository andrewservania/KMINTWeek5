#include "Rabbit.h"
#include "Parameters.h"
#include "RabbitGlobalState.h"
#include "Dashboard.h"
#include "RabbitPursuitState.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. Create a rabbit by providing the an ID, a position vector, a rotation
/// 			value, a velocity vector, a mass value, a maximum force, a maximum speed, a maximum
/// 			turn rate and a scale.
///
/// 			During the instantiation of rabbit the following actions will be taken:
/// 			1) A picture of the rabbit will be created.
/// 			2) pill and weapon pickup flags will be set to false.
/// 			3) score will be set to 0.
/// 			4) the rabbit will be given a steering behavior
/// 			5) the heading smoother will be instantiated
/// 			6) the rabbit will be added to items that must be shown on screen
/// 			7) the rabbit will be given a state machine
/// 			8) the rabbit's state will be set to a Global state
/// 			   the rabbit will not move or do anything else during while being in a Global state
/// 		   10) the rabbit's color will be set to 0.
/// 		     </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="id">			 	The identifier. </param>
/// <param name="_position">	 	The position. </param>
/// <param name="_rotation">	 	The rotation. </param>
/// <param name="_velocity">	 	The velocity. </param>
/// <param name="_mass">		 	The mass. </param>
/// <param name="_max_force">	 	The maximum force. </param>
/// <param name="_max_speed">	 	The maximum speed. </param>
/// <param name="_max_turn_rate">	The maximum turn rate. </param>
/// <param name="_scale">		 	The scale. </param>
/// <param name="_enemy">		 	[in,out] The enemy. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Rabbit::Rabbit(int id,
	Vector2D _position,
	double _rotation,
	Vector2D _velocity,
	double _mass,
	double _max_force,
	double _max_speed,
	double _max_turn_rate,
	double _scale, Cow& _enemy) : Vehicle(id,
	_position,
	_rotation,
	_velocity,
	_mass,
	_max_force,
	_max_speed*1.7,
	_max_turn_rate,
	_scale),
	enemy(_enemy)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	pickedUpPill = false;
	pickedUpWeapon = false;
	score = 0;

	// set up the steering behavior class
	steeringBehavior = new SteeringBehavior(this);

	//set up the smoother
	headingSmoother = new Smoother<Vector2D>(Parameters::Instance()->NumSamplesForSmoothing, Vector2D(0.0, 0.0));

	//add cow to renderable objects
	mApplication->AddRenderable(this);

	// Add sample code here that is responsible for updating the cow
	// Set up the state machine
	stateMachine = new StateMachine<Rabbit>(this);
	stateMachine->SetCurrentState(RabbitGlobalState::Instance());

	// Initialize with 'no' color
	color = new Color(0, 0, 0, 255);
	//add cow to renderable objects
	mApplication->AddRenderable(this);

	instanceColor = "null";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Rabbit::~Rabbit()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The rabbit will be updated
///
/// 			1) The state of the rabbit will be updated.
/// 			2) The force-driven movement of the rabbit will be calculated, regulated and updated
/// 			3) The arena will be treated as toroid, therefore the movement of the rabbit will be
/// 		       regulated to move accordingly. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::Update(float deltaTime)
{
	stateMachine->Update();

	double elapsedTime = static_cast<double>(deltaTime);

	// calculate the combined force from each steering behavior in the vehicle's list
	Vector2D SteeringForce = steeringBehavior->Calculate();

	// Accelaration = Force/Mass
	Vector2D acceleration = SteeringForce / mass;

	// update velocity
	velocity += acceleration * elapsedTime;

	// make sure vehicle does not exceed maximum velocity
	velocity.Truncate(maxSpeed);

	// update the position
	position += velocity * elapsedTime;

	//update the heading if the cow has a velocity greater than a very small
	//value
	if (velocity.LengthSq() > 0.00000001)
	{
		heading = Vec2DNormalize(velocity);

		side = heading.Perp();
	}

	// treat the screen as a toroid. Current window resolution is 1300x700
	WrapAround(position, 800, 800);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw the rabbit texture. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::Draw()
{
	mApplication->DrawTexture(mTexture, static_cast<int>(position.x), static_cast<int>(position.y), 100, 100, Color(color->r, color->b, color->g, 255));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> NOT IN USE Trigger an action if the rabbit is left-clicked on.
/// 		  Print in console window
/// 		  </summary>
///
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::OnLeftClick()
{
	printf("Left-clicked on rabbit!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> NOT IN USE Trigger an action if the rabbit is right-clicked on.
/// 		  Print in console window
/// 		  </summary>
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::OnRightClick()
{
	printf("Right-clicked on rabbit!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Respawns the rabbit at a random location.
/// 			Set its velocity to 0.
/// 			Set the state of the rabbit to Pursuit. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::Respawn()
{
	position = Vector2D(600, 200 + rand() % 200);
	velocity = Vector2D(0, 0);
	stateMachine->SetCurrentState(RabbitPursuitState::Instance());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Resets the rabbit.
/// 			The rabbit is put on a random location on the screen
/// 			Set velocity to a vector of x=200 and y=100.
/// 			Set the rabbit's state to Pursuit. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::Reset()
{
	SetScore(0);
	position = Vector2D(600, 200 + rand() % 200);
	velocity = Vector2D(200, 100);
	stateMachine->SetCurrentState(RabbitPursuitState::Instance());
}