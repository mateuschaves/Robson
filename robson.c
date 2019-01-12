#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RIGHT "direita"
#define LEFT "esquerda"
#define TRUE 1
#define FALSE 0

void turnRight();
void turnLeft();
void walkToFront(int miles);
void walkToBack(int miles);
void setDistanceTotal(int miles);
void getDistanceTotal();
void setDistanceRight(int miles);
void getDistanceRight();
void setDistanceLeft(int miles);
void getDistanceLeft();
void setupRobson();
int checkRobson();
void wakeUpRobson();

typedef struct {

    char direction[20];
    int on;
    int distanceWalkedToRight;
    int distanceWalkedToLeft;
    int distanceTotalWalked;

} robsonStruct;

robsonStruct robson;

int main(void){

    turnRight();
    walkToFront(100);
    turnLeft();
    walkToFront(200);
    getMiles();

    system("pause");
    return 0;
}

void turnRight(){
    printf("Virando para a %s ! \n\n", RIGHT);
    strcpy(robson.direction, RIGHT);
}

void turnLeft(){
    printf("Virando para a %s ! \n\n", LEFT);
    strcpy(robson.direction, LEFT);
}

void walkToBack(int miles){
    printf("Voltando %d metros em direcao a %s!\n\n", miles, robson.direction);
    setMiles(miles);
}

void walkToFront(int miles){
    printf("Andando %d metros em direcao a %s! \n\n", miles, robson.direction);
    setMiles(miles);
}

void setDistanceTotal(int miles){
    robson.distanceTotalWalked = robson.distanceWalkedToLeft + robson.distanceWalkedToRight;
}

void getDistanceTotal(){
    printf("O Robson andou %d metros no total !\n\n", robson.distanceTotalWalked);
}

void setDistanceLeft(int miles){
    robson.distanceWalkedToLeft += miles;
}

void getDistanceLeft(){
    printf("O Robson andou %d metros para a %s !\n\n", LEFT);
}

void setDistanceRight(int miles){
    robson.distanceWalkedToRight += miles;
}

void getDistanceRight(){
    printf("O Robson andou %d metros para a %s ! \n\n", RIGHT);
}

void setupRobson(){
    robson.on = FALSE;
    robson.distanceTotalWalked = 0;
    robson.distanceWalkedToLeft = 0;
    robson.distanceWalkedToRight = 0;
}

int checkRobson(){
    if(robson.on != TRUE){
        printf("Silencioo, Robson esta dormindo agoraaa, lige ele para comecar a utilizar !\n\n");
        return FALSE;
    }else{
        return TRUE;
    }
}

void wakeUpRobson(){
    robson.on = TRUE;
    printf("O gigante acordouu !\n\n");
}