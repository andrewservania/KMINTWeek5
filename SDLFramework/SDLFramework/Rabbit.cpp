#include "Rabbit.h"
#include "RabbitWanderingState.h"
#include "Parameters.h"

Rabbit::Rabbit(int id,
	Vector2D _position,
	double _rotation,
	Vector2D _velocity,
	double _mass,
	double _max_force,
	double _max_speed,
	double _max_turn_rate,
	double _scale) : Vehicle(id,
					_position,
					_rotation,
					_velocity,
					_mass,
					_max_force,
					_max_speed,
					_max_turn_rate,
					_scale)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	pickedUpPill = false;
	pickedUpWeapon = false;

	// set the location of the cow on the screen
	mX = static_cast<uint32_t>(position.x);
	mY = static_cast<uint32_t>(position.y);

	// set up the steering behavior class
	steering = new SteeringBehavior(this);

	//set up the smoother
	headingSmoother = new Smoother<Vector2D>(Parameters::Instance()->NumSamplesForSmoothing, Vector2D(0.0, 0.0));

	//add cow to renderable objects
	mApplication->AddRenderable(this);

	// Add sample code here that is responsible for updating the cow
	// Set up the state machine
	stateMachine = new StateMachine<Rabbit>(this);
	stateMachine->SetCurrentState(RabbitWanderingState::Instance());
	//stateMachine->SetGlobalState()

}

Rabbit::~Rabbit()
{
}

void Rabbit::Update(float deltaTime)
{
	stateMachine->Update();

	double elapsedTime = static_cast<double>(deltaTime);

	// calculate the combined force from each steering behavior in the vehicle's list
	Vector2D SteeringForce = steering->Calculate();

	// Accelaration = Force/Mass
	Vector2D acceleration = SteeringForce / mass;

	// update velocity
	velocity += acceleration * elapsedTime;

	// make sure vehicle does not exceed maximum velocity
	velocity.Truncate(maxSpeed);

	// update the position
	position += velocity * elapsedTime;

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
	WrapAround(position, 1300, 700);

	if (isSmoothingOn()) smoothedHeading = headingSmoother->Update(Heading());
}

// Draw the rabbit texture
void Rabbit::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}

// Execute code if rabbit has been left-clicked upon
void Rabbit::OnLeftClick()
{
	printf("Left-clicked on rabbit!\n");
}

// Execute code if rabbit has been right-clicked upon
void Rabbit::OnRightClick()
{
	printf("Right-clicked on rabbit!\n");
}

void Rabbit::setCurrentNode(Node* node)
{
	currentNode = node;
	mX = node->GetBoundingBox().x;
	mY = node->GetBoundingBox().y;
}