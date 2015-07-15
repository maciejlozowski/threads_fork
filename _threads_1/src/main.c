#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *myThread(void *arg){
	int i;
	int idPotomnego = fork(); //dokladna kopia procesu macierzystego(tworzy proces potomny z danego procesu)ale otrzymuje nowe PID i nowe zasoby. Dodoatkowo proces macierzysty otrzymuje kod powrotou funkcji fork() równy PID-owi procesu potomnego, a proces potomny otrzymuje kod powrotu funkcji fork() równy 0.
	if (idPotomnego == 0) {
	    printf("Jesteś w procesie potomnym, jego ID = %d\n", getpid());
	} else {
	    printf("Jesteś w procesie macierzystym, jego ID = %d\n", getpid());
	}
	/*for(i = 0; i < 10; i++){
		printf("Inkrem numb: %d",i);
		sleep(1);
	} */
	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t firstThread;
	pthread_create ( &firstThread, NULL, myThread, NULL);
	while(1){
		sleep(10); // w shellu ps aux |grep  pthread_cos-nazwa  .... gdb -p (pid procesu)(sledzimy procesy) (gdb) t a a bt (sprawdza ilosc watkow)
	} //fork() kopiuje tylko dany watek, ktory go wywolal i tylko go bedzie sledzil...
	pthread_join(firstThread, NULL);
	exit(0);
	return 0;
}
