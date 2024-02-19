#include <stdio.h>

struct Employee {
   char firstName[20 + 1];
   char lastName[30 + 1];
   int positionId;
   int employedSinceYear;
};

struct Position {
   int idPosition;
   char positionName[20 + 1];
};

void generateReport(const char *employeesFilename,
                    const char *positionsFilename, const char *outputFilename) {
   struct Employee zaposlenik;
   struct Position pozicija;
   FILE *ulazZ = fopen(employeesFilename, "rb");
   FILE *ulazP = fopen(positionsFilename, "rb");
   FILE *izlaz = fopen(outputFilename, "w");

   while (fread(&zaposlenik, sizeof(zaposlenik), 1, ulazZ) == 1) {
      if (zaposlenik.employedSinceYear > 2007) {
         fseek(ulazP, 0L, SEEK_SET);
         while (fread(&pozicija, sizeof(pozicija), 1, ulazP) == 1) {
            if (zaposlenik.positionId == pozicija.idPosition) {
               fprintf(izlaz, "%s,%s;%d;%s\n", zaposlenik.firstName,
                       zaposlenik.lastName, zaposlenik.employedSinceYear,
                       pozicija.positionName);
            }
         }
      }
   }
}