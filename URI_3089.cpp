#include <iostream>
#include <vector>

int main()
{
    int n{}, price{}, mostCostly{}, cheapest{};
    
    std::vector<int> giftPrice; // Already given in descending order
    std::vector<int> pairPrice;
    
    while(std::cin>>n && n)
    {
        giftPrice.reserve(2*n);
        pairPrice.reserve(n);
        
        for(int i = 0; i < 2*n; ++i)
        {
            std::cin>>price;
            giftPrice[i] = price;
        }
        
        for(int i = 0; i < n; ++i)
        {
            // Combine the most expensive gift with the cheapest
            pairPrice[i] = giftPrice[i] + giftPrice[2*n - i - 1];
        }
        
        mostCostly = pairPrice[0];
        cheapest = pairPrice[0];
        
        for(int i = 1; i < n; ++i)
        {
            if(mostCostly < pairPrice[i])
                mostCostly = pairPrice[i];
                
            if(cheapest > pairPrice[i])
                cheapest = pairPrice[i];
        }
        
        std::cout<<mostCostly<<" "<<cheapest<<'\n';
        
        giftPrice.clear();
        pairPrice.clear();
    }
    
    return 0;
}
