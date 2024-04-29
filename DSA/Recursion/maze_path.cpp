#include<iostream>
using namespace std;
 
int mazePath(int sr, int sc, int er, int ec){
    if (sr>er || sc>ec){
        return 0;
    }
    if (sr==er && sc==ec){
        return 1;
    }

    int rightways = mazePath(sr, sc+1, er, ec);
    int downways = mazePath(sr+1, sc, er, ec);

    return rightways+downways;
}

int mazePath2(int er, int ec){
    if (er<1 || ec<1){
        return 0;
    }
    if (er==1 && ec==1){
        return 1;
    }

    int rigthways = mazePath2(er, ec-1);
    int downways = mazePath2(er-1, ec);

    return rigthways+downways;
}

void printPath(int sr, int sc, int er, int ec, string s){
    if (sr>er || sc>ec){
        return;
    }
    if (sr==er && sc==ec){
        cout << "The ways are: (using 5 parameters) " << s << endl;
    }
    printPath(sr, sc+1, er, ec, s+'R'); //right
    printPath(sr+1, sc, er, ec, s+'D'); //down
}

void printPath2(int er, int ec, string s){
    if (er<1 || ec<1){
        return;
    }
    if (er==1 && ec==1){
        cout << "The ways are: (using 3 parameters) " << s << endl;
        return;
    }
    printPath2(er, ec-1, s+'R'); //right
    printPath2(er-1, ec, s+'D'); //column

}

int main(){
    int row, column;
    cout << "Enter the value of row and column of the maze: ";
    cin >> row >> column;

    cout << "The number of ways to cross the maze using four parameters are: " << mazePath(1, 1, row, column) << endl;
    cout << "The number of ways to cross the maze using two parameters are: " << mazePath2(row, column) << endl;
    printPath(1, 1, row, column, " ");
    printPath2(row, column, " ");


}