// A module for the Mine Sweeper game

extern int row;
extern int col;
extern int num;

struct posn;
struct llnode;
struct llist;

// NOTE: All of the following functions REQUIRE:
//       1 <= row <= 100, 1 <= col <= 100, 1 <= num <= 10000,

// init_board(minemap, cur) initiates the board for the game
// effects: mutates minemap and cur
// time: O(mn), where m is row, n is col
void init_board(char minemap[row][col], char cur[row][col]);

// display_board(cur) prints the board for the current state of the game
// effects: display the board for the game
// time: O(mn), where m is row, n is col
void display_board(char cur[row][col]);

// mlst_create() returns a new empty linked list for storing mines' positions
// effects : allocates memory (caller must call mlst_destroy)
// time: O(1)
struct llist *mlst_create();

// mlst_destroy(mlst) frees all dynamically allocated memory 
// effects: the memory at mlst is invalid (freed)
// time: O(n), where n is the length of mlst
void mlst_destroy(struct llist *mlst);

// mlst_add_back(p, mlst) adds position information p of a newly generated mine 
//   to the back of mlst
// effects : allocates memory (caller must call mlst_destroy)
// time: O(1)
void mlst_add_back(struct posn p, struct llist *mlst);

// set_mine(minemap, mlst) and generates mines randomly and stores 
//   position information of each new mine p into mlst and returns the queue mlst
// effects: mutates minemap
struct llist *set_mine(char minemap[row][col], struct llist *mlst) {

// display_mine(cur[row][col], mlst) displays all mines' positions stored in mlst on cur
// effects: mutates cur
// time: O(n), where n is the length of mlst
char** display_mine(char cur[row][col], struct llist *mlst);

// count_mine(char minemap[row][col], int x, int y) returns the number of mines 
//   around the center mine[x][y] in a 3x3 square (if applicable) within the board
// requires: 3 <= x <= row, 3 <= y <= col
// time: O(1)
int count_mine(char minemap[row][col], int x, int y);

// mine_sweeping(minemap, cur, mlst) allows the user to enter guesses for mine sweeping
// effects: displays messages, reads in inputs, may mutate cur
// time: O(mnk), where m is row, n is col, k is the number of mines
void mine_sweeping(char minemap[row][col], char cur[row][col], struct llist *mlst);

// play_mine_sweeping() plays the game of mine sweeping
// effects: displays messages, reads in inputs, allocates memory
// time: O(mnk), where m is row, n is col, k is the number of mines
void play_mine_sweeping();
