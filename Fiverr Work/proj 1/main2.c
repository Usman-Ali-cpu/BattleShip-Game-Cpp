#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structure.h"
#include "leak_detector_c.c"

monster* createMonster(char *name, char *element, int population){
    monster *m;
    m->element = (char*) malloc(50 * sizeof(char));
    m->element = element;
    m->name = (char*) malloc(50 * sizeof(char));
    m->name = name;
    m->population = population;
    return m;
}

monster** readMonsters(FILE* infile, int monsterCount){
    monster** monsters;
    monsters = (monster**)malloc(monsterCount * sizeof(monster));
    char str[20];
    int num;
    for (int i = 0; i < monsterCount; i++)
    {
        fscanf(infile ,"%s", str);
        printf("%s ", str);
        char *name = str ;
        fscanf(infile ,"%s", str);
        printf("%s ", str);
        char *element = str;
        fscanf(infile ,"%s", str);
        printf("%s \n",str);
        //printf("num : %s", str);
        num = atoi(str);
        monster *m = createMonster(name, element,num);
        monsters[i] = createMonster(name, element,num);
        free(m);
    }
    return monsters;
}


region** readRegions(FILE* infile, int *countRegions, monster** monsterList, int monsterCount){


}

int main(){

    FILE* fptr;
    char str[20];
    int num;
    fptr = fopen("in.txt", "r");




    fscanf(fptr ,"%s", str);
    // printf("%s ",str);
    // printf("num : %s", str);

    num = atoi(str);
    printf("num : %d\n", num);
    fscanf(fptr ,"%s", str);
    // printf("%s\n", str);
    monster** monsters;
    monsters = (monster**)malloc(num * sizeof(monster));
    monsters = readMonsters(fptr, num);



    fscanf(fptr ,"%s", str);
    // printf("%s\n", str);
    int numRegion = atoi(str);
    printf("%d ", numRegion);

    readRegions(fptr,numRegion, monster** monsterList, int monsterCount)



    fscanf(fptr, "%s", str);

    monster **monsterList = (monster**)malloc(num * sizeof(monster));

    for (int i = 0; i < numRegion; i++)
    {
        printf("Printing Regions\n");

        fscanf(fptr, "%s", str);
        char *name = str;
        printf("%s \n", name);

        fscanf(fptr, "%s", str);
        int numMon = atoi(str);
        printf("numMon : %d\n ", numMon);

        fscanf(fptr, "%s", str);
        // monster* rMonsters;
        monsterList = (monster *)malloc(numMon * sizeof(monster));
        // regions[i].monsters = rMonsters;

        for (int j = 0; j < numMon; j++)
        {
            fscanf(fptr, "%s", str);
            printf("%s\n", str);
            struct monster m = {.name = str};
            regions[i].monsters[j] = &m;
            //regions[i].monsters[j]->name = str;
        }
        }




   
    



/*

    char str[40];
    int num;
    // if(fptr)
    fscanf(fptr ,"%s", str);
    printf("%s ",str);
    //printf("num : %s", str);
    num = atoi(str);
    // printf("num : %d", num);
    if(fptr)
    fscanf(fptr ,"%s", str);
    printf("%s\n", str);
    monster* monsters;
    monsters = (monster*)malloc(num * sizeof(monster));
    for (int i = 0; i < num; i++)
    {
        // char *name;
        // char element;
        // char pop[2];

        fscanf(fptr ,"%s", str);
        // strcpy(monsters[i].name , str);
        // strncpy(monsters[i].name ,str, strlen(str) + 1);
        monsters[i].name = str;
        printf("%s ", monsters[i].name);
        // if(i>0){
        //     printf("%s ", monsters[i-1].name);
        // }

        fscanf(fptr ,"%s", str);
        // strcpy(monsters[i].element, str);
        // strncpy (monsters[i].element,str, strlen(str) + 1 );
        monsters[i].element = str;
        printf("%s ", monsters[i].element);

        fscanf(fptr ,"%s", str);
        monsters[i].population = atoi(str); 
        printf("%d\n", monsters[i].population);

        for (int i = 0; i < num; i++) {
            printf("%s" , monsters[i].element);
        }
    }

    

    printf("--------------------------\n");

    fscanf(fptr ,"%s", str);
    // printf("%s\n", str);
    int numRegion = atoi(str);
    printf("%d ", numRegion);


    fscanf(fptr, "%s", str);

    
    region* regions;
    regions = (region*)malloc(numRegion * sizeof(region));

    for (int i = 0; i <numRegion; i++){
        regions[i].name = "Name ";
    }
    region r;

        for (int i = 0; i < numRegion; i++)
        {
            printf("Printing Regions\n");

            fscanf(fptr, "%s", str);
            char *name = str;
            printf("%s \n", name);

            fscanf(fptr, "%s", str);
            int numMon = atoi(str);
            printf("numMon : %d\n ", numMon);

            fscanf(fptr, "%s", str);
            // monster* rMonsters;
            regions[i].monsters = (monster*) malloc(numMon * sizeof(monster));
            // regions[i].monsters = rMonsters;

            for (int j = 0; j < numMon; j++)
            {
                fscanf(fptr, "%s", str);
                printf("%s\n", str);
                struct monster m = { .name = str};
                regions[i].monsters[j] = &m;
                //regions[i].monsters[j]->name = str;
            }
        }
        printf("--------------------------\n");

        fscanf(fptr, "%s", str);
        // printf("%s\n", str);
        int numTrainer = atoi(str);
        printf("%d\n", numTrainer);


        fscanf(fptr, "%s", str);
    for (int j = 0; j < numTrainer; j++)
    {
        fscanf(fptr, "%s", str);
        printf("Al : %s\n", str);

        fscanf(fptr, "%s", str);
        int capture = atoi(str);
        printf("%d ", capture);
        trainer* train;
        train = (trainer*)malloc(capture * sizeof(trainer));
    

        fscanf(fptr, "%s", str);
        printf(" %s\n", str);

        fscanf(fptr, "%s", str);
        int numReg = atoi(str);
        printf("%d\n", numReg);
        fscanf(fptr, "%s", str);
        printf("hdhd : %s\n", str);

        for (int i = 0; i < numReg; i++){
            fscanf(fptr, "%s", str);
            // train[0].visits->regions = str;
            printf("h: %s\n", str);
        }
    }


            // fscanf(fptr, "%s", &str);
            // int numMon = atoi(str);
            // printf("%d\n ", numMon);

            // fscanf(fptr, "%s", &str);
            // monster rMonsters[num];
            // for (int i = 0; i < numMon; i++){
            //     fscanf(fptr, "%s", &str);
            //     printf("%s\n", str);
            //     rMonsters[i].name = str;
            // }


*/


            // for (int i = 0; i < 8; i++){
            //     printf("Name %d ", monsters[i].population);
            //     printf("%s ", monsters[i].name);
            //     printf("%d \n", monsters[i].population);
            // }

            return 0;
}