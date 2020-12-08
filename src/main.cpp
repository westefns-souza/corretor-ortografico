#include <iostream>
#include <string>
#include "levenshtein.h"
#include "palavraerrada.h"

int main(int argc, char const *argv[])
{
    std::string caminhoDoDicionario;
    std::string caminhoDoTexto;

    if (argc < 3)
    {
        std::cout << "use ./programa caminhoDoDicionario.txt caminhoDotexto.txt" << std::endl;
        return -1;
    }

    caminhoDoDicionario = argv[1];
    caminhoDoTexto = argv[2];

    PalavraErrada* pe = new PalavraErrada("la", 1, 1);

    std::string sugestao = "teste"; 
    pe->addSugestao(sugestao);

    std::cout << pe << std::endl;

    // estrutura de dados para o dicionario e o porque vai utilizar
    
    // estrutura de dados para o texto e o porque vai utilizar
    // sugestão previa fila
    // porque por quê as primeiras palavras a entrar seram as primeiras a serem lidas ou processadas

    // ler e armazenar as palavras do dicionario

    // ler as palavras do texto

    // procurar palavras erradas
        // criar uma struct ou class para representar as palavras erradas
        // atributos: palavra errada, linha, coluna, sugestões (Array de até 5 possições)

    // procurar sugestoes para as palavras erradas

    // lista as palavras erradas
    
    return 0;
}