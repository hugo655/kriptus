/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list_[201] = {};
int i = 0;

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

char* filter(char* entry){
  char *pch = strtok (entry," ");
  pch = strtok (NULL, " ");
  return pch;
}

void put(char* entry) {
  char* aux;
  aux = filter(entry);
  int response = strtol(aux,NULL,10);
  list_[i] = response;
  for (int j = 0;j <=i;j++){
    printf("%d ", list_[j]);
  }
  printf("\n");
  i++;
}
/*
void remove(char* entry) {
  char* aux;
  aux = filter(entry);
  int response = strtol(aux,NULL,10);
  list_[i] = response;
  for (int j = 0;j <=i;j++){
    printf("%d ", list_[j]);
  }
  printf("\n");
  i++;
}
*/
void get(char* entry) {
  char* aux;
  aux = filter(entry);
  int response = strtol(aux,NULL,10);
  printf("%d\n", list_[response-1]);

}

int main(int argc, char *argv[]) {
	char input[201];

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

    if (strncmp(input, "put", 3) == 0) {
			put(input);
		}

    if (strncmp(input, "get", 3) == 0) {
			get(input);
		}
    
    if (strncmp(input, "first\n", 6) == 0) {
			printf("%d\n",list_[0]);
		}

    if (strncmp(input, "last\n", 5) == 0) {
			printf("%d\n",list_[i-1]);
		}

    if(strncmp(input,"list\n",5)==0){
      for(int k=0;k<i;k++){
        printf("%d ",list_[k]);
      }
      printf("\n");
    }  
		//print_entry(input);
	}

	return EXIT_SUCCESS;
}
