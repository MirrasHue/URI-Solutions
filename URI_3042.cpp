#include <iostream>


int main()
{
    int meters{}, totalTouches{};
    int l{}, c{}, r{};
    char currentLane{'c'};
    
    while(std::cin>>meters && meters)
    {
        for(int i = 0; i < meters; ++i)
        {
            std::cin>>l>>c>>r;
            
            if(l == 0 && c == 0 && r == 0)
                continue;
            else
            if(l == 1 && c == 1 && r == 0)
            {
                if(currentLane == 'c')
                {
                    totalTouches++;
                }
                else
                if(currentLane == 'l')
                {
                    totalTouches += 2;
                }
                currentLane = 'r';
            }
            else
            if(l == 1 && c == 0 && r == 1)
            {
                if(currentLane == 'l' || currentLane == 'r')
                {
                    totalTouches++;
                    currentLane = 'c';
                }
            }
            else
            if(l == 0 && c == 1 && r == 1)
            {
                if(currentLane == 'c')
                {
                    totalTouches++;
                }
                else
                if(currentLane == 'r')
                {
                    totalTouches += 2;
                }
                currentLane = 'l';
            }
        }
        
        std::cout<<totalTouches<<'\n';
        currentLane = 'c';
        totalTouches = 0;
    }

    return 0;
}
