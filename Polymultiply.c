#include <stdio.h>

#define MAX_TERMS 101

struct term {
    float coef;
    int expon;
};

struct term terms[MAX_TERMS] = {
    {4.0, 3}, {3.0, 2}, {2.0, 1}, {1.0, 0},
    {3.0, 2}, {2.0, 1}, {8.0, 0}
};

int avail1 = 7;

int As1 = 0, Ae1 = 3, Bs1 = 4, Be1 = 6, Cs1, Ce1;

struct term terms2[MAX_TERMS] = {
    {7.0, 6}, {5.0, 3}, {9.0, 2}, {1.0, 0},
    {5.0, 3}, {2.0, 2}, {10.0, 0}
};
int avail2 = 8;

int As2 = 0, Ae2 = 3, Bs2 = 4, Be2 = 7, Cs2, Ce2;

void poly_multiply(struct term* terms1, int As, int Ae, struct term* terms2, int Bs, int Be, struct term* result_terms, int* avail) {
    int avail_result = 0;

    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            int exp = terms1[i].expon + terms2[j].expon;
            float coef = terms1[i].coef * terms2[j].coef;
            result_terms[avail_result].coef = coef;
            result_terms[avail_result].expon = exp;
            avail_result++;
        }
    }

    *avail = avail_result;
}

void print_poly(struct term* terms, int avail) {
    for (int i = 0; i < avail - 1; i++) {
        printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%.1fx^%d\n", terms[avail - 1].coef, terms[avail - 1].expon);
}

int main() {
    struct term result_terms[MAX_TERMS];

    poly_multiply(terms, As1, Ae1, terms, Bs1, Be1, result_terms, &avail1);

    print_poly(terms, avail1);
    print_poly(terms, avail1);
    printf("------------------------\n");
    print_poly(result_terms, avail1);

    printf("\n");

    poly_multiply(terms2, As2, Ae2, terms2, Bs2, Be2, result_terms, &avail2);

    print_poly(terms2, avail2);
    print_poly(terms2, avail2);
    printf("------------------------\n");
    print_poly(result_terms, avail2);

    return 0;
}

