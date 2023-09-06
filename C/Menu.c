#include <stdio.h>
int main() {
   int pilih = 0;
   while(pilih != 4){
 puts("/---------------------/");
 puts("          MENU         ");
 puts("/---------------------/");
 puts("1. Menu 1");
 puts("2. Menu 2");
 puts("3. Menu 3");
 puts("4. Exit");
 printf(">> ");
 scanf("%d", &pilih);

 switch(pilih){
   case 1:
      puts("Menu 1 Terpilih!");
      break;
   case 2:
      puts("Menu 2 Terpilih!");
      break;
   case 3:
      puts("Menu 3 Terpilih!");
     break;
   case 4:
      puts("Exit Terpilih!");
      break;
   default:
      puts("INVALID COMMAND");
    }
   }
 return 0;
}