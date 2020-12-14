#pragma once

#include <iostream>
#include <string>

#include "palavra.hpp"
#include "queue.hpp"

class PalavraErrada : public Palavra
{
    public:
        PalavraErrada(std::string palavra, int linha, int coluna);
        ~PalavraErrada();

        bool addSugestao(std::string sugestao);
        
        friend std::ostream& operator<< (std::ostream& o, PalavraErrada* const p);

    private:
        Queue<std::string> sugestoes;
        // Usei uma fila para as sugestoes pois queria uma estrutura que não ocupasse sempre 5 espaços pos nem todas as palavras
        // teram 5 sugestões, e precisava de uma estrutura que o primeiro que entrasse fosse o primeiro a sair, por terá um indice levenshtein menor
};