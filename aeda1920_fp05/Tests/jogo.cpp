/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

// a implementar
Jogo::Jogo()
{
    this->criancas = list<Crianca>();
}

// a implementar
Jogo::Jogo(list<Crianca>& lc2)
{
    this->criancas = lc2;
}

// a implementar
void Jogo::insereCrianca(const Crianca &c1)
{
    this->criancas.push_back(c1);
}

// a implementar
list<Crianca> Jogo::getCriancasJogo() const
{
    list<Crianca> res = this->criancas;
    return res;
}

// a implementar
string Jogo::escreve() const
{
    string res;
    for(auto c : criancas){
        res += c.escreve() + "\n";
    }
    return res;
}

// a implementar
Crianca& Jogo::perdeJogo(string frase)
{
    int npal = numPalavras(frase)-1;
    list<Crianca>::iterator it = criancas.begin();
    list<Crianca>::iterator ite = criancas.end();
    while (criancas.size()>1) {
        int nc = criancas.size();
        int p = npal % nc;
        for (int i = 1; i <= p; i++) {
            it++;
            if (it == ite) it = criancas.begin();
        }
        cout << "sai: " << it->escreve() << endl;
        it = criancas.erase(it);
        if (it == ite) it = criancas.begin();
    }
    return *it;
}

// a implementar
list<Crianca>& Jogo::inverte()
{
    this->criancas.reverse();
    return criancas;
}

// a implementar
list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> res;
    for(auto c : this->criancas){
        if(c.getIdade() > id)
            res.push_back(c);
    }
    return res;
}

// a implementar
void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
    for(auto c : l1){
        this->insereCrianca(c);
    }
}

// a implementar
bool Jogo::operator==(Jogo& j2) {
    bool is_equal = true;

    if (this->criancas.size() != j2.criancas.size()) return false;
    else {
        int index = 0;
        for (auto c1 : this->criancas) {
            int index2 = 0;
            for (auto c2 : j2.criancas) {
                if (index == index2) {
                    if (!(c1 == c2)) return false;
                    else break;
                }
                index2++;
            }
            index++;
        }
    }
	return true;
}

// a implementar
list<Crianca> Jogo::baralha() const
{
    list<Crianca> result;
    int random, counter = 0, num_criancas = criancas.size();

    while (result.size() < num_criancas) {
        srand(time(nullptr));
        random = rand() % criancas.size();

        for (const auto &i : criancas) {
            if (counter == random) {
                result.push_back(i);
                break;
            }

            counter++;
        }

        counter = 0;
    }

    return result;
}
