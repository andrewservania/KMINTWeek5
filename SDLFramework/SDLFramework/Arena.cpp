#include "Arena.h"
#include "Parameters.h"


using namespace std;



Arena::Arena()
{

	for (int i = 0; i < 5; ++i)
	{
		auto instance = make_shared<InstanceOfGameEntities>();
		instance->SetColor(new Color(rand() % 220, rand() % 220, rand() % 220, 255));
	}
}


Arena::~Arena()
{

}
