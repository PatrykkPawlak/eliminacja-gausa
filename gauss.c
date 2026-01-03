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
      break;
    }
  }
  if (czy_osobliwa == 0)
    return 1;

  return 0;
}
