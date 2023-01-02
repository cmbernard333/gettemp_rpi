#include <stdio.h>
#include <stdlib.h>

#define ZONETEMPFILE "/sys/class/thermal/thermal_zone0/temp"

int main(int argc, char **argv) {

  FILE *fptr = NULL;
  float tempread = 0;
  int i_ferror = 0;

  fptr = fopen(ZONETEMPFILE, "r");

  if (fptr == NULL) {
    fprintf(stderr, "Could not open %s", ZONETEMPFILE);
    return 3;
  }

  fscanf(fptr, "%f", &tempread);
  if ((i_ferror = ferror(fptr)) != 0) {
    fprintf(stderr, "Could not read %s: ferror %d", ZONETEMPFILE, i_ferror);
    fclose(fptr);
    return i_ferror;
  }

  fprintf(stdout, "Temp %f\n", (float)(tempread / 1000));
  fclose(fptr);

  return 0;
}
