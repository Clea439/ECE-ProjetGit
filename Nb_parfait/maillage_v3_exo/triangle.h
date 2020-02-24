#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include "util.h"
#include "svgfile.h"
#include "couleur.h"
#include"coords.h"
#include"sommet.h"
#include<vector>

class Triangle
{
    private :
        Sommet m_sommet1;
        Sommet m_sommet2;
        Sommet m_sommet3;
        Couleur m_couleur;

    public:
        Triangle();
        ~Triangle();
        Sommet getm_sommet1();
        Sommet getm_sommet2();
        Sommet getm_sommet3();
        void setm_sommet1(Sommet saisie);
        void setm_sommet2(Sommet saisie);
        void setm_sommet3(Sommet saisie);
        void saisir_triangle();
        void dessiner_triangle(std::vector<Triangle*> mesTriangles,Svgfile& file);
};
std::vector<Sommet> translation(std::vector<Sommet> selection_sommet_triangle,Svgfile& file,std::vector<Triangle*> mesTriangles);
std::vector<Triangle*> ajouter(std::vector<Triangle*> tableau);
std::vector<Sommet> selection_sommet(std::vector<Triangle*> mesTriangles,Svgfile& file,std::vector<Sommet> selection_sommet_triangle);
std::vector<Sommet> deselectionner(std::vector<Sommet> selection_sommet_triangle,Svgfile& file);
void actualiser(std::vector<Sommet> selection_sommet_triangle,Svgfile& file);
///void selection_sommet(std::vector<Triangle*> mesTriangles,Svgfile& file);
//void dessiner(std::vector<Sommet*> mesSommets, std::vector<Triangle*> mesTriangles,Svgfile& file);
#endif // TRIANGLE_H_INCLUDED
