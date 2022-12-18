#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

static char strNo[6] = "NO";
static char strYes[6] = "YES";
static char str1[6];
static int line170(void);
static int line410(int *A,int *D);
static int line490(int *A,int *D,int CC);
static int line680(int *A,int *D,int CC);
static int line710(int *A,int *D,int CC);
static int line950(int *A);
static int line1120(void );


void Tab(int a){
    for(int i; i<=a;i++){
        printf(" ");
    }
}

int line170(){
    printf("DO YOU NEED INSTRUCTIONS?\n");
    while(true){
        scanf("%s",str1);
        if (strcmp (str1, strYes)==0){
                printf("STRIKE NINE IS PLAYED WITH A PAIR OF DICE AND A\n");
                printf("BOARD WITH NINE NUMBERS: 1 2 3 4 5 6 7 8 9. YOU\n");
                printf("ARE GIVEN A ROLL AND CAN KNOCK OFF UP TO 4 NUMBERS.\n");
                printf("IF YOU INPUT THAT YOU WANT TO REMOVE 5 NUMBERS, YOU\n");
                printf("WILL BE GIVEN A CHART OF THE NUMBERS YOU HAVE LEFT\n");
                printf("TO REMOVE. NEXT YOU INPUT HOW MANY NUMBERS YOU WANT\n");
                printf("TO REMOVE, AND THEN INPUT THE NUMBERS YOU WANT TO \n");
                printf("TAKE OFF, ONE AT A TIME. THE NUMBERS YOU TAKE OFF\n");
                printf("MUST ADD UP TO THE ROLL. YOU WIN BY REMOVING EVERY\n");
                printf("NUMBER FROM THE BOARD. YOU LOSE IF YOU CANNOT");
                printf("REMOVE ALL NUMBERS WITH THE ROLL YOU HAVE.\n");
                printf("READY TO PLAY?\n\n");
                break;
            }else if(strcmp (str1, strNo)==0){
                printf("READY TO PLAY?\n\n");
                break;
            } 
    }
    
    printf("HERE IS THE BOARD:\n");
    int D[4]= {0,0,0,0};
    int A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    line410(A,D);
    return 0;
}
int line410(int *A,int *D){
    srand(time(NULL));
    int num1 = 0 + rand() % (1 - 0 + 1);
    int num2 = 0 + rand() % (1 - 0 + 1);
    int CC = (num1 * 6 + 1) + (num2 * 6 + 1);
    printf("YOUR ROLL IS %d\n",CC);
    int T=0;
    for (int i=0;i<9;i++){
        T = T + A[i];
    }
    if (CC>T){
        line950(A);
    }
    if (CC==T){
        line1120();
    }
    line490(A,D,CC);
    return 0;
}
int line490(int *A,int *D,int CC){
    int F = 0;
    int F1 = 0;
    for(int K =1; K<10;K++){
        for(int L =1; L<10;L++){
            for(int M = 1; M<10;M++){
                for(int N = 1; N<10;N++){
                    F=0;
                    F1=0;                    
                    if(N==L){
                        F=1;
                    }
                    if (N==M)
                    {
                        F=1;
                    }
                    if(N==M){
                        F=1;
                    }
                    if(N==K){
                        F=1;
                    }
                    if (M==K){
                        break;
                    }
                    if (M==L){
                        break;
                    }
                    if (L==K){
                        F1=1;
                        break;
                    }
                    if (F!=1){
                        if (CC-A[K-1]==0) {
                            line680(A,D,CC);
                        }
                        if ((CC-A[K-1]==A[N-1])){
                            line680(A,D,CC);
                        }
                        if (CC-A[K-1]-A[L-1]==A[N-1]) {
                            line680(A,D,CC);
                        }
                        if (CC-A[K-1]-A[M-1]==A[N-1]){
                            line680(A,D,CC);
                        }
                    }
                }
                if(F1==1){
                    break;
                }
            }
        }
    }
    line950(A);
    return 0;
}

int line680(int *A,int *D,int CC){
    for(int X=0;X<5;X++){
        D[X]=0;
    }
    line710(A,D,CC);
    return 0;
}

int line710(int *A,int *D,int CC){
    printf("# OF NUMBERS TO REMOVE ");
    int E,res;
    res=scanf("%d",&E);
    fflush(stdin);
    if(res==1){ 
    }else {
        printf("%s","ANSWER 1, 2, 3, OR 4 (5 FOR THE BOARD)\n");
        line710(A,D,CC);
    }
    if(E<1){
        printf("%s","ANSWER 1, 2, 3, OR 4 (5 FOR THE BOARD)\n");
        line710(A,D,CC);
    }else if(E>4){
        printf("THE NUMBERS YOU HAVE LEFT TO REMOVE ARE:  \n");
        for(int B=1;B<9;B++){
            if (A[B-1]==0){
               printf("%d\n",A[B]); 
            }
        }
        line710(A,D,CC);
    }
    printf("WHAT IS THE NUMBER ? ");
    for(int F=1;F<=E;F++){
        scanf("%d",&D[F-1]);
        if(A[D[F-1]-1]==0){
            printf( "YOU REMOVED IT BEFORE, TRY AGAN.\n");
            line710(A,D,CC);
        }
    }
    if(CC==D[0]+D[1]+D[2]+D[3]){
        for(int F=1;F<=E;F++){
            A[D[F-1]-1]=0;
            
        }
        line410(A,D);
    }else{
        printf( " THOSE NUMBERS DON'T ADD UP TO YOUR ROLL, TRY AGAIN\n");
        line710(A,D,CC);
    }
    return 0;
}

int line950(int *A){
    printf("SORRY, YOU LOST THIS TIME.\n");
    int T=0;
    for(int B=1;B<10;B++){
        if (A[B-1]!=0){
            T=T+1;
        }
    }
    printf("THERE ARE %d",T);
    printf(" NUMBERS LEFT ON THE BOARD:   ");
    for (int X = 1; X < 10; X++){
        printf("%d",A[X-1]);
    }
    printf("\n");
    printf("WANT TO TRY AGAIN (YES OR NO)\n");
    char str3[1024];
    scanf("%s",str3);
    if(strcmp (str3, strYes)==0){
        line170();
    }else if(strcmp (str3, strNo)==0){
        exit (EXIT_SUCCESS);
    }
    return 0;
}

int line1120(void ){
    printf("* * * CONGRATULATIONS * * *\n");
    printf("* YOU WON *\n");
    printf("PLAY ANOTHER GAME (YES OR NO)\n");
    char str4[1024];
    scanf("%s",str4);
    while(true){
        if(strcmp(str4, strYes)==0){
            line170();
        }else if(strcmp(str4, strNo)==0){
            exit (EXIT_SUCCESS);
        } 
    }
    return 0;
}

int main(void){
    Tab(25);
    printf("STRIKE 9\n");
    Tab(19);
    printf("CREATIVE COMPUTING\n");
    Tab(18);
    printf("MORRISTOWN NEW JERSEY\n");
    line170();
}
    
