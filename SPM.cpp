
#include <vector>
#include <iostream> 
#include <string>
#include <cmath>

double g = 9.8;
double PI = 4*atan(1);


using namespace std;

void printPos(double pos[], double t);

int main(/*int argc, char* argv[]*/) { 
    
    double time = 0;
    double timeSeg = 0.01;
    double iVelMag = 2;
    double angRad = PI/4;
    
    double vel[2];
    vel[0] = iVelMag*cos(angRad);
    vel[1] = iVelMag*sin(angRad);
    
    double iPos[2] = {0};
    double pos[2] = {0};
    
    while(pos[1]>=0) {
        printPos(pos, time);
        
        time+=timeSeg;
        
        pos[0] = iPos[0] + vel[0]*time;
        pos[1] = iPos[1] + vel[1]*time - g*pow(time,2)/2;
    
    }
    
    return 0;
}

void printPos(double pos[], double t) {
    cout<<"\nAt time "<<t<<" seconds, the position is ("<<pos[0]<<", "<<pos[1]<<") meters\n";
}