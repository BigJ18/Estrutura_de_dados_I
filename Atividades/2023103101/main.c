#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

    int tamanho = 0,numeroProcurado = 0;

    printf("Insira o tamanho da lista: ");
    scanf("%d",&tamanho);

    Lista* listinha = CriaLista(tamanho);

    PreencherValoresDaLista(listinha);

    system("cls");
    ExibirLista(listinha);

    printf("Exemplo de Busca com um numero encontrado e outro nao encontrado:\n\n");
    BuscarElementoNaListaDeFormaSequencial(listinha,listinha->elementos[0]);
    BuscarElementosDeFormaBinaria(listinha,198462);

    printf("\n Insira um numero para buscar na lista, (farei uma busca sequencial e uma busca binaria):");
    scanf("%d",&numeroProcurado);

    system("cls");
    ExibirLista(listinha);
    BuscarElementoNaListaDeFormaSequencial(listinha,numeroProcurado);
    BuscarElementosDeFormaBinaria(listinha,numeroProcurado);


    BuscarOMenorElemento(listinha);
    SomarTodosOsElementos(listinha);
    ProdutoDeTodosOsElementos(listinha);

    Lista* lista2 = CriaLista(30);
    PreencherValoresDaListaAutomaticamente(lista2);

    printf("\n Insira um numero para buscar na lista 2:");
    scanf("%d",&numeroProcurado);
    BuscarElementoNaListaDeFormaSequencial(lista2,numeroProcurado);
    BuscarElementosDeFormaBinaria(lista2,numeroProcurado);

    DestruirLista(listinha);
    DestruirLista(lista2);

    return 0;
}
