#include "geometrie/transformation.h"
#include "graphisme/couleur.h"
#include "svg/svgfile.h"
#include "util/util.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//#include "svgfile.h"
//#include "couleur.h"
//#include "util.h"
#include"geometrie/triangle.h"
#include"geometrie/sommet.h"
#include "maillage/maillage.h"


/// CREER UNE CLASS TRIANGLE QUI A LES COORDONNEES DE 3 SOMMETS ET UNE COULEUR, ENSUITE FAIRE UN TABLEAU DE SOMMETS
void svgTest();

int main()
{
    //svgTest();
    int menu;
     Svgfile svgout;
    svgout.addGrid();
    std::vector<Triangle*> mesTriangles;
    std::vector<Sommet> mesSommets;
    std::vector<Sommet*> sommet_triangle;
    Maillage maillage;
    std::vector<Sommet> selection_sommet_triangle;
    std::cout<<"0/ quitter\n1/Dessiner scene\n2/ Afficher tous sommets\n3/ Ajouter sommets\n4/ Ajouter triangle\n5/Selection d'un sommet\n6/Deselection d'un sommet\n7/Faire une translation\n";
    util::startAutoCin("cocotte.txt", 50);
    do
    {
        std::cout<<"\n";
        std::cin>>menu;
        switch(menu)
        {
            case 1:
                {
                    for(unsigned i=0;i<mesTriangles.size();++i)
                    {
                       // mesSommets[i]->dessiner_sommet(svgout);
                       mesTriangles[i]->dessiner_triangle(mesTriangles,svgout);
                    }
                    for(unsigned i=0;i<mesSommets.size();++i)
                    {
                        mesSommets[i].dessiner_sommet(svgout,mesSommets);
                    }
                    break;
                }
            case 2:
                {
                    afficher_sommet(mesSommets);
                    break;
                }
            case 3:
                {
                    mesSommets=ajouter_sommet(mesSommets);
                    break;
                }
            case 4:
                {
                    mesTriangles=ajouter(mesTriangles,mesSommets);
                    break;
                }
            case 5:
                {
                   selection_sommet_triangle=maillage.selection_sommet(mesTriangles,svgout,selection_sommet_triangle);
                    break;
                }
            case 6:
                {
                    selection_sommet_triangle=maillage.deselectionner(selection_sommet_triangle,svgout);
                    break;
                }
            case 7:
                {
                    selection_sommet_triangle=maillage.translation(selection_sommet_triangle,svgout,mesTriangles);
                    maillage.actualiser(selection_sommet_triangle,svgout);
                    break;
                }
                case -10: /// Spécial, fin de script autoCin
                    {
                        util::stopAutoCin();
                        //afficherMenu();
                        break;
                    }
                /// Dessin automatique à chaque opération
                Svgfile::s_verbose = false;
                Svgfile svgout;
                svgout.addGrid();
                //calqueCourant->dessiner(svgout, styleDessin);
                for(unsigned i=0;i<mesTriangles.size();++i)
                    {
                       // mesSommets[i]->dessiner_sommet(svgout);
                       mesTriangles[i]->dessiner_triangle(mesTriangles,svgout);
                    }
                    for(unsigned i=0;i<mesSommets.size();++i)
                    {
                        mesSommets[i].dessiner_sommet(svgout,mesSommets);
                    }

        }
    }while(menu!=0);

    return 0;
}

/// Code initial pour comprendre les ajouts de primitives
void svgTest()
{
    /// Sortie graphique dans le fichier output.svg
    /// ( options à voir svgfile.h au niveau du constructeur )
    Svgfile svgout;

    /// Dessin du repère cartésien (facultatif)
    // svgout.addGrid();

    /// On a perdu les dessins de sphères (une autre fois peut-être)

    /// Nouveau : on peut toujours utiliser les couleurs "red" "green"...
    /// Mais on a maintenant un type Couleur qui prend 3 composantes RVB
    /// Exemple pour déclarer du Jaune (beaucoup Rouge + Vert, pas de bleu)
    /// Chaque canal est dans l'intervalle [0..255]
    Couleur jaune{255, 200, 0};

    /// Dessin de disque : xcentre ycentre rayon couleur
    svgout.addDisk(100, 100, 30, jaune);
    svgout.addDisk(200, 100, 30, Couleur{100, 150, 200});
    svgout.addDisk(300, 100, 30, "pink");
    svgout.addDisk(400, 100, 30);

    /// Dessin de cercle : xcentre ycentre rayon epaisseur couleur
    svgout.addCircle(100, 200, 30, 10, "red");
    svgout.addCircle(200, 200, 30, 5, "red");
    svgout.addCircle(300, 200, 30, 1, "red");

    /// Dessin de triangle : x1 y1 x2 y2 x3 y3 couleur_remplissage ...
    ///                         epaisseur_bordure couleur_bordure
    svgout.addTriangle(100,300, 200,300, 150,250, "green", 5, "orange");

    /// Dessin de triangle : x1 y1 x2 y2 x3 y3 couleur_remplissage
    svgout.addTriangle(300,300, 400,300, 350,250, "green");

    /// Dessin de texte : xcentre ycentre texte couleur
    svgout.addText(100, 320, "Hello Triangles !", Couleur{0,100,0} );

    /// Dessin de texte : xcentre ycentre texte couleur
    svgout.addText(342, 320, 6*7, "black");

    /// Dessin de croix : xcentre ycentre taille couleur
    svgout.addCross(400, 200, 25);

    /// Dessin de segments : x1 y1 x2 y2 couleur
    svgout.addLine(300, 70, 400, 70);
    svgout.addLine(300, 130, 400, 130);
    svgout.addLine(340, 70, 300, 30, "blue");
    svgout.addLine(360, 70, 400, 30, "red");

    /// L'objet svgout est automatiquement libéré à la sortie
    /// de ce sous-programme : le fichier output.svg est alors fermé
}

