#include "Weapon.h"
#include "Graph.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor.
/// 			Create a weapon by providing an id, a location on the arena. 
/// 			
/// 			1) A picture of a weapon is loaded to screen.  
/// 			2) The color of the weapon is set to "nothing"  
/// 			3) The weapon is added to items that must be shown on screen.
/// 			
/// 			
/// 			Furthemore a couple of other parameters get set to 0 as they
/// 			are not applicable for the weapon.</summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="_x">	The x coordinate. </param>
/// <param name="_y">	The y coordinate. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Weapon::Weapon(uint32_t _x, uint32_t _y) : Vehicle(1,
	Vector2D(_x, _y),0,
	Vector2D(0, 0),0,0,0,0,1)
{
	mTexture = mApplication->LoadTexture("gun-metal.png");

	position = Vector2D(_x, _y);
	// Initialize with 'no' color
	color = new Color(0, 0, 0, 255);

	mApplication->AddRenderable(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Weapon::~Weapon()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the weapon with a given delta time. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Weapon::Update(float deltaTime)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw the picture of the weapon on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Weapon::Draw()
{
	mApplication->DrawTexture(mTexture, static_cast<int>(position.x), static_cast<int>(position.y), 50, 50, Color(color->r, color->b, color->g, 255));
};

