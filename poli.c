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
    printf("%c(x) = ", p.nome);
    // Os casos n == 0 e n == 1 sao tratados a parte
    //   apenas para evitar escrever x^1 e x^0
    if (p.n == 0){
        printf("%.3f\n", p.c[0]);
        return; // dica: o return termina a funcao 
        // eh como se tudo daqui para baixo fosse um 'else'
    } 
    if (p.n == 1){
        printf("%.3f . x", p.c[1]);
        if (p.c[0] > TOL)
            printf(" + %.3f", p.c[0]);
        putchar('\n');
        return;
    }

    printf("%.3f . x^%d", p.c[p.n], p.n);
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

bool normalizado(struct pn p) {
    int i, grau;
    for(i = 0, grau = 0; i < MAX; i = i + 1) {
        if (p.c[i] < TOL)
            grau = i;
    }
    return p.n == grau;
}

void normalizar(struct pn p) {
    int i, grau;
    for(i = 0, grau = 0; i < MAX; i = i + 1) {
        if (p.c[i] < TOL)
            grau = i;
    }
    res.nome = p.nome;
    res.n = grau;
    for(i = 0; i < MAX; i = i + 1) 
        res.c[i] = p.c[i];
}

// somar

// derivar

// multiplicar por escalar (constante)

// multiplicar por x

// multiplicar 2 polinomios

int main() {
    struct pn q; q.nome = 'q'; q.n = 2;
    q.c[0] = 1.0; q.c[1] = 5.0; q.c[2] = 2.7;
    pprint(q);

    struct pn p1;
    p1.nome = 'k';
    p1.n = 1;
    p1.c[0] = 4.7;
    p1.c[1] = 0.575;
    pprint(p1);

    struct pn p2;
    p2.nome = 'w';
    p2.n = 2;
    p2.c[2] = 3.5;
    p2.c[1] = 0.5;
    p2.c[0] = 0.0;
    pprint(p2);

    struct pn p3;
    p3.nome = 'z';
    p3.n = 0;
    p3.c[0] = 0.0;
    pprint(p3);
}