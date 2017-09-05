#include<stdio.h>
#include <stdlib.h>
#include "My_Mine_Sweeping.h"

// This is a program to start playing the mine sweeping game.

int main() {
    int cmd = 1;
    printf("--- Welcome to Mine Sweeping ---\n");
    while (cmd) {
        printf("Please enter: 0 or 1 (exit or start):\n");
        scanf("%d", &cmd);
        if (cmd == 0) {
            printf("Bye!\n");
            break;
        } else if (cmd == 1) {
            play_mine_sweeping();
            printf("\n");
        } else {
            printf("INVALID. Please try again.\n");
        }
    }
}
