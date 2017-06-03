#define _CRT_RAND_S
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int *occ, *squadre, i = 0, j = 0, k = 0, h = 0, iw = 0, trovato = 0;
  unsigned int number;
  printf("inserisci totale numeri da sorteggiare: ");
  #ifdef __linux__
  scanf("%d", &k);
  #elif _WIN32
  scanf_s("%d", &k);
  #endif
  /*alloco arrays*/
  squadre = malloc(k * sizeof(int));
  occ = calloc(k, sizeof(int));
  memset(occ, -1, sizeof(int));
  /*fine allocazione*/
  for (i = 0; i < k; i++) {
    squadre[i] = i;
  }
  for (i = 0; i < k; i++) occ[i] = -1;
  i = 0;
  while (!trovato) {
    #ifdef __linux__
	number = rand();
    #elif _WIN32
    rand_s(&number);
    #endif
    if (occ[j = (number % k)] == -1) {
      occ[j] = i;
      ++i;
    }
    if (i == k - 1) {
      while (occ[h] != -1) ++h;
      occ[h] = i;
      trovato = 1;
    }
    iw++;
  }
  for (i = 0; i < k; i++) {
    printf("sorteggio N. %d --> %d\n", i + 1, squadre[occ[i]]);
  }
  printf("riprove:%d\n", iw);
  return 0;
}
