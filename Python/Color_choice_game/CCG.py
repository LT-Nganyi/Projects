import random
import os
name = input(
'''
Welcome to the Color Choice Game. Made by TC technologies.
The game works like this: The user selects a color,
if the color matches the color selected by the computer,
The user wins. If it differs, the computer wins.
Enjoy!

Enter name to begin: 

''').capitalize()
colors = ('Red', 'Yellow', 'Orange', 'Green', 'Blue')
comp_score, user_score = 0,0
os.system("CLS")

print(f'Welcome {name}')

os.system("PAUSE")
os.system("CLS")
while True:
    
    print(f'{name}: {user_score}\nComputer: {comp_score}')
    user_choice = input('''
Enter number between 1 and 5 to choose a color.
    1. Red
    2. Yellow
    3. Orange
    4. Green
    5. Blue
    ''')
    
    if(user_choice.isdigit() and int(user_choice) <= len(colors)+1):

        user_choice = int(user_choice)-1
        print(f'Your choice is : {colors[user_choice]}')

        comp_choice = random.randint(0,4)
        print(f'Computer choice is : {colors[comp_choice]}')

        if user_choice == comp_choice:
            user_score += 1
            print(f'{name} wins this round!')
        else:
            comp_score += 1
            print('\nComputer wins this round!')

    else:
        print("Oops! Invalid choice. Try Again")
        continue

    play_again = input('\nDo you want to play again?\n Y or N\n')
    if play_again == 'N' or play_again == 'n':
        os.system("CLS")
        break
    os.system("CLS")
print(f'''
Game over!
Final Scores

{name}: {user_score}
Computer: {comp_score}\n''')
if comp_score > user_score:
    print('You lost! But they say practice makes perfect! Try agin')
elif comp_score == user_score:
    print('Its a tie!!')
else:
    print('Congratulations!!! You won the game!')
os.system("PAUSE")