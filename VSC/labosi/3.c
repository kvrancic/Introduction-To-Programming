void PronadjiBroj(int a, int b, int c, int *x, int *min) {
   int naj = a;
   if (b < naj)
      naj = b;
   if (c < naj)
      naj = c;

   *min = naj;

   if (naj < 0) {
      *x = a * c;
   } else {
      *x = a * b * c;
   }
}
