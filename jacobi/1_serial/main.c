#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define n_cells 2048

double T[n_cells+2][n_cells+2];
double T_new[n_cells+2][n_cells+2];

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

// smallest permitted change in temperature
double MAX_RESIDUAL = 1.e-5;

int main(int argc, char *argv[]) {

    unsigned int max_iterations = 1000; // maximum number of iterations
    printf("------------------------------------------\n");
    printf("Using number of cells = %u\n", n_cells);
    printf("Using maximum iteration count = %u\n", max_iterations);
    printf("------------------------------------------\n");

    for (unsigned i = 0; i <= n_cells + 1; i++) {
        for (unsigned j = 0; j <= n_cells + 1; j++) {
            T[i][j] = (double)rand() / (double)RAND_MAX;
        }
    }

    // Timer variables
    struct timeval start, end, elapsed;

    // Time jacobi execution
    gettimeofday(&start, NULL);

    int iteration = 0;
    double residual = 1.e5;

    // simulation iterations
    while (residual > MAX_RESIDUAL && iteration <= max_iterations) {

        // main computational kernel, average over neighbours in the grid
        for (unsigned i = 1; i <= n_cells; i++){
            for (unsigned j = 1; j <= n_cells; j++){
                T_new[i][j] =
                    0.25 * (T[i + 1][j] + T[i - 1][j] + T[i][j + 1] + T[i][j - 1]);
            }
        }

        // reset residual
        residual = 0.0;

        // compute the largest change and copy T_new to T
        for (unsigned int i = 1; i <= n_cells; i++) {
            for (unsigned int j = 1; j <= n_cells; j++) {
                residual = MAX(fabs(T_new[i][j] - T[i][j]), residual);
                T[i][j] = T_new[i][j];
            }
        }
        iteration++;

        if(iteration % 100 == 0){
            printf("Iteration: %d, Residual %.9lf\n", iteration, residual);
        }

    }

    gettimeofday(&end, NULL);
    timersub(&end, &start, &elapsed);

    printf("------------------------------------------\n");
    printf("Jacobi time (s) = %.6f \n", elapsed.tv_sec+elapsed.tv_usec/1000000.0);
    printf("------------------------------------------\n");

    return 0;
}
