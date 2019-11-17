// Atividade estruturada da Disciplina de Algoritmos
// Autor: Danielly Oliveira

// Cálculo do preço de um automóvel 0 km que varia de acordo com os opcionais
// escolhidos pelo cliente

#include <iostream>
#include <iomanip> // para manipular casas decimais dos numeros do tipo float
using namespace std;

//menu
void imprimirMenu(void) {
    cout << "\n\n--------- Menu de Opcionais: ---------\n\n";
    cout << "1 - Trio Eletrico (alarme, vidros e travas eletricas)\n";
    cout << "2 - Ar Condicionado\n";
    cout << "3 - Direcao Hidraulica\n";
    cout << "4 - Completo\n";
    cout << "0 - Nenhum / Finalizar\n";
    cout << "\n--------------------------------------\n";
    cout << "\nDigite o codigo do opcional desejado: ";
}

int main(void) {
    int opcao = 0;
    int contTrio = 0;
    int contAr = 0;
    int contDirecao = 0;
    int contCompleto = 0;
    float valorTrio = 0.0;
    float valorAr = 0.0;
    float valorDirecao = 0.0;
    float valorCompleto = 0.0;
    float valorFabrica = 0.0;
    float valorIpi = 0.0;
    float valorParcial = 0.0;
    float valorTotal = 0.0;

    cout << "\n\nVamos montar seu carro? Digite o valor de fabrica do carro: ";
    cin >> valorFabrica;
    valorIpi = valorFabrica * 0.08;

    // ler opçao escolhida pelo usuario
    imprimirMenu();
    cin >> opcao;

    //seleção do menu    
    while(opcao != 0){

        switch(opcao){

            case 1:
                contTrio++;
                valorTrio = (valorFabrica + valorIpi) * 0.02;
                break;

            case 2:
                contAr++;
                valorAr = valorFabrica * 0.02;
                break;

            case 3:
                contDirecao++;
                valorDirecao = valorFabrica * 0.02;
                break;

            case 4:
                contCompleto++;
                // 0.04 = 0.02 do direçao hidraulica + 0.02 do ar    
                valorCompleto = (valorFabrica * 0.04) + ((valorFabrica + valorIpi) * 0.02); 
                break;
                    
            default:
                // para opções não fornecidas no menu
                cout << "\nOpcao invalida!\n";
        }
        // ler opçao escolhida pelo usuario
        imprimirMenu();
        cin >> opcao;
    }

    // valor sem nenhum opcional
    valorParcial = valorFabrica + valorIpi;

    // com trio
    if (contTrio > 0)
    {
        valorParcial += valorTrio;
    }

    // com ar
    if (contAr > 0)
    {
        valorParcial += valorAr;
    }

    // com direcao
    if (contDirecao > 0)
    {
        valorParcial += valorDirecao;
    }

    // valor total
    valorTotal = valorParcial;

    // completo
    // se o usuario escolheu completo,
    // devemos ignorar as opcoes 1, 2 e 3,
    // e sobreescrever o valor total
    if (contCompleto > 0)
    {
        valorTotal = (valorParcial + valorCompleto) - 0.035;
    }

    // impressao do valor total
    cout.precision(2); // limita para duas casa decimais
    cout << "\nValor total: R$ " << fixed << valorTotal << "\n";

    // impressão dos contadores
    cout << "\n\nO Trio Eletrico foi escolhido " << contTrio << " vezes.\n";
    cout << "O Ar Condicionado foi escolhido " << contAr << " vezes.\n";
    cout << "A Direcao Hidraulica foi escolhida " << contDirecao << " vezes.\n";
    cout << "O Completo foi escolhido " << contCompleto << " vezes.\n";

    return 0;
}
