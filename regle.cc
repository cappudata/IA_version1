#include "regle.hh"


void Regle::afficher() const {
    std::cout << "SI ";
    for (int i =0; i<_condition.size(); ++i){
        std::cout <<"\t"<<_condition[i] << "\n";
    }
    std::cout << "ALORS ";
        std::cout <<"\t"<< _resultat << "\n";
    std::cout << std::endl;
}


