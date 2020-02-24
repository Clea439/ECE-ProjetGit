#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include<vector>
#include"coords.h"

#include "../svg/svgfile.h"
class Sommet
{
    private:
    Coords m_position;
    public:
    void afficher() const;
    Sommet(Coords position);
    ~Sommet();
    Sommet();
    Coords getm_position();
    void dessiner_sommet(Svgfile& file,std::vector<Sommet> tableau);
    void saisir();

};
std::vector<Sommet> ajouter_sommet(std::vector<Sommet> tableau);
 void afficher_sommet(std::vector<Sommet> tableau);
#endif // SOMMET_H_INCLUDED
