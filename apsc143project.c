#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//declare global variables
char hiddenCells[10][10];
char revealedCells[10][10];


//function declaration
void printGrid();

int check(int row, int col);

void flag(int row, int col);

int checkWin();

//mainline
int main() {

    //seed random numbers
    srand(2);

    //initialize variables
    int startMines = 10;
    int min = 0;
    int range = 10;
    int xCell;
    int yCell;
    char checkOrFlag;
    int mine = 1;

    //fill the revealed grid with only *
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            revealedCells[i][j] = '*';
        }
    }

    //fill the hidden grid with only 0
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            hiddenCells[i][j] = '0';
        }
    }

    //add the mines into the grid
    while (startMines > 0){
        int x = rand() % range + min;
        int y = rand() % range + min;
        if (hiddenCells[x][y] != 'M'){
            hiddenCells[x][y] = 'M';
            startMines --;
        }
    }

    //change all the numbers in the grid to reflect the number of adjacent mines, use isdigit() to only increment numbers
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (hiddenCells[i][j] == 'M') {
                //not on a corner or edge
                if (i > 0 && i < 9 && j > 0 && j < 9) {
                    if (isdigit(hiddenCells[i - 1][j - 1]))
                        hiddenCells[i - 1][j - 1]++;
                    if (isdigit(hiddenCells[i][j - 1]))
                        hiddenCells[i][j - 1]++;
                    if (isdigit(hiddenCells[i + 1][j - 1]))
                        hiddenCells[i + 1][j - 1]++;
                    if (isdigit(hiddenCells[i - 1][j]))
                        hiddenCells[i - 1][j]++;
                    if (isdigit(hiddenCells[i + 1][j]))
                        hiddenCells[i + 1][j]++;
                    if (isdigit(hiddenCells[i - 1][j + 1]))
                        hiddenCells[i - 1][j + 1]++;
                    if (isdigit(hiddenCells[i][j + 1]))
                        hiddenCells[i][j + 1]++;
                    if (isdigit(hiddenCells[i + 1][j + 1]))
                        hiddenCells[i + 1][j + 1]++;
                } else {
                    //left edge
                    if (i == 0 && j < 9 && j > 0 ) {
                        if (isdigit(hiddenCells[i][j - 1]))
                            hiddenCells[i][j - 1]++;
                        if (isdigit(hiddenCells[i + 1][j - 1]))
                            hiddenCells[i + 1][j - 1]++;
                        if (isdigit(hiddenCells[i + 1][j]))
                            hiddenCells[i + 1][j]++;
                        if (isdigit(hiddenCells[i][j + 1]))
                            hiddenCells[i][j + 1]++;
                        if (isdigit(hiddenCells[i + 1][j + 1]))
                            hiddenCells[i + 1][j + 1]++;
                    }
                    //top edge
                    if (i < 9 && i > 0 && j == 0) {
                            hiddenCells[i + 1][j - 1]++;
                        if (isdigit(hiddenCells[i - 1][j]))
                            hiddenCells[i - 1][j]++;
                        if (isdigit(hiddenCells[i + 1][j]))
                            hiddenCells[i + 1][j]++;
                        if (isdigit(hiddenCells[i - 1][j + 1]))
                            hiddenCells[i - 1][j + 1]++;
                        if (isdigit(hiddenCells[i][j + 1]))
                            hiddenCells[i][j + 1]++;
                        if (isdigit(hiddenCells[i + 1][j + 1]))
                            hiddenCells[i + 1][j + 1]++;
                    }
                    //right edge
                    if (i == 9 && j < 9 && j > 0) {
                        if (isdigit(hiddenCells[i - 1][j - 1]))
                            hiddenCells[i - 1][j - 1]++;
                        if (isdigit(hiddenCells[i][j - 1]))
                            hiddenCells[i][j - 1]++;
                        if (isdigit(hiddenCells[i - 1][j]))
                            hiddenCells[i - 1][j]++;
                        if (isdigit(hiddenCells[i - 1][j + 1]))
                            hiddenCells[i - 1][j + 1]++;
                        if (isdigit(hiddenCells[i][j + 1]))
                            hiddenCells[i][j + 1]++;
                    }
                    //bottom edge
                    if (i < 9 && i > 0 && j == 9) {
                        if (isdigit(hiddenCells[i - 1][j - 1]))
                            hiddenCells[i - 1][j - 1]++;
                        if (isdigit(hiddenCells[i][j - 1]))
                            hiddenCells[i][j - 1]++;
                        if (isdigit(hiddenCells[i + 1][j - 1]))
                            hiddenCells[i + 1][j - 1]++;
                        if (isdigit(hiddenCells[i - 1][j]))
                            hiddenCells[i - 1][j]++;
                        if (isdigit(hiddenCells[i + 1][j]))
                            hiddenCells[i + 1][j]++;
                    }
                    //top left corner
                    if (i == 0 && j == 0) {
                        if (isdigit(hiddenCells[i + 1][j]))
                            hiddenCells[i + 1][j]++;
                        if (isdigit(hiddenCells[i][j + 1]))
                            hiddenCells[i][j + 1]++;
                        if (isdigit(hiddenCells[i + 1][j + 1]))
                            hiddenCells[i + 1][j + 1]++;
                    }
                    //top right corner
                    if (i == 9 && j == 0) {
                        if (isdigit(hiddenCells[i - 1][j]))
                            hiddenCells[i - 1][j]++;
                        if (isdigit(hiddenCells[i - 1][j + 1]))
                            hiddenCells[i - 1][j + 1]++;
                        if (isdigit(hiddenCells[i][j + 1]))
                            hiddenCells[i][j + 1]++;
                    }
                    //bottom left corner
                    if (i == 0 && j == 9) {
                        if (isdigit(hiddenCells[i][j - 1]))
                            hiddenCells[i][j - 1]++;
                        if (isdigit(hiddenCells[i + 1][j - 1]))
                            hiddenCells[i + 1][j - 1]++;
                        if (isdigit(hiddenCells[i + 1][j]))
                            hiddenCells[i + 1][j]++;
                    }
                    //bottom right corner
                    if (i == 9 && j == 9) {
                        if (isdigit(hiddenCells[i - 1][j - 1]))
                            hiddenCells[i - 1][j - 1]++;
                        if (isdigit(hiddenCells[i][j - 1]))
                            hiddenCells[i][j - 1]++;
                        if (isdigit(hiddenCells[i - 1][j]))
                            hiddenCells[i - 1][j]++;
                    }
                }
            }
        }
    }

    //game loop. ends when win condition met, or a mine is hit
    while (!checkWin(revealedCells, hiddenCells) && mine == 1){
        //print the grid
        printGrid(revealedCells);

        //get user input
        printf("Enter 'c' for check cell, 'f' for flag cell.\nEnter command & cell row col:");
        scanf(" %c %d %d", &checkOrFlag, &xCell, &yCell);
        printf("\n");

        //check if checking cell or flagging cell
        if (checkOrFlag == 'c'){
            mine = check(xCell, yCell);
        }
        if (checkOrFlag == 'f') {
            flag(xCell, yCell);
        }
    }

    //game ends
    printGrid();
    if (mine == 0){
        printf("You hit a mine, game over.");
    }
    else{
        printf("Congratulations! You win!");
    }
    return 0;
}

