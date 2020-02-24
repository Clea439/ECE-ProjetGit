#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include"triangle.h"
#include"sommet.h"
#include"../graphisme/couleur.h"

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

void Triangle::saisir_triangle(std::vector<Sommet> tableau)
{
    double numero;
    std::cout<<"selectionner les sommets que vous voulez \n";
    std::cin>>numero;
    std::cout<<"\n";
    for(int i=0;i<tableau.size();++i)
    {
        if(i==numero)
        {
            m_sommet1=tableau[numero];
        }
    }
    std::cin>>numero;
    std::cout<<"\n";
    for(int i=0;i<tableau.size();++i)
    {
        if(i==numero)
        {
            m_sommet2=tableau[numero];
        }
    }
    std::cin>>numero;
    std::cout<<"\n";
    for(int i=0;i<tableau.size();++i)
    {
        if(i==numero)
        {
            m_sommet3=tableau[numero];
        }
    }

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



std::vector<Triangle*> ajouter(std::vector<Triangle*> tableau,std::vector<Sommet> tableau_sommet)
{
    Triangle* nouveau=new Triangle;
    nouveau->saisir_triangle(tableau_sommet);
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






