#include <stdio.h>

//PRIMEIRA SOLUÇÃO, USANDO VETOR

int main() {
	
    int num_cidade;
    printf("==== IBGE ==== \n \n");
    printf("Digite a quantidade de cidades a serem cadastradas: ");
    scanf("%d", &num_cidade); // numero de cidades a ser cadastradas

    /** Nessa solução usaremos apenas vetores,
    como é ncessário 3 informações por cidade, teremos que usar três vetores
    representando cada informação.
    Devemos enteder que cada cidade será represtanda pela posição dos vetores declarados*/
    printf("\n\nAgora digite os dados da cidade: \n\n");
    int vet_codigo_cidade[num_cidade];
    int vet_numero_veiculos[num_cidade];
    int vet_acidente_vitimas[num_cidade];


    for (int i = 0; i < num_cidade; i++) { //usaremos sempre o num_cidade para varrer os vetores.
        printf("------------------------------");
        printf("\n\nCadastro da cidade: %d", i+1);

        printf("\nDigite o código da cidade: ");
        scanf("%d", &vet_codigo_cidade[i]);

        printf("Digite o número de veiculos de passeio da cidade:");
        scanf("%d", &vet_numero_veiculos[i]);

        printf("Digite o número de acidentes de trânsito com vítimas:");
        scanf("%d", &vet_acidente_vitimas[i]);
    }

    printf("\n\nRELATÓRIOS: \n\n");
    printf("\n\n-------------------\n\n");
    /**
     Aqui faremos uma lógica de maior,
     pegamos as informações da priemira posição do vetor vet_acidente_vitimascomparamos com as sbsequentes da mesma
     se o volor da variável for menor que a comparada, ela recebe o valor da comparada,
     assim no final a variável ficará com o maior valor de todo o array.
    */
    int maior_n_acidente = vet_acidente_vitimas[0];  //variável para guardar o valor do maior numero de acidentes
    int cod_cid_maior_acid = vet_codigo_cidade[0]; //variável para guardar o valor o código da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < vet_acidente_vitimas[i]){
            maior_n_acidente = vet_acidente_vitimas[i];
            cod_cid_maior_acid = vet_codigo_cidade[i]; //sabemos que a posição [i] corresponde a mesma cidade mesmo que em vetores separados
        }
     }
    printf("A cidade com maior indíce de acidentes é: %d", cod_cid_maior_acid);
    printf("\nE o número de acidentes é: %d", maior_n_acidente);


    printf("\n\n-------------------\n\n");
     /**
     Aqui faremos uma lógica de menor,
     pegamos as informações da priemira posições da vet_acidente_vitimascomparamos e comparamos com as sbsequentes da mesma
     se o volor da variável for maior que a comparada, ela recebe o valor da comparada,
     assim no final a variável ficará com o menor valor de todo o array.
    */
    int menor_n_acidente = vet_acidente_vitimas[0]; //variável para guardar o valor do menor numero de acidentes
    int cod_cid_menor_acid = vet_codigo_cidade[0]; //variável para guardar o valor o código da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > vet_acidente_vitimas[i]) {
            menor_n_acidente = vet_acidente_vitimas[i];
            cod_cid_menor_acid = vet_codigo_cidade[i];
        }
     }
    printf("A cidade com  menor indíce de acidentes é: %d", cod_cid_menor_acid);
    printf("\nE o número de acidentes é: %d", menor_n_acidente);

    printf("\n\n-------------------\n\n");
     /**
        Lógica de média de veiculos, somamos todos os veiculos do array vet_numero_veiculos,
        e no fim dividimos pela quantiade de cidades.
    */
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + vet_numero_veiculos[i];
    }

    float media_veiculo = total_veiculos / num_cidade;
    printf("A méida de veiculos nas cidades juntas é: %.1f", media_veiculo);

    printf("\n\n-------------------\n\n");
    /**
        Lógica de média de acidentes de trânsito,
        desde que a cidade tenha menos que 2000 veiculos.
    */
    int total_acident_transito = 0; //variável para somar os acidentes de trânsito
    int count_cidades_menor_2000 = 0; //varável que irá contar quntas cidade tem menos que 2000, necessária para média, já que não faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(vet_numero_veiculos[i] < 2000) {
            total_acident_transito = total_acident_transito + vet_acidente_vitimas[i];
            count_cidades_menor_2000++;
        }
    }

     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf("A méida de acidentes de trânsito em cidades com menos de 2000 veículos é: %.1f", media_acidente_transito);


    return 0;
}

