#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>

using namespace std;



ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao-vagas; }


int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    vector<string> nomes;
    for(auto i : this->clientes)
        nomes.push_back(i.nome);

    return sequentialSearch(nomes, nome);
}

//a implementar
int ParqueEstacionamento::getFrequencia(const string &nome) const
{
    int i = posicaoCliente(nome);
    if(i != -1)
        return clientes[i].frequencia;
    else throw ClienteNaoExistente(nome);
}

// a alterar/atualizar ?
bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
	clientes.push_back(info);
	numClientes++;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	clientes[pos].frequencia ++;
	vagas--;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}


// a implementar
void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
    insertionSort(this->clientes);
}


// a implementar
void ParqueEstacionamento::ordenaClientesPorNome()
{
    for (unsigned int p = 1; p < this->clientes.size(); p++)
    {
        InfoCartao tmp = this->clientes[p];
        int j;
        for (j = p; j > 0 && tmp.nome < this->clientes[j-1].nome; j--)
            this->clientes[j] = this->clientes[j-1];
        this->clientes[j] = tmp;
    }
}


// a implementar
vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2)
{
    vector<string> nomes;
    ordenaClientesPorFrequencia();
    for(auto i : clientes){
        if(i.frequencia >= n1 && i.frequencia <= n2)
            nomes.push_back(i.nome);
    }
    return nomes;
}


// a implementar
ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
    os << "Nome: " << " - " << "PRESENTE" << " - " << "FREQUENCIA";
    for(auto i : pe.clientes){
        os << i.nome << i.presente << i.frequencia;
    }
    return os;
}


// a implmentar
InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    InfoCartao info;
    if(p<0 || p>= this->clientes.size()) throw PosicaoNaoExistente();
    return info;
}

bool InfoCartao::operator<(const InfoCartao &rhs) const {
    if(rhs.frequencia == frequencia)
        return this->nome < rhs.nome;
    return rhs.frequencia < frequencia;
}

int PosicaoNaoExistente::getValor() const {
    return valor;
}

