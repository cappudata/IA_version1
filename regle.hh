#pragma once
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <ostream>

class Regle
{
private:
    std::vector<std::string> _condition;
    std::string _resultat;
public:
    Regle(std::vector<std::string> const & c, std::string const & r) : _condition(c), _resultat(r) {}
    void afficher() const;

    std::vector<std::string> getCondition() const & { return _condition; }
    std::string getResultat() const & { return  _resultat; }


};
