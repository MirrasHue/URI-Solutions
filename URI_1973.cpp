#include <iostream>
#include <vector>

int main()
{
    int64_t n{}, nSheep{}, invadedFarms{};
    int64_t sheepLeft{};
    
    std::vector<int> farms;
    
    std::cin>>n;
    
    farms.reserve(n);
    
    for(int i = 0; i < n; ++i)
    {
        std::cin>>nSheep;
        farms[i] = nSheep;
    }
    
    int ithFarm{};
    bool returning = false;
    
    for(ithFarm = 0; ithFarm < n; ++ithFarm)
    {
        if(farms[ithFarm] % 2) // Odd number of sheep, keep going
        {
            if(farms[ithFarm] - 1 >= 0)
            {
                --farms[ithFarm];
                sheepLeft += farms[ithFarm];
            }
        }
        else // Even, time to go back
        {
            returning = true;
            
            if(farms[ithFarm] - 1 >= 0) // Steal one more before heading back, if any
            {
                --farms[ithFarm];
                sheepLeft += farms[ithFarm];
            }
            
            break;
        }
    }
    
    // At this point, we stopped at the ith farm
    if(ithFarm < n - 1 || returning)
        invadedFarms = ithFarm + 1;
    else
        invadedFarms = ithFarm; // Was already incremented after the last iteration

    
    if(returning)
    {
        // Add the remaining sheep given that we didn't pass by all farms
        for(int i = ithFarm + 1; i < n; ++i)
            sheepLeft += farms[i];
        
        // We are returning, look for more sheep to steal
        for(int i = ithFarm - 1; i >= 0; --i)
        {
            if(farms[i] - 1 >= 0)
            {
                --farms[i];
                sheepLeft--;
            }
        }
    }
    
    std::cout<<invadedFarms<<" "<<sheepLeft<<'\n';
    
    return 0;
}
