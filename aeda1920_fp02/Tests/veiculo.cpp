#include "veiculo.h"
#include <iostream>

using namespace std;

//------------------------------Veiculo-----------------------------------------------------//

Veiculo::Veiculo(string mc, int m, int a) {
    this->marca=mc;
    this->mes=m;
    this->ano=a;
}

string Veiculo::getMarca() const {
    return this->marca;
}

int Veiculo::getAno() const {
    return this->ano;
}

int Veiculo::info() const {
    cout << "Marca: " << this->getMarca() << endl;
    cout << "Mês: " << this->mes << endl;
    cout << "Ano: " << this->getAno() << endl;
    return 3;
}

bool Veiculo::operator < (const Veiculo & v) const {
    string date1 = to_string(this->getAno()) + to_string(this->mes);
    string date2 = to_string(v.getAno()) + to_string(v.mes);
    return date1<date2;
}

//------------------------------Motorizado-----------------------------------------------------//

Motorizado::Motorizado(string mc, int m, int a, string c, int cil) : Veiculo(mc,m,a) {
    this->combustivel=c;
    this->cilindrada=cil;
}

string Motorizado::getCombustivel() const {
    return this->combustivel;
}

int Motorizado::info() const {
    int infoV=Veiculo::info();
    cout << "Combustível: " << this->getCombustivel() << endl;
    cout << "Cilindrada: " << this->cilindrada << endl;
    return infoV+2;
}

float Motorizado::calcImposto() const{
    if (combustivel=="gasolina") {
        if (cilindrada<=1000)
            if (ano<=1995) return 8.10; else return 14.56;
        else if (cilindrada<=1300)
            if (ano<=1995) return 14.56; else return 29.06;
        else if (cilindrada<=1750)
            if (ano<=1995) return 22.65; else return 45.15;
        else if (cilindrada<=2600)
            if (ano<=1995) return 54.89; else return 113.98;
        else if (cilindrada<=3500)
            if (ano<=1995) return 87.13; else return 181.17;
        else if (ano<=1995) return 148.35; else return 320.89;
    }
    else {
        if (cilindrada<=1500)
            if (ano<=1995) return 8.10; else return 14.56;
        else if (cilindrada<=2000)
            if (ano<=1995) return 14.56; else return 29.06;
        else if (cilindrada<=3000)
            if (ano<=1995) return 22.65; else return 45.15;
        else  if (ano<=1995) return 54.89; else return 113.98;
    }
}

//------------------------------Automovel-----------------------------------------------------//

Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado(mc,m,a,c,cil){}

int Automovel::info() const {
   int infoM=Motorizado::info();
   return infoM;
}


//------------------------------Camiao-----------------------------------------------------//

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) : Motorizado(mc,m,a,c,cil) {
  this->carga_maxima=cm;
}

int Camiao::info() const {
    int infoM=Motorizado::info();
    cout << "Carga máxima: " << this->carga_maxima << endl;
    return infoM+1;
}

//------------------------------Bicicleta-----------------------------------------------------//

Bicicleta::Bicicleta(string mc, int m, int a, string t) : Veiculo(mc,m,a) {
    this->tipo=t;
}

int Bicicleta::info() const {
    int infoV=Veiculo::info();
    cout << "Tipo: " << this->tipo << endl;
    return infoV+1;
}

float Bicicleta::calcImposto() const{
    return 0;
}