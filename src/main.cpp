#include <iostream>
#include <string.h>
#include <stdio.h>
#include "levenshtein.hpp"
#include "palavraerrada.hpp"
#include "queue.hpp"
#include "dicionario.hpp"

int main(int argc, char const *argv[])
{
    const char *caminhoDoDicionario;
    const char *caminhoDoTexto;

    if (argc < 3)
    {
        std::cout << "use ./programa caminhoDoDicionario.txt caminhoDotexto.txt" << std::endl;
        return -1;
    }

    caminhoDoDicionario = argv[1];
    caminhoDoTexto = argv[2];

    // estrutura de dados para o texto e o porque vai utilizar
    // sugestão previa fila
    // porque por quê as primeiras palavras a entrar seram as primeiras a serem lidas ou processadas
    Dicionario<std::string, std::string> *dicionario = new Dicionario<std::string, std::string>();

    int index = 0;
    int column = 0;
    char Linha[100];
    char *result;

    // ler e armazenar as palavras do dicionario
    FILE *arquivoDicionario = fopen(caminhoDoDicionario, "rt");

    index = 1;
    while (!feof(arquivoDicionario))
    {
        result = fgets(Linha, 100, arquivoDicionario);

        if (result)
        {
            std::string s = Linha; 
            dicionario->insert(Linha, Linha);
        }

        index++;
    }

    fclose(arquivoDicionario);

    // ler as palavras do texto
    Queue<Palavra *> *palavras = new Queue<Palavra *>();

    FILE *arquivoTexto = fopen(caminhoDoTexto, "rt");

    index = 1;
    column = 1;
    while (!feof(arquivoTexto))
    {
        result = fgets(Linha, 100, arquivoTexto);

        if (result)
        {
            char *pch;

            pch = strtok(Linha, " ,.-");

            while (pch != NULL)
            {
                pch = strtok(NULL, " ,.-");

                if (pch != NULL)
                {
                    Palavra *novaPalavra = new Palavra(pch, index, column);
                    palavras->pushBack(novaPalavra);

                    ++column;
                }
            }
        }

        column = 1;
        index++;
    }

    fclose(arquivoTexto);

    // procurar palavras erradas
    // criar uma struct ou class para representar as palavras erradas
    // atributos: palavra errada, linha, coluna, sugestões (Array de até 5 possições)
    Queue<PalavraErrada *> *palavrasErradas = new Queue<PalavraErrada *>();

    for (size_t i = 0; i < palavras->size(); ++i) {
        bool palavraCerta = false;
        Palavra* p = palavras->front();

        palavraCerta = dicionario->has(p->getPalavra());
    
        if (!palavraCerta){
            PalavraErrada* pe = new PalavraErrada(p->getPalavra(), p->getLinha(), p->getColuna());
            palavrasErradas->pushBack(pe);   
        }

        palavras->popFront();
    }

    // lista as palavras erradas 
    palavrasErradas->print();

    delete[] dicionario;
    delete[] palavras;
    delete[] palavrasErradas;

    return 0;
}

// http://www.cplusplus.com/reference/cstring/strtok/
// https://www.cplusplus.com/reference/functional/hash/