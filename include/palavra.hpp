#pragma once

#include <iostream>
#include <string>

class Palavra
{
    public:
        Palavra(std::string palavra, int linha, int coluna);
        ~Palavra();

        std::string getPalavra() const;
        int getLinha() const;
        int getColuna() const;

        friend std::ostream& operator<< (std::ostream& o, Palavra* const p);

    protected:
        std::string palavra;
        int linha;
        int coluna;
};
