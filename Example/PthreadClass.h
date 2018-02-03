#ifndef __PTHREAD_CLASS__
#define __PTHREAD_CLASS__


#include <pthread.h>
#include <iostream>

using namespace std;

class PthreadClass{

	public:
	       	int thread_numbers;

	public:
	       	PthreadClass(int thread_numbers){
			this->thread_numbers = thread_numbers;
		}
		void run();
		int get_thread_numbers(){
			return thread_numbers;
		}
		virtual void kernel(int thread_id)=0;

};


#endif
