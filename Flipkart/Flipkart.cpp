// Flipkart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string> 
#include<fstream>
#define SIZE 8
#define QUEEN 'Q'
#define KNIGHT 'H'
#define PAWN 'P'
using namespace std;
char board[SIZE][SIZE][3] = {
	{ "WR", "WH", "WB", "WQ", "WK", "WB", "WH", "WR", },
{ "WP", "WP", "WP", "WP", "WP", "WP", "WP", "WP", },
{ "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", },
{ "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", },
{ "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", },
{ "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", },
{ "BP", "BP", "BP", "BP", "BP", "BP", "BP", "BP", },
{ "BR", "BH", "BB", "BQ", "BK", "BB", "BH", "BR", }
};

class Board
{
	
public:
	
	
	virtual void move(int ,int ,int ,int)=0;
	void display()
	{
		cout << endl << "******************** Latest Chess State *********************** :" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int k = 0; k <= 1; k++)
					if (board[i][j][k] == '\0')
						cout << "_";
					else
						cout << board[i][j][k];
				cout << " ";
			}
			cout << endl;
		}

	}
};
class Display:public Board
{
public:
	
	void move(int ,int ,int ,int )
	{

	}
};
 

class Queen:public Board
{
public:
	Queen()
	{


	}
	bool isValid(int i, int j)
	{
		if (i >= 0 && i < SIZE && j >= 0 && j < SIZE)
			return true;
		else
			return false;

	}
	void move(int s1,int s2,int d1,int d2)
	{
		//rows
		if ((isValid(d1, d2) == true) && (s1 == d1))
		{

			//check for obstacles
			int i = s2+1;
			while (i < d1)
			{
				if (board[i][d2][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i++;
			}
			i = s2-1;
			while (i > d1)
			{
				if (board[i][d2][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i--;
			}

 				//move 
				board[d1][d2][1] = QUEEN;
				board[d1][d2][0] = board[s1][s2][0];

				board[s1][s2][0] = '\0';
				board[s1][s2][1] = '\0';

		}

		//col
		if ((isValid(d1, d2) == true) && (s2 == d2))
		{
			//check for obstacles
			int i = s1 + 1;
			while (i < d1 && i<SIZE)
			{
				if (board[i][d2][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i++;
			}
			i = s1 - 1;
			while (i > d1 && i >=0)
			{
				if (board[i][d2][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i--;
			}

			//move 
			board[d1][d2][1] = QUEEN;
			board[d1][d2][0] = board[s1][s2][0];

			board[s1][s2][0] = '\0';
			board[s1][s2][1] = '\0';

		}

		//diagonals

		if ((d1 < s1 && d2 < s2))//upper left diagonal
		{
			//check for obstacles
			int i = s1-1, j = s2-1;
			while (i < d1 && i>=0 && j>=0)
			{
				if (board[i][j][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i--; j--;
			} 
		}

		else if ((d1 < s1 && d2 > s2))//upper right diagonal
		{
			//check for obstacles
			int i = s1 - 1, j = s2 + 1;
			while (i < d1 && i >= 0 && j >= 0)
			{
				if (board[i][j][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i--; j++;
			}
		}

		else if ((d1 > s1 && d2 > s2))//lower right diagonal
		{
			//check for obstacles
			int i = s1 + 1, j = s2 + 1;
			while (i < d1 && i >= 0 && j >= 0)
			{
				if (board[i][j][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i++; j++;
			}
		}
		else if ((d1 > s1 && d2 < s2))//lower left diagonal
		{
			//check for obstacles
			int i = s1 + 1, j = s2 - 1;
			while (i < d1 && i >= 0 && j >= 0)
			{
				if (board[i][j][0] != '\0')
				{
					cout << endl << "Invalid" << endl;
					goto DISP;
				}
				i++; j--;
			}
		}


	DISP:
		display();
		 
	}


};
class Knight :public Board
{
	int dirR[8] = {-2,-2,-1,-1,+1,+1,+2,+2};
	int dirC[8] = {-1,+1,-2,+2,-2,+2,-1,+1};

public:
	Knight()
	{

	}
	bool isValid(int i, int j)
	{
		if (i >= 0 && i < SIZE && j >= 0 && j < SIZE)
			return true;
		else
			return false;
		
	}
	void move(int s1, int s2, int d1, int d2)
	{ 
		int done = 0;
		if ((isValid(d1, d2) == true))
		{
			for (int i = 0; i < 8; i++)
			{
				if ((s1 + dirR[i] == d1 && s2 + dirC[i] == d2) && board[d1][d2][0] == '\0')
				{
					//move 
					board[d1][d2][1] = KNIGHT;
					board[d1][d2][0] = board[s1][s2][0];

					board[s1][s2][0] = '\0';
					board[s1][s2][1] = '\0';

					done = 1;
				}
				if (done == 1)
					break;
			}

			if (done == 0)
				cout << endl << "Invalid move " << endl;
		}
		display();
	}

};

class Pawn :public Board
{
public:
	Pawn()
	{

	}
	void move(int s1, int s2, int d1, int d2)
	{
		if (board[s1][s2][0] == 'W')
		{
			if (s1+1 == (d1) && (s2 == d2) && (d1 < SIZE) && board[d1][d2][0] == '\0')
			{
				//move
				board[d1][d2][0] = 'W';
				board[d1][d2][1] = 'P';

				board[s1][s2][0] = '\0';
				board[s1][s2][1] = '\0';

			}
			else if ((s2 == d2 - 1 && (d2 - 1 >= 0) && board[d1][d2][0] != '\0') && (s2 == d2 + 1 && (d2 + 1 < SIZE) && board[d1][d2][0] != '\0'))
			{
				board[d1][d2][0] = 'W';
				board[d1][d2][1] = 'P';

				board[s1][s2][0] = '\0';
				board[s1][s2][1] = '\0';

			}
			else if (d1 == SIZE)
			{
				cout << endl << "What you want to make it (Q,K,R) ?"<<endl;
			}
			else
				cout << endl << "Indvalid move"<<endl;

		 
		}
		 

		if (board[s1][s2][0] == 'B')
		{
			if (s1-1 == (d1) && (s2 == d2) && (d1 >=0) && board[d1][d2][0] == '\0')
			{
				//move
				board[d1][d2][0] = 'B';
				board[d1][d2][1] = 'P';

				board[d1][d2][0] = '\0';
				board[d1][d2][1] = '\0';

			}
			else if (s1 == d1 && (s2 == d2 + 1 && (d2 + 1 >= 0) && board[d1][d2][0] != '\0') && (s2 == d2 - 1 && (d2 - 1 < SIZE) && board[d1][d2][0] != '\0'))
			{
				board[d1][d2][0] = 'B';
				board[d1][d2][1] = 'P';

				board[d1][d2][0] = '\0';
				board[d1][d2][1] = '\0';
			}
			else if (d1 == SIZE-1)
			{
				cout << endl << "What you want to make it (Q,K,R) ?" << endl;
			}
			else
				cout << endl << "Indvalid move" << endl;
		}

		display();
	}

};

class Player  
{
	Queen *Qobj;
	Knight *Kobj;
	Pawn *Pobj;
	 
public:
	Player(Queen *Q,Knight *K,Pawn *P) {
		Qobj = Q;
		Kobj = K;
		Pobj = P;
	};
	void PlayerMove(const char piece[],int i,int j,int m,int n)
	{
		cout << endl << "Piece :"<<piece<<" Moving from :" << i << "," << j << " - > " << m << "," << n;
		if (piece[1] == QUEEN)
		{
			Qobj->move(i,j,m,n);
		} 
		else if (piece[1] == KNIGHT)
		{
			Kobj->move(i, j, m, n);
		}

		else if (piece[1] == PAWN)
		{
			Pobj->move(i, j , m , n );
		}
	}
	 
};


int main()
{
	Queen *Q = new Queen();
	Knight *K = new Knight();
	Pawn *Pw = new Pawn();
	Display *dsp = new Display();
	Player *P = new Player(Q,K,Pw);

	//dsp->display();
	cout <<endl<< "Moving from 1,2 --> 2,2" << endl;
	P->PlayerMove("WP",1,2,2,2);
	
	P->PlayerMove("WP", 1, 3, 2, 3);

	P->PlayerMove("WP", 2, 3, 3, 3);

	P->PlayerMove("WP", 2, 2, 4, 2);

	P->PlayerMove("WP", 3, 3, 5, 9);

	P->PlayerMove("BP", 6, 4, 4, 4);

	P->PlayerMove("BP", 6, 4, 5, 4);

	P->PlayerMove("BP", 5, 4, 4, 4);

	P->PlayerMove("WP", 3, 3, 4, 4);

	P->PlayerMove("WQ", 0, 3, 1, 4);

	P->PlayerMove("WH",0,1, 1, 3);

	P->PlayerMove("WH", 1, 3, 3, 4);

	P->PlayerMove("WH", 3, 4, 2, 7);


	P->PlayerMove("WH", 0, 0, 2, 1);

	P->PlayerMove("WQ", 0, 4, 1, 4);

	P->PlayerMove("WQ", 1, 4, 3, 4);

	P->PlayerMove("WQ", 1, 4, 6, 9);



	return 0;

	 
}

