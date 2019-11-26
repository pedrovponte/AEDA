#include "aposta.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// a alterar
bool Aposta::contem(unsigned num) const
{
	for(auto i : this->numeros){
	    if(num == i)
	        return true;
	}
	return false;
}

//a alterar
void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
    vector<unsigned> aux;
    for(auto i : valores){
        if(find(aux.begin(), aux.end(), i) == aux.end()){
            aux.push_back(i);
            n--;
        }
        if(n == 0) break;
    }
    for(auto i : aux){
        this->numeros.insert(i);
    }
}

//a alterar
unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
    int counter;
    for(auto i : this->numeros){
        if(find(sorteio.begin(), sorteio.end(), i) != sorteio.end())
            counter++;
    }
    return counter;
}





