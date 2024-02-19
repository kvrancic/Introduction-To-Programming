#include <stdio.h>
#include <string.h>

struct Student {
   char firstName[30 + 1];
   char lastName[30 + 1];
   int points[5];
};

void analyzeGrades(const char *studentsFilename, const char *reportFilename) {
   struct Student ucenik;
   FILE *ulazb = fopen(studentsFilename, "rb");
   FILE *izlazt = fopen(reportFilename, "w");
   int bodovi = 0, max = 0;
   char ime[31], prezime[31];

   while (fread(&ucenik, sizeof(ucenik), 1, ulazb) == 1) {
      bodovi = 0;
      for (int i = 0; i < 5; i++) {
         bodovi += ucenik.points[i];
      }
      fprintf(izlazt, "%s %s %d\n", ucenik.firstName, ucenik.lastName, bodovi);
      printf("%s %s %d\n", ucenik.firstName, ucenik.lastName, bodovi);
      if (bodovi > max) {
         max = bodovi;
         strcpy(ime, ucenik.firstName);
         strcpy(prezime, ucenik.lastName);
      }
   }
   fprintf(izlazt, "Najbolji rezultat: %s %s", ime, prezime);
   printf("Najbolji rezultat: %s %s", ime, prezime);

   fclose(ulazb);
   fclose(izlazt);
}
