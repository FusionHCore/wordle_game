# Wordle in C
A game where you guess the letters of the word. If your guess contains the letter of the targetted word, the game will let you know.
 
## Fixed Issues
- Correct messages is now shown after each correct guess.
- The program doesnt run indefinitely now. It was caused because of the assignment operator instead of comparision in line 87
- There used to be leftover data in the "pos" and "s" arrays if the user put less character than the word.
- replaced the use of strupr with capitalizing user_input with the macro built in the program itself. (strupr isnt universal)

## Features
A feature that must be in the game that is missing 
- If a character you guessed exists in the word, It will say that it exists, but not in the right position.

## Note
- You can change the number of words you want to play by changing max_words at the definition section.
- There is %19s at user_input to make sure more than 19 characters cannot be entered, 20th index is for the null terminator. If you want the words of length n, Put the max_length (n+1).