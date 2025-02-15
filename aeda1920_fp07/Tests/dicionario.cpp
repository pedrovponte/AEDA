#include <iostream>
#include <string>
#include <fstream>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

//a alterar
bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
     return palavra < ps1.palavra;
}

bool PalavraSignificado::operator == (const PalavraSignificado &ps1) const {
    return palavra == ps1.palavra;
}

//a alterar
void Dicionario::lerDicionario(ifstream &fich)
{
     string pal, sig;
     while(!fich.eof()){
         getline(fich, pal);
         getline(fich, sig);
         PalavraSignificado p1(pal, sig);
         palavras.insert(p1);
     }
}

//a alterar
string Dicionario::consulta(string palavra) const
{
    PalavraSignificado p1(palavra,"");
    PalavraSignificado px=palavras.find(p1);
    PalavraSignificado pNotFound("","");
    if (px==pNotFound)
    {
        BSTItrIn<PalavraSignificado> it(palavras);
        string palAntes="",signifAntes="";
        while (!it.isAtEnd() && it.retrieve()<p1)
        {
            palAntes=it.retrieve().getPalavra();
            signifAntes=it.retrieve().getSignificado();
            it.advance();
        }
        string palApos="",signifApos="";
        if (!it.isAtEnd())
        {
            palApos=it.retrieve().getPalavra();
            signifApos=it.retrieve().getSignificado();
        }
        throw PalavraNaoExiste(palAntes,signifAntes,palApos,signifApos);
    }
    else
        return px.getSignificado();
}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
    return 0;
}

//a alterar
void Dicionario::imprime() const
{
    BSTItrIn<PalavraSignificado> it(palavras);
    while(!it.isAtEnd()){
        cout << it.retrieve().getPalavra() << endl << it.retrieve().getSignificado() << endl;
        it.advance();
    }
}

