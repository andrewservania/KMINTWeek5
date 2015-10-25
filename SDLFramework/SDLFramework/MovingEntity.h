#pragma once
#include "BaseGameEntity.h"
#include "Vector2D.h"
class MovingEntity : public BaseGameEntity
{
protected:

	Vector2D velocity;

	// a normalized vector pointin the direction the entity is heading.
	Vector2D heading;

	// a vector perpendicular to the heading vector
	Vector2D side;

	double mass;

	// the maximum speed this entity may travel at.
	double maxSpeed;

	// the maximum force the entity can produce to power itself
	// (think rockets and thrust)
	double maxForce;

	// the maximum rate (radians per second) this vehicle can rotate
	double maxTurnRate;

public:
	MovingEntity(int id,
		Vector2D _position,
		double    _radius,
		Vector2D _velocity,
		double    _max_speed,
		Vector2D _heading,
		double    _mass,
		Vector2D _scale,
		double    _turn_rate,
		double    _max_force);

	~MovingEntity();
	virtual void Update(float deltaTime) = 0;

	Vector2D Velocity()const{ return velocity; }
	void SetVelocity(const Vector2D& NewVel){ velocity = NewVel; }

	double Mass()const{ return mass; }

	Vector2D Side()const{ return side; }

	double MaxSpeed()const{ return maxSpeed; }
	void SetMaxSpeed(double new_speed){ maxSpeed = new_speed; }

	double MaxForce()const{ return maxForce; }
	void SetMaxForce(double mf){ maxForce = mf; }

	bool IsSpeedMaxedOut()const{ return maxSpeed*maxSpeed >= velocity.LengthSq(); }
	double Speed()const{ return velocity.Length(); }
	double SpeedSq()const{ return velocity.LengthSq(); }

	Vector2D Heading()const{ return heading; }
	void SetHeading(Vector2D new_heading);
	bool RotateHeadingToFacePosition(Vector2D target);

	double MaxTurnRate()const{ return maxTurnRate; }
	void SetMaxTurnRate(double val){ maxTurnRate = val; }
};
