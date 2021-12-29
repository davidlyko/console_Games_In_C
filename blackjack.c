#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct Card{
  char suit;
  int rank;
  int drawn;
}Card;


typedef struct Player{
  int total;
  Card hand[5];
  int win;
  int turn;
}Player;


typedef struct Dealer{
  int total;
  int win;
  int turn;
  Card hand[5];
}Dealer;
	
	

int drawRandom(int *arr){
    int rand1;
    while(1){
        rand1 = rand() % 104;
        
        if(arr[rand1] != 1) break;     
    }
    arr[rand1] = 1;
    
    return rand1;
}
	
	
	
int main(){

  srand(time(NULL));
  
  printf("----------------------------------------------------------\n");
  printf("Welcome to simplified blackjack! \n"
	 "Here are the rules: \n"
	 "1. The dealer will deal you 2 cards. \n"
	 "2. You can hit or stop \n"
	 "Each card has a value, 2 has a value of 2, 3 has a value of 3... Jack, Queen, king have a value of 10, and ACE has a value of 10 as well. \n"
	 "3. Hitting means the dealer gives you another card. \n"
	 "4. Stopping means you are satisfied with your cards. \n"
	 "5. When both you and the dealer stop, you both show your cards, the player closest to 21 wins! \n"
	 "6. If you go over 21 you lose. \n"
	 "7. The first player to win 5 rounds wins the game!!! \n");
	printf("----------------------------------------------------------\n");
  Player p1;
  p1.win = 0;
  p1.turn = 1;
  
  Dealer d1;
  d1.win = 0;
  d1.turn = 1;

  //generate deck of cards
  
  Card* deck = malloc(104*sizeof(Card));

  int check[104];
  for(int i = 0; i < 104; i++){
    check[i] = 0;
  }
  
  int count = 0;
  for(int a = 0; a < 2; a++){
    for(int i = 0; i < 4; i++){ 
        for(int k = 2; k < 15; k++){
            if(i == 0){
                Card card;
                card.suit = 's';
                if(k >= 10){
                    card.rank = 10;
                }
                else{
                card.rank = k;
                }
                deck[count] = card;
                count++;   
            }
            else if(i == 1){
                Card card;
                card.suit = 'c';
                if(k >= 10){
                    card.rank = 10;
                }
                else{
                card.rank = k;
                }
                deck[count] = card;
                count++;
            }
            else if(i == 2){
                Card card;
                card.suit = 'h';
                if(k >= 10){
                    card.rank = 10;
                }
                else{
                card.rank = k;
                }
                deck[count] = card;
                count++;
            }
            else if(i == 3){
                Card card;
                card.suit = 'd';
                if(k >= 10){
                    card.rank = 10;
                }
                else{
                card.rank = k;
                }
                deck[count] = card;
                count++;
            }       
          }
        } 
      }
      
     for(int i = 0; i < 104; i++){
        //printf("%i\n", deck[i].rank);
     
     }
     
    //main game loop
  printf("----------------------------------------------------------\n");int roundNum = 0;
    while(d1.win < 5 && p1.win < 5){
        
        if(d1.turn){
        
            printf("Dealers turn \n");
      printf("----------------------------------------------------------\n");
            
            
            d1.hand[0] = deck[drawRandom(check)];
            
            //printf("d1.hand[0].rank = %i\n", d1.hand[0].rank);
            
            
            
             
            
            d1.hand[1] = deck[drawRandom(check)];
            
            //printf("d1.hand[1].rank = %i\n", d1.hand[1].rank);
            
            
            
            d1.total = d1.hand[0].rank + d1.hand[1].rank;
            
            int numCards = 2;
            
            if(d1.total < 13){
	            printf("The dealer hits\n");
	         printf("----------------------------------------------------------\n");
	            d1.hand[numCards] = deck[drawRandom(check)];
	            d1.total = d1.hand[0].rank + d1.hand[1].rank + d1.hand[2].rank;
            }
            printf("The dealer stops\n");
        printf("----------------------------------------------------------\n");
            //printf("The dealers total rank is %i\n", d1.total);
            numCards = 0;
            
        }
        
        if(p1.turn){
            
            printf("Your turn \n");
          printf("----------------------------------------------------------\n");
            
            p1.hand[0] = deck[drawRandom(check)];
           
            printf("p1.hand[0].rank = %i\n", p1.hand[0].rank);
         printf("----------------------------------------------------------\n");
            
            
            
            p1.hand[1] = deck[drawRandom(check)];

            printf("p1.hand[1].rank = %i\n", p1.hand[1].rank);
           printf("----------------------------------------------------------\n");
            
            p1.total = p1.hand[0].rank + p1.hand[1].rank;
            
            printf("Your total rank is %i\n", p1.total);
            printf("----------------------------------------------------------\n");
            
            
            int hitOrStop;
            
            int card = 2;
            
            while(1){
            
                printf("Would you like to hit (press 1) or stop (press 0)\n"); 
                printf("----------------------------------------------------------\n");
            
                scanf("%i", &hitOrStop);
                printf("----------------------------------------------------------\n");
            
                if(hitOrStop){
            
                    p1.hand[card] = deck[drawRandom(check)];
                    card++;
                    p1.total = 0;
                    for(int i = 0; i < card; i ++){
                        p1.total += p1.hand[i].rank;
                    }
                    printf("YOUR SCORE = %i\n", p1.total);
                 printf("----------------------------------------------------------\n");
                }
            
                else{
            
                    break;
            
                }
                
             printf("----------------------------------------------------------\n");   
            }
            

            
        }
        
        
        //check who won
        
        
        if(p1.total > 21){
            if(d1.total > 21){
                
                printf("No One won the round\n");
                  printf("----------------------------------------------------------\n");   
            }
            else{
           
                printf("The dealer won this round XXXXX\n");
                  printf("----------------------------------------------------------\n");   
                d1.win++;
            }
        }
        else if(d1.total > 21){
            if(p1.total > 21){
    
                printf("You won this round !!!\n");
              printf("----------------------------------------------------------\n");   
            }
            else{
                                             
                printf("You won this round !!!!!!\n");
                  printf("----------------------------------------------------------\n");   
            
                p1.win++;
            }
        }
        else if(d1.total > p1.total){
     

            printf("The dealer won this round XXX\n");
              printf("----------------------------------------------------------\n");   
            
            
            d1.win++;
        }
        else if(d1.total == p1.total){
          
      
         
            printf("The round is tied ~~~~~~\n");
           
            
            roundNum++;
            printf("ROUND = %i\n", roundNum);
            printf("YOUR SCORE = %i\n", p1.win);
            printf("DEALER'S SCORE = %i\n", d1.win);
            
            continue;
        }
        else{
   
      
            printf("You won this round !!!!\n");
              printf("----------------------------------------------------------\n");   
            
         
            
            p1.win++;
        }
        
        roundNum++;
        
        
        
        

    }
  
    if(p1.win == 5){
    
         roundNum--;
        printf("Congratulations You won the game!!!\n");
        printf("ROUND = %i\n", roundNum);
        printf("YOUR SCORE = %i\n", p1.win);
        printf("DEALER'S SCORE = %i\n", d1.win);
        
       printf("----------------------------------------------------------\n");  
   }
   else{
   
   
    roundNum--;

    printf("The dealer won the game\n");
    printf("ROUND = %i\n", roundNum);
    printf("YOUR SCORE = %i\n", p1.win);
    printf("DEALER'S SCORE = %i\n", d1.win);
    
  printf("----------------------------------------------------------\n"); 
  }
  



    return 0;
}











