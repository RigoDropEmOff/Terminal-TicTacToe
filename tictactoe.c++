#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TicTacToeBoard{
    private:
    char board [3][3];
    
    public:
    TicTacToeBoard(){
        InitializeBoard(); //automatically initialized
    }
    
    void InitializeBoard(){
        for(int i =0; i < 3; i++){
        for(int j =0; j <3; j++){
            board [i][j] = ' ';
       }
    }
}
    void DisplayBoard(){
        cout<<"-------------"<<endl;
        for(int i =0; i <3; i++){
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |" << endl;
        cout << "-------------" << endl;
    }
    }
    
    bool MakeMove(char player, int row, int col){
        if(row < 0 || row >= 3 || col < 0 || col >= 3){
            cout<<"Imvalid move! Choose a row and column between 0 and 2."<<endl;
            return false;
        }
        if(board[row][col] != ' '){
            cout << "Cell already occupied! Choose another one."<<endl;
            return false;
        }
        board[row][col] = player;
        return true;
    }
    bool CheckWin(char player){
        //check rows and columns
        for(int i =0; i < 3; i++){
            if((board[i][0] == player && board[i][1] == player && board[i][2] == player)||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)){
                return true;
            }
        }
        //check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            return true;
    }
    return false;
    }
    
    bool CheckDraw(){
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == ' '){
                    return false;
                }
            }
        }
        return true;
    }
    
};

int main()
{
    char playAgain;
    
    do{
    TicTacToeBoard game;
    char currentPlayer = 'X';
    int row, col;
    
    while(true){
    game.DisplayBoard();
    cout<<"Player "<< currentPlayer << ", enter your move (row and column)."<<endl;
    cin>>row>>col;
    
    if(game.MakeMove(currentPlayer, row, col)){
        if(game.CheckWin(currentPlayer)){
            game.DisplayBoard();
            cout<<"Player "<<currentPlayer<<" Wins!!"<<endl;
            break;
        }else if (game.CheckDraw()){
            game.DisplayBoard();
            cout << "The game is a draw!" <<endl;
            break;
        }
        //alternate the Player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
cout<<"Do you want to play again? (y/n): ";
cin>>playAgain;

} while (playAgain == 'y'|| playAgain == 'Y');
    return 0;
}