#include <cstdlib>
#include <iostream>
#include <math.h>

bool approxEqual(double x, double y, double threshold=0.00005){
            bool g = false;
            if (fabs(x - y) <= threshold){
                g = true;
            }
            return g;
}

int main(int argc, char* argv[]){
    double x = atof(argv[1]);
    double y = atof(argv[2]);

    std::cout << approxEqual(x, y);
    return 0;
}