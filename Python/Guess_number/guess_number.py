#This is a guess the number the game

import random

print("Hello! What is your name?")
name = input()

print("Well," + name + ", I am thinking of a number between 1 and 20")
secretnumber = random.randint(1,20)

for guessTaken in range (0,6):
    print('Take a guess.')
    guess= int(input())

    if guess< secretnumber:
        print("your guess is low")
    elif guess > secretnumber:
        print("your guess is high")
    else:
        break

if(guess == secretnumber):
    print("Good Job, "+ name + "! you guessed the number in " + str(guess) + " guesses")
else:
    print("Sorry, Timeout the secret number is" + str(secretnumber))