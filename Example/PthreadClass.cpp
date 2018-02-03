#include "PthreadClass.h"


struct PTHREAD_STRUCT{
	int thread_numbers;
	PthreadClass *pc;
};

void * voidf(void *argv){
	PTHREAD_STRUCT *a = (PTHREAD_STRUCT *)argv;
	a->pc->kernel(a->thread_numbers);
	pthread_exit(0);
};

void PthreadClass::run(){

	if ( thread_numbers <= 0 ){
		cout<<"ERROR : thread numbers is less than zero ";
	}else{

		pthread_t tid [20];
		PTHREAD_STRUCT tst[20];
		for ( int i=0 ; i<thread_numbers ; i++ ){
			tst[i].thread_numbers = i;
			tst[i].pc = this;
			pthread_create ( &tid[i] , NULL , voidf , (void *)(tst+i) );
		}
		for ( int i=0 ; i<thread_numbers ; i++ ){
			pthread_join ( tid[i] , NULL );
		}

	}
}
