#include <stdio.h>


void pat1(){
    // * * * * * * * * * 
    //   * * * * * * *           
    //     * * * * * 
    //       * * * 
    // 	       *

    int row, col;
    for(row=1; row<=5; row++){
        for(col=1; col<=9; col++){
            if(col >= row && col <= 10-row){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void pat2(){
    // * 
    // * * 
    // * * * 
    // * * * *
    // * * * 
    // * * 
    // * 

    int row, col, n=1;
    for(row=1; row<=7; row++){
        for(col=1; col<=4; col++){
            if(col<=n){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");

        if(row < 4){
            n++;
        }
        else{
            n--;
        }
    }

}

void pat3(){
    // * * * * * * * * * 
    //   * * * * * * * * * 
    //     * * * * * * * * * 
    //       * * * * * * * * * 
    //         * * * * * * * * * 

    int row, col;
    for(row=1; row<=5; row++){
        for(col=1; col<=13; col++){
            if(col>=row && col<=8+row ){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
  
}

void pat4(){
    //       *
    //     * *
    //   * * *
    // * * * *
    //   * * *
    //     * *
    //       *

    int row, col, n=1;
    for(row=1; row<=7; row++){
        for(col=1; col<=4; col++){
            if(col>=5-n){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
        if(row < 4){
            n++;
        }
        else{
            n--;
        }
    }
}

void pat5(){
    // 	       *
    //       * * * 
    //     * * * * * 
    //   * * * * * * *           
    // * * * * * * * * * 
    //   * * * * * * *           
    //     * * * * * 
    //       * * * 
    // 	       *

    int row, col, n=1;
    for(row=1; row<=9; row++){
        for(col=1; col<=9; col++){
            if(col>5-n && col<5+n){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
        if(row < 5){
            n++;
        }
        else{
            n--;
        }
    }
}

void pat6(){
    //         * * * * * * * * * 
    //       * * * * * * * * * 
    //     * * * * * * * * * 
    //   * * * * * * * * * 
    // * * * * * * * * * 

    int row, col;
    for(row=1; row<=5; row++){
        for(col=1; col<=13; col++){
            if(col>=6-row && col<= 14-row){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void pat7(){
    //    * * * * *
    //    * *   * * 
    //    *       *
    //    * *   * *
    //    * * * * * 

    int row, col, n=0;
    for(row=1; row<=5; row++){
        for(col=1; col<=5; col++){
            if(col<=3-n || col>=3+n){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
        if(row < 3){
            n++;
        }
        else{
            n--;
        }
    }

}

void pat8(){
    //             1
    //           1 2 1
    //         1 2 3 2 1
    //       1 2 3 4 3 2 1

    int row, col, num;
    for(row=1; row<=4; row++){
        num=1;
        for(col=1; col<=7; col++){
            if(col>4-row && col<4+row){
                if(col < 4){
                    printf("%d ", num++);   
                }
                else{
                    printf("%d ", num--);
                }
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void pat9(){
    //            1
    //          2 3 2 
    //        3 4 5 4 3
    //      4 5 6 7 6 5 4 

    int row, col, num=1;
    for(row=1; row<=4; row++){
        for(col=1; col<=7; col++){
            if(col>4-row && col<4+row){
                if(col < 4){
                    printf("%d ", num++);
                }
                else{
                    printf("%d ", num--);
                }
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
        num += 2;
    }
}

void pat10(){
    // 	       *
    //       * * * 
    //     * * * * * 
    //   * * * * * * *           
    // * * * * * * * * * 

    int row, col;
    for(row=1; row<=5; row++){
        for(col=1; col<=9; col++){
            if(col>5-row && col<5+row){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void pat11(){
    //     A B C D E D C B A
    //     A B C D   D C B A
    //     A B C       C B A
    //     A B           B A
    //     A               A 

    char ch;
    for(int row=1; row<=5; row++){
        ch = 'A';
        for(int col=1; col<=9; col++){
            if(col<=6-row || col>=4+row){
                if(col < 5){
                    printf("%c ", ch++);
                }
                else if(row == 1 && col>=5){
                    printf("%c ", ch--);
                }
                else{
                    printf("%c ", --ch);
                }
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main(){
    pat1();
    printf("\n");

    pat2();
    printf("\n");

    pat3();
    printf("\n");

    pat4();
    printf("\n");

    pat5();
    printf("\n");

    pat6();
    printf("\n");

    pat7();
    printf("\n");

    pat8();
    printf("\n");

    pat9();
    printf("\n");

    pat10();
    printf("\n");

    pat11();
    printf("\n");

    return 0;
}