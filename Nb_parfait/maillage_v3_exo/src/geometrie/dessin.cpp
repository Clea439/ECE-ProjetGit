#include "../svg/svgfile.h"
#include "../graphisme/couleur.h"
#include "../util/util.h"
#include"triangle.h"
#include"sommet.h"
#include"coords.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include"../maillage/maillage.h"


Maillage::Maillage()
{

}
Maillage::~Maillage()
{

}
void Sommet::dessiner_sommet(Svgfile& file,std::vector<Sommet> tableau)
{
    //Svgfile svg;
    for(unsigned i=0;i<tableau.size();++i)
    {
        file.addDisk(m_position.getX(),m_position.getY(), 4, "black");
    }

}

void Triangle::dessiner_triangle(std::vector<Triangle*> mesTriangles,Svgfile& file)
{
    //Svgfile svg;
    for(unsigned i=0;i<mesTriangles.size();++i)
    {
        file.addTriangle(m_sommet1.getm_position().getX(), m_sommet1.getm_position().getY(), m_sommet2.getm_position().getX(),m_sommet2.getm_position().getY(),m_sommet3.getm_position().getX(), m_sommet3.getm_position().getY(),m_couleur);
        file.addCircle(m_sommet1.getm_position().getX(),m_sommet1.getm_position().getY(),2, 2, "black");
        file.addCircle(m_sommet2.getm_position().getX(),m_sommet2.getm_position().getY(),2, 2, "black");
        file.addCircle(m_sommet3.getm_position().getX(),m_sommet3.getm_position().getY(),2, 2, "black");
    }

}


std::vector<Sommet> Maillage::selection_sommet(std::vector<Triangle*> mesTriangles,Svgfile& file,std::vector<Sommet> selection_sommet_triangle)
{
    std::vector<Sommet> sommet_triangle;
    unsigned indice;
    for(unsigned i=0;i<mesTriangles.size();++i)
    {
        sommet_triangle.push_back(mesTriangles[i]->getm_sommet1());
        sommet_triangle.push_back(mesTriangles[i]->getm_sommet2());
        sommet_triangle.push_back(mesTriangles[i]->getm_sommet3());
    }
    std::cout<<"Saisir un indice sommet\n";
    std::cin>>indice;
    for(unsigned i=0;i<sommet_triangle.size();++i)
    {
        if(i==indice)
        {
               file.addCircle(sommet_triangle[i].getm_position().getX(),sommet_triangle[i].getm_position().getY(),4, 4, "pink");
               selection_sommet_triangle.push_back(sommet_triangle[i]);
               for(unsigned j=0;j<sommet_triangle.size();++j)
               {
                   if(j!=i&&sommet_triangle[i].getm_position().getX()==sommet_triangle[j].getm_position().getX()&&sommet_triangle[i].getm_position().getY()==sommet_triangle[j].getm_position().getY())
                   {
                       file.addCircle(sommet_triangle[j].getm_position().getX(),sommet_triangle[j].getm_position().getY(),4, 4, "pink");
                       selection_sommet_triangle.push_back(sommet_triangle[j]);
                   }
               }
        }
    }
    return selection_sommet_triangle;
}

std::vector<Sommet> Maillage::deselectionner(std::vector<Sommet> selection_sommet_triangle,Svgfile& file)
{
    unsigned indice;
    std::cout<<"Saisir l indice du sommet dans les sommets selectionne que vous voulez deselectionner\n";
    std::cin>>indice;
    for(unsigned i=0;i<selection_sommet_triangle.size();++i)
    {
        if(i==indice)
        {
               file.addCircle(selection_sommet_triangle[i].getm_position().getX(),selection_sommet_triangle[i].getm_position().getY(),4, 4, "white");
               selection_sommet_triangle.erase(selection_sommet_triangle.begin()+i);
               for(unsigned j=0;j<selection_sommet_triangle.size();++j)
               {
                   if(j!=i&&selection_sommet_triangle[i].getm_position().getX()==selection_sommet_triangle[j].getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==selection_sommet_triangle[j].getm_position().getY())
                   {
                       file.addCircle(selection_sommet_triangle[j].getm_position().getX(),selection_sommet_triangle[j].getm_position().getY(),4, 4, "white");
                       selection_sommet_triangle.erase(selection_sommet_triangle.begin()+j);
                   }
               }
        }
    }
return selection_sommet_triangle;
}

