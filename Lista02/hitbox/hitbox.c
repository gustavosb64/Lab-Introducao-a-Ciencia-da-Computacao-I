#include<stdio.h>
#include<stdlib.h>

/*returns the intersection length*/
int compare_edge(int smaller_e, long long int smaller_l, int bigger_e, long long int bigger_l){

    if (smaller_e + smaller_l >= bigger_e){
        if ( (smaller_e + smaller_l) > (bigger_e + bigger_l) ){
            return bigger_l;
        }
        return (smaller_e+smaller_l - bigger_e);
    }

    return -1;
}

int main(int argc, char *argv[]){
    int x1, y1;
    long long int l1, h1;
    int x2, y2;
    long long int l2, h2;

    scanf(" %d %d %lld %lld",&x1,&y1,&l1,&h1);
    scanf(" %d %d %lld %lld",&x2,&y2,&l2,&h2);

    /*Comparing x1 to x2*/
    int smaller_x;
    long long int smaller_l;
    int bigger_x;
    long long int bigger_l;
    if (x1 <= x2){
        smaller_x = x1;
        smaller_l = l1;

        bigger_x = x2;
        bigger_l = l2;
    }
    else{
        smaller_x = x2;
        smaller_l = l2;

        bigger_x = x1;
        bigger_l = l1;
    }

    /*Comparing y1 to y2*/
    int smaller_y; 
    long long int smaller_h;
    int bigger_y;
    long long int bigger_h;
    if (y1 <= y2){
        smaller_y = y1;
        smaller_h = h1;

        bigger_y = y2;
        bigger_h = h2;
    }
    else{
        smaller_y = y2;
        smaller_h = h2;

        bigger_y = y1;
        bigger_h = h1;
    }

    long long int intersec_x = compare_edge(smaller_x, smaller_l, bigger_x, bigger_l);
    long long int intersec_y = compare_edge(smaller_y, smaller_h, bigger_y, bigger_h);
    if (intersec_x == -1){
        printf("MISS\n");
        return 0;
    }
    else if (intersec_y == -1){
        printf("MISS\n");
        return 0;
    }

    printf("HIT: %d %d %lld %lld\n", bigger_x, bigger_y, intersec_x, intersec_y);
    return 0;
}
