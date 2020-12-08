#pragma once

#include <iostream>
#include <string>
#include "palavra.h"

class PalavraErrada : public Palavra
{
    public:
        PalavraErrada(std::string palavra, int linha, int coluna);
        ~PalavraErrada();

        bool addSugestao(std::string sugestao);

        friend std::ostream& operator<< (std::ostream& o, PalavraErrada* const pe);

    private:
        // modificar para uma estrutura que consoma apenas o suficiente como uma fila, lista emcadeada, pilha 
        int quantidadeDeSugestoes;
        std::string sugestoes[5];
};