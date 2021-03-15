#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int main()
{
    int n{}, x{};
    int64_t sumRangel{}, sumGugu{}, diff{LLONG_MAX};

    std::vector<int> difficulty;
    
    while(std::cin>>n)
    {
        difficulty.reserve(n);
        
        for(int i = 0; i < n; ++i)
        {
            std::cin>>x;
            
            if(i < std::ceil(n / 2.f))
                sumRangel += x;
            else
                sumGugu += x;
                
            difficulty[i] = x;
        }
        
        if(sumRangel > sumGugu)
        {
            int i = std::ceil(n / 2.f) - 1;
            while(!(sumRangel - difficulty[i] < sumGugu + difficulty[i]) && i >= 0)
            {
                sumRangel -= difficulty[i];
                sumGugu += difficulty[i];
                
                i--;
            }
            
            if(i) // Exited earlier, need to check if we left behind the optimal solution
            {
                diff = std::min(std::abs(sumRangel - sumGugu), std::abs((sumRangel - difficulty[i]) - (sumGugu + difficulty[i])));
            }
        }
        else
        if(sumRangel < sumGugu)
        {
            int i = std::ceil(n / 2.f);
            while(!(sumRangel + difficulty[i] > sumGugu - difficulty[i]) && i < n)
            {
                sumGugu -= difficulty[i];
                sumRangel += difficulty[i];
                
                i++;
            }
            
            if(i < n) // Exited earlier, need to check if we left behind the optimal solution
            {
                diff = std::min(std::abs(sumRangel - sumGugu), std::abs((sumRangel + difficulty[i]) - (sumGugu - difficulty[i])));
            }
        }
        
        std::cout<<std::min(diff, std::abs(sumRangel - sumGugu))<<'\n';
        
        difficulty.clear();
        sumRangel = sumGugu = 0;
    }

    return 0;
}
