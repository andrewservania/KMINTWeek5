#include "BaseGameEntity.h"

int BaseGameEntity::nextValidID = 0;

BaseGameEntity::BaseGameEntity(int id, int _entity_type, Vector2D _pos, double _r) : position(_pos),
boundingRadius(_r),
id(nextValidID),
scale(Vector2D(1.0, 1.0)),
entityType(_entity_type),
tag(false)
{
	SetID(id);
}

BaseGameEntity::~BaseGameEntity()
{

}

void BaseGameEntity::SetID(int val)
{
	if (val >= nextValidID)
	{
		id = val;
		nextValidID++;
	}
}