#include <stdio.h>
#include <math.h>

int main() {

    FILE *f = fopen("/Users/bojanangjeleski/CLionProjects/untitled137/schema.txt", "w");

    int i, j, n;
    scanf("%d", &n);

    int N = (int) ceil(sqrt(n));
    printf("%d", N);
    int matrix[100][100];
    int currentNumber = 1;
    for (j = 0; j < N; j++) {
        if (j % 2 == 0) { // rastecki red
            for (i = 0; i < N; i++) {
                if (currentNumber > n) {
                    matrix[i][j] = 0;
                    continue;
                }
                matrix[i][j] = currentNumber;
                currentNumber++;
            }
        } else {
            for (i = N; i >= 0; i--) {
                if (currentNumber > n) {
                    matrix[i][j] = 0;
                    continue;
                }
                matrix[i][j] = currentNumber;
                currentNumber++;
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fprintf(f, "%d ", matrix[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}

/*
Од тастатура се чита природен број N (N < 400).

Да се напише програма којашто формира квадратна матрица што ги содржи броевите од 1 до N по растечки редослед на следниот начин: во прва колона во
правец од горе надолу, па продолжува во втора колона од долу нагоре, па продолжува во трета колона од горе надолу итн. да се избере најмалата димензија на
матрица во која ќе ги собере сите броеви до N. Доколкуу има преостанати празни места, тие да се пополнат со нули.

Формираната матрица да се запише во датотека "shema.txt".

Пример,
Влез
22

Излез во датотеката "shema.txt"
1 10 11 20 21
2 9 12 19 22
3 8 13 18 0
4 7 14 17 0
5 6 15 16 0

 * */