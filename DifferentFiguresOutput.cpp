#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int arifm_progr(int n);
int min_line_size_rombus(int n, int k);
int arifm_rombus(int n, int k, int *counts_rombus);
int special_arifm_rombus(int k);
int arifm_circle(size_t i_y, size_t i_x, int *counts);
// int dist(double xc, double yc, double x1, double y1, double r);
// int circle_positions_counter(size_t size, int *counts);
int count_rombus(size_t size, int *counts);
int *return_address_square(int *data, size_t sizeX, size_t i_y, size_t i_x);
int find_max1(int *data, size_t size);
void output_data_square(int *data, size_t sizeY, size_t sizeX);
void output_data_triangle(int *data, int n);
void output_data_rombus(int *data, int n, int k, int *counts_rombus);
void output_data_circle(int *ptr, int n, int *counts);
int find_min_rombus(int n, int k);
int find_address_rombus(int n, int k, size_t i_y, size_t i_x, int *count_rombus);


int arifm_progr(int n) {
    return n * (n + 1) / 2;
}

int find_min_rombus(int n, int k) {
    int line_size = 0;
    if (n <= k){
        line_size = min_line_size_rombus(n, k);

    } else {
        line_size = special_arifm_rombus(k);
    }
    return line_size;
}

int min_line_size_rombus(int n, int k) {
    int line_size = k - ((n-1) / 2) * 2;

    return line_size;
}

int special_arifm_rombus(int k) {
    int line_size = 2 - k % 2;
    return line_size;
}

int arifm_rombus(int n, int k, int *counts_rombus) {
    int line_size = find_min_rombus(n, k);

    int ans = 0;
    size_t i = 0;
    while (i < n) {
        if (line_size == k && n > k) {
            size_t j = i + ((n + 1) / 2 - i) * 2;
            while (i < j) {
                counts_rombus[i] = line_size;
                ans += line_size;
                i++;
            }
            line_size -= 2;
        } 

        counts_rombus[i] = line_size;

        ans += line_size;
        line_size = (i <= (n / 2 - 1)) ? (line_size + 2) : (line_size - 2);
        if (n % 2 == 0 && i == n / 2 - 1) {
            line_size -= 2;
        }

        i++;
    }
    return ans;
}

int find_address_rombus(int n, int k, size_t i_y, size_t i_x, int *count_rombus) {
    int ans = 0;
    for (size_t y = 0; y < i_y; y++) {
        ans += count_rombus[y];
    }
    return ans + i_x;
}

int arifm_circle(size_t i_y, size_t i_x, int *counts) {
    assert(counts != NULL);

    int counter = 0;
    for (size_t i = 0; i < i_y; i++) {
        counter += counts[i];
    }

    return counter + i_x;
}

// int dist(double xc, double yc, double x1, double y1, double r) {
//     return ((xc - x1) * (xc - x1) + (yc - y1) * (yc - y1) <= r * r);
// }

// int circle_positions_counter(size_t size, int *counts) {
//     assert(counts != NULL);

//     int count = 0;
//     double yc = size / 2.0;
//     double xc = yc;
//     if (size % 2 == 0) {
//         yc -= 0.5; 
//         xc -= 0.5;
//     }

//     for (size_t i = 0; i < size; i++) {
//         int counter = 0;
//         for (size_t j = 0; j < size; j++) {
//             if (dist(xc, yc, i, j, size / 2.0)) {
//                 counter++;
//             }
//         }
//         counts[i] = i;
//         counts[i] = counter;
//         count += counter;
//     }

//     return count;
// }

int count_rombus(size_t size, int *counts) {
    assert(counts != NULL);

    int count = 0, counter = 0;
    double yc = size / 2.0;
    double xc = yc;
    if (size % 2 != 0) {
        yc -= 0.5; 
        xc -= 0.5;
    }

    for (size_t i = 0; i < size; i++) {

        double sqr = sqrt(size/2 * size/2 - (i - yc) * (i - yc));
        int x2 = (ceil)(xc + sqr);
        int x1 = (floor)(xc - sqr);
        count = (x2 - x1 + 1);
        printf("%d %d %d\n", x2, x1, count);
        counts[i] = count;
        counter += count;
    }

    return counter;
}

//-------------------------------------------------------------------
int *return_address_square(int *data, size_t sizeX, size_t i_y, size_t i_x) {
    assert(data != NULL);

    return (data + i_y * sizeX + i_x);
}

int *return_address_triangle(int *data, int i_y, int i_x) {
    assert(data != NULL);

    return (data + arifm_progr(i_y) + i_x);
}

int *return_address_rombus(int *data, int i_y, int i_x, int n, int k, int *counts_rombus) {
    assert(data != NULL);

    return (data + find_address_rombus(n, k, i_y, i_x, counts_rombus));
}

int *return_address_circle(int *ptr, int i_y, int i_x, int counts[]) {
    assert(ptr != NULL);

    return (ptr + arifm_circle(i_y, i_x, counts));
}

