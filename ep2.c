/***************************************************************/
/**   Luis H C Cavada                                         **/
/**   Exercício-Programa 2                                    **/                             
/***************************************************************/


#include <stdio.h>
#include <math.h>


void read_data(double *x0, double *x1, double *x2, double *x3, double *v0, double *v1, double *v2, double *v3, double *m0, double *m1, double *m2, double *m3, double *T_max){

scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", x0, v0, m0, x1, v1, m1, x2, v2, m2, x3, v3, m3, T_max);

}

double t(double x, double xx, double v, double vv){
    double d;
    d = xx - x - 0.1;
if(vv < 0 && v > 0){
if(vv < v)
    return d/(v - vv);
    else
    return HUGE_VAL;
}


if(v < 0 && vv < 0){
if(v < vv)
return HUGE_VAL;
if(vv < v)
return d/(v - vv);
if(v == vv)
return HUGE_VAL;
}

if(v > 0 && vv > 0){
if(v < vv)
return HUGE_VAL;
if(vv < v)
return d/(v - vv);
if(v == vv)
return HUGE_VAL;
}


if(v < 0 && vv > 0)
    return HUGE_VAL;
    
if(v == 0 && vv == 0)
return HUGE_VAL;
if(v == 0 && vv < 0)
return d/(-vv);
if(v == 0 && vv > 0)
return HUGE_VAL;
if(vv == 0 && v > 0)
return d/v;
if(vv == 0 && v < 0)
return HUGE_VAL;
    return 501;
}


double min(double a, double b, double c, int *i){
if((a<b && a<c)){
*i = 1;
return a;
}

if((b<a && b<c)){
*i = 2;
return b;
}

if(c<a && c<b){
*i = 3;
return c;
}
if(a == b){
*i = 1;
return a;
}
if(a==c){
*i = 1;
return a;
}
if(b == c){
*i=2;


}


return 500;

}

double adv(double *x, double v, double t){
*x = (*x) + (v*t);

if(v>0)
return v*t;
else
return -(v*t);
}

void resolve(double *v, double *vv, double m, double mm){
double A;
A = (2*(m*(*v) + mm*(*vv))/(m + mm));
*v = A - *v;
*vv = A - *vv;
}


void print_data(long c1, long c2, long c3,double x0, double x1, double x2, double x3,double v0, double v1, double v2, double v3,double d0, double d1, double d2, double d3){
long soma, s;
soma = c1 + c2 +c3;
s = c2+ c3;
printf("Numero de colisoes por bloco: %ld %ld %ld\n", c1, c2, c3);
printf("Numero total de colisoes: %ld\n", soma);
printf("Colisoes dos dois blocos a direita: %ld\n", s);

if(x0 >= 0 && x0 < 10)
printf("x0 =  %f  ", x0);
else
printf("x0 = %f  ", x0);

if(v0 >= 0 && v0 < 10)
printf("v0 =  %f  ", v0);
else
printf("v0 = %f  ", v0);

if(d0 >= 0 && d0 < 10)
printf("d0 =  %f\n", d0);
else
printf("d0 = %f\n", d0);

if(x1 >= 0 && x1 < 10)
printf("x1 =  %f  ", x1); 
else
printf("x1 = %f  ", x1);

if(v1 >= 0 && v1 < 10)
printf("v1 =  %f  ", v1);
else
printf("v1 = %f  ", v1);

if(d1>= 0 && d1 < 10)
printf("d1 =  %f\n", d1);
else
printf("d1 = %f\n", d1);

if(x2 >= 0 && x2 < 10)
printf("x2 =  %f  ", x2);
else
printf("x2 = %f  ", x2);

if(v2 >= 0 && v2 < 10)
printf("v2 =  %f  ", v2);
else
printf("v2 = %f  ", v2);

if(d2 >= 0 && d2 < 10)
printf("d2 =  %f\n", d2);
else
printf("d2 = %f\n", d2);

if(x3 >= 0 && x3 < 10)
printf("x3 =  %f  ", x3);
else
printf("x3 = %f  ", x3);

if(v3 >= 0 && v3 < 10)
printf("v3 =  %f  ", v3);
else
printf("v3 = %f  ", v3);

if(d3 >= 0 && d3 < 10)
printf("d3 =  %f\n", d3);
else
printf("d3 = %f\n", d3);
if(t(x0, x1, v0, v1) == HUGE_VAL && t(x1, x2, v1, v2) == HUGE_VAL && t(x2, x3, v2, v3) == HUGE_VAL)
printf("Nao ha mais colisoes\n");
else
printf("Ha colisoes remanescentes\n");
}


int main(){
double x0, v0, m0, x1, v1, m1, x2, v2, m2, x3, v3, m3, T_max, Tempo, ta, tb, tc, tr=0, d0=0, d1=0, d2=0, d3=0;
long c1=0, c2=0, c3=0;
int i;
read_data(&x0, &x1, &x2, &x3, &v0, &v1, &v2, &v3, &m0, &m1, &m2, &m3, &T_max);
Tempo = 0.0;
while(Tempo < T_max){
ta = t(x0, x1, v0, v1);
tb = t(x1, x2, v1, v2);
tc = t(x2, x3, v2, v3);

if(Tempo + min(ta, tb, tc, &i) < T_max)
tr = min(ta, tb, tc, &i);
else{
tr = T_max - Tempo;
i=0;}

d0 = d0 + adv(&x0, v0, tr);
d1 = d1 + adv(&x1, v1, tr);
d2 = d2 + adv(&x2, v2, tr);
d3 = d3 + adv(&x3, v3, tr);
if(i == 1){
resolve(&v0, &v1, m0, m1);
c1++;
}
if(i == 2){
resolve(&v1, &v2, m1, m2);
c2++;

}

if(i == 3){
resolve(&v2, &v3, m2, m3);

c3++;

}


Tempo = Tempo + tr;

}
print_data(c1, c2, c3, x0, x1, x2, x3, v0, v1, v2, v3, d0, d1, d2, d3);

return 0;


}
