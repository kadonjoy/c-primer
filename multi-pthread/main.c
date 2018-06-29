/*
 **************************************************************************************
 *       Filename:  main.cpp
 *    Description:  multi pthread example
 *
 *        Version:  1.0
 *        Created:  2018-06-29 09:42:22
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <pthread.h>
#include <stdio.h>
#include <time.h>

typedef unsigned char uint_8;

void * routimeFunc(void* arg)
{
    long long sum = 0;
    int i=1;
    for (; i < 1000000000; i++) {
        sum += i;
    }
}

int main(int argc, char** agrv)
{
    pthread_t tids[10];
    time_t curTime = time(NULL);
    uint_8 j;
    // 1. serial calculate
    for (j = 0; j < 10; j++) {
        routimeFunc(NULL);
    }
    printf("serial consume time %ld s\n", time(NULL)-curTime);

    // 2. multi threads calculate
    curTime = time(NULL);
    for (j = 0; j < 10; j++) {
        if ((pthread_create(&tids[j], NULL, routimeFunc, (void*)NULL)) == -1) {
            printf("The %d thread create error!\n", j);
            return -1;
        }
    }

    for (j=0; j<10; j++) {
        if (pthread_join(tids[j], NULL)) {
            printf("The thread %d is not exit...\n", j);
            return -1;
        }
    }
    printf("multi threads consume time %ld s\n", time(NULL)-curTime);

    return 0;
}

/********************************** END **********************************************/