//prints the revealed cell grid
void printGrid(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%c  ", revealedCells[i][j]);
        }
        printf("\n");
    }
}

//checks the cell and reveals it, returns 0 if its a mine
int check(int i, int j) {
    int mine;
    if (hiddenCells[i][j] == 'M') {
        revealedCells[i][j] = hiddenCells[i][j];
        return 0;
    } else {
        if (hiddenCells[i][j] == '0') {
            revealedCells[i][j] = hiddenCells[i][j];

            if (revealedCells[i - 1][j - 1] != hiddenCells[i - 1][j - 1] && j > 0 && i > 0){
                revealedCells[i - 1][j - 1] = hiddenCells[i - 1][j - 1];
                check(i - 1, j - 1);
            }

            if (revealedCells[i][j - 1] != hiddenCells[i][j - 1] && j > 0){
                revealedCells[i][j - 1] = hiddenCells[i][j - 1];
                check(i, j - 1);
            }

            if (revealedCells[i + 1][j - 1] != hiddenCells[i][j] && j > 0 && i < 9){
                revealedCells[i][j] = hiddenCells[i][j];
                check(i + 1, j - 1);
            }

            if (revealedCells[i - 1][j] != hiddenCells[i - 1][j] && i > 0){
                revealedCells[i - 1][j] = hiddenCells[i - 1][j];
                check(i - 1, j);
            }

            if (revealedCells[i + 1][j] != hiddenCells[i + 1][j] && i < 9){
                revealedCells[i + 1][j] = hiddenCells[i + 1][j];
                check(i + 1, j);
            }

            if (revealedCells[i - 1][j + 1] != hiddenCells[i - 1][j + 1] && i > 0 && j < 9){
                revealedCells[i - 1][j + 1] = hiddenCells[i - 1][j + 1];
                check(i - 1, j + 1);
            }

            if (revealedCells[i][j + 1] != hiddenCells[i][j + 1] && j < 9){
                revealedCells[i][j + 1] = hiddenCells[i][j + 1];
                check(i, j + 1);
            }

            if (revealedCells[i + 1][j + 1] != hiddenCells[i + 1][j + 1] && i < 9 && j < 9){
                revealedCells[i + 1][j + 1] = hiddenCells[i + 1][j + 1];
                check(i + 1, j + 1);
            }

        }
        else{
            revealedCells[i][j] = hiddenCells[i][j];
        }
        return 1;

    }
}

//flags the cell
void flag(int x, int y){
    revealedCells[x][y] = 'F';
}

//checks if the win condition was met
int checkWin(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (hiddenCells[i][j] != revealedCells[i][j] && hiddenCells[i][j] != 'M'){
                //printf("%c %c\n", hiddenCells[i][j], revealedCells[i][j]);
                return 0;

            }
        }
    }
    return 1;
}