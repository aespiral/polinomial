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

/*
 * Melhorias possiveis no Pretty Print:
 * - Em vez de mostrar 2.000, 3.000, etc., mostrar 2 , 3 , etc.
 * - Em vez de mostrar 1.000 . x^algo (ou 1 . x^algo), mostrar x^algo
 */
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
    return p.c[p.n] > TOL;
}

void normalizar(struct pn p) {
    int i = p.n; 
    while(p.c[i] < TOL) 
        i = i - 1;
    res.nome = p.nome;
    res.n = i;
    for(i = 0; i <= res.n; i = i + 1) 
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

    // Exemplo de polinomio normalizado
    puts("--------");
    pprint(p1);
    if (normalizado(p1))
        printf("O polinomio %c estah normalizado.\n", p1.nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p1.nome);

    // Exemplo de polinomio nao normalizado
    puts("--------");
    struct pn p4;
    p4.nome = 's';
    p4.n = 4;
    p4.c[4] = 0.0;
    p4.c[3] = 0.0;
    p4.c[2] = 1.0;
    p4.c[1] = 7.5;
    p4.c[0] = 4.0;
    pprint(p4);
    if (normalizado(p4))
        printf("O polinomio %c estah normalizado.\n", p4.nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p4.nome);

    // Normalizando
    puts("--------");
    normalizar(p4);
    struct pn p5;
    p5.nome = res.nome;
    p5.n = res.n;
    int i;
    for(i = 0; i <= res.n; i = i + 1) 
        p5.c[i] = res.c[i];
    pprint(p5);
    if (normalizado(p5))
        printf("O polinomio %c estah normalizado.\n", p5.nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p5.nome);
}