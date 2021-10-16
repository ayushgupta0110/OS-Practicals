#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int sum;
void *runner(void *param);

int main(int argc,char *argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	
	if(argc !=2){
	  cerr<<"\nInsufficient arguments provided!"<<endl;
	  return -1;
	}
	if(atoi(argv[1])<0){
	  cout<<"\nInvalid argument is provided(should be >0): "<<atoi(argv[1]);
	  return -1;
	}
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	
	cout<<"\nSum of first "<<atoi(argv[1])<<" Natural Numbers is: "<<sum<<endl;
}

void *runner(void *param){
   int i, upper = atoi((char *)param);
	sum = 0;
	for (i =1; i <= upper; i++)
	sum += i;
	pthread_exit(0);	
}

