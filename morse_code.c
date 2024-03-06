#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



char* text_to_morse(char *sentence, int sentence_length);
char* morse_to_text(char *sentence, int sentence_length);

int main(){

int i;
char choosingMTQ;
printf("==========================\n");
printf("what would you like to do?\n");
printf("==========================\n");
printf("Convert to morse code (M)\n");
printf("Convert to text (T)\n");
printf("Quit (Q)\n");
printf("--------------------------\n");
while(choosingMTQ == 0){
printf("Enter a choice from the menu (M, T, Q):");
scanf("%s", &choosingMTQ);
fgetc(stdin);
if (choosingMTQ == 'm' || choosingMTQ == 'M'){
  printf("Enter the text you would like to convert: ");
char userInput[1000];
fgets(userInput, 1000, stdin);
char *finalcode =text_to_morse(userInput,strlen(userInput));
printf("%s\n", finalcode );
return main();
}else if(choosingMTQ == 't' || choosingMTQ == 'T'){
  printf("Enter the text you would like to convert: ");
char userInputT[1000];
fgets(userInputT,1000,stdin);
char *finalTcode = morse_to_text(userInputT, strlen(userInputT));
printf("%s\n", finalTcode);
return main();
}else if(choosingMTQ == 'q' || choosingMTQ == 'Q'){
exit(0);
}
return (0);
}
}


char* text_to_morse(char *sentence, int sentence_length){
char uppers[sentence_length-1];
int i ;
      for ( i = 0; i < sentence_length-1; i++) {
        if ((int)sentence[i] == 0x0A){
          uppers[i]=' ';
        }
        else if (((int)toupper(sentence[i]) < 65 || (int)toupper(sentence[i]) > 90) && (int)sentence[i] != 32){
          uppers[i] ='?';
        }else{
        uppers[i]=toupper(sentence[i]);
        }
      }
char dest[1000000]="Morse code: ";
int b = 0;
for (int x = 0 ; x < sentence_length-1 ; x++){
  switch (uppers[x]) {
    case 'A':strcat(dest, ".- ");
    break;
    case 'B':strcat(dest, "-... ");
    break;
    case 'C':strcat(dest, "-.-. ");
    break;
    case 'D':strcat(dest, "-.. ");
    break;
    case 'E':strcat(dest, ". ");
    break;
    case 'F':strcat(dest, "..-. ");
    break;
    case 'G':strcat(dest, "--. ");
    break;
    case 'H':strcat(dest, ".... ");
    break;
    case 'I':strcat(dest, ".. ");
    break;
    case 'J':strcat(dest, ".--- ");
    break;
    case 'K':strcat(dest, "-.- ");
    break;
    case 'L':strcat(dest, ".-.. ");
    break;
    case 'M':strcat(dest, "-- ");
    break;
    case 'N':strcat(dest, "-. ");
    break;
    case 'O':strcat(dest, "--- ");
    break;
    case 'P':strcat(dest, ".--. ");
    break;
    case 'Q':strcat(dest, "--.- ");
    break;
    case 'R':strcat(dest, ".-. ");
    break;
    case 'S':strcat(dest, "... ");
    break;
    case 'T':strcat(dest, "- ");
    break;
    case 'U':strcat(dest, "..- ");
    break;
    case 'V':strcat(dest, "...- ");
    break;
    case 'W':strcat(dest, ".-- ");
    break;
    case 'X':strcat(dest, "-..- ");
    break;
    case 'Y':strcat(dest, "-.-- ");
    break;
    case 'Z':strcat(dest, "--.. ");
    break;
    case ' ':strcat(dest, " ");
    break;
    case '?':strcat(dest, "? ");
    break;
    default:
            printf("Error! operator is not correct");
 }
}
char* final = dest;
return final;
}

char* morse_to_text(char *sentence, int sentence_length){
    char letters [sentence_length-1];
    char dest[100000];
    char final[00000];
    int space = 0;
    //printf("%s\n",sentence);
    for(int i =0; i<sentence_length;i++){
      if (sentence[i] == ' '){
          if (strcmp(dest,".-")){
            printf("here\n");
            strcat(final,"a");
          }
          space++;
      }else{
        if (sentence[i] == '-'){
          strcat(dest,"-");
        }else if (sentence[i] == '.'){
          strcat(dest,".");
        }
      }
    }




    printf("%s\n",dest );







    /*int i ;
          for ( i = 0; i < sentence_length-1; i++) {
            letters[i]=sentence[i];
          }


    char dest[1000000]="Morse code: ";
    char temp [1000000]=" ";
    int counter = 0;
    while(counter != 9){
      int i = 0;
      while(letters[i] != ' '){
        strcat(temp,letters[i]);
        counter ++;
      }

      if (counter == 1){
        printf("1 lett \n");
        if (letters[i]=="?"){
          break;
        }
      }else if(counter == 2){
        printf("2 lett \n");
      }else if (counter ==  3){
        printf("three let \n" );
      }else{
        printf("4 lett\n" );
      }
      i++;
      counter ++;
    }*/
    return sentence;
}
