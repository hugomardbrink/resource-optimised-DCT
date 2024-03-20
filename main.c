#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define DCT_SIZE 8
#define TOTAL_DCT_BLOCKS 100

#define PI 3.14159265358979323846

#define element_t int16_t
#define real_t double

void dct_2d(element_t** matrix_in, element_t** matrix_out) {
    real_t cu, cv, sum;
    int u, v, i, j;

    for (u = 0; u < DCT_SIZE; u++) {
        for (v = 0; v < DCT_SIZE; v++) {
            cu = u == 0 ? 1 / sqrt(DCT_SIZE) : sqrt(2) / sqrt(DCT_SIZE);
            cv = v == 0 ? 1 / sqrt(DCT_SIZE) : sqrt(2) / sqrt(DCT_SIZE); 

            sum = 0;
            for (i = 0; i < DCT_SIZE; i++) {
                for (j = 0; j < DCT_SIZE; j++) {
                    sum += matrix_in[i][j] * cos((2 * i + 1) * u * PI / (2 * DCT_SIZE)) * cos((2 * j + 1) * v * PI / (2 * DCT_SIZE));
                }
            }
            matrix_out[u][v] = cu * cv * sum;
        }
    }
}


void populate_mock_matrices(element_t*** mock_matrices) {
    for (long i = 0; i < TOTAL_DCT_BLOCKS; i++) {
        for (int j = 0; j < DCT_SIZE; j++) {
            for (int k = 0; k < DCT_SIZE; k++) {
                mock_matrices[i][j][k] = j + k;
            }
        }
    }
}


element_t*** generate_mock_matrices() {
    element_t ***mock_matrices = (element_t ***) malloc(TOTAL_DCT_BLOCKS * sizeof(element_t**));
    for (int i = 0; i < TOTAL_DCT_BLOCKS; i++) {
        mock_matrices[i] = (element_t **) malloc(DCT_SIZE * sizeof(element_t*));
        for (int j = 0; j < DCT_SIZE; j++) {
            mock_matrices[i][j] = (element_t *) malloc(DCT_SIZE * sizeof(element_t));              
        }
    }

    populate_mock_matrices(mock_matrices);

    return mock_matrices;
}

void free_mock_matrices(element_t*** mock_matrices, element_t** matrix_out) {
    for (int i = 0; i < TOTAL_DCT_BLOCKS; i++) {
        for (int j = 0; j < DCT_SIZE; j++) {
            free(mock_matrices[i][j]);
        }
        free(mock_matrices[i]);
    }
    free(mock_matrices);

}

int main() {
    element_t ***mock_matrices = generate_mock_matrices();

    element_t** matrix_out = (element_t **) malloc(DCT_SIZE * sizeof(element_t*));
    for (int i = 0; i < DCT_SIZE; i++) {
        matrix_out[i] = (element_t *) malloc(DCT_SIZE * sizeof(element_t));
    }

    for(long i = 0; i < TOTAL_DCT_BLOCKS; i++) {
        dct_2d(mock_matrices[i], matrix_out);
    }

    free_mock_matrices(mock_matrices, matrix_out);

    for (int i = 0; i < DCT_SIZE; i++) {
        free(matrix_out[i]);
    }
    free(matrix_out);

    return 0;
}
