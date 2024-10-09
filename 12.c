#include <stdio.h>
#include <omp.h>

void fibonacci(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    #pragma omp parallel shared(fib) private(n)
    {
        #pragma omp for
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }

    printf("Serie de Fibonacci hasta el término %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Ingrese el número de términos para la serie de Fibonacci: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
