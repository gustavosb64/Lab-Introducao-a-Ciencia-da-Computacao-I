#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
    return;
}

//double Interseccao(p1,l1,p2,l2){
    
//}

int main(int argc, char *argv[]){
    int x1, y1, l1, h1;
    int x2, y2, l2, h2;

    scanf(" %d %d %d %d",&x1,&y1,&l1,&h1);
    scanf(" %d %d %d %d",&x2,&y2,&l2,&h2);

    /*intersectam se
     * x1+l1 >= x2 e y1+a1 >= y2
     * ou
     * x2+l2 >= x1 e y2+a2 >= y1
    */

    int menor_x, menor_l, menor_y, menor_h;
    int maior_x, maior_l, maior_y, maior_h;

    if (x1 < x2){
        menor_x = x1;
        menor_l = l1;
        maior_x = x2;
        maior_l = l2;
    }
    else{
        menor_x = x2;
        menor_l = l2;
        maior_x = x1;
        maior_l = l1;
    }
    if (y1 < y2){
        menor_y = y1;
        menor_h = h1;
        maior_y = y2;
        maior_h = h2;
    }
    else{
        menor_y = y2;
        menor_h = h2;
        maior_y = y1;
        maior_h = h1;
    }

    if ((menor_x+menor_l < maior_x) || (menor_y+menor_h) < maior_y){
        printf("MISS\n");
        return 0;
    }
/*
    int ix = 0, iy = 0, il = 0, ih = 0;
*/
    printf("HIT\n");
    return 0;
}
