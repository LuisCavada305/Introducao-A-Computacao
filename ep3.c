/***************************************************************/
/**   Luis H C Cavada                                         **/
/**   Exercício-Programa 3                                    **/
/***************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PIXELS 1000000
#define rand2166() (rand2166f(-1))
#define srand2166(seed) (rand2166f((seed)))
#define AA 16807
#define MM 2147483647

void output_image(int col, int row, int v_max, int image[]);

void read_image(int *col, int *row, int *v_max, int image[]);

void encode(int col, int row, int v_max, int image[], int key);

void decode(int col, int row, int v_max, int image[], int key, int decoded[]);

void decode_in_loco(int col, int row, int v_max, int image[], int key);

void decode_brute_force(int col, int row, int v_max, int image[], int max_key);

double entropy(int v_max, int N, int image[]);

int rand2166f(int seed);


int main(int argc, char *argv[]) {
int col, row, v_max;
int image[MAX_PIXELS];
int key = atoi(argv[2]);
int opcao = atoi(argv[1]);

read_image(&col, &row, &v_max, image);

if(opcao == 0){
encode(col, row, v_max, image, key);
output_image(col, row, v_max, image);
return 0;
}

if(opcao == 1){
decode_in_loco(col, row, v_max, image, key);
output_image(col, row, v_max, image);

return 0;
}

if(opcao == 2){
decode_brute_force(col, row, v_max, image, key);
output_image(col, row, v_max, image);
return 0;
}
return 0;
}

void output_image(int col, int row, int v_max, int image[]){
    int i, j, n=0;
    printf("P2\n");
    printf("%d %d\n", col, row);
    printf("%d\n", v_max);
    for(i=0; i < row; i++){
        for(j=0; j < col; j++){
            printf("%03d ", image[n++]);
        }
        printf("\n");
    }
}

void read_image(int *col, int *row, int *v_max, int image[]){
    char P;
    int dois, cont;
        scanf("%c", &P);
        scanf("%d", &dois);
        scanf("%d", col);
        scanf("%d", row);
        scanf("%d", v_max);
        for(cont=0; cont < (*col) * (*row); cont++){
            scanf("%d", &image[cont]);
            
}
}

void encode(int col, int row, int v_max, int image[], int key){
int i, j, cont = 0;
srand2166(key);
for(i=0; i < row; i++){
    for(j=0; j < col; j++){
        image[cont] =  (image[cont] + (rand2166() % (v_max+1))) % (v_max+1);
            cont++;
    }
}
}
void decode(int col, int row, int v_max, int image[], int key, int decoded[]){
int i, j, cont=0;
srand2166(key);
for(i=0; i < row; i++){
    for(j=0; j < col; j++){
        decoded[cont] = (image[cont] - (rand2166() % (v_max + 1)) + (v_max + 1)) % (v_max + 1);
            cont++;
    }
}
}

void decode_in_loco(int col, int row, int v_max, int image[], int key){
int i, j, cont=0;
srand2166(key);
for(i=0; i < row; i++){
    for(j=0; j < col; j++){
        image[cont] = (image[cont] - (rand2166() % (v_max + 1)) + (v_max + 1)) % (v_max + 1);
            cont++;
    }
}
}

void decode_brute_force(int col, int row, int v_max, int image[], int max_key){
int key=0, keymin;
double H, Hmin;
int decoded[MAX_PIXELS];
Hmin = entropy(v_max, col * row, image);
keymin = 0;
for(key = 1; key <= max_key; key++){
decode(col, row, v_max, image, key, decoded);
H = entropy(v_max, col * row, decoded);
if(H < Hmin){
Hmin = H;
keymin = key;
}
}
decode_in_loco(col, row, v_max, image, keymin);
}

double entropy(int v_max, int N, int image[]){
int cont=0, f[256];
double  H=0, p;
for(cont=0; cont <= v_max; cont++)
    f[cont] = 0;


for(cont=0; cont < N; cont++)
    f[image[cont]]++;

 for(cont=0; cont <= v_max; cont++){
  if(f[cont] != 0){
    p = f[cont]/ (double)N;
    H += p * (-log(p));
    }
}
return H;
}

int rand2166f(int seed) {
static long r;
if (seed >= 0) {
r = seed;
return 0;
}
r = (r * AA) % MM;
return r;
}
