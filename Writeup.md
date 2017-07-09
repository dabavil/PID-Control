# Writeup for CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Describe the effect each of the P, I, D components had in your implementation.

The PID components were implemented using the formula 
    alpha = - p_error * P - i_error * I - d_error * D 
    
The P term has the effect of immediately steering the car in proportion to the cross-track error. 
It is enough to steer the car, but it overshoots and develops a significant 'wobble', especially at high speeds. 
However, even with just the P term the car was able to navigate the track at low speed (~10km/h).

How the car behaved with only P term implemented and constant throttle (0.3) is captured by the video:
[./Videos/P-controller-constant]


The D term takes into account the time differential of the CTE. I found it able to compensate for the wobble, but was only able to do so with relatively high coefficient, in the order of magnitude 10x of the P term. 
Still, at high speeds (~50km/h) the car develops a 'wobble', but not significant enough to drive off the track. It would not make the ride pleasant, however. 
How the car drove around the track with only P and D terms implemented is visible in video:
[./Videos/PD-controller-constant]

The I term compensates for long-term, systemic bias in the car's steering. I was surprised to find that it needs to be set to a relatively low value (vs the other components) to be useful. As the car drove around corners, inevitably a large cumulative CTE developed that drove the car off track. One of my first implementation of the controller including the I term can be seen here (the car started driving in circle)

[./Videos/PID-controller1-constant]



## Describe how the final hyperparameters were chosen.

I chose the final hyperparameters by manually tweaking them, in what was a manual approximation of twiddle.
I first set the "P" param to a value that was aggresive enough to get the car through tight corners. Then I set the "D" parameter to a value that compensated for the overshooting of the car. Finally, I implemented a "I" parameter with value that stabilized the car over time (course of several laps). 

My final selected coefficients were:
P = 0.15
I = 0.00001
D = 1.7
