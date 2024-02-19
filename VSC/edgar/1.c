#include <stdio.h>

struct Vehicle {
   char registration[8 + 1];
   int weightKilos;
   int productionYear;
   _Bool isInUse;
};

void reuseVehicles(const char *vehiclesFilename, int fromYear,
                   int belowWeight) {
   struct Vehicle vozilo = {0};
   FILE *stream = fopen(vehiclesFilename, "r+b");

   while (fread(&vozilo, sizeof(vozilo), 1, stream) == 1) {
      if (vozilo.productionYear > fromYear &&
          vozilo.weightKilos < belowWeight) {
         vozilo.isInUse = 1;
      } else {
         vozilo.isInUse = 0;
      }

      fseek(stream, -1L * sizeof(_Bool), SEEK_CUR);
      fwrite(&vozilo.isInUse, sizeof(_Bool), 1, stream);
   }

   return;
}

int main(void) {}