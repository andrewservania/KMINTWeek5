#include "Pill.h"
#include "Graph.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor.
/// 			1) Create a pill and put it to items that have to be shown on screen.  
/// 			2) load a pill picture  
/// 			3) give the pill some coordinates on the arena.    
/// 			4) Set the color of the pill to "nothing"
/// 			
/// 			The pill automatically gets an ID of two, some parameters are set to zero as they
/// 			are not relevant for the pill. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="_x">	The x coordinate. </param>
/// <param name="_y">	The y coordinate. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Pill::Pill(uint32_t _x, uint32_t _y) :
	Vehicle(2,
	Vector2D(_x, _y), 0,
	Vector2D(0, 0),0,0,0,0,1)
{
	mTexture = mApplication->LoadTexture("pill.png");

	position = Vector2D( _x,_y);

	// Initialize with 'no' color
	color = new Color(0, 0, 0, 255);

	mApplication->AddRenderable(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Pill::~Pill()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Update the pill
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Pill::Update(float deltaTime)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw the picutre of the pill on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Pill::Draw()
{
	mApplication->DrawTexture(mTexture, static_cast<int>(position.x), static_cast<int>(position.y), 50, 50,Color(color->r, color->b, color->g, 255));
	
};