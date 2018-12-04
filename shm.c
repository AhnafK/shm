#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

int main(){
  key_t key = ftok("banana", 'R');
  int shmid = shmget(key, 800, 0644 | IPC_CREAT);
  char *data = shmat(shmid, (void *)0, 0);
  //printf("\n%d\n%d\n", key, shmid);
  printf("Enter a string: ");
  fgets(data, 800, stdin);
  printf("shared contents: %s\n", data);
  char *answer;
  printf("Delete? (y/n): ");
  fgets(answer, 4, stdin);
  if(answer[0] == 'y'){
    shmctl(shmid, IPC_RMID, NULL);
  }
  printf("%s", answer);
  return 0;
}
