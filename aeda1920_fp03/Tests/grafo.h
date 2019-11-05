#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

// excecao NoRepetido
template <class N>
class NoRepetido
{
public:
    N info;
    NoRepetido(N inf) { info=inf; }
};

// excecao NoInexistente
template <class N>
class NoInexistente {
public:
    N info;
    NoInexistente(N inf) {
        info = inf;
    }
};

// excecao ArestaRepetida
template <class A>
class ArestaRepetida {
public:
    A valor;
    ArestaRepetida(A inf) {
        valor= inf;
    }
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo(){
    };
    ~Grafo(){
        for(auto i : this->nos){
            delete i;
        }
    };
    Grafo & inserirNo(const N &dados){
        for (auto element : this->nos) {
            if (element->info == dados) {
                throw NoRepetido<N>(dados);
            }
        }
        this->nos.push_back(new No<N,A>(dados));
        return *this;
    };
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val){
        bool exists = false;
        No<N,A> *endnode;
        for(auto i : this->nos)
            if(i->info == fim)
                exists = true;
                endnode = i;
        if(!exists){
            throw NoInexistente<N>(fim);
        }
        for(auto i : this->nos){
            if(i->info == inicio){
                for(auto ar : i->arestas){
                    if(ar.valor == val || ar.destino->info == fim){
                        throw ArestaRepetida<A>(val);
                    }
                }
                i->arestas.push_back(Aresta<N,A>(endnode,val));
                return *this;
            }
        }
        throw NoInexistente<N>(inicio);
    };
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const{
        unsigned int counter = 0;
        for (auto i : this->nos){
            counter += i->arestas.size();
        }
        return counter;
    }
    int numNos(void) const{
        return this->nos.size();
    }
    void imprimir(std::ostream &os) const; 
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);

template <class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{out << "No repetido: " << no.info; return out; }


template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

template <class A>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<A> &ar)
{ out << "Aresta Repetida: " << ar.valor; return out; }
