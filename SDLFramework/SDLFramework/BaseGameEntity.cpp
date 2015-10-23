#include "BaseGameEntity.h"

/// <summary>	The next valid identifier for the base game entity. </summary>
int BaseGameEntity::nextValidID = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///  
///  Create a base game entity by providing an id, an entity type, a position and a radius
///  
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="id">		   	The identifier. </param>
/// <param name="_entity_type">	Type of the entity. </param>
/// <param name="_pos">		   	The position. </param>
/// <param name="_r">		   	The r. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

BaseGameEntity::BaseGameEntity(int id, int _entity_type, Vector2D _pos, double _r) : position(_pos),
boundingRadius(_r),
id(nextValidID),
scale(Vector2D(1.0, 1.0)),
entityType(_entity_type),
tag(false)
{
	SetID(id);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

BaseGameEntity::~BaseGameEntity()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the identifier for the base game entity. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="val">	The value. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void BaseGameEntity::SetID(int val)
{
	if (val >= nextValidID)
	{
		id = val;
		nextValidID++;
	}
}