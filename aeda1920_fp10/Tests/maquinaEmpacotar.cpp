#include "maquinaEmpacotar.h"
#include <sstream>


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


// a alterar
unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
	int counter = 0;
	vector<int> v2;
	for(int i = 0; i < objs.size(); i++){
	    if(objs.at(i).getPeso() <= this->capacidadeCaixas){
	        this->objetos.push(objs.at(i));
	        v2.push_back(i);
	        counter++;
	    }
	}
	for(auto i : v2){
        objs.erase(objs.begin() + i);
	}
	return counter;
}

// a alterar
Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
    Caixa cx = Caixa(obj.getPeso());
    vector<Caixa> vCaixas;

    int sizeC = caixas.size();

    while(sizeC != 0){
        vCaixas.push_back(this->caixas.top());
        caixas.pop();
        sizeC--;
    }
    int found = -1;
    for(int i = 0; i < vCaixas.size(); i++){
        if(vCaixas.at(i).getCargaLivre() >= obj.getPeso()) {
            found = i;
            break;
        }
    }
    if(found != -1){
        cx = vCaixas.at(found);
        vCaixas.erase(vCaixas.begin() + found);
    }
    for(auto i : vCaixas){
        caixas.push(i);
    }
    return cx;
}

// a alterar
unsigned MaquinaEmpacotar::empacotaObjetos() {
	return 0;
}

// a alterar
string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
	return "";
}

// a alterar
Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
	Caixa cx;
	return cx;
}



