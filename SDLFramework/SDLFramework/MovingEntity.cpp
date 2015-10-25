#include "MovingEntity.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. Create a moving entity by providing an identifier, a position vector,
/// a radius a velocity vector, a maximum speed, a heading vector, a mass, a scale, a turn rate,
/// and a maximum force.
///   </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="id">		 	The identifier. </param>
/// <param name="_position"> 	The position. </param>
/// <param name="_radius">   	The radius. </param>
/// <param name="_velocity"> 	The velocity. </param>
/// <param name="_max_speed">	The maximum speed. </param>
/// <param name="_heading">  	The heading. </param>
/// <param name="_mass">	 	The mass. </param>
/// <param name="_scale">	 	The scale. </param>
/// <param name="_turn_rate">	The turn rate. </param>
/// <param name="_max_force">	The maximum force. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

MovingEntity::MovingEntity(int id,
	Vector2D _position,
	double    _radius,
	Vector2D _velocity,
	double    _max_speed,
	Vector2D _heading,
	double    _mass,
	Vector2D _scale,
	double    _turn_rate,
	double    _max_force) : BaseGameEntity(id, 0, _position, _radius),
	heading(_heading),
	velocity(_velocity),
	mass(_mass),
	side(_heading.Perp()),
	maxSpeed(_max_speed),
	maxTurnRate(_turn_rate),
	maxForce(_max_force)
{
	scale = _scale;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

MovingEntity::~MovingEntity()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the the moving entity with a given delta time </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void MovingEntity::Update(float deltaTime)
{
}