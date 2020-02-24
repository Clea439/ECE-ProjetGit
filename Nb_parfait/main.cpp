#include <iostream>
#include <vector>

std::vector<int> recupDiviseur(int entier)
{
    int somme_diviseur=0;
    std::vector<int> diviseur;
    int i;
    for(i=1;i<entier;++i)
    {
        if(i!=entier)
        {
                if(entier%i==0)
            {
            somme_diviseur=somme_diviseur+i;
            diviseur.push_back (i);
            }
        }

    }


return diviseur;
}

int somme(std::vector<int> nombre, int entier)
{
    int somme=0;
    for(int unsigned i=0;i<nombre.size();++i)
    {
        somme=nombre[i]+somme;
    }
    if(entier==somme)
    {
        return 1;
    }
    return 0;
}

void affichage(int entier,std::vector<int> diviseur)
{
    std::cout<<entier<<" = ";
    for(int unsigned i=0;i<diviseur.size();++i)
    {
        if(i==0)
        {
            std::cout<<diviseur[i];
        }
        else
        {
            std::cout<<" + "<<diviseur[i];
        }

    }

}

int main()
{
    int affichage_vector=0;
    std::vector<int>testvector;
    for(int i=1;i<10000;++i)
    {
        testvector= recupDiviseur(i);
        //std::cout << std::endl;
        affichage_vector=somme(testvector,i);
        //std::cout << std::endl;
        if(affichage_vector==1)
        {
          affichage(i,testvector);
          std::cout << std::endl;
        }

    }


    return 0;
}
