#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : numMaximoClientes(nMaxCli),lotacao(lot){
    this->vagas=lot;
    this->clientes={};
}

unsigned int ParqueEstacionamento::getNumLugares() const {
    return this->lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
    return this->numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const {
    for (int i=0; i<this->clientes.size();i++)
        if (this->clientes.at(i).nome == nome)
            return i;
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) {
    if (this->getNumClientesAtuais() != this->getNumMaximoClientes()){
        InfoCartao newClient;
        newClient.nome = nome;
        newClient.presente = false;
        this->clientes.push_back(newClient);
    }
    return posicaoCliente(nome) != -1;
}

bool ParqueEstacionamento::entrar(const string & nome) {
    int n_dex = posicaoCliente(nome);
    if (n_dex != -1){
        if(this->getNumLugaresOcupados() == this->getNumLugares())
            return false;
        else{
            InfoCartao client = this->clientes[n_dex];
            if (client.presente)
                return false;
            else{
                this->vagas -= 1;
                client.presente = true;
                this->clientes[n_dex] = client;
                return true;
            }
        }
    } else return false;
}

bool ParqueEstacionamento::retiraCliente(const string & nome) {
    int n_dex = posicaoCliente(nome);
    if (n_dex != -1) {
        InfoCartao client = this->clientes[n_dex];
        if (client.presente)
            return false;
        else{
            this->clientes.erase(this->clientes.begin() + n_dex);
            return posicaoCliente(nome) == -1;
        }
    } else return false;
}

bool ParqueEstacionamento::sair(const string & nome) {
    int n_dex = posicaoCliente(nome);
    if (n_dex != -1) {
        InfoCartao client = this->clientes[n_dex];
        if (!client.presente)
            return false;
        else{
            this->vagas +=1;
            client.presente = false;
            this->clientes[n_dex] = client;
            return true;
        }
    } else return false;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    return this->lotacao - this->vagas;
}
unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    return this->clientes.size();
}


