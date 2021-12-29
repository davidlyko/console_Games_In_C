#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Player{
  char name[30];
  char type;
  int turn;
}Player;

void initializeBoard(char gameBoard[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      gameBoard[i][j] = ' ';
    }
  }
}

char selectPlayer(){

  srand(time(0));
  
  int randomZeroOrOne = rand() % 2;
  
  char randomXorO = (randomZeroOrOne == 1) ? 'X' : 'O';
  
  return randomXorO;
}


void printGameBoard(char gameBoard[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(j == 2){printf("%c ", gameBoard[i][j]); printf("\n");}
      else{printf("%c | ", gameBoard[i][j]);}
    }
	printf("---------\n");    
  }

}



int main(){

  printf("Welcome to Tic Tac Toe!!!\n");

  char gameBoard[3][3];				//generate gameboard
  initializeBoard(gameBoard);

  Player playerOne;

  printf("Player One please enter your name\n");
  
  fgets(playerOne.name, 30, stdin);

  printf("Player Two please enter your name\n");

  char playerOneType = selectPlayer();
  
  playerOne.type = playerOneType;
  
  Player playerTwo;

  fgets(playerTwo.name, 30, stdin);

  if(playerOne.type == 'X'){
    playerTwo.type = 'O';
    playerOne.turn = 1;
    playerTwo.turn = 0;
  }
  else{
    playerTwo.type = 'X';
    playerOne.type = 'O';
    playerTwo.turn = 1;
    playerOne.turn = 0;
  }


  
  printf("The game randomly decided that %s is %c\n",playerOne.name, playerOne.type);
  printf("Thus: %s is %c\n", playerTwo.name, playerTwo.type);


  

  
  int gameEnd = 0;
  
 
  
  while(gameEnd == 0){
    int insert = 0;
    
    //Player One
    if(playerOne.turn){
      int i = 0;
      int j = 0;
      while(insert == 0){
	printf("%s, What row would you like to place your marker (1, 2, 3) ?\n", playerOne.name);
	scanf("%d", &i);
	i--;
	printf("%s, What column would you like to place your marker in (1,2,3) ?\n", playerOne.name);
	scanf("%d", &j);
	j--;
	if(gameBoard[i][j] == ' '){gameBoard[i][j] = playerOne.type; insert = 1; playerOne.turn = 0; playerTwo.turn = 1;}
        else{continue;}
      }
    }
    //Player 2 turn
    else{
      int i = 0;
      int j = 0;
      while(insert == 0){
	printf("%s, What row would you like to place your marker (1, 2, 3) ?\n", playerTwo.name);
        scanf("%d", &i);
	i--;
        printf("%s, What row would you like to place your marker (1, 2, 3) ?\n", playerTwo.name);
        scanf("%d", &j);
	j--;
	if(gameBoard[i][j] == ' '){gameBoard[i][j] = playerTwo.type; insert = 1; playerTwo.turn = 0; playerOne.turn = 1;}
	else{continue;}
      }
    }
    
    //check for winner
    int p1Row = 0;
    int p2Row = 0;
    //check rows
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	if(gameBoard[i][j] == playerOne.type){p1Row++;}
	if(gameBoard[i][j] == playerTwo.type){p2Row++;}	 
      }
      if(p2Row == 3){printf("%s WINS!!!\n", playerTwo.name); gameEnd = 1;}
      if(p1Row == 3){printf("%s WINS!!!\n", playerOne.name); gameEnd = 1;}
      p1Row = 0;
      p2Row = 0;
    }

    //check diagonoals

    //'boolean' values to see who controls row 2 column 2 (middle square)
    int p1Diagonal = 0;  
    int p2Diagonal = 0;
    if(gameBoard[1][1] == playerOne.type){p1Diagonal = 1;}
    if(gameBoard[1][1] == playerTwo.type){p2Diagonal = 1;}
    if(p1Diagonal){
      if(gameBoard[0][0] == playerOne.type && gameBoard[2][2] == playerOne.type){printf("%s WINS!!!\n", playerOne.name); gameEnd = 1;}
      if(gameBoard[0][2] == playerOne.type && gameBoard[2][0] == playerOne.type){printf("%s WINS!!!\n", playerOne.name); gameEnd = 1;}
    }
    if(p2Diagonal){
      if(gameBoard[0][0] == playerTwo.type && gameBoard[2][2] == playerTwo.type){printf("%s WINS!!!\n", playerTwo.name); gameEnd = 1;}
      if(gameBoard[0][2] == playerTwo.type && gameBoard[2][0] == playerTwo.type){printf("%s WINS!!!\n", playerTwo.name); gameEnd = 1;}
    }
    // ensured you can win on a diagonal
    // now we have to ensure you can win with columns
    int p1Col = 0;
    int p2Col = 0;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	if(gameBoard[j][i] == playerOne.type){p1Col++;}
	if(gameBoard[j][i] == playerTwo.type){p2Col++;}
      }
      if(p2Col == 3){printf("%s WINS!!!\n", playerTwo.name); gameEnd = 1;}
      if(p1Col == 3){printf("%s WINS!!!\n", playerOne.name); gameEnd = 1;}
      p1Col = 0;
      p2Col = 0;
    }

    //check if there is no winner
    int occupiedSquares = 0;
    if(gameEnd == 0){
      for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
	  if(gameBoard[i][j] != ' '){occupiedSquares++;}
	}
      }
      if(occupiedSquares == 9){printf("No Winner, try again\n"); gameEnd = 1;}
    }
    occupiedSquares = 0;
    insert = 0;
    printGameBoard(gameBoard);
  }
  
  //printGameBoard(gameBoard);
  return 0;  
}
