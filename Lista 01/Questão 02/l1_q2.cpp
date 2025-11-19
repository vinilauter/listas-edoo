#include <iostream>

using namespace std;

// funcao de intercalacao e ordenacao

void merge(int* fila, int indice_inicio, int indice_meio, int indice_fim) {

    // calcula o tamanho dos dois vetores
    int tam_esq = indice_meio - indice_inicio + 1;
    int tam_dir = indice_fim - indice_meio;

    // vetores temporarios
    int* vet_temp_esq = new int[tam_esq];
    int* vet_temp_dir = new int[tam_dir];

    // passa os dados para os vetores temporarios

    for (int i = 0; i < tam_esq; i++) {
        vet_temp_esq[i] = fila[indice_inicio + i];
    }

    for (int j = 0; j < tam_dir; j++) {
        vet_temp_dir[j] = fila[indice_meio + 1 + j];
    }

    int index_esq = 0;
    int index_dir = 0;
    int index_principal = indice_inicio;

    // loop para intercalar ambos os vetores

    while (index_esq < tam_esq and index_dir < tam_dir) {
        // compara os elementos
        if (vet_temp_esq[index_esq] <= vet_temp_dir[index_dir]) {
            // se o da esquerda for menor ou igual ele entra na fila principal
            fila[index_principal] = vet_temp_esq[index_esq];
            index_esq++;
        }
        else {
            // caso contrario quem entra e o da direita
            fila[index_principal] = vet_temp_dir[index_dir];
            index_dir++;
        }
        index_principal++;
    }

    // caso sobre algo
    while (index_esq < tam_esq) {
        fila[index_principal] = vet_temp_esq[index_esq];
        index_esq++;
        index_principal++;
    }
    while (index_dir < tam_dir) {
        fila[index_principal] = vet_temp_dir[index_dir];
        index_dir++;
        index_principal++;
    }

    delete[] vet_temp_esq;
    delete[] vet_temp_dir;
}

// funcao recursiva para ordenar internamente

void merge_sort(int* fila, int indice_inicio, int indice_fim) {

    // caso base: se o inicio for menor que o fim, ainda tem como dividir
    // se o inicio for igual ao fim, ent esta ordenado
    if (indice_inicio < indice_fim) {

        // formula para encontrar o meio sem dar overflow
        int indice_meio = indice_inicio + (indice_fim - indice_inicio) / 2;

        // chamada recursiva da primeira metade
        merge_sort(fila, indice_inicio, indice_meio);

        // chamada recursiva da segunda metade
        merge_sort(fila, indice_meio + 1, indice_fim);

        // juntar as duas partes ordenadas e intercalar
        merge(fila, indice_inicio, indice_meio, indice_fim);
    }
}
int main() {
    int n_pessoas;
    cin >> n_pessoas;

    int* fila = new int[n_pessoas];

    for (int i = 0; i < n_pessoas; i++) {
        cin >> fila[i];
    }

    // ordenação
    merge_sort(fila, 0, n_pessoas - 1);

    // contagem do tempo
    long long tempo_espera = 0;
    int felizes = 0;

    for (int i = 0; i < n_pessoas; i++) {
        if (tempo_espera <= fila[i]) {
            felizes++;
            tempo_espera += fila[i];
        }
        // se n está feliz não precisa contar o tempo, e como se fosse para o final da fila
    }
    cout << felizes << endl;
    return 0;
}