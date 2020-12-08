#include "palavraerrada.h"

PalavraErrada::PalavraErrada(std::string palavra, int linha, int coluna) 
    : Palavra(palavra, linha, coluna), quantidadeDeSugestoes(0) {}

PalavraErrada::~PalavraErrada() {}

bool 
PalavraErrada::addSugestao(std::string sugestao) {
    if(this->quantidadeDeSugestoes < 5) {
        this->sugestoes[quantidadeDeSugestoes] = sugestao;
        
        this->quantidadeDeSugestoes++;
        
        return true;
    }
    
    return false;
}

std::ostream&
operator<< (std::ostream& o, PalavraErrada* const pe) {
    o << pe->palavra << ":" << std::endl;

    if (pe->quantidadeDeSugestoes > 0) {
        int index = 0;
        while (index != pe->quantidadeDeSugestoes)
        {
            o << "  - " << pe->sugestoes[index] << std::endl;

            index++;
        }
    }

    return o;
}