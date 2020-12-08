#include "palavra.h"

Palavra::Palavra(std::string palavra, int linha, int coluna)
    : palavra(palavra), linha(linha), coluna(coluna) {}

Palavra::~Palavra() {}

int
Palavra::getLinha() const {
    return this->linha;
}

int 
Palavra::getColuna() const {
    return this->coluna;
}

std::ostream& 
operator<< (std::ostream& o, Palavra* const p) {
    o << p->palavra;

    return o;
}