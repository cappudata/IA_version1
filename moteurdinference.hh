#pragma once
#include "regle.hh"

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>


class moteurdinference
{

private: 
	std::vector<Regle> _baseDeConnaissance;
	std::vector<std::string> _baseDefait;
    std::string _but;
public:
	moteurdinference()=default;

	
	void ajouterRegle(Regle const &r) {_baseDeConnaissance.push_back(r);}
	void ajouterFait(std::string const & fait) {_baseDefait.push_back(fait);}
    void afficher() const;
    void afficherBF() const;
    void setBut(const std::string &newBut);
    void chainageAvant();
    void chainageArriere();


	std::size_t taille() const { return _baseDeConnaissance.size();}
	std::vector<Regle> getbaseDeConnaissance() const { return _baseDeConnaissance;}
    std::vector<std::string> getbaseDeFait() const { return _baseDefait;}
    bool ruleCanBeTaken(Regle const & r) const;


    std::vector<Regle> getAllRules(std::string const & r) const ;
    void explorer(Regle const & r);
    bool appartient(std::string const & resultatDonnee) const;
    bool verifierRegle(std::string const & resultatDonnee) const;
    Regle GetRegle(std::string const & resultatDonnee) const ;
    void run(std::string const & resultatDonne);

};
