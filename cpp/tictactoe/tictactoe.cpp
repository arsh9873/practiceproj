//simple 2 player implementation
#include <bits/stdc++.h>
using namespace std;
class game{
private:
    char board[3][3];
    char p0,p1;
    int row,col;
public:
    void init();
    void board_display();
    bool check_move();
    bool make_move(char);
    bool check_result(char);
    void play();
    bool full();
};
void game::init(){
    cout<<"\nenter symbol for player 0:";
    cin>>p0;
    cout<<"\nenter symbol for player 1:";
    cin>>p1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';
    board_display();
}
bool game::full(){
    bool flag=true;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ')
                flag=false;
    if(flag==true)
        return true;//its full
    else    
        return false;
}
bool game::check_move(){
    if(board[row][col]!=' ')
        return false;
    else    
        return true;
}   
bool  game::make_move(char p){
    cout<<"\nenter row and collum:";
    cin>>row>>col;
    if(check_move()==true){
        board[row][col]=p;
        board_display();
        return true;
    }
    else{
        return false;
    }    
}
bool game::check_result(char p){
    //checking row 
    unsigned int i;
    bool flag=true;
    for(i=0;i<3;i++){
        int col_idx=(col+i)%3;
        if(board[row][col_idx]!=p)
            flag=false;
    }
    if(flag==true)
        return true;
    else
        flag=true;
        //checking col;
    for(i=0;i<3;i++){
        int row_idx=(row+i)%3;
        if(board[row_idx][col]!=p)
            flag=false;
    }
    if(flag==true)
        return true;
    else
        flag=true;
    if(row==col){
        //checking left diagonal
        for(i=0;i<3;i++){
            int row_idx=(row+i)%3;
            int col_idx=(col+i)%3;
            if(board[row_idx][col_idx]!=p)
                flag=false;
        }
        if(flag==true)
            return true;
        else
            flag=true;
    }
    if(row==0 and col==2 or row==2 and col==0){
        //checking right diagonal
        for(i=0;i<3;i++){
            int row_idx=(row+i)%3;
            int col_idx=(col+3-i)%3;
            if(board[row_idx][col_idx]!=p)
                flag=false;
        }
        if(flag==true)
            return true;
        else
            flag=true;
    }
        return false;//gone through all the checks and flag is still true
}
void game::board_display(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<" | ";
        }
        cout<<endl;
    }
}
void game::play(){
    init();
    while(1){
        cout<<"\nplayer0:\n";
        while(make_move(p0)==false);
        if(check_result(p0)==true){
            cout<<"\nplayer0 wins!";
            return;
        }
        if(full()==true){
            cout<<"\nDraw";
            return;
        }
        cout<<"\nplayer1:\n";
        while(make_move(p1)==false);
        if(check_result(p1)==true){
            cout<<"\nplayer1 wins!";
            return;
        }
    }
    cout<<"\nDRAW!";
    return;
}
int main(){
    game g;
    g.play();
    return 0;
}
