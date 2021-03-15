#include <iostream>
#include <cmath>

class Circle
{
    int radius;
    int x, y;
public:
    Circle(int _x, int _y, int _radius);
    bool IsInside(const Circle& OtherCircle);
};

Circle::Circle(int _radius, int _x, int _y)
    : radius(_radius), x(_x), y(_y)
{}

bool Circle::IsInside(const Circle& OtherCircle)
{
    float distance = sqrt(pow(x - OtherCircle.x, 2) + pow(y - OtherCircle.y, 2));
    
    if(OtherCircle.radius >= distance + radius)
        return true;
    else
        return false;
}

int main()
{
    int r1, x1, y1, r2, x2, y2;

    while(std::cin>>r1>>x1>>y1>>r2>>x2>>y2)
    {
        Circle hunter(r1, x1, y1),
               flower(r2, x2, y2);

        if(flower.IsInside(hunter))
            std::cout<<"RICO"<<std::endl;
        else
            std::cout<<"MORTO"<<std::endl;
    }

    return 0;
}
