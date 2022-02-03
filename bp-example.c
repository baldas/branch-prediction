
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define SIZE (1<<16)

int vector[SIZE];
int less_or_equal[SIZE];

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}


int main()
{
  struct timeval start, end;

  /* use same seed */
  srand(time(NULL));

  int i, j;
  /* initialize */
  for (i=0; i<SIZE; i++) {
    vector[i] = rand() % SIZE;
    less_or_equal[i] = 0;
  }

  gettimeofday(&start, NULL);

#ifdef SORT_FIRST
  qsort (vector, SIZE, sizeof(int), compare);
#endif
  
  /*
   * Count, for each index i, how many values in the vector is less or equal
   * than i
   */
  for (i=0; i<SIZE; i++)
    for (j=0; j<SIZE; j++)
      if (vector[j] <= i) less_or_equal[i]++;

  gettimeofday(&end, NULL);

  int duration;
  duration = (end.tv_sec*1000 + end.tv_usec/1000) - (start.tv_sec*1000 + start.tv_usec/1000);
  printf("Time = %d ms\n", duration);

  return 0;
}

