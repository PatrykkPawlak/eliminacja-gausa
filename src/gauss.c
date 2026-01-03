#include "gauss.h"
#include "mat_io.h"

int eliminate_recursive(Matrix *mat, Matrix *b, int krok) {
  if (krok == mat->r) {
    return 0;
  }
  /* sprawdzenie czy maciez jest osobliwa*/
  int czy_osobliwa = 0;
  for (int ir = krok; ir < mat->r; ir++) {
    if (mat->data[ir][krok] != 0) {
      czy_osobliwa = 1;
      double *buf = mat->data[ir];
      mat->data[ir] = mat->data[krok];
      mat->data[krok] = buf;
      buf = b->data[ir];
      b->data[ir] = b->data[krok];
      b->data[krok] = buf;
      break;
    }
  }
  if (czy_osobliwa == 0)
    return 1;

  for (int i = krok + 1; i < mat->r; i++) {
    double li = mat->data[i][krok] / mat->data[krok][krok];
    for (int j = krok; j < mat->c; j++) {
      mat->data[i][j] = mat->data[i][j] - li * mat->data[krok][j];
    }
    b->data[i][0] = b->data[i][0] - li * b->data[krok][0];
  }
  return eliminate_recursive(mat, b, krok + 1);
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) { return eliminate_recursive(mat, b, 0); }
