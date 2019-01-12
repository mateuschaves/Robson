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
void setDistanceTotal();
void getDistanceTotal();
void setDistanceRight(int miles);
void getDistanceRight();
void setDistanceLeft(int miles);
void getDistanceLeft();
void setupRobson();
int checkRobson();
void wakeUpRobson();
void sleepRobson();

typedef struct {

    char direction[20];
    int on;
    int distanceWalkedToRight;
    int distanceWalkedToLeft;
    int distanceTotalWalked;

} robsonStruct;

robsonStruct robson;

int main(void){
    setupRobson();
    wakeUpRobson();
    turnRight();
    walkToFront(100);
    turnLeft();
    walkToFront(200);
    setDistanceTotal();
    getDistanceTotal();
    getDistanceLeft();
    getDistanceRight();
    sleepRobson();
    turnLeft();

    system("pause");
    return 0;
}

void turnRight(){
    if(checkRobson()){
        printf("Virando para a %s ! \n\n", RIGHT);
        strcpy(robson.direction, RIGHT);
    }
}

void turnLeft(){
    if(checkRobson()){
        printf("Virando para a %s ! \n\n", LEFT);
        strcpy(robson.direction, LEFT);
    }
}

void walkToBack(int miles){
    if(checkRobson()){
        printf("Voltando %d metros em direcao a %s!\n\n", miles, robson.direction);
        if( strcmp(robson.direction, LEFT) == 0 ){
            setDistanceLeft(miles);
        }else if ( strcmp(robson.direction, RIGHT) == 0 ){
            setDistanceRight(miles);
        }
    }
}

void walkToFront(int miles){
    if(checkRobson()){
        printf("Andando %d metros em direcao a %s! \n\n", miles, robson.direction);
        if( strcmp(robson.direction, LEFT) == 0 ){
            setDistanceLeft(miles);
        }else if ( strcmp(robson.direction, RIGHT) == 0 ){
            setDistanceRight(miles);
        }
    }
}

void setDistanceTotal(int miles){
    robson.distanceTotalWalked = robson.distanceWalkedToLeft + robson.distanceWalkedToRight;
}

void getDistanceTotal(){
    if(checkRobson())
        printf("O Robson andou %d metros no total !\n\n", robson.distanceTotalWalked);
}

void setDistanceLeft(int miles){
    if(checkRobson())
        robson.distanceWalkedToLeft += miles;
}

void getDistanceLeft(){
    if(checkRobson())
        printf("O Robson andou %d metros para a %s !\n\n", robson.distanceWalkedToLeft, LEFT);
}

void setDistanceRight(int miles){
    if(checkRobson())
        robson.distanceWalkedToRight += miles;
}

void getDistanceRight(){
    if(checkRobson())
        printf("O Robson andou %d metros para a %s ! \n\n", robson.distanceWalkedToRight, RIGHT);
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
    if(robson.on == TRUE){
        printf("Robson já esta acordadooo !");
    }else{
        robson.on = TRUE;
        printf("O gigante acordouu !\n\n");
    }
}

void sleepRobson(){
    if(robson.on == FALSE){
        printf("Robson ja esta dormindoo !\n\n");
    }else{
        robson.on = FALSE;
        printf("Robson morreu rapidao ! \n\n");
    }
}