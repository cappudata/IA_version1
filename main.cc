#include <iostream>
#include "moteurdinference.hh"
#include "regle.hh"

int main()
{



    Regle regle1({"responsabilite","langues","neerlandais"},"dynamique");
    Regle regle2({"langues","anglais"},"adaptabilite");
    Regle regle3({"slave","dynamique"},"adaptabilite");
    Regle regle4({"responsabilite"},"leadership");
    Regle regle5({"langues"},"neerlandais");
    Regle regle6({"adaptabilite","leadership"}, "accepte");
    Regle regle7({"slave"},"langues");
    Regle regle8({"leadership","slave"}, "adaptabilite");

    moteurdinference moteur;
    moteur.ajouterRegle(regle1);
    moteur.ajouterRegle(regle2);
    moteur.ajouterRegle(regle3);
    moteur.ajouterRegle(regle4);
    moteur.ajouterRegle(regle5);
    moteur.ajouterRegle(regle6);
    moteur.ajouterRegle(regle7);
    moteur.ajouterRegle(regle8);

    moteur.ajouterFait("slave");
    moteur.ajouterFait("responsabilite");
    moteur.setBut("accepte");

    moteur.afficherBF();

   // moteur.chainageAvant();
    //moteur.chainageArriere();

    //std::vector<Regle> vecTest = moteur.getAllRules("accepte");

    moteur.chainageArriere();

    return 0;
}
