// import libraries
// ********************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// internal functions
// ********************************************
void* sum_runner(void* arg){

	long long *limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;
	free(arg);

	long long sum = 0;
	for (long long i = 0; i <= limit; i++) {
		sum += i;
	}

	// Pass back data in dynamically allocated memory
	long long *answer = malloc(sizeof(*answer));
	*answer = sum;
	pthread_exit(answer);

}


// main function
// ********************************************
int main(int argc, char **argv){

	long long *limit = malloc(sizeof(*limit));
	*limit = atoll(argv[1]);

	// create thread
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, sum_runner, limit);

	/*
		02 - DO OTHER STUFF IN HERE (CONCURRENTLY)
	*/

	// 03 - wait until thread is done its work
	long long *result;
	pthread_join(tid, (void**)&result);
	printf("Sum is %lld\n", *result);
	free(result);

}
