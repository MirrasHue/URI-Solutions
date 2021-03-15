#include <iostream>
#include <cmath>
#include <vector>

class shape
{
    int x, y;
public:
    shape(int _x, int _y) : x(_x), y(_y) {}
    double Distance(const shape& OtherShape);
};

double shape::Distance(const shape& OtherShape)
{
    return sqrt(pow(x - OtherShape.x, 2) + pow(y - OtherShape.y, 2));
}

int main()
{
    int width, length, r1, r2;
    
    while(std::cin>>width>>length>>r1>>r2 && (r1 && r2))
    {
        shape Cylinder1(r1, length - r1), // First cylinder at the top left corner
              Cylinder2(width - r2, r2); // Second cylinder at the bottom right corner

        double distance = Cylinder2.Distance(Cylinder1);

        if(distance < r1 + r2 || (r1 > width / 2.f || r1 > length / 2.f || r2 > width / 2.f || r2 > length / 2.f))
            std::cout<<"N\n";
        else
            std::cout<<"S\n";
    }

    return 0;
}
