int povratak(int *polje, int m, int n) {
   int mini = 0;
   int min = *polje;
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         if (*(polje + n * i + j) < min) {
            min = *(polje + n * i + j);
            mini = i;
         }
      }
   }

   return mini;
}