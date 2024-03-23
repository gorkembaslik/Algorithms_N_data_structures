#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printStars(int *arg) {
    int *n = (int *)arg;
    pthread_t id = pthread_self(); //returns thread id

    for (int i = 0; i < *n; i++) {
        printf("*");
    }
    printf(" threadId%d\n", id);

    return NULL;
}

int main(int argc, char *argv[]) {
    // check if there are correct # of inputs
    if (argc != 2) {
        fprintf(stderr, "Not correct # of parameters, enter 1 integer\n");
        return 1;
    }

    // int conversion of char input
    int n = atoi(argv[1]);

    if (n < 0) {
        fprintf(stderr, "Input positive integer\n");
        return 0;
    } else if (n == 0) {
        fprintf(stderr, "If you want to create threads and print stars, input positive integer!!\n");
        return 0;
    }


    pthread_t threads[n];
    // create n threads, call the funtion and pass the number of stars to be printed as a reference
    for (int i = 0; i < n; i++) {
        if (pthread_create(&threads[i], NULL, printStars, &n) != 0) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // wait all threads to finish, then terminate
    for (int i = 0; i < n; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
    }

    exit(0);
}