#include "moteurdinference.hh"



void moteurdinference::setBut(const std::string &newBut)
{
    _but = newBut;
}


//chainage arriere

void moteurdinference::chainageArriere() {
    // verifier le but
    // si le but n'est pas dans la base de fait => go

    while (std::find(_baseDefait.begin(), _baseDefait.end(), _but) == _baseDefait.end()) {
        std::cout << "In while" << std::endl;
        run(_but);

    }
    std::cout << "Ne trouve Pas" << std::endl;
}




void moteurdinference::run(const std::string &resultatDonne) {
    std::vector<Regle> vecRegle (getAllRules(resultatDonne));
    for (auto const r : vecRegle)
        explorer(r);
}



//récupérer toutes les règles à partir un résultat donné
// et les stock dans un vector<Regle>
std::vector<Regle> moteurdinference::getAllRules(const std::string & resultatDonne) const {
    std::vector<Regle> rules;
    for (auto const & r : _baseDeConnaissance) {
        if (r.getResultat() == resultatDonne)
            rules.push_back(r);
    }
    return rules;
}



void moteurdinference::explorer(Regle const & r) {
    for (int i=0; i<r.getCondition().size(); ++i) {
        if (appartient(r.getCondition().at(i))) {
            if (ruleCanBeTaken(r)) {
                ajouterFait(r.getResultat());
                std::cout << "in explorer" << std::endl;
            } else { ++i;
                std::cout << "in explorer2" << std::endl;
              }
        } else if (!appartient(r.getCondition().at(i)) && verifierRegle(r.getCondition().at(i))) {
            //explorer(GetRegle(r.getCondition().at(i)));
            std::cout << "in explorerrrr" << std::endl;
            run(r.getCondition().at(i));
        } else if (!appartient(r.getCondition().at(i)) && !verifierRegle(r.getCondition().at(i))) {
            std::cout << "inn explorer" << std::endl;
            break;
        }
    }
}


// fonction vérifie si un résultat donnee est dans la BF ou pas ?
bool moteurdinference::appartient(const std::string &resultatDonnee) const {
    for (auto const & r : _baseDefait){
        return r == resultatDonnee;
    }
}



// fonction vérifie si ya une règle avec le résultat == resultatDonnee dans la base de connaissance ou pas ?
bool moteurdinference::verifierRegle(const std::string &resultatDonnee) const {
    for (auto const & r : _baseDeConnaissance) {
        return r.getResultat() == resultatDonnee;
    }
}


Regle moteurdinference::GetRegle(const std::string &resultatDonnee) const {
    for (auto const & r : _baseDeConnaissance)
        if (r.getResultat() == resultatDonnee)
            return r;
}

//---------------------------------------------------------------------------------


//chainage avant en profonduer
void moteurdinference::chainageAvant()
{

    while(std::find(_baseDefait.begin(), _baseDefait.end(), _but) == _baseDefait.end()){

        for(unsigned int i =0; i < _baseDeConnaissance.size(); ++i ){

            if(ruleCanBeTaken(_baseDeConnaissance.at(i))) {

                ajouterFait(_baseDeConnaissance.at(i).getResultat());
                std::cout<<"Par R"<<i+1<<" <<"<< _baseDeConnaissance.at(i).getResultat()  <<">> U BF \n";
                std::cout<<std::endl;
                afficherBF();
                break;
            }
        }
    }
}





bool moteurdinference::ruleCanBeTaken(const Regle &r) const
{
    int nbr = 0; //calcul nombre de prémisse

    for(auto const & i : r.getCondition())
        if(std::find(_baseDefait.begin(), _baseDefait.end(), i) != _baseDefait.end() && std::find(_baseDefait.begin(), _baseDefait.end(), r.getResultat()) == _baseDefait.end())
            ++nbr;

    return nbr == r.getCondition().size();

}

void moteurdinference::afficher() const
{
    std::cout<<"**************Base de connaissance**************\n";
    std::cout<<" \n";
    for(auto const & i : _baseDeConnaissance)
        i.afficher();

    afficherBF();

    std::cout<<"**************But**************\n";
    std::cout<<" \n";
    std::cout<<"{ "<< _but <<" }\n";
    std::cout << std::endl;
}

void moteurdinference::afficherBF() const
{
    std::cout<<"**************Base de fait**************\n";
    std::cout<<" \n";
    std::cout<<"BF = { ";
    for(auto const & i : _baseDefait)
        std::cout<< i <<" ";

    std::cout<<"}\n";
    std::cout << std::endl;
}
