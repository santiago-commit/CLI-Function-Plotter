#include <iostream>
#include <math.h>

using namespace std;

void initialize(int M[41][41], int f, int c){
	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++)
			M[i][j] = 0;
	}
}

void fill(int M[41][41], int f, int c){
	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++){
			if(M[i][j] != 999){
				if(j == (c/2))
					M[i][j] = (i - (f/2)) * -1;
				if(i == (f/2))
					M[i][j] = j - (c/2);
			}
		}
	}
}

void show(int M[41][41], int f, int c){
	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++){
			if(M[i][j] < -9)
				cout<<" "<<M[i][j];
			else if((M[i][j] < 0) && (M[i][j] > -10))
				cout<<"  "<<M[i][j];
			else if((M[i][j] >= 0) && (M[i][j] < 10))
				cout<<"   "<<M[i][j];
			else if((M[i][j] > 9) && (M[i][j] < 100))
				cout<<"  "<<M[i][j];
			else if(M[i][j] > 99)
				cout<<" "<<M[i][j];
		}
		cout<<endl;
	}
}

void function(int y, int M[41][41], int f, int c){
	for(int x = -(c/2); x <= (c/2); x++){
		if (x != 0){
			y = sin(x) * 10; //<--- The function
			if((((f/2)- y) <= f) && (((f/2)- y) >= 0))
				M[ ((f/2)- y) ][ ((c/2)+ x) ] = 999;
		}
	}
}

int main(){
	int y = 0, M[41][41], f = 41, c = 41;

	initialize(M, f, c);
	function(y, M, f, c);
	fill(M, f, c);
	show(M, f, c);

	return 0;
}
