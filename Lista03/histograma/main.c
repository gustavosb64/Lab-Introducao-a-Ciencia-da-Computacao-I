#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int *V = (int *) malloc(25 * sizeof(int));  
    int n[5]; //counter for each pixel

    for(int i=0; i<5; i++) n[i] = 0;

    int largest = 0; //stores the most used colour
    for(int i=0; i<25; i++){
        scanf(" %d",&V[i]);
        switch (V[i]){
            case 0:
                if (++n[0] >= n[largest]) largest = 0;
                break;
            case 1:
                if (++n[1] >= n[largest]) largest = 1;
                break;
            case 2:
                if (++n[2] >= n[largest]) largest = 2;
                break;
            case 3:
                if (++n[3] >= n[largest]) largest = 3;
                break;
            case 4:
                if (++n[4] >= n[largest]) largest = 4;
                break;
        }
    }

    //Print histogram
    for(int i=0; i<5; i++){
        printf("%d: |",i);
        for(int j=0; j<n[i]; j++){
            printf("#");
        }
        printf("\n");
    }

    //Print pixel index
    for(int i=0; i<25; i++){
        if (V[i] == largest) printf("%d\n",i);
    }

    return 0;
}
