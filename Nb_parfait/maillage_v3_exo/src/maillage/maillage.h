#ifndef MAILLAGE_H_INCLUDED
#define MAILLAGE_H_INCLUDED
#include"../geometrie/sommet.h"
#include"../geometrie/triangle.h"

class Maillage
{
    public:
        Maillage();
        ~Maillage();
        std::vector<Sommet> translation(std::vector<Sommet> selection_sommet_triangle,Svgfile& file,std::vector<Triangle*> mesTriangles);
        std::vector<Triangle*> ajouter(std::vector<Triangle*> tableau,std::vector<Sommet> tableau_sommet);
        std::vector<Sommet> selection_sommet(std::vector<Triangle*> mesTriangles,Svgfile& file,std::vector<Sommet> selection_sommet_triangle);
        std::vector<Sommet> deselectionner(std::vector<Sommet> selection_sommet_triangle,Svgfile& file);
        void actualiser(std::vector<Sommet> selection_sommet_triangle,Svgfile& file);
};

#endif // MAILLAGE_H_INCLUDED
