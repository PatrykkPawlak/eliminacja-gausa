#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
  /* sprawdzenie czy maciez jest osobliwa*/
  int czy_osobliwa = 0;
  for (int ir = 0; ir < mat->r; ir++) {
    if (mat->data[ir][0] != 0) {
      czy_osobliwa = 1;
      double *buf = mat->data[ir];
      mat->data[ir] = mat->data[0];
      mat->data[0] = buf;
      buf = b->data[ir];
      b->data[ir] = b->data[0];
      b->data[0] = buf;
      break;
    }
  }
  if (czy_osobliwa == 0)
    return 1;

  return 0;
}
