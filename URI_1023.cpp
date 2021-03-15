#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

int getRatioIndex(const std::map<int, int>& ratioAtIndex, int ratioToFind)
{
    // If itr is equal to the end of this map, the given ratio wasn't inserted yet
    auto itr = ratioAtIndex.find(ratioToFind);
    return (itr != ratioAtIndex.end()) ? itr->second : -1;
}

int main()
{
    int n{}, residents{}, consumption{}, city{};
    int totalRes{}, totalCons{};
    
    std::vector<std::pair<int, int>> res_cons;
    std::map<int, int> ratioAtIndex;
    
    std::cout.precision(2);
    
    while(std::cin>>n && n)
    {      
        res_cons.reserve(n);
        int ratio{}, distinctRatios{};
        
        for(int i = 0; i < n; ++i)
        {
            std::cin>>residents>>consumption;
            ratio = consumption / residents;
            
            int index = getRatioIndex(ratioAtIndex, ratio);
            
            // If the current ratio was already inserted, just add residents to the pair at
            // this index, so that we group all residents with the same consumption / residents
            if(index != -1)
                res_cons[index].first += residents;
            else
            {
                res_cons.emplace_back(std::make_pair(residents, ratio));
                ratioAtIndex.emplace(ratio, distinctRatios++);
            }

            totalRes += residents;
            totalCons += consumption;
        }
        
        std::sort(res_cons.begin(), res_cons.end(), [](const auto& a, const auto& b)
        {
            return a.second < b.second;
        });
        
        if(city) std::cout<<'\n';
        
        std::cout<<"Cidade# "<< ++city <<":\n";
        for(auto [residents, consumption] : res_cons)
        {            
            std::cout<<residents<<"-"<<consumption<<" ";
        }
        
        float average = std::trunc(100 * (float)totalCons / totalRes) / 100;
        
        std::cout<<"\nConsumo medio: "<<std::fixed<<average<<" m3.\n";
        
        res_cons.clear();
        ratioAtIndex.clear();
        totalRes = totalCons = 0;
    }
    
    return 0;
}
