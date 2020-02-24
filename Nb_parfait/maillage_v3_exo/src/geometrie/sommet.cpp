#include "sommet.h"
#include"coords.h"
#include <iostream>


Sommet::Sommet(Coords position)
{
    m_position=position;
}

Sommet::Sommet()
{
    m_position=Coords();
}

Sommet::~Sommet()
{
}

void Sommet::afficher() const
{
  m_position.afficher();
}
Coords Sommet::getm_position()
{
    return {m_position.getX() ,m_position.getY() };
}
void Sommet::saisir()
{
    m_position.saisir();
}

std::vector<Sommet> ajouter_sommet(std::vector<Sommet> tableau)
{
    //Sommet* nouveau= new Sommet;
    Sommet nouveau;
    nouveau.saisir();
    tableau.push_back(nouveau);
    return tableau;
}

void afficher_sommet(std::vector<Sommet> tableau)
{
    for(unsigned i=0;i<tableau.size();++i)
    {
        tableau[i].afficher();
    }
}

