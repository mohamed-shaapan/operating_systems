// import libraries
// ********************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// global variables
// ********************************************
long long sum = 0;


// internal functions
// ********************************************
void* sum_runner(void* arg){

	long long *limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;

	for (long long i = 0; i <= limit; i++) {
		sum += i;
	}

	// sum is a global variable, so other threads can access.

	pthread_exit(0);
}


// main function
// ********************************************
int main(int argc, char **argv){

	long long limit = atoll(argv[1]);

	// 01 - create thread
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, sum_runner, &limit);

	/*
		02 - DO OTHER STUFF IN HERE (CONCURRENTLY)
	*/

	// 03 - wait until thread is done its work
	pthread_join(tid, NULL);
	printf("Sum is %lld\n", sum);

}