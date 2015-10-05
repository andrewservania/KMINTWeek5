#pragma once
class Parameters
{
public:
	static double NumAgents;

	static double NumObstacles;
	static double MinObstacleRadius;
	static double MaxObstacleRadius;



		//number of horizontal cells used for spatial partitioning
	static double NumCellsX;
		//number of vertical cells used for spatial partitioning
	static double NumCellsY;


		//how many samples the smoother will use to average a value
	static int NumSamplesForSmoothing;


		//this is used to multiply the steering force AND all the multipliers
		//found in SteeringBehavior
	static double SteeringForceTweaker;

	static double SteeringForce;
	static double MaxSpeed;
	static double VehicleMass;
	static double VehicleScale;

		//use these values to tweak the amount that each steering force
		//contributes to the total steering force
	static double SeparationWeight;
	static double AlignmentWeight;
	static double CohesionWeight;
	static double ObstacleAvoidanceWeight;
	static double WallAvoidanceWeight;
	static double WanderWeight;
	static double SeekWeight;
	static double FleeWeight;
	static double ArriveWeight;
	static double PursuitWeight;
	static double OffsetPursuitWeight;
	static double InterposeWeight;
	static double HideWeight;
	static double EvadeWeight;
	static double FollowPathWeight;

		//how close a neighbour must be before an agent perceives it (considers it
		//to be within its neighborhood)
	static double ViewDistance ;

		//used in obstacle avoidance
	static double MinDetectionBoxLength;

		//used in wall avoidance
	static double WallDetectionFeelerLength;

		//these are the probabilities that a steering behavior will be used
		//when the Prioritized Dither calculate method is used to sum
		//combined behaviors
	static float prWallAvoidance;
	static double prObstacleAvoidance;
	static double prSeparation;
	static double prAlignment;
	static double prCohesion;
	static double prWander;
	static double prSeek;
	static double prFlee;
	static double prEvade;
	static double prHide;
	static double prArrive;
	static double Parameters::MaxTurnRate;	 // add PI as max turn rate


	Parameters();
	~Parameters();


	static Parameters* Instance()
	{
		static Parameters instance;

		return &instance;
	}
};

