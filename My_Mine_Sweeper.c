#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<time.h>

// Source: srand() and rand() functions in set_mine(mine); from http://www.tutorialspoint.com/c_standard_library/c_function_rand.htm

int row = 9;
int col = 9;
int num = 10;

struct posn {
    int x;
    int y;
};

struct llnode {
    struct posn pos;
    struct llnode *next;
};

struct llist {
    struct llnode *front;
    struct llnode *back;
};

void init_board(char minemap[row][col], char cur[row][col]) {
    for (int i = 1; i < row + 1; i++) {
        for (int j = 1; j < col + 1; j++) {
            minemap[i][j] = '-';
        }
    }
    for (int i = 1; i < row + 1; i++) {
        for (int j = 1; j < col + 1; j++) {
            cur[i][j] = '_';
        }
    }
}


void display_board(char cur[row][col]) {
    printf("  ");
    for (int i = 1; i < col + 1; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i < row + 1; i++) {
        printf("%d ", i);
        for (int j = 1; j < col + 1; j++) {
            printf("%c ", cur[i][j]);
        }
        printf("\n");
    }
}


// queue:
struct llist *mlst_create() { // a linked list storing mine positions
    struct llist *mlst = malloc(sizeof(struct llist));
    mlst->front = NULL;
    mlst->back = NULL;
    return mlst;
}


void mlst_destroy(struct llist *mlst) {
    struct llnode *curnode = mlst->front;
    while (curnode) {
        struct llnode *nextnode = curnode->next;
        free(curnode);
        curnode = curnode->next;
    }
    free(mlst);
}


void mlst_add_back(struct posn p, struct llist *mlst) {
    struct llnode *mine = malloc(sizeof(struct llnode));
    mine->pos = p;
    mine->next = NULL;
    if (mlst->front == NULL) {
        mlst->front = mine;
    } else {
        mlst->back->next = mine;
    }
    mlst->back = mine;
}


struct llist *set_mine(char minemap[row][col], struct llist *mlst) {
    srand((unsigned)time(NULL));
    for(int count = num; count > 0; ) {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (minemap[x][y] == '-') {
            minemap[x][y] = '*';
            struct posn p = {x, y};
            mlst_add_back(p, mlst);
            --count;
        }
    }
    return mlst;
}


char** display_mine(char cur[row][col], struct llist *mlst) {
    assert(mlst->front);
    struct llnode *mine = mlst->front;
    while (mine) {
        cur[mine->pos.x][mine->pos.y] = '*';
        mine = mine->next;
    }
    return cur;
}


int count_mine(char minemap[row][col], int x, int y) {
    assert(3 <= x <= row && 3 <= y <= col);
    int count = 0;
    if (minemap[x - 1][y - 1] == '*') ++count;
    if (minemap[x - 1][y] == '*') ++count;
    if (minemap[x - 1][y + 1] == '*') ++count;
    if (minemap[x][y - 1] == '*') ++count;
    if (minemap[x][y + 1] == '*') ++count;
    if (minemap[x + 1][y - 1] == '*') ++count;
    if (minemap[x + 1][y] == '*') ++count;
    if (minemap[x + 1][y + 1] == '*') ++count;
    return count;
}


void mine_sweeping(char minemap[row][col], char cur[row][col], struct llist *mlst) {
    int x = 0;
    int y = 0;
    int left = row*col;
    while (left != num || left == row*col) {
        printf("\nPlease choose a coordinate: row(1-row) col(1-col)：\n");
        scanf("%d%d", &x, &y);
        while (x > row || y > col || x < 1 || y < 1) {
            printf("INVALID. Please try again.\n");
            printf("Please choose a coordinate: row(1-row) col(1-col)：\n");
            scanf("%d%d", &x, &y);
        }
        printf("\n");
        if (minemap[x][y] == '*') {
            printf("BOMB! Mine-Reveal-Map: \n");
            display_mine(cur, mlst);
            display_board(cur);
            return;
        } else {
            --left;
            int val = count_mine(minemap, x, y);
            cur[x][y] = val + '0';
            display_board(cur);
        }
    }
    printf("\n");
    display_mine(cur, mlst);
    display_board(cur);
    printf("SUCCESS! Congrats :)!\n");
}


void play_mine_sweeping() {
    char custom;
    printf("Do you want Custom Mode (y/n)?");
    scanf(" %c", &custom);
    while (custom != 'y' && custom != 'n') {
        printf("INVALID. Please try again.\n");
        printf("Do you want Custom Mode (y/n)?");
        scanf(" %c", &custom);
    }
    if (custom == 'y') {
        printf("row (3-100):");
        scanf("%d", &row);
        while (row < 1 || row > 100) {
            printf("INVALID. Please try again.\n");
            printf("row (3-100):");
            scanf("%d", &row);
        }
        printf("col (3-100):");
        scanf("%d", &col);
        while (col < 1 || col > 100) {
            printf("INVALID. Please try again.\n");
            printf("col (3-100):");
            scanf("%d", &col);
        }
        printf("# of mines (1-row*col):");
        scanf("%d", &num);
        while (num < 1 || num > row*col) {
            printf("INVALID. Please try again.\n");
            printf("# of mines (1-row*col):");
            scanf("%d", &num);
        }
    }
    struct llist *mines = mlst_create();
    char **minemap = malloc(sizeof(char) * (row+1) * (col+1));
    char **cur = malloc(sizeof(char) * (row+1) * (col+1));
    init_board(minemap, cur);
    display_board(cur);
    set_mine(minemap, mines);
    mine_sweeping(minemap, cur, mines);
    free(minemap);
    free(cur);
    mlst_destroy(mines);
}
