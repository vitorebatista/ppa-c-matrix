#define N 10
#define M 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    mymatriz mat_a;

    if (!malocar(&mat_a))
    {
        printf("Error..\n");
    }

    mimprimir(&mat_a);
    mzerar(&mat_a);
    mimprimir(&mat_a);
    mgerar(&mat_a, -9999);
    mimprimir(&mat_a);
    mliberar(&mat_a);

    return 0;
}