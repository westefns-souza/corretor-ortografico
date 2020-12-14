#include "palavra.hpp"

Palavra::Palavra(std::string palavra, int linha, int coluna)
    : palavra(palavra), linha(linha), coluna(coluna) {}

Palavra::~Palavra() {}

std::string
Palavra::getPalavra() const {
    return this->palavra;
}

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