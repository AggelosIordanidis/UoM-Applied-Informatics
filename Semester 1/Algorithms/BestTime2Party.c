#include <stdio.h>
#define N 6
#define BANDS 35
int main () {
  int hours[BANDS][2], i, j, max, min, minpos, maxpos;
  for (i=0; i<BANDS; i++) {
    for (j=0; j<2; j++) {
      scanf("%d", &hours[i][j]);
    }
  }
  int attendance[N] = {0,0,0,0,0,0};
  for (i=0; i<N; i++) {
    for (j=0; j<BANDS; j++) {
      if (hours[j][0] <= i + 18) {
        if (hours[j][1] > i + 18) {
            attendance[i]++;
        }
      }
    }
  }
  min = max = attendance[0];
  minpos = maxpos = 0;
  for (i=0; i<N; i++) {
    if (attendance[i] > max) {
      max = attendance[i];
      maxpos = i;
    }
    if (attendance[i] < min) {
      min = attendance[i];
      minpos = i;
    }
  }
  printf("Best time to attend is %d:00 - %d:00.\n", maxpos + 18, maxpos + 19);
  printf("Worst time to attend is %d:00 - %d:00.\n", minpos + 18, minpos + 19);
  return 0;
}
