#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"

using namespace std;

//a alterar
Cliente::Cliente() {
    this->numPresentes = (rand() % 5) + 1;
}

//a alterar
int Cliente::getNumPresentes() const {
    return this->numPresentes;
}

//a alterar
Balcao::Balcao(int te): tempo_embrulho(te) {
    clientes_atendidos = 0;
    prox_chegada = (rand() % 20) + 1;
    tempo_atual = 0;
    prox_saida = 0;
}

//a alterar
void Balcao:: proximoEvento()
{
    if(!clientes.empty()){
        if(prox_chegada < prox_saida){
            tempo_atual = prox_chegada;
            chegada();
        }
        else{
            tempo_atual = prox_chegada;
            chegada();
        }
    }
}

//a alterar
void Balcao::chegada()
{
    Cliente *c = new Cliente();
    this->prox_chegada = (rand() % 20) + 1;
    if(this->clientes.empty())
        this->prox_saida = this->tempo_atual + c->getNumPresentes() * this->tempo_embrulho;
    this->clientes.push(*c);
    cout << "tempo: " << this->tempo_atual << "\nchegou novo cliente com " << c->getNumPresentes() << "presentes\n";
    this->prox_chegada = (rand() % 20) + 1;
}

//a alterar
void Balcao::saida()
{
    cout << "tempo= " << tempo_atual << endl;
    Cliente c1;
    try{
        c1 = getProxCliente();
    }
    catch (FilaVazia  &e){
        cout << e.getMsg() << endl;
        return;
    }
    clientes.pop();
    clientes_atendidos++;
    if(clientes.empty() != false)
        prox_saida = tempo_atual + clientes.front().getNumPresentes() * tempo_embrulho;
}


int Balcao::getTempoAtual() const { return tempo_atual; }

int Balcao::getProxChegada() const { return prox_chegada; }

//a alterar
ostream & operator << (ostream & out, const Balcao & b1)
{
     return out;
}

//a alterar
int Balcao::getTempoEmbrulho() const {
	return this->tempo_embrulho;
}

//a alterar
int Balcao::getProxSaida() const {
	return this->prox_saida;
}

//a alterar
int Balcao::getClientesAtendidos() const {
    return this->clientes_atendidos;
}

//a alterar
Cliente & Balcao::getProxCliente() {
    if(clientes.empty()) throw FilaVazia();
    this->clientes_atendidos++;
    Cliente *c = & this->clientes.back();
    return *c;
}

      
