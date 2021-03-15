#include <iostream>
#include <cmath>
#include <vector>

bool isPrimeNumber(int64_t n)
{
    if(n == 1) return false;
    
    bool flag = true;
    for(int i = 2; i <= ((int)sqrt(n)); ++i)
    {
        if(n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int coins{}, value{}, jump{};
    int64_t sum{};
    std::vector<int> values; 
    
    while(std::cin>>coins)
    {
        for(int i = 0; i < coins; ++i)
        {
            std::cin>>value;
            values.push_back(value);
        }
        
        std::cin>>jump;
        
        for(int i = coins - 1; i >= 0; i -= jump)
        {
            sum += values[i];
        }

        if(isPrimeNumber(sum))
            std::cout << "You’re a coastal aircraft, Robbie, a large silver aircraft.\n";
        else
            std::cout << "Bad boy! I’ll hit you.\n";
            
        sum = 0;
        values.clear();
    }
    
    return 0;
}