/// Code initial pour comprendre les transformations géométriques
//void transfoTest()
//{
//    /// Sortie graphique dans le fichier output.svg
//    /// ( options à voir svgfile.h au niveau du constructeur )
//    Svgfile svgout;
//
//    /// Dessin du repère cartésien (facultatif)
//    svgout.addGrid();
//
//    /// Mutation de couleur
//    Couleur jaune{255, 200, 0};
//    for (double x=100; x<=900; x+=50)
//    {
//        svgout.addDisk(x, 100, 30, jaune);
//        /// Chaque canal modifié aléatoirement de [-40...+40]
//        jaune.muter(40);
//    }
//
//    /// Coordonnées aléatoire
//    for (double x=100; x<=900; x+=100)
//    {
//        Coords posBase{x, 200};
//
//        for (int i=0; i<8; ++i)
//        {
//            /// Coords::aleatoire est une méthode statique de classe
//            /// qui renvoie un objet (c'est une sorte de constructeur)
//            /// Voir Coords .h et .cpp
//            Coords posAlea = posBase + Coords::aleatoire(50);
//
//            svgout.addLine(posBase.getX(), posBase.getY(),
//                           posAlea.getX(), posAlea.getY(), "black");
//        }
//    }
//
//    /// On défini des positions initiales d'un triangle...
//    Coords c1{100, 300};
//    Coords c2{200, 500};
//    Coords c3{100, 500};
//    svgout.addTriangle(c1.getX(), c1.getY(), c2.getX(), c2.getY(), c3.getX(), c3.getY(), "green");
//
//    /// Translation de vecteur 200 0
//    {
//        Coords vecteur{200, 0};
//        Transformation transfo{ Translation{vecteur} };
//        transfo.appliquer(c1);
//        transfo.appliquer(c2);
//        transfo.appliquer(c3);
//        svgout.addTriangle(c1.getX(), c1.getY(), c2.getX(), c2.getY(), c3.getX(), c3.getY(), "red");
//    }
//
//    /// Rotation de centre 300 500 d'angle +30° (sens trigo)
//    {
//        Coords centre{300, 500};
//        double angle = 30;
//        Transformation transfo{ Rotation{centre, angle} };
//        transfo.appliquer(c1);
//        transfo.appliquer(c2);
//        transfo.appliquer(c3);
//        svgout.addTriangle(c1.getX(), c1.getY(), c2.getX(), c2.getY(), c3.getX(), c3.getY(), "blue");
//    }
//
//    /// Symétrie de centre 400 500 par rapport à l'axe à 90° (vertical)
//    {
//        Coords centre{400, 500};
//        double angle = 90;
//        Transformation transfo{ Symetrie{centre, angle} };
//        transfo.appliquer(c1);
//        transfo.appliquer(c2);
//        transfo.appliquer(c3);
//        svgout.addTriangle(c1.getX(), c1.getY(), c2.getX(), c2.getY(), c3.getX(), c3.getY(), "orange");
//    }
//
//    /// Symétrie de centre 500 500 par rapport à l'axe à 0° (horizontale)
//    /// ici on conserve les coordonnées de départ en utilisant la méthode résultat
//    /// qui donne une copie transformée
//    {
//        Coords centre{500, 500};
//        double angle = 0;
//        Transformation transfo{ Symetrie{centre, angle} };
//        Coords d1 = transfo.resultat(c1);
//        Coords d2 = transfo.resultat(c2);
//        Coords d3 = transfo.resultat(c3);
//        svgout.addTriangle(d1.getX(), d1.getY(), d2.getX(), d2.getY(), d3.getX(), d3.getY(), "pink");
//    }
//
//    /// Homothetie de centre 200 400 de rapport 1.5
//    {
//        Coords centre{200, 400};
//        double rapport = 1.5;
//        Transformation transfo{ Homothetie{centre, rapport} };
//        transfo.appliquer(c1);
//        transfo.appliquer(c2);
//        transfo.appliquer(c3);
//        svgout.addTriangle(c1.getX(), c1.getY(), c2.getX(), c2.getY(), c3.getX(), c3.getY(), "brown");
//    }
//
//    /// Homotheties de centre 650 450 de rapport 0.8
//    Couleur coul{128,128,128};
//    for (int i=0; i<80; ++i)
//    {
//        Coords centre{650, 450};
//        double rapport = 0.9;
//        Transformation transfo{ Homothetie{centre, rapport} };
//        transfo.appliquer(c1);
//        transfo.appliquer(c2);
//        transfo.appliquer(c3);
//        svgout.addTriangle(c1.getX(), c1.getY(), c2.getX(), c2.getY(), c3.getX(), c3.getY(), coul);
//        coul.muter(20);
//    }

    /// L'objet svgout est automatiquement libéré à la sortie
    /// de ce sous-programme : le fichier output.svg est alors fermé
//}


