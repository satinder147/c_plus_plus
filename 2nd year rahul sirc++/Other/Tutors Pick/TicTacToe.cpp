//Tic Tac Toe Game

#include <iostream>
#define EMPTY char(222)

using namespace std;

class Canvas
{
public:
    char mat[3][3];

    Canvas();
    void drawCanvas();
    void clearCanvas();
    int updateCanvas(int r, int c, char symbol);
};

Canvas :: Canvas()
{
    int i, j;
    for(i =0 ;i< 3; i++)
        for(j=0; j< 3; j++)
            mat[i][j] = EMPTY;
}

void Canvas :: clearCanvas()
{
    int i, j;
    for(i =0 ;i< 3; i++)
        for(j=0; j< 3; j++)
            mat[i][j] = EMPTY;
}

void Canvas :: drawCanvas()
{
    int i, j;
    
    for(i =0 ; i< 3; i++)
    {
        cout<<"\n\n";
        for(j =0 ; j< 3; j++)
        {
            cout.width(5);
            cout<<mat[i][j];
        }
    }
    cout<<"\n\n";

}

int Canvas :: updateCanvas(int r, int c, char symbol)
{
    if(r >=0 && r <=2 && c >=0 && c <=2)
    {
        if(mat[r][c] == EMPTY)
        {
            mat[r][c] = symbol;
            return 1;//true
        }
        else
            return 0;//false
    }
    else
        return 0;//false
}

class Game
{
    Canvas canvas;
public:
    void rules();
    void play();
    int checkWins(char symbol);
    int checkIsOver();
};

void Game :: rules()
{
    cout<<"\n rule 1";
    cout<<"\n rule 2";
    cout<<"\n rule 3";
}

void Game :: play()
{
    int r, c, flag;
    char symbol;

    rules();
    canvas.clearCanvas();
    do
    {
        do
        {
            symbol = 'X';
            canvas.drawCanvas();
            cout<<"\n player1 plays ";
            cout<<"\n enter row coordinate (0-2) ";
            cin>>r;
            cout<<"\n enter column coordinate (0-2) ";
            cin>>c;

            if(canvas.updateCanvas(r, c,symbol))
                flag = 0;
            else
            {
                cout<<"\n player 1 plays again";
                flag = 1;
            }
        }while(flag == 1);
        
        if(checkWins(symbol))
        {
            canvas.drawCanvas();
            cout<<"\n player 1 wins";
            flag = 99;
            break;
        }
        else if(checkIsOver())
        {
            canvas.drawCanvas();
            break;
        }
        
        flag = 0;
        do
        {
            symbol = 'O';
            canvas.drawCanvas();
            cout<<"\n player2 plays ";
            cout<<"\n enter row coordinate (0-2) ";
            cin>>r;
            cout<<"\n enter column coordinate (0-2) ";
            cin>>c;

            if(canvas.updateCanvas(r, c,symbol))
                flag = 0;
            else
            {
                cout<<"\n player 2 plays again";
                flag = 1;
            }
        }while(flag == 1);
        
        if(checkWins(symbol))
        {
            canvas.drawCanvas();
            cout<<"\n player 2 wins";
            flag = 99;
            break;
        }
    }while(! checkIsOver());
    
    if(flag != 99)
        cout<<"\n Its a Draw";
}

int Game :: checkWins(char symbol)
{
    if(canvas.mat[0][0]== symbol && canvas.mat[0][1] == symbol && canvas.mat[0][2] == symbol)
        return 1;
    if(canvas.mat[1][0]== symbol && canvas.mat[1][1] == symbol && canvas.mat[1][2] == symbol)
        return 1;
    if(canvas.mat[2][0]== symbol && canvas.mat[2][1] == symbol && canvas.mat[2][2] == symbol)
        return 1;
    
    if(canvas.mat[0][0]== symbol && canvas.mat[1][0] == symbol && canvas.mat[2][0] == symbol)
        return 1;
    if(canvas.mat[0][1]== symbol && canvas.mat[1][1] == symbol && canvas.mat[2][1] == symbol)
        return 1;
    if(canvas.mat[0][2]== symbol && canvas.mat[1][2] == symbol && canvas.mat[2][2] == symbol)
        return 1;
    
    if(canvas.mat[0][0]== symbol && canvas.mat[1][1] == symbol && canvas.mat[2][2] == symbol)
        return 1;
    if(canvas.mat[0][2]== symbol && canvas.mat[1][1] == symbol && canvas.mat[2][0] == symbol)
        return 1;

    return 0;
}

int Game :: checkIsOver()
{
    int i, j;
    for(i =0 ; i< 3; i++)
    {
        for(j=0; j< 3; j++)
        {
            if(canvas.mat[i][j] == EMPTY)
                return 0;//false
        }
    }
    return 1;//true
}




int main() 
{
    Game g;
    char ch;
    
    do
    {
        g.play();
        cout<<"\n Do you want to play again (y/n) ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}

