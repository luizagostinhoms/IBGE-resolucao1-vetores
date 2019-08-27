#include <stdio.h>

//PRIMEIRA SOLU��O, USANDO VETOR

int main() {
	
    int num_cidade;
    printf("==== IBGE ==== \n \n");
    printf("Digite a quantidade de cidades a serem cadastradas: ");
    scanf("%d", &num_cidade); // numero de cidades a ser cadastradas

    /** Nessa solu��o usaremos apenas vetores,
    como � ncess�rio 3 informa��es por cidade, teremos que usar tr�s vetores
    representando cada informa��o.
    Devemos enteder que cada cidade ser� represtanda pela posi��o dos vetores declarados*/
    printf("\n\nAgora digite os dados da cidade: \n\n");
    int vet_codigo_cidade[num_cidade];
    int vet_numero_veiculos[num_cidade];
    int vet_acidente_vitimas[num_cidade];


    for (int i = 0; i < num_cidade; i++) { //usaremos sempre o num_cidade para varrer os vetores.
        printf("------------------------------");
        printf("\n\nCadastro da cidade: %d", i+1);

        printf("\nDigite o c�digo da cidade: ");
        scanf("%d", &vet_codigo_cidade[i]);

        printf("Digite o n�mero de veiculos de passeio da cidade:");
        scanf("%d", &vet_numero_veiculos[i]);

        printf("Digite o n�mero de acidentes de tr�nsito com v�timas:");
        scanf("%d", &vet_acidente_vitimas[i]);
    }

    printf("\n\nRELAT�RIOS: \n\n");
    printf("\n\n-------------------\n\n");
    /**
     Aqui faremos uma l�gica de maior,
     pegamos as informa��es da priemira posi��o do vetor vet_acidente_vitimascomparamos com as sbsequentes da mesma
     se o volor da vari�vel for menor que a comparada, ela recebe o valor da comparada,
     assim no final a vari�vel ficar� com o maior valor de todo o array.
    */
    int maior_n_acidente = vet_acidente_vitimas[0];  //vari�vel para guardar o valor do maior numero de acidentes
    int cod_cid_maior_acid = vet_codigo_cidade[0]; //vari�vel para guardar o valor o c�digo da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < vet_acidente_vitimas[i]){
            maior_n_acidente = vet_acidente_vitimas[i];
            cod_cid_maior_acid = vet_codigo_cidade[i]; //sabemos que a posi��o [i] corresponde a mesma cidade mesmo que em vetores separados
        }
     }
    printf("A cidade com maior ind�ce de acidentes �: %d", cod_cid_maior_acid);
    printf("\nE o n�mero de acidentes �: %d", maior_n_acidente);


    printf("\n\n-------------------\n\n");
     /**
     Aqui faremos uma l�gica de menor,
     pegamos as informa��es da priemira posi��es da vet_acidente_vitimascomparamos e comparamos com as sbsequentes da mesma
     se o volor da vari�vel for maior que a comparada, ela recebe o valor da comparada,
     assim no final a vari�vel ficar� com o menor valor de todo o array.
    */
    int menor_n_acidente = vet_acidente_vitimas[0]; //vari�vel para guardar o valor do menor numero de acidentes
    int cod_cid_menor_acid = vet_codigo_cidade[0]; //vari�vel para guardar o valor o c�digo da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > vet_acidente_vitimas[i]) {
            menor_n_acidente = vet_acidente_vitimas[i];
            cod_cid_menor_acid = vet_codigo_cidade[i];
        }
     }
    printf("A cidade com  menor ind�ce de acidentes �: %d", cod_cid_menor_acid);
    printf("\nE o n�mero de acidentes �: %d", menor_n_acidente);

    printf("\n\n-------------------\n\n");
     /**
        L�gica de m�dia de veiculos, somamos todos os veiculos do array vet_numero_veiculos,
        e no fim dividimos pela quantiade de cidades.
    */
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + vet_numero_veiculos[i];
    }

    float media_veiculo = total_veiculos / num_cidade;
    printf("A m�ida de veiculos nas cidades juntas �: %.1f", media_veiculo);

    printf("\n\n-------------------\n\n");
    /**
        L�gica de m�dia de acidentes de tr�nsito,
        desde que a cidade tenha menos que 2000 veiculos.
    */
    int total_acident_transito = 0; //vari�vel para somar os acidentes de tr�nsito
    int count_cidades_menor_2000 = 0; //var�vel que ir� contar quntas cidade tem menos que 2000, necess�ria para m�dia, j� que n�o faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(vet_numero_veiculos[i] < 2000) {
            total_acident_transito = total_acident_transito + vet_acidente_vitimas[i];
            count_cidades_menor_2000++;
        }
    }

     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf("A m�ida de acidentes de tr�nsito em cidades com menos de 2000 ve�culos �: %.1f", media_acidente_transito);


    return 0;
}

