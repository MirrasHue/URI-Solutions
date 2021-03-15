#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{}, beg{}, end{}, count{1};
    std::vector<std::pair<int, int>> vec;

    std::cin>>n;

    for(int i = 0; i < n; i++)
    {
        std::cin>>beg>>end;
        vec.emplace_back(std::make_pair(end, beg));
    }

    std::sort(vec.begin(), vec.end());

    int j = 0;

    for(int i = 1; i < n; i++)
    {
        if(vec[i].second >= vec[j].first)
        {
            count++;
            j = i;
        }
    }

    std::cout<<count<<'\n';

    return 0;
}

