#include "Vehicle.h"
//#include "C2DMatrix.h"
//#include "Geometry.h"
//#include "SteeringBehaviors.h"
//#include "Transformations.h"
//#include "GameWorld.h"
//#include "CellSpacePartition.h"
//#include "cgdi.h"
#include "Parameters.h"
Vehicle::Vehicle(int id,
	Vector2D _position,
	double _rotation,
	Vector2D _velocity,
	double _mass,
	double _max_force,
	double _max_speed,
	double _max_turn_rate,
	double _scale) : 
						MovingEntity(id,
						_position,
						_scale,
						_velocity,
						_max_speed,
						Vector2D(sin(_rotation), -cos(_rotation)),
						_mass,
						Vector2D(_scale, _scale),
						_max_turn_rate,
						_max_force),
	smoothedHeading(Vector2D(0,0)),
	smoothingOn(false),
	timeElapsed(0.0)
{

}


Vehicle::~Vehicle()
{
}

//void Vehicle::Update(float deltaTime)
//{
//	double elapsedTime = static_cast<double>(deltaTime);
//
//	// calculate the combined force from each steering behavoir in the
//	// vehicle's list
//	Vector2D SteeringForce = steering->Calculate();
//
//	// Acceleration = Force/Mass
//	Vector2D acceleration = SteeringForce / mass;
//
//	// update velocity
//	velocity += acceleration * elapsedTime;
//
//	// make sure vehicle does not exceed maximum velocity
//	velocity.Truncate(maxSpeed);
//
//	// update the position
//	position += velocity * elapsedTime;
//
//	// set the actual location of the vehicle in the arena
//	mX = static_cast<uint32_t>(position.x);
//	mY = static_cast<uint32_t>(position.y);
//
//	// update the heading if the vehicle has a velocity greater than a very small
//	// value
//	if (velocity.LengthSq() > 0.00000001)
//	{
//		heading = Vec2DNormalize(velocity);
//
//		side = heading.Perp();
//	}
//
//	//treat the screen as a toroid. Current window resolution is 1300x700
//	WrapAround(position, 1300, 700);
//	if (isSmoothingOn())
//	{
//		smoothedHeading =headingSmoother->Update(Heading());
//	}
//}

//void Vehicle::Draw()
//{
//	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
//}