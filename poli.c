#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 32
#define TOL 1.e-6

/*
 * Representação de polinomio
 * nome(x) = c_n . x^n + c_n-1 . x^(n-1) + ... + c_1 . x + c_0
 * - nome
 * - grau (n)
 * - coeficientes
 */
struct pn {
    char nome;
    int n;
    float c[MAX];
};

// retorno improvisado para funções que resultam em polinomio
struct pn res;

/*
 * Funções
 */

float avaliar(struct pn p, float a) {
    return 0.0; // TODO: calcular p(a)
}

float raiz(struct pn p) {
    return 0.0;
    // retorna uma raiz do polinomio; se houver 2 ou mais, retorna 1 qq
    // funciona para n == 1 e n == 2 (báskara)
}

void pprint(struct pn p) {
    printf("%c(x) = %.3f . x^%d", p.nome, p.c[p.n], p.n);
    int i;
    for(i=p.n-1; i >= 2; i = i - 1) {
        if (p.c[i] > TOL)
            printf(" + %.3f . x^%d", p.c[i],i);
    }
    if (p.c[1] > TOL)
        printf(" + %.3f . x", p.c[1]);
    if (p.c[0] > TOL)
        printf(" + %.3f", p.c[0]);
    putchar('\n');
}

int main() {
    struct pn q; q.nome = 'q'; q.n = 2;
    q.c[0] = 1.0; q.c[1] = 5.0; q.c[2] = 2.7;
    pprint(q);
}