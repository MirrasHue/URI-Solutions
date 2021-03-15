#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

class Point2D
{
public:
    Point2D() = default;
    Point2D(int _x, int _y) : x(_x), y(_y) {}

    int x, y;
    static Point2D BottomMost;
};

Point2D Point2D::BottomMost = Point2D(0, 0);

float Distance(const Point2D& p0, const Point2D& p1)
{
    return sqrt(pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2));
}

int ccw(const Point2D& p0, const Point2D& p1, const Point2D& p2)
{
    int determinant = (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);

    if(determinant > 0) return 1; // Counterclockwise, p2 is on the left side of vector p0->p1, therefore p1 belongs the hull
    if(determinant < 0) return -1; // Clockwise, p2 is on the right side of vector p0->p1, therefore p1 is not in the hull
    return 0; // All 3 points are collinear
}

bool compare(const Point2D& p0, const Point2D& p1)
{
    /* Use the orientation to compare angles instead of actually computing them,
       since trigonometric functions(arccos in this case) are costly to evaluate */
    int Orientation = ccw(Point2D::BottomMost, p0, p1);

    if(Orientation == 0)
      return (Distance(Point2D::BottomMost, p0) <= Distance(Point2D::BottomMost, p1)) ? true : false;
    else
      return (Orientation > 0) ? true : false;
}

std::stack<Point2D> ConvexHull(std::vector<Point2D>& PCs)
{
    Point2D LowestPC = PCs[0];
    int index = 0;

    for(int i = 1; i < PCs.size(); i++)
    {
        if(PCs[i].y < LowestPC.y)
        {
            LowestPC = PCs[i];
            index = i;
        }
        else
        if(PCs[i].y == LowestPC.y && PCs[i].x < LowestPC.x) // In case of tie, choose the leftmost
        {
            LowestPC = PCs[i];
            index = i;
        }
    }

    Point2D::BottomMost = LowestPC;

    std::swap(PCs[0], PCs[index]);

    // Sort by polar angle in counterclockwise order with respect to PCs[0]
    std::sort(PCs.begin() + 1, PCs.end(), compare);

    std::stack<Point2D> Hull;
    // PCs[0] and PCs[1] are definitely in the hull
    Hull.push(PCs[0]);
    Hull.push(PCs[1]);
    Hull.push(PCs[2]);

    for(int i = 3; i < PCs.size(); i++)
    {
        Point2D last = Hull.top();
        Hull.pop();

        while(ccw(Hull.top(), last, PCs[i]) <= 0)
        {
            // PCs[i] is on clockwise direction or it's collinear, so 'last' doesn't make part of the hull
            last = Hull.top();
            Hull.pop();
        }

        Hull.push(last);
        Hull.push(PCs[i]);
    }

    return Hull;
}

int main()
{
    int n{}, x{}, y{};

    std::cout.precision(2);

    while(std::cin>>n && n)
    {
        std::vector<Point2D> PCs;

        for(int i = 0; i < n; i++)
        {
            std::cin>>x>>y;
            Point2D PC(x, y);
            PCs.emplace_back(PC);
        }

        std::stack<Point2D> Solution = ConvexHull(PCs);
        int m = Solution.size();

        float TapeLength = 0.f;

        Point2D aux = Solution.top();
        Point2D last;

        for(int i = 0; i < m; i++)
        {
            if(i < m-1)
            {
                last = Solution.top();
                Solution.pop();
                TapeLength += Distance(last, Solution.top());
            }
            else
                TapeLength += Distance(aux, Solution.top());
        }

        std::cout<<"Tera que comprar uma fita de tamanho "<<std::fixed<<TapeLength<<".\n";
    }
}
