#include "Parameters.h"




double Parameters::NumAgents = 1;

double Parameters::NumObstacles = 7;
double Parameters::MinObstacleRadius = 10;
double Parameters::MaxObstacleRadius = 30;



//number of horizontal cells used for spatial partitioning
double Parameters::NumCellsX = 7;
//number of vertical cells used for spatial partitioning
double Parameters::NumCellsY = 7;


//how many samples the smoother will use to average a value
int Parameters::NumSamplesForSmoothing = 10;


//this is used to multiply the steering force AND all the multipliers
//found in SteeringBehavior
double Parameters::SteeringForceTweaker = 200.0;

double Parameters::SteeringForce = 2.0;
double Parameters::MaxSpeed = 50.0;
double Parameters::VehicleMass = 1.0;
double Parameters::VehicleScale = 3.0;

//use these values to tweak the amount that each steering force
//contributes to the total steering force
double Parameters::SeparationWeight = 1.0;
double Parameters::AlignmentWeight = 1.0;
double Parameters::CohesionWeight = 2.0;
double Parameters::ObstacleAvoidanceWeight = 10.0;
double Parameters::WallAvoidanceWeight = 10.0;
double Parameters::WanderWeight = 1.0;
double Parameters::SeekWeight = 1.0;
double Parameters::FleeWeight = 1.0;
double Parameters::ArriveWeight = 1.0;
double Parameters::PursuitWeight = 1.0;
double Parameters::OffsetPursuitWeight = 1.0;
double Parameters::InterposeWeight = 1.0;
double Parameters::HideWeight = 1.0;
double Parameters::EvadeWeight = 0.01;
double Parameters::FollowPathWeight = 0.05;

//how close a neighbour must be before an agent perceives it (considers it
//to be within its neighborhood)
double Parameters::ViewDistance = 50.0;

//used in obstacle avoidance
double Parameters::MinDetectionBoxLength = 40.0;

//used in wall avoidance
double Parameters::WallDetectionFeelerLength = 40.0;

//these are the probabilities that a steering behavior will be used
//when the Prioritized Dither calculate method is used to sum
//combined behaviors
 float Parameters::prWallAvoidance = 0.5;
 double Parameters::prObstacleAvoidance = 0.5;
 double Parameters::prSeparation = 0.2;
 double Parameters::prAlignment = 0.3;
 double Parameters::prCohesion = 0.6;
 double Parameters::prWander = 0.8;
 double Parameters::prSeek = 0.8;
 double Parameters::prFlee = 0.6;
 double Parameters::prEvade = 1.0;
 double Parameters::prHide = 0.8;
 double Parameters::prArrive = 0.5;
 double Parameters::MaxTurnRate = 3.14159;	 // add PI as max turn rate

Parameters::Parameters()
{
}


Parameters::~Parameters()
{
}
