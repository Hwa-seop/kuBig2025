 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 static int seed = 1;
 // extern int seed;
 
 void my_srand(int s)
 {
     seed = s;
 }
 int my_rand(void){
    seed=seed*110351522454+1234;
    return ((unsigned)(seed
 }
 
 int seed = 1;