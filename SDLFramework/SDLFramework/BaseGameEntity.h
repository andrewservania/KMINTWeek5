#pragma once
#include "IGameObject.h"
#include "Vector2D.h"
class BaseGameEntity :
	public IGameObject
{
private:

	int id;										// Every entity has a unique identifying number

	static int nextValidID;						// This is the next valid ID. Each time a BaseGameEntity is instantiated
	// this value is updated

	//this is a generic flag
	bool tag;

	// every entity has a type associated with (health, troll, ammo etc)
	int entityType;

	void SetID(int val);

protected:

	// The entity's location within the arena
	Vector2D position;
	Vector2D scale;

	//The length of this object's bounding radius
	double boundingRadius;


public:

	enum{default_entity_type =-1};

	BaseGameEntity(int id, int _entity_type, Vector2D _pos, double _r);

	virtual		 ~BaseGameEntity();
	virtual void Update(float deltaTime) = 0;

	Vector2D     Pos()const{ return position; }
	void         SetPos(Vector2D new_pos){ position = new_pos; }
	double        BRadius()const{ return boundingRadius; }
	void         SetBRadius(double r){ boundingRadius = r; }
	int          ID()const{ return id; }
	bool         IsTagged()const{ return tag; }
	void         Tag(){ tag = true; }
	void         UnTag(){ tag = false; }
	Vector2D     Scale()const{ return scale; }
	void         SetScale(Vector2D val){ boundingRadius *= MaxOf(val.x, val.y) / MaxOf(scale.x, scale.y); scale = val; }
	void         SetScale(double val){ boundingRadius *= (val / MaxOf(scale.x, scale.y)); scale = Vector2D(val, val); }
	int          EntityType()const{ return entityType; }
	void         SetEntityType(int new_type){ entityType = new_type; }
};
