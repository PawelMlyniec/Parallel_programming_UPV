#include <stdio.h>
#include <math.h>
#include <omp.h>

typedef unsigned long long Entero_grande;
#define N 50000000ULL

int primo(Entero_grande n)
{
  int p;
  Entero_grande i, s;

  p = (n % 2 != 0 || n == 2);

  if (p) {
    s = sqrt(n);

    for (i = 3; p && i <= s; i += 2)
      if (n % i == 0) p = 0;
  }

  return p;
}

int main()
{
  Entero_grande i, n;
  double t1, t2;
  int idThreat;

  n = 2; /* Por el 1 y el 2 */

  t1 = omp_get_wtime();
  
  /* no parallelism
   // time: 81.923804
  for (i = 3; i <= N; i += 2)
    if (primo(i)) n++;
  */

  /* parallel for
    //time: 30.186964
  #pragma omp parallel for reduction(+:n)
  for (i = 3; i <= N; i += 2)
    if (primo(i)) n++;
  */
  
  /* parallel cyclic
    //time: 5.625847
  #pragma omp parallel reduction(+:n) private(idThreat)
  {
    idThreat = omp_get_thread_num();
    for (i = 3+(idThreat*2); i <= N; i += 2+(omp_get_num_threads()*2))
      if (primo(i)) n++;
  }
  */
  
  t2 = omp_get_wtime();

  printf("Entre el 1 y el %llu hay %llu numeros primos.\n",
         N, n);
  printf("Tiempo: %f:\n", t2-t1);
  return 0;
}
