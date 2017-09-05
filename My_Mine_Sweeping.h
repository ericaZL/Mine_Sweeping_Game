// A module for a Mine Sweeping game

extern int row;
extern int col;
extern int num;

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

// set_mine(minemap) prints the board for the current state of the game
// effects: mutates minemap
// time: O(n), where n is the number of mines
void set_mine(char minemap[row][col]);

// mine_count(minemap, x, y) returns the number of mines around the center mine[x][y] in a 3x3 square (if applicable) within the board
// requires: 3 <= x <= row, 3 <= y <= col
// time: O(1)
int mine_count(char minemap[row][col], int x, int y);

// mine_sweeping(minemap, cur) allows the user to enter guesses for mine sweeping
// effects: displays messages, reads in inputs, may mutate cur
// time: O(mnk), where m is row, n is col, k is the number of mines
void mine_sweeping(char minemap[row][col], char cur[row][col]);

// play_mine_sweeping() plays the game of mine sweeping
// effects: displays messages, reads in inputs, allocates memory
// time: O(mnk), where m is row, n is col, k is the number of mines
void play_mine_sweeping();
