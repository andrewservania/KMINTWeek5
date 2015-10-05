#include "MovingEntity.h"


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


MovingEntity::~MovingEntity()
{
}

void MovingEntity::Update(float deltaTime)
{


}