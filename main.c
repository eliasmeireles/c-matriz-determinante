#include <stdio.h>

// Para cada posição da matriz, solicita a entrada do valor para a posição atual na matriz.
void carregarMatriz(int ordemMatriz, double matrix[ordemMatriz][ordemMatriz]);

// Imprime os valores da matriz
void imprimirMatriz(char *label, int linhas, int colunas, double matriz[linhas][colunas]);

// Para cada elemento da matriz espelhada, percorre e obtem os valores.
double calcularDeterminante(int linhas, int colunas, double matriz[linhas][colunas]);

// Percorre a matriz espelhada, aplicando a regra Sarrus para calcular as determinates.
// Se for uma matriz de ordem 2 ou superior, então calcula sua determinante, caso contrário, retorna seu unico elemento
double calcularMatrizDeterminante(int ordemMatriz, double matriz[ordemMatriz][ordemMatriz]);

int main() {
    double determinante;
    int ordemMatriz;

    printf("Informe a ordem da matriz: ");
    scanf("%d", &ordemMatriz);

    double matrizDeterminante[ordemMatriz][ordemMatriz];

    carregarMatriz(ordemMatriz, matrizDeterminante);

    imprimirMatriz("Valores informados para matriz", ordemMatriz, ordemMatriz, matrizDeterminante);

    determinante = calcularMatrizDeterminante(ordemMatriz, matrizDeterminante);

    printf("\nDeterminante: %.2f\n", determinante);
    return 0;
}

void carregarMatriz(int ordemMatriz, double matrizDeterminante[ordemMatriz][ordemMatriz]) {
    for (int i = 0; i < ordemMatriz; ++i) {
        for (int j = 0; j < ordemMatriz; ++j) {
            printf("Informe o valor para [%d] e [%d]: ", i, j);
            scanf("%lf", &matrizDeterminante[i][j]);
            printf("\n");
        }
    }
}

void imprimirMatriz(char *label, int linhas, int colunas, double matriz[linhas][colunas]) {
    printf("\n---------  ");
    printf("%s", label);
    printf(" ---------\n");

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

double calcularDeterminante(int linhas, int colunas, double matriz[linhas][colunas]) {
    double determinanteA = 0;
    double determinanteB = 0;

    for (int i = 0; i < linhas; ++i) {
        int ultimaPosicao = colunas - (i + 1);

        double calculaA = 1;
        double calculaB = 1;

        for (int j = 0; j < linhas; ++j) {
            calculaA *= matriz[j][j + i];
            calculaB *= matriz[j][ultimaPosicao];
            ultimaPosicao--;
        }

        determinanteA += calculaA;
        determinanteB += calculaB;
    }
    return determinanteA - determinanteB;
}

double calcularMatrizDeterminante(int ordemMatriz, double matriz[ordemMatriz][ordemMatriz]) {
    if (ordemMatriz >= 2) {
        if (ordemMatriz == 2) {
            return calcularDeterminante(ordemMatriz, ordemMatriz, matriz);
        } else {
            int totalColunas = ordemMatriz * 2 - 1;
            double matrizEpelhada[ordemMatriz][totalColunas];

            for (int i = 0; i < ordemMatriz; ++i) {
                for (int j = 0; j < ordemMatriz; ++j) {
                    matrizEpelhada[i][j] = matriz[i][j];
                    matrizEpelhada[i][j + ordemMatriz] = matriz[i][j];
                }
            }

            imprimirMatriz("Matriz Espelhada", ordemMatriz, totalColunas, matrizEpelhada);
            return calcularDeterminante(ordemMatriz, totalColunas, matrizEpelhada);
        }
    } else {
        return matriz[0][0];
    }
}