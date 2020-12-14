#include "palavraerrada.hpp"

PalavraErrada::PalavraErrada(std::string palavra, int linha, int coluna) 
    : Palavra(palavra, linha, coluna + 1) {}

PalavraErrada::~PalavraErrada() {}

bool 
PalavraErrada::addSugestao(std::string sugestao) {
    // if(this->sugestoes.size() < 5) {
    //     this->sugestoes.pushBack(sugestao);
        
    //     return true;
    // }
    
    return false;
}

std::ostream&
operator<< (std::ostream& o, PalavraErrada* const pe) {
    o << "linha: " << pe->linha << " coluna: " << pe->coluna << " " << pe->palavra << ":" << std::endl;

    // if (pe->sugestoes.size() > 0) {
    //     int index = 0;
    //     while (index != pe->sugestoes.size())
    //     {
    //         o << "  - " << pe->sugestoes.front() << std::endl;

    //         pe->sugestoes.popFront();

    //         index++;
    //     }
    // }

    return o;
}