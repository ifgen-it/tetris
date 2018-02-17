// auto tetris

#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h> //nanosleep

wchar_t Sym1 = L'@';
wchar_t Sym2= L'♡';
wchar_t Space = L' ';

// nanosleep parametrs:
	timespec tw = {0, 40000000 };
	timespec tr;
	
	// Display dimensions
const int Rows = 45;  
const int Cols = 60;

	// display
	wchar_t Disp[Rows][Cols];

// current figure position
int CurRows = 0;
int CurCols = 16;

// Figures
const int FRows = 4;
const int FCols = 5;

struct FORM {
	char Data[FRows][FCols];
};


void PrintArr(wchar_t Arr[][Cols], int Rows, int Cols );
void FillArr( wchar_t Arr[][Cols], int Rows, int Cols );
void MakeField( wchar_t Arr[][Cols], int Rows, int Cols );

void BornFigure( char Figure[][FCols], int FCols);
void MoveFigure( char Figure[][FCols],  int FCols);
bool CanMove( char Figure[][FCols],  int FCols);

using namespace std;

int main(){
	// array of figures
	FORM Fig[8];
	
	strcpy(Fig[0].Data[0],"    ");
	strcpy(Fig[0].Data[1],"1   ");
	strcpy(Fig[0].Data[2],"1   ");
	strcpy(Fig[0].Data[3],"1111");
	
	strcpy(Fig[1].Data[0],"   1");
	strcpy(Fig[1].Data[1],"   1");
	strcpy(Fig[1].Data[2],"   1");
	strcpy(Fig[1].Data[3]," 111");
	
	strcpy(Fig[2].Data[0],"111 ");
	strcpy(Fig[2].Data[1],"1   ");
	strcpy(Fig[2].Data[2],"1   ");
	strcpy(Fig[2].Data[3],"    ");
	
	strcpy(Fig[3].Data[0],"   1");
	strcpy(Fig[3].Data[1],"   1");
	strcpy(Fig[3].Data[2],"   1");
	strcpy(Fig[3].Data[3],"   1");
	
	strcpy(Fig[4].Data[0],"1   ");
	strcpy(Fig[4].Data[1],"1   ");
	strcpy(Fig[4].Data[2],"1   ");
	strcpy(Fig[4].Data[3],"1   ");
	
	strcpy(Fig[5].Data[0],"1111");
	strcpy(Fig[5].Data[1],"    ");
	strcpy(Fig[5].Data[2],"    ");
	strcpy(Fig[5].Data[3],"   ");
	
	strcpy(Fig[6].Data[0],"111 ");
	strcpy(Fig[6].Data[1],"111 ");
	strcpy(Fig[6].Data[2],"    ");
	strcpy(Fig[6].Data[3],"    ");
	
	strcpy(Fig[7].Data[0],"1111");
	strcpy(Fig[7].Data[1],"1  1");
	strcpy(Fig[7].Data[2],"1  1");
	strcpy(Fig[7].Data[3],"    ");
	
	srand(time(0));
   
   // loading game
   cout << "Loading..."<< endl;
   //delay , ready for start
   for (int i = 0; i < 10; i ++){
   	 nanosleep(&tw, &tr);
   }
       system("cls");
   	MakeField(Disp, Rows, Cols);
   	
   	// figure start rate
   	int MinCol = 2;
   	int MaxCol = Cols - 1 - FCols; //54
   	
   	while ( true ){
   		// chose figure
   		int ch = rand()%8;
       // fugure start rate
       CurRows = 0;
       CurCols = MinCol + rand()%(MaxCol-MinCol+1);
       
       // figure starts
   	BornFigure(Fig[ch].Data,  FCols );
   	PrintArr(Disp, Rows, Cols);
   	nanosleep(&tw, &tr);
   	
   	while( true ){
   		if (CanMove(Fig[ch].Data, FCols)){
   	MoveFigure(Fig[ch].Data,  FCols );
   		}
   		else break;
        system("cls");
   	PrintArr(Disp, Rows, Cols);
   	nanosleep(&tw, &tr);
   	}
  
   	}
   	
	return 0;
}
void BornFigure( char Figure[][FCols],  int FCols){
	for (int i = 0; i < FRows; i++){
		for (int j = 0; j < FCols-1; j++){
			if (Figure[i ] [ j ] == '1'){
	 Disp [ CurRows+i][CurCols+ j ] = Sym1;
			}
	
		}
	}
}

void MoveFigure( char Figure[][FCols],  int FCols){
	//clean current placement
	for (int i = 0; i < FRows; i++){
		for (int j = 0; j < FCols-1; j++){
			if (Figure[i ] [ j ] == '1'){
 Disp [ CurRows+i][CurCols+ j ] = Space;
			}
		}
	}
	CurRows++;
	// new placement
	BornFigure(Figure,  FCols );
}


bool CanMove( char Figure[][FCols],  int FCols){
	for (int k=0;k<FCols-1;k++){
		for (int y=FRows-1; y>=0;y--){
			if (Figure[y][k] == '1'){
if (Disp [CurRows+y+1][CurCols+k] == Sym1) return false;
   else break;
			}
		}
	}
	return true;
}



void FillArr( wchar_t Arr[][Cols], int Rows, int Cols ){
		// fill Disp 
	wchar_t* p = Arr[0];
	for (int i = 0; i < Rows*Cols; i++){
		*p = Sym1;
		p++;
	}
}
void MakeField(wchar_t Arr[][Cols], int Rows, int Cols ){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			if ( j>1&& j<Cols-2&&i<Rows-1){
				Arr[i][j] = Space;
			}
			else Arr[i][j] = Sym1;
		
		}
	}
}

void PrintArr(wchar_t Arr[][Cols], int Rows, int Cols ){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			wcout << Arr[i][j] ;
		}
		//	nanosleep(&tw, &tr);
		
		cout << endl;
	}
}

