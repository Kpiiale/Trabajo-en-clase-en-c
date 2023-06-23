#include <stdio.h>
#include <math.h>

float calcularDistancias(float x1, float y1, float x2, float y2, float z1, float z2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
}

float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f){
    *a = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2]);
    *b = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    *c = calcularDistancias(puntos[2][0],puntos[2][1],puntos[2][2],puntos[1][0],puntos[1][1],puntos[1][2]);
    *d = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    *e = calcularDistancias(puntos[1][0],puntos[1][1],puntos[1][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    *f = calcularDistancias(puntos[2][0],puntos[2][1],puntos[2][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float p=*a+*b+*c+*d+*e+*f;
    return p;
}
float calcularArea(float lado1, float lado2, float lado3){
    float perimetro=lado1+lado2+lado3;
    float s=perimetro/2;
    float area=sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
    return area;
}
void calcularAreaSup(float *a, float *b, float *c, float *d, float *e, float *f, float *areaSup, float *area1){
    *area1=calcularArea(*a,*b,*c);
    float area2=calcularArea(*a,*d,*e);
    float area3=calcularArea(*c,*e,*f);
    float area4=calcularArea(*b,*d,*f);
    *areaSup=*area1+area2+area3+area4;
}
void baricentro(float puntos[4][3],float *gx,float *gy, float *gz){
    *gx=(puntos[0][0]+puntos[1][0]+puntos[2][0])/3;
    *gy=(puntos[0][1]+puntos[1][1]+puntos[2][1])/3;
    *gz=(puntos[0][2]+puntos[1][2]+puntos[2][2])/3;
}
void Cvolumen(float puntos[4][3], float area1,float gx,float gy,float gz, float *volumen){
    float altura=calcularDistancias(gx,gy,gz,puntos[3][0],puntos[3][1],puntos[3][2]);
    *volumen=altura*area1/3; 
}

int main(int argc, char *argv[])
{

    float puntos[4][3]={{0,0,0},{3,0,0},{0,0,3},{1,7,1}}; 
    float a, b, c, d, e, f,areaSup, gx, gy, gz, volumen, area1; 
   
    float perimetro = calcularPerimetro(puntos,&a,&b,&c, &d, &e, &f);
    printf("El perimetro del triangulo es %.2f\n", perimetro);
    calcularAreaSup(&a,&b,&c,&d,&e,&f,&area1, &areaSup);
    printf("El area superficial es %.2f\n", areaSup);
    Cvolumen(puntos,area1,gx,gy,gz,&volumen); 
    printf("El volumen es %.2f\n", volumen);


    return 0;
}

