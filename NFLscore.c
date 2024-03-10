#include<stdio.h>

void combinations(int score) {
    printf("\nPossible Combinations of Scoring Plays:\n");
    for(int td = 0; td <= score/6; td++) {
        for(int fg = 0; fg <= score/3; fg++) {
            for(int s = 0; s <= score/2; s++) {
                for(int TD2 = 0; TD2 <= (score - (td*6 + fg*3 + s*2))/8; TD2++) {
                    for(int TD1 = 0; TD1 <= (score - (td*6 + fg*3 + s*2 + TD2*8))/7; TD1++) {
                        if ((score - (td*6 + fg*3 + s*2 + TD2*8 + TD1*7)) == 0) {
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety\n", TD2, TD1, td, fg, s);
                        }
                    }
                }
            }                
        }
    }
}

int main(){
    while(1) {
    int score;
    printf("\nEnter 0 or 1 to STOP\n");
    printf("Enter the NFL Score: ");
    scanf("%d", &score);
    
    if (score <= 1) {
        break;
    }
    combinations(score);
    }
    return 0;
}