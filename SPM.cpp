
#include <vector>
#include <iostream> 
#include <string>
#include <cmath>

double g = 9.8; // gravity
double PI = 4*atan(1); // PI


using namespace std;

void printPos(double pos[], double t);

int main(/*int argc, char* argv[]*/) { 
    
    // Simulation Parameters, eventual inputs from user
    
    double timeSeg = 0.01; // seconds, how much time has passed between each calculation
    double iVelMag = 2; // total velocity magnitude in m/s
    double angRad = PI/4; // angle of projectile in radians
   

    //Initalizations
    
    double time = 0; // total time
    
    double vel[2]; // (m/s) velocity has two components: (x,y)
    vel[0] = iVelMag*cos(angRad); // x vel (horizontal)
    vel[1] = iVelMag*sin(angRad); // y vel (vertical)
    
    double iPos[2] = {0}; // initial position 
    double pos[2] = {0}; // updated position array based on time (meters)
    
    
    // while loop and will stop when projectile hits to ground. 
    // Currently no bouncing
    
    while(pos[1]>=0) {
        // Prints out position first
        printPos(pos, time);
        
        // Adds the time segment to the total time
        time+=timeSeg;
        
        // updates position
        pos[0] = iPos[0] + vel[0]*time;
        pos[1] = iPos[1] + vel[1]*time - g*pow(time,2)/2;
    
    }
    
    return 0;
}

// Prints out position in meters at given time
void printPos(double pos[], double t) {
    cout<<"\nAt time "<<t<<" seconds, the position is ("
                <<pos[0]<<", "<<pos[1]<<") meters\n";
}