#include "Cow.h"
#include <memory>
#include <assert.h>
#include "CowGlobalState.h"
#include "Parameters.h"
#include "CowWanderingState.h"
#include "Dashboard.h"

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// Create a cow by providing an identifier, a position a, rotation value, a velocity value,
/// a mass, a maximum force, a maximum speed, a maximum turn rate, a scale value and an enemy,
/// in this case a rabbit.
/// 
/// The cow is created by 
/// 1) being added to items that need to in the Arena,   
/// 2) setting its score to 0  
/// 3) loading a cow picture  
/// 4) giving it a steering behavior  
/// 5) setting a heading smoother  
/// 6) giving it a set of random percentage values on the chances for its choices (Probability distribution)  
/// 7) give it a state machine   
/// 8) set the state machine to an initial global state  
/// 9) set the cow's color to "nothing"
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
/// <param name="_enemy">		 	[in,out] If non-null, the enemy. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

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
	cowDoesNotMove = false;
	score = 0;
	//smoothedHeading = Vector2D(0, 0);
	//smoothingOn = true ;
	//timeElapsed = 0.0;

	//Load the picture corresponding to the cow
	mTexture = mApplication->LoadTexture("cow-1.png");
	//position = _position;
	
	// set the location of the cow on the screen
	//mX = static_cast<uint32_t>(position.x);
	//mY = static_cast<uint32_t>(position.y);



	// set up the steering behavior class
	steeringBehavior = new SteeringBehavior(this);

	// set up the smoother
	headingSmoother = new Smoother<Vector2D>(Parameters::Instance()->NumSamplesForSmoothing, Vector2D(0.0, 0.0));

	// instantiate probability with random values
	probabilityDistribution = new ProbabilityDistribution();

	// Set up the state machine
	stateMachine = new StateMachine<Cow>(this);
	stateMachine->SetCurrentState(CowGlobalState::Instance());

	// Initialize with 'no' color
	color = new Color(0, 0, 0, 255);
	//add cow to renderable objects
	mApplication->AddRenderable(this);
	instanceColor = "null";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the cow with a given deltaTime. </summary>
///
/// 1) The current state of the cow is updated.  
/// 2) The force-driven speed of the cow is calculated and regulated  
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Update(float deltaTime)
{
	stateMachine->Update();

	timeElapsed = static_cast<double>(deltaTime);


	if (!cowDoesNotMove){
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


		//update the heading if the cow has a velocity greater than a very small
		//value
		if (velocity.LengthSq() > 0.00000001)
		{
			heading = Vec2DNormalize(velocity);

			side = heading.Perp();
	}

	   // treat the screen as a toroid. Current window resolution is 800 x 800
	   WrapAround(position, 800, 800);


	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///  
///  The state machine is deleted.
///  
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Cow::~Cow()
{
	delete stateMachine;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the current node of the cow to a new node. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="node">	[in,out] If non-null, the node. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::setCurrentNode(Node* node)
{
	currentNode = node;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draws the picture of the cow on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Draw()
{
	mApplication->DrawTexture(mTexture, static_cast<int>(position.x), static_cast<int>(position.y), 100, 100, Color(color->r,color->b,color->g,255));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Respawns this object. 
/// The position of the cow is determined at random
/// The velocity of the cow is set to 0.	
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Respawn()
{
	position = Vector2D(200, rand() % 800);
	velocity = Vector2D(0, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Resets this object.
/// The position of the cow is determined at random.
/// The velocity of the cow is set to a 2D vector of x=200 and y=100
/// The cow's current state is set back to a Wandering State
/// The cow will now be able to move again
///  			
///  </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Reset()
{
	SetScore(0);
	position = Vector2D(200, rand() % 800);
	velocity = Vector2D(200, 100);
	stateMachine->SetCurrentState(CowWanderingState::Instance());
	DoesNotMove_Off();
	
}
