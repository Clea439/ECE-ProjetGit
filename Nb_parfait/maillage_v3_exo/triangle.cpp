#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include"triangle.h"
#include"sommet.h"

Triangle::Triangle()///VALEURS PAR DEFAUT
{
    m_sommet1=Sommet();
    m_sommet2=Sommet();
    m_sommet3=Sommet();
    m_couleur=Couleur();
}

Triangle::~Triangle()///DESTRUCTEUR
{

}

void Triangle::saisir_triangle()
{
    m_sommet1.saisir();
    m_sommet2.saisir();
    m_sommet3.saisir();
    m_couleur.saisir();
}

Sommet Triangle::getm_sommet1()
{
    return {m_sommet1.getm_position()};
}
Sommet Triangle::getm_sommet2()
{
    return {m_sommet2.getm_position() };
}

Sommet Triangle::getm_sommet3()
{
    return {m_sommet3.getm_position() };
}



std::vector<Triangle*> ajouter(std::vector<Triangle*> tableau)
{
    Triangle* nouveau=new Triangle;
    nouveau->saisir_triangle();
    tableau.push_back(nouveau);
    return tableau;
}

void Triangle::setm_sommet1(Sommet saisie)
{
    m_sommet1=saisie;
}
void Triangle::setm_sommet2(Sommet saisie)
{
    m_sommet2=saisie;
}
void Triangle::setm_sommet3(Sommet saisie)
{
    m_sommet3=saisie;
}






