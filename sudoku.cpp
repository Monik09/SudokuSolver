#include<iostream>
using namespace std;
#define MAX 9
int a[MAX][MAX],b[MAX][MAX],emptrow,emptcol;

void createsudoku(){
    cout<<"Press 0 to represent empty cell"<<endl;
  for(int i=0;i<MAX;i++){
      for(int j=0;j<MAX;j++){
          cin>>a[i][j];
      }
  }  
}
int findemptycell(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(a[i][j]==0){
                emptcol=j;
                emptrow=i;
                return 0;
            }
        }
    }
    return 1;
}
int valid(int i,int j,int key){
    for(int k=0;k<9;k++){
        if(a[k][j]==key || a[i][k]==key){
            return 0;
        }
    }
    //for a particular box
    for(int q=i-i%3;q<(i-i%3)+3;q++){
        //checking row of a box
        for(int w=j-j%3;w<(j-j%3)+3;w++){
            //in the column of particular box
            if(a[q][w]==key){
                return 0;
            }
        }
    }
    return 1;
}
int solution(){
    if(findemptycell()){
        //if we find a empty cell we will again solve the sudoku,otherwise it means that no empty cell is left and thus sudoku is solved 
        return 1;
    }
    int prevr,prevc;
    for(int i=1;i<=9;i++){
        int r=valid(emptrow,emptcol,i);
        if(r==1){
            a[emptrow][emptcol]=i;
            prevc=emptcol;  prevr=emptrow;
            //assigning the values of the column and row of empty cell so as to keep the track of the cell modified while guessing the 
            //correct value in that empty cell
            int s=solution();
            if(s==1)
                return 1;
             //if s==0 then we will unassign the  value of cell which was being checked by assigning values to zero
            emptrow=prevr;  emptcol=prevc;
            a[emptrow][emptcol]=0;
        }
    }
    return 0;
}

void displaysudoku(){
  /*  for(int i=0;i<6;i++)
    cout<<"__";
    cout<<endl;
    */
    cout<<"_____________________________________\n";
    for(int i=0;i<MAX;i++){
        cout<<"|";
           for(int j=0;j<MAX;j++){
               cout<<"_";
               if(a[i][j]==0)   cout<<".";
               else             cout<<a[i][j];
               cout<<"_"<<"|";
        }
        cout<<endl;
    }
}

int main(){
    cout<<"\n------------------------------------This is my C++ project------------------------------------";
    cout<<"\n         ------------Now, Enter data of sudoku whose solution you want------------\n";
    createsudoku();
    cout<<"\nThe sudoku whose anser is to be determined is:\n";
    displaysudoku();
    
    if(solution()==1){
        cout<<"\nThe solution of the above given sudoku is:\n";
    displaysudoku();
    cout<<endl;
    }
    else
    {
        cout<<"No solution exists\n"<<endl;
    }
    
return 0;
}
