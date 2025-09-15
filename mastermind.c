#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


/*
 * All your code for the Intro to C Assignment (mastermind) should go
 * in this file.
 *
 * The functions printString and printInt are already written
 * for you to help with output.  Reminder: you CANNOT use 
 * printf, fprintf, fgets, etc.  The only I/O functions you may 
 * use are individual character-based I/O functions like getchar, putchar,
 * getc, fgetc, putc, etc.
 */ 


/*
 * Print the parameter string to stdout using
 * putchar().  Don't return anything.
 */
void printString(char str[]) {
  for (uint8_t i = 0; str[i] != '\0'; i++) {
    putchar(str[i]);
  }
}

/*
 * Print the given 8-bit integer to stdout using
 * the putchar() function.  
 */
void printInt(int8_t i) {
  if (i < 0) {
    putchar('-');
  }
  i = abs(i);
  if (i > 100) {
    putchar('0' + (i/100));
  }
  i = i % 100;
  if (i > 9) {
    putchar('0' + (i/10));
  }
  putchar('0' + (i%10));
}



// void printString(char str[]){
//   for(int i = 0; str[i] != '\0'; i++){
//     putchar(str[i]);
//   }
// }

// void printInt(int8_t myInt){
//   if(myInt == 0){
//     putchar('0');
//   }

//   if (myInt / 10) {
//     printInt(myInt / 10);
//   }

//   putchar((myInt % 10) + '0');
// }


bool guessCorrect(int8_t secret[4], int8_t guess[4]){
  for(int i = 0; i < 4; i++){
    if(secret[i] != guess[i]){
      return false;
    }
  }
  return true;
}

bool validGuess(int8_t guess[4]){
  for(int i = 0; i < 4; i++){
    if (guess[i] < 0 || guess[i] > 9) {
      return false;
    }
  }
  return true;
}


void getGuess(int8_t guess[4]){
  bool isValid = false;
  while(!isValid){
    printString("Your guess: ");
    fflush(NULL);
    int i = 0;
    int ch;
    while (1) {
      ch = getchar();
      if (ch == '\n') {
        break;
      }
      if(i < 4 && ch >= '0' && ch <= '9'){
        guess[i] = (int8_t)(ch - '0');
        i++;
      }
    }
    if (i == 4 && validGuess(guess)) {
      isValid = true;
    } 
  }
}



void scoreGuess(int8_t secret[4], int8_t guess[4]){
  for(int i = 0; i < 6; i++){
    putchar(' ');
  }
  for(int j = 0; j < 4; j++){
    if(secret[j] == guess[j]){
      putchar('0' + secret[j]); 
    } 
    else {
      int digit = guess[j];
      int matched = 0;
      for(int k = 0; k < 4; k++){ 
        if(secret[k] == digit){
          matched = 1;
          break;
        }
      }
      if (matched) {
        putchar('.');
      } 
      else {
        putchar('x');              
      }
    }
  }
  putchar('\n');                   
}



/*
 * @params secret_code: array of 8-bit signed integers containing
 *          the secret code.
 *          Note that the value of each entry in the secret_code 
 *          array is an 8-bit integer value 0..9.  It is _NOT_ a
 *          character (e.g., '0'..'9') or a C string.
 */
void mastermind(int8_t secret_code[4]) {
    /*
     * Your code should start here.
     *
     * Be sure to break down the problem into a reasonable set of functions.
     * See google doc description for a suggested set of functions.
     */

     printString("Welcome to mastermind.\n");
     int tries = 0;
     bool win = false;
     int8_t guess[4];
     while(!win){
      tries++;
      getGuess(guess);
      if(guessCorrect(secret_code, guess)){
        printString("You win! That took ");
        printInt((int8_t)tries);
        printString(" tries.\n");
        break;
      }
      scoreGuess(secret_code, guess);
     }
}
