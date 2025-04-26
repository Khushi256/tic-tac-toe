
#include<iostream>

using namespace std;

char array[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char row;
char column;
char turn='x';
string A=" ";
string B=" ";
char value;
bool tie;

// structure of the game
void structure(){
     cout<<"     |      |    \n";
    cout<<"  "<<array[0][0]<<"  | "<<" "<<array[0][1]<<"   | "<<" "<<array[0][2]<<" \n";
    cout<<"_____|______|_____\n";
    cout<<"     |      |    \n";
    cout<<"  "<<array[1][0]<<"  | "<<" "<<array[1][1]<<"   | "<<" "<<array[1][2]<<" \n";
    cout<<"_____|______|_____\n";
    cout<<"     |      |    \n";
    cout<<"  "<<array[2][0]<<"  | "<<" "<<array[2][1]<<"   | "<<" "<<array[2][2]<<" \n";
    cout<<"     |      |    \n";
}
//defining the index
void index(){
    if(turn=='x'){
        cout<<A<<" "<<"Enter your choice"<<endl;
        cin>>value;
    }
    if(turn=='0'){
        cout<<B<<" "<<"Enter your choice"<<endl;
        cin>>value;
    }
    switch(value){
        case '1':
        row=0;
        column=0;
        break;

        case '2':
        row=0;
        column=1;
        break;
        
        case '3':
        row=0;
        column=2;
        break;
        
        case '4':
        row=1;
        column=0;
        break;
        
        case '5':
        row=1;
        column=1;
        break;
        
        case '6':
        row=1;
        column=2;
        break;
        
        case '7':
        row=2;
        column=0;
        break;
        
        case '8':
        row=2;
        column=1;
        break;
        
        case '9':
        row=2;
        column=2;
        break;
         
        default :
        cout<<" Invalid input"<<endl;
        break;

    }
//check for the availibility of index
    if(turn=='x' && array[row][column]!='x' && array[row][column]!='0'){
        array[row][column]='x';
        turn='0';
    }
    else if(turn=='0' && array[row][column]!='x' && array[row][column]!='0'){
        array[row][column]='0';
        turn='x';
    }
    else{
        cout<<"Oops! No space"<<endl;
    }
}    
//condition for win or continuation of game.
bool win(){
    for(int i=0;i<3;i++){
        if(array[i][0]==array[i][1] && array[i][0]==array[i][2] || array[0][i]==array[1][i] && array[0][i]==array[2][i]){
            return true;
        }
        if(array[0][0]==array[1][1] && array[0][0]==array[2][2] || array[0][2]==array[1][1] && array[0][2]==array[2][0]){
            return true;
        }
    }
    //condition to continuation of the game.
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(array[i][j]!='x' && array[i][j]!='0'){
                return false;
            }
        }
    }
    tie=true;
    return false;
}

int main(){
    
    //taking input from user.
    cout<<"Enter name of the first player "<<" "<<endl;
    getline(cin,A);
    cout<<"Enter name of the second player"<<" "<<endl;
    getline(cin,B);
    cout<<A<<" "<<"will play first!!"<<endl;
    cout<<B<<" "<<"will play next!!"<<endl;
   
    //winning statement
    while(!win()){
        structure();
        index();
        win();
    }    
    structure();
    if(turn=='0' && tie==false){
        cout<<A<<" "<<"WINS!!"<<endl;
    }
    else if(turn=='x' && tie==false){
        cout<<B<<" "<<"WINS!!"<<endl;
    }
    else{
        cout<<"It's a draw"<<endl;
    }
    return 0;
}