//-------------------------------------------------------------------
int find_max1(int *data, size_t size) {
    assert(data != NULL);
    
    int maxi = -1000;
    for (size_t y = 0; y < size; y++) {
        maxi = (maxi <= data[y]) ? data[y] : maxi;
    }
    return maxi;
}

// int find_max2(int data[][3], size_t sizeY) {
//     int maxi = -1000;
//     for (size_t y = 0; y < sizeY; y++) {
//         for (size_t x = 0; x < 3; x++) {
//             maxi = (maxi <= data[y][x]) ? data[y][x] : maxi;
//         }
//     }
//     return maxi;
// }

//-------------------------------------------------------------------
void output_data_square(int *data, size_t sizeY, size_t sizeX) {
    assert(data != NULL);

    for (size_t y = 0; y < sizeY; y++) {
        for (size_t x = 0; x < sizeX; x++) {
            printf("[%lu][%lu] = %d, ", y, x, *return_address_square(data, sizeX, y, x));
        }
        printf("\n");
    }
}

void output_data_triangle(int *data, int n) {
    assert(data != NULL);

    int counter = n;
    int line_size = 1;
    for (size_t y = 0; y < counter; y++) {
        for (size_t x = 0; x < line_size; x++) {
            printf("[%lu][%lu] = %d, ", y, x, *return_address_triangle(data, y, x));
        }
        line_size++;
        printf("\n");
    }
}

void output_data_rombus(int *data, int n, int k, int *counts_rombus) {
    assert(data != NULL);
    assert(counts_rombus != NULL);

    for (size_t y = 0; y < n; y++) {
        for (size_t x = 0; x < counts_rombus[y]; x++) {
            printf("[%lu][%lu] = %d, ", y, x, *return_address_rombus(data, y, x, n, find_min_rombus(n, k) - 1, counts_rombus));
        }
        printf("\n");
    }
}

void output_data_circle(int *ptr, int n, int *counts) {
    assert(ptr != NULL);
    assert(counts != NULL);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < counts[i]; j++) {
            printf("[%lu][%lu] = %d, ", i, j, *return_address_circle(ptr, i, j, counts));
        }
        printf("\n");
    }
}

//-------------------------------------------------------------------
int main(void) {
    int number = 0;
    int n = 0, m = 0;
    int k = 0;

    printf("Введите размеры прямоугольного массива (2 параметра): \n");
    scanf("%d %d", &n, &m);

    int *data_square = (int *) calloc (n * m + 1, sizeof(int));

    printf("Введите %d чисел: \n", n * m);
    for (int i = 0; i < n * m; i++) {
        scanf("%d", &number);
        data_square[i] = number;
    }    

    output_data_square(data_square, n, m);
    printf("%d\n\n", find_max1(data_square, n * m));
    free(data_square);


    //--------------
    printf("Введите длину лесенки (1 параметр):\n"); //1
    scanf("%d", &n);

    int size_d = n * (n + 1) / 2;
    int * data_triangle = (int *)calloc(size_d + 1, sizeof(int));

    printf("Введите %d элементов массива лесенки: \n", size_d);
    for (size_t i = 0; i < size_d; i++) {
        scanf("%d", &number);
        data_triangle[i] = number;
    }

    output_data_triangle(data_triangle, n);
    printf("%d\n", find_max1(data_triangle, size_d));
    free(data_triangle);

    //--------------
    printf("Введите количество строк и столбцов ромбового массива: \n");
    scanf("%d %d", &n, &m);

    int counts_rombus[n];
    int size_r = arifm_rombus(n, m, counts_rombus);
    int *data_rombus1 = (int *) calloc(size_r + 1, sizeof(int));

    printf("Введите %d чисел: \n", size_r);
    for (int i = 0; i < size_r; i++) {
        scanf("%d", &number);
        data_rombus1[i] = number;
    }

    output_data_rombus(data_rombus1, n, m, counts_rombus);
    printf("\n");
    free(data_rombus1);

    // int data_rombus2 [12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // output_data_rombus(data_rombus2, 4, 4);
    // printf("\n");

    // int data_rombus3 [23] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    // output_data_rombus(data_rombus3, 5, 7);
    // printf("\n");

    //--------------------------
    printf("Введите размер круговой матрицы:\n");
    scanf("%d", &k);
    int counts[k];
    int l = count_rombus(k, counts);
    int *data_circle = (int *)calloc(l + 1, sizeof(int));

    printf("Введите чисел %d:\n", l);

    for (size_t j = 0; j < l; j++) {
        scanf("%d", &number);
        data_circle[j] = number;
    }

    output_data_circle(data_circle, k, counts);
    free(data_circle);
    printf("\n");

}

// int *ptr = &mas[0][0];
// int size = 2 * 3;
// for (int k = 0; k < size; k++) {
//     printf("%d ", ptr[k]);
// }