#include "Parameters.h"




/// <summary>	The parameters number agents. </summary>
double Parameters::NumAgents = 1;

/// <summary>	The parameters number obstacles. </summary>
double Parameters::NumObstacles = 7;
/// <summary>	The parameters minimum obstacle radius. </summary>
double Parameters::MinObstacleRadius = 10;
/// <summary>	The parameters maximum obstacle radius. </summary>
double Parameters::MaxObstacleRadius = 30;

/// <summary>	number of horizontal cells used for spatial partitioning. </summary>
double Parameters::NumCellsX = 7;
/// <summary>	number of vertical cells used for spatial partitioning. </summary>
double Parameters::NumCellsY = 7;


/// <summary>	how many samples the smoother will use to average a value. </summary>
int Parameters::NumSamplesForSmoothing = 10;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// this is used to multiply the steering force AND all the multipliers found in SteeringBehavior.
/// </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////

double Parameters::SteeringForceTweaker = 200.0;

/// <summary>	The parameters steering force. </summary>
double Parameters::SteeringForce = 2.0;
/// <summary>	The parameters maximum speed. </summary>
double Parameters::MaxSpeed = 50.0;
/// <summary>	The parameters vehicle mass. </summary>
double Parameters::VehicleMass = 1.0;
/// <summary>	The parameters vehicle scale. </summary>
double Parameters::VehicleScale = 3.0;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// use these values to tweak the amount that each steering force contributes to the total
/// steering force.
/// </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////

double Parameters::SeparationWeight = 1.0;
/// <summary>	The parameters alignment weight. </summary>
double Parameters::AlignmentWeight = 1.0;
/// <summary>	The parameters cohesion weight. </summary>
double Parameters::CohesionWeight = 2.0;
/// <summary>	The parameters obstacle avoidance weight. </summary>
double Parameters::ObstacleAvoidanceWeight = 10.0;
/// <summary>	The parameters wall avoidance weight. </summary>
double Parameters::WallAvoidanceWeight = 10.0;
/// <summary>	The parameters wander weight. </summary>
double Parameters::WanderWeight = 1.0;
/// <summary>	The parameters seek weight. </summary>
double Parameters::SeekWeight = 1.0;
/// <summary>	The parameters flee weight. </summary>
double Parameters::FleeWeight = 1.0;
/// <summary>	The parameters arrive weight. </summary>
double Parameters::ArriveWeight = 1.0;
/// <summary>	The parameters pursuit weight. </summary>
double Parameters::PursuitWeight = 1.0;
/// <summary>	The parameters offset pursuit weight. </summary>
double Parameters::OffsetPursuitWeight = 1.0;
/// <summary>	The parameters interpose weight. </summary>
double Parameters::InterposeWeight = 1.0;
/// <summary>	The parameters hide weight. </summary>
double Parameters::HideWeight = 1.0;
/// <summary>	The parameters evade weight. </summary>
double Parameters::EvadeWeight = 0.01;
/// <summary>	The parameters follow path weight. </summary>
double Parameters::FollowPathWeight = 0.05;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// how close a neighbour must be before an agent perceives it (considers it to be within its
/// neighborhood)
/// </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////

double Parameters::ViewDistance = 50.0;

/// <summary>	used in obstacle avoidance. </summary>
double Parameters::MinDetectionBoxLength = 40.0;

/// <summary>	used in wall avoidance. </summary>
double Parameters::WallDetectionFeelerLength = 40.0;

 ////////////////////////////////////////////////////////////////////////////////////////////////////
 /// <summary>
 /// these are the probabilities that a steering behavior will be used when the Prioritized Dither
 /// calculate method is used to sum combined behaviors.
 /// </summary>
 ////////////////////////////////////////////////////////////////////////////////////////////////////

 float Parameters::prWallAvoidance = 0.5;
 /// <summary>	The parameters pr obstacle avoidance. </summary>
 double Parameters::prObstacleAvoidance = 0.5;
 /// <summary>	The parameters pr separation. </summary>
 double Parameters::prSeparation = 0.2;
 /// <summary>	The parameters pr alignment. </summary>
 double Parameters::prAlignment = 0.3;
 /// <summary>	The parameters pr cohesion. </summary>
 double Parameters::prCohesion = 0.6;
 /// <summary>	The parameters pr wander. </summary>
 double Parameters::prWander = 0.8;
 /// <summary>	The parameters pr seek. </summary>
 double Parameters::prSeek = 0.8;
 /// <summary>	The parameters pr flee. </summary>
 double Parameters::prFlee = 0.6;
 /// <summary>	The parameters pr evade. </summary>
 double Parameters::prEvade = 1.0;
 /// <summary>	The parameters pr hide. </summary>
 double Parameters::prHide = 0.8;
 /// <summary>	The parameters pr arrive. </summary>
 double Parameters::prArrive = 0.5;
 /// <summary>	add PI as max turn rate. </summary>
 double Parameters::MaxTurnRate = 3.14159;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Parameters::Parameters()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Parameters::~Parameters()
{
}
