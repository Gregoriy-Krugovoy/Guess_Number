// Игра "Угадай Число. Игрок должен угадать случайное число от 1 до 100. "
#include <stdio.h> // input/output
#include <stdlib.h> // rand/srand
#include <ctype.h> // isdigit()
#include <time.h> // time()

int is_valid( char number );

int main ( void ) 
{
    int number; // неизвестное нам число от 0 до 100
    int guess; // введенное нами число
    int attempts = 0; // количество попыток угадать число

    srand( time( NULL ) ); // инициализировать генератор случайных чисел текущим времинем
    number = 1 + ( rand() % 100 ); // генерация случайного числа от 1 до 100
    printf( "Welcome to the Guess the Number game!\n" );
    printf( "I'm thinking of a number between 1 and 100.\n" );

    do {
        printf( "Enter your guess: " );
        scanf( "%d", &guess );
        guess = is_valid( guess );
        attempts++;
        if( guess > number ) {
            printf( "Too high! Try again.\n");

        } else if( guess < number ) {
            printf( "Too low! Try again.\n" );
        } else{
            printf( "Congratulations! You guessed the the number is %d attempts.\n", attempts );
            }
        } while ( guess != number );
    return 0;
}

int is_valid( char number )
{
    if (isdigit(number)) {
        return number;
    } else {
       printf( "Input error\n" );
    }
}