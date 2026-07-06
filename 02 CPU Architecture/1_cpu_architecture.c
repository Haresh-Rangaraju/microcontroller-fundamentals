#include<stdio.h>
int main(){
    int sensor_value=50;
    int threshold=40;
    if(sensor_value>threshold){
        printf("True\n");
    }

    int a=5;
    int b=10;
    int c=a+b;
    printf("Sum=%d\n",c);

    return 0;
}
