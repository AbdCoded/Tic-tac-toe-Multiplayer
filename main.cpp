#include <iostream>


using namespace std;

void printBoard(int b[][3], int rows){

    cout << "-------------" << endl;
    for(int i = 0; i < 3; i++){
        cout << "|";
        for(int j = 0; j < 3; j++){
            if(b[i][j] == 0)
                cout << "   ";
            else if(b[i][j] == 1)
                cout << " x ";
            else
                cout << " o ";
            cout << "|";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool checkWinner(int b[][3], int rows, int& who){
    for(int i = 0; i < 3; i++){
        if(b[i][0] == b[i][1] && b[i][1] == b[i][2] && (b[i][0] != 0)){
            who = b[i][0];
            return true;
        }
        if(b[0][i] == b[1][i] && b[1][i] == b[2][i] && (b[0][i] != 0)){
            who = b[0][i];
            return true;
        }
    }

    if(b[0][2] == b[1][1] && b[1][1] == b[2][0] && (b[0][2] != 0)){
        who = b[0][2];
        return true;
    }
    if(b[0][0] == b[1][1] && b[1][1] == b[2][2] && (b[0][0] != 0)){
        who = b[0][0];
        return true;
    }

    return false;
}

int main() {
    system("cls");


    int board[3][3] = {0}, player = 1, row, col, who;
    bool winner = 0;

    printBoard(board, 3);
    for(int i = 1; i <= 9 && winner == 0; i++)
    {
        if(player == 1)
        {
            cout << "Player 1's turn:\n";
            cin >> row >> col;
            while(board[row][col] != 0){
                cout << "Invalid Input:\n";
                cin >> row >> col;
            }
            system("cls");
            board[row][col] = 1;
            player = 2;
        }
        else{
            cout << "Player 2's turn:\n";
            cin >> row >> col;
            while(board[row][col] != 0){
                cout << "Invalid Input:\n";
                cin >> row >> col;
            }
            system("cls");
            board[row][col] = 2;
            player = 1;
        }
        printBoard(board, 3);
        winner = checkWinner(board, 3, who);
    }
    if(winner == 1)
        cout << "Player " << who << " is the winner!\n";
    else
        cout << "Draw!\n";

    system("pause");
    return 0;
}
