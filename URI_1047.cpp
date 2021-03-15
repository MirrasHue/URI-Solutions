#include <iostream>
 
int main() {

    int inih, inim, finh, finm;
    int durh, durm;
    
    std::cin>>inih>>inim>>finh>>finm;
    
    if(inih == finh && inim == finm)
    {
        durh = 24;
        durm = 0;
    }
    else
    if(inih >= finh && inim > finm)
    {
        durh = (finh + 23) - inih;
        durm = (finm + 60) - inim;
    }
    else
    if(inih >= finh && inim <= finm)
    {
        durh = (finh + 24) - inih;
        durm = finm - inim;
    }
    else
    if(inih < finh && inim > finm)
    {
        durh = (finh - inih) - 1;
        durm = (finm + 60) - inim;
    }
    else
    if(inih < finh && inim <= finm)
    {
        durh = finh - inih;
        durm = finm - inim;
    }
    
    if(durh == 24 && durm > 0)
        durh = 0;
    
    if(durh != 0 || durm != 0)
        std::cout<<"O JOGO DUROU "<<durh<<" HORA(S) E "<<durm<<" MINUTO(S)\n";
        
 
    return 0;
}