std::vector<Sommet> Maillage::translation(std::vector<Sommet> selection_sommet_triangle,Svgfile& file,std::vector<Triangle*> mesTriangles)
{
    unsigned indice;
    int premier_tour=0;
    Sommet saisie;
    std::cout<<"Saisir l indice du sommet dans les sommets selectionner dont vous voulez modifier l emplacement\n";
    std::cin>>indice;
    for(unsigned i=0;i<selection_sommet_triangle.size();++i)
    {
        if(i==indice)
        {
               file.addCircle(selection_sommet_triangle[i].getm_position().getX(),selection_sommet_triangle[i].getm_position().getY(),4, 4, "white");
               file.addDisk(selection_sommet_triangle[i].getm_position().getX(),selection_sommet_triangle[i].getm_position().getY(), 4,"white" );
               selection_sommet_triangle.erase(selection_sommet_triangle.begin()+i);
               for(unsigned j=0;j<selection_sommet_triangle.size();++j)
               {
                   if(j!=i&&selection_sommet_triangle[i].getm_position().getX()==selection_sommet_triangle[j].getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==selection_sommet_triangle[j].getm_position().getY())
                   {
                       file.addCircle(selection_sommet_triangle[j].getm_position().getX(),selection_sommet_triangle[j].getm_position().getY(),4, 4, "white");
                       selection_sommet_triangle.erase(selection_sommet_triangle.begin()+j);
                   }
               }
        }
    }
    for(unsigned i=0;i<selection_sommet_triangle.size();++i)
    {
        if(i==indice)
        {
            for(unsigned j=0;j<mesTriangles.size();++j)
            {
                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[j]->getm_sommet1().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[j]->getm_sommet1().getm_position().getY())
                {
                    if(premier_tour==0)
                    {

                        saisie.saisir();

                        premier_tour=1;
                    }

                            for(unsigned l=0;l<mesTriangles.size();++l)
                            {
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet1().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet1().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet1().~Sommet();
                                     mesTriangles[l]->setm_sommet1(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet1());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet1().getm_position().getX(),mesTriangles[l]->getm_sommet1().getm_position().getY(),4, 4, "white");
                                }
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet2().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet2().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet2().~Sommet();
                                     mesTriangles[l]->setm_sommet2(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet2());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet2().getm_position().getX(),mesTriangles[l]->getm_sommet2().getm_position().getY(),4, 4, "white");
                                }
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet3().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet3().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet3().~Sommet();
                                     mesTriangles[l]->setm_sommet3(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet3());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet3().getm_position().getX(),mesTriangles[l]->getm_sommet3().getm_position().getY(),4, 4, "white");
                                }
                            }



                    ///file.addCircle(selection_sommet_triangle[i].getm_position().getX(),selection_sommet_triangle[i].getm_position().getY(),4, 4, "white");
                   mesTriangles[j]->setm_sommet1(saisie);
                   selection_sommet_triangle[i]=saisie;
                }


                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[j]->getm_sommet2().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[j]->getm_sommet2().getm_position().getY())
                {
                    if(premier_tour==0)
                    {
                        saisie.saisir();
                        premier_tour=1;
                    }

                            for(unsigned l=0;l<mesTriangles.size();++l)
                            {
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet1().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet1().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet1().~Sommet();
                                     mesTriangles[l]->setm_sommet1(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet1());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet1().getm_position().getX(),mesTriangles[l]->getm_sommet1().getm_position().getY(),4, 4, "white");
                                }
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet2().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet2().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet2().~Sommet();
                                     mesTriangles[l]->setm_sommet2(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet2());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet2().getm_position().getX(),mesTriangles[l]->getm_sommet2().getm_position().getY(),4, 4, "white");
                                }
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet3().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet3().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet3().~Sommet();
                                     mesTriangles[l]->setm_sommet3(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet3());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet3().getm_position().getX(),mesTriangles[l]->getm_sommet3().getm_position().getY(),4, 4, "white");
                                }
                            }



                    ///file.addCircle(selection_sommet_triangle[i].getm_position().getX(),selection_sommet_triangle[i].getm_position().getY(),4, 4, "white");
                   mesTriangles[j]->setm_sommet2(saisie);
                   selection_sommet_triangle[i]=saisie;
                }

                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[j]->getm_sommet3().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[j]->getm_sommet3().getm_position().getY())
                {
                    if(premier_tour==0)
                    {
                        saisie.saisir();
                        premier_tour=1;
                    }

                            for(unsigned l=0;l<mesTriangles.size();++l)
                            {
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet1().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet1().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet1().~Sommet();
                                     mesTriangles[l]->setm_sommet1(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet1());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet1().getm_position().getX(),mesTriangles[l]->getm_sommet1().getm_position().getY(),4, 4, "white");
                                }
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet2().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet2().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet2().~Sommet();
                                     mesTriangles[l]->setm_sommet2(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet2());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet2().getm_position().getX(),mesTriangles[l]->getm_sommet2().getm_position().getY(),4, 4, "white");
                                }
                                if(selection_sommet_triangle[i].getm_position().getX()==mesTriangles[l]->getm_sommet3().getm_position().getX()&&selection_sommet_triangle[i].getm_position().getY()==mesTriangles[l]->getm_sommet3().getm_position().getY())
                                {
                                    mesTriangles[l]->getm_sommet3().~Sommet();
                                     mesTriangles[l]->setm_sommet3(saisie);
                                    selection_sommet_triangle.push_back(mesTriangles[l]->getm_sommet3());
                                    ///file.addCircle(mesTriangles[l]->getm_sommet3().getm_position().getX(),mesTriangles[l]->getm_sommet3().getm_position().getY(),4, 4, "white");
                                }
                            }



                    ///file.addCircle(selection_sommet_triangle[i].getm_position().getX(),selection_sommet_triangle[i].getm_position().getY(),4, 4, "white");
                   mesTriangles[j]->setm_sommet3(saisie);
                   selection_sommet_triangle[i]=saisie;
                }
                }
                }

            }

return selection_sommet_triangle;
        }




void Maillage::actualiser(std::vector<Sommet> selection_sommet_triangle,Svgfile& file)
{
    for(unsigned i=0;i<selection_sommet_triangle.size();++i)
    {
        file.addCircle(selection_sommet_triangle[i].getm_position().getX(),selection_sommet_triangle[i].getm_position().getY(),4, 4, "pink");
    }
}
