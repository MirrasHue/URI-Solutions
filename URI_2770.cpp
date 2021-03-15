#include <iostream>


int main()
{
    int x, y, m;
    int xi, yi;
    bool xi_fitX = false,
         xi_fitY = false;
         
    bool yi_fitX = false,
         yi_fitY = false;
    
    while(std::cin>>x>>y>>m)
    {
        for(int i = 0; i < m; ++i)
        {
            xi_fitX = xi_fitY = yi_fitX = yi_fitY = false;
            
            std::cin>>xi>>yi;
            
            if(((xi > x) && (xi > y)) || ((yi > x) && (yi > y))) // Save some time if neither fit
            {
                std::cout<<"Nao\n";
                continue;
            }
            
            // Check for xi
            if((xi <= x) && (xi <= y)) // xi can fit in both x & y
            {
                xi_fitX = true;
                xi_fitY = true;
            }
            else
            if((xi <= x) && (xi > y)) // xi can fit only in x
            {
                xi_fitX = true;
            }
            else
            if((xi > x) && (xi <= y)) // xi can fit only in y
            {
                xi_fitY = true;
            }
            
            
            // Check for yi
            if((yi <= x) && (yi <= y)) // yi can fit in both x & y
            {
                yi_fitX = true;
                yi_fitY = true;
            }
            else
            if((yi <= x) && (yi > y)) // yi can fit only in x
            {
                yi_fitX = true;
            }
            else
            if((yi > x) && (yi <= y)) // yi can fit only in y
            {
                yi_fitY = true;
            }

            
            if(xi_fitX && xi_fitY) // Just see if yi fits in any dimension
            {
                if(yi_fitX || yi_fitY)
                    std::cout<<"Sim\n";
                
                continue;
            }
            else
            if(xi_fitX) // If xi just fit in x, yi need to fit in y
            {
                if(yi_fitY)
                    std::cout<<"Sim\n";
                else
                    std::cout<<"Nao\n";
            }
            else
            if(xi_fitY) // If xi just fit in y, yi need to fit in x
            {
                if(yi_fitX)
                    std::cout<<"Sim\n";
                else
                    std::cout<<"Nao\n";
            }
        }
    }

    return 0;
}
