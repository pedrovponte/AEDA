#include "jogador.h"

//a alterar
void Jogador::adicionaAposta(const Aposta & ap)
{
    this->apostas.insert(ap);
}

//a alterar
unsigned Jogador::apostasNoNumero(unsigned num) const
{
	int counter;
	for(auto i : this->apostas){
	    for(auto j : i.getNumeros()){
	        if(num == j)
	            counter++;
	    }
	}
	return counter;
}

//a alterar
tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
    tabHAposta t;
    for(auto i : this->apostas){
        if(i.calculaCertos(sorteio) >= 3)
            t.insert(i);
    }
    return t;
}
