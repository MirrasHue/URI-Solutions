#include <iostream>
#include <cmath>

class vec2D
{
public:
    int x, y;
    vec2D(int _x, int _y) : x(_x), y(_y) {}
};

class Rectangle
{
public:
    vec2D LowLeft,
          UpRight,
          UpLeft,
          LowRight;

    Rectangle(int Xl, int Yl, int Xr, int Yr);
    double LeastTime(const vec2D& home, const vec2D& school);
};

Rectangle::Rectangle(int Xl, int Yl, int Xr, int Yr)
    : LowLeft(Xl, Yl), UpRight(Xr, Yr), UpLeft(Xl, Yr), LowRight(Xr, Yl)
{}

double Rectangle::LeastTime(const vec2D& home, const vec2D& school)
{
    int terrainWidth = LowRight.x - LowLeft.x;

    double distance = 
        std::min(
                    sqrt(pow(home.x - LowLeft.x, 2) + pow(home.y - LowLeft.y, 2)) + terrainWidth + sqrt(pow(LowRight.x - school.x, 2) + pow(LowRight.y - school.y, 2)),
                    sqrt(pow(home.x - UpLeft.x, 2) + pow(home.y - UpLeft.y, 2)) + terrainWidth + sqrt(pow(UpRight.x - school.x, 2) + pow(UpRight.y - school.y, 2))
                );

    return distance;
}

int main()
{
    // Jaozin's house coordinates & school coordinates
    int Xi, Yi, Xf, Yf, Vel;
    // Vacant lot's coordinates, bottom left corner & upper right corner
    int Xl, Yl, Xr, Yr;

    std::cout.precision(1);

    while(std::cin>>Xi>>Yi>>Xf>>Yf>>Vel >> Xl>>Yl>>Xr>>Yr)
    {
        vec2D home(Xi, Yi),
              school(Xf, Yf);

        Rectangle terrain(Xl, Yl, Xr, Yr);

        std::cout<<std::fixed<<terrain.LeastTime(home, school) / Vel<<'\n';
    }

    return 0;
}
