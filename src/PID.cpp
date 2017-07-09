#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {

	//Kp_ = 0.15;
	//Ki_ = 0.0;
	//Kd_ = 0.05;

	p_error = 0; // init value
	i_error = 0; // init value
	d_error = 0; // init value

}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;
}

void PID::UpdateError(double cte)
{

	d_error = cte - p_error;

	p_error = cte;

	i_error += cte; 
}

double PID::SendControl()
{
	return - p_error * Kp_ - i_error * Ki_ - d_error * Kd_;
}

