#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
	Kp = Kp;
	Ki = Ki;
	Kd = Kd;

	p_error = -100; // init value
	i_error = -100; // init value
}

void PID::UpdateError(double cte)
{
	
	// Check if we already have a valid initialize p_error
	if(p_error == -100)
	{
		p_error = cte;
	}

	d_error = cte - p_error;





}

double PID::TotalError() 
{
	return i_error += cte; 
}

