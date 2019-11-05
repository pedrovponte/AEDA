#include "frota.h"
#include <string>
#include <iostream>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1){
    this->veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
    return this->veiculos.size();
}

int Frota::menorAno() const {
    if (this->numVeiculos() == 0)
        return 0;

    int a = 9999;
    for (auto i : this->veiculos){
        int na = i->getAno();
        if (na<a)
            a = na;
    }
    return a;
}

ostream & operator<<(ostream & o, const Frota & f){
    vector <Veiculo *> v = f.veiculos;
    for(auto i : v)
        o << i->info();

    return o;
}

vector<Veiculo *> Frota::operator () (int anoM) const{
    vector <Veiculo *> v;
    for(auto i: this->veiculos){
        if(i->getAno() == anoM)
        v.push_back(i);
    }
    return v;
}

float Frota::totalImposto() const{
    float total=0;
    for(auto i : this->veiculos){
        total += i->calcImposto();
    }
    return total;
}
