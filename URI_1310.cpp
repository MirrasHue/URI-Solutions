#include <iostream>
#include <vector>

// Kadane's Algorithm to find the max contiguous subarray sum
int maxSubarraySum(std::vector<int>& vec)
{
    // Initialize to 0 so that we don't return negative values, solution specific
    int maxSoFar{}, maxEndingHere{};
    
    for(int i = 0; i < vec.size(); ++i)
    {
        maxEndingHere = std::max(vec[i], maxEndingHere + vec[i]);
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

int main()
{
    int n{}, perDayCost{}, dailyRevenue{}, profit{};
    
    std::vector<int> revenues;
    
    while(std::cin>>n>>perDayCost)
    {
        while(n--)
        {
            std::cin>>dailyRevenue;
            revenues.emplace_back(dailyRevenue - perDayCost);
        }
        
        profit = maxSubarraySum(revenues);
        
        std::cout<<profit<<'\n';
        
        revenues.clear();
    }

    return 0;
}
