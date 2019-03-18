# Written by Aaron Barge
# Copyright 2019
import random
import os
ANSWERS = []
FILE_PATH = os.path.abspath(__file__) + "/../Answers.txt"
def get_answers():
    global FILE_PATH
    global ANSWERS
    try:
        file_in = open(FILE_PATH, 'r')
        for line in file_in:
            ANSWERS.append(line)
        file_in.close()
        return True
    except IOError:
        print("Answers failed to load")
        return False

def get_answer():
    global ANSWERS
    if ANSWERS == []:
        print(ANSWERS[random.randrange(len(ANSWERS))])
    else:
        if get_answers():
            get_answer()

def main():
    global FILE_PATH
    while True:
        print("Concentrate on your Question")
        print("Type 'no' if you no longer need my help")
        print("Type 'idea' if you have a good idea for an answer")
        text = input("Press enter when ready ")
        if text == 'no':
            break
        elif text == 'idea':
            new_answer = input("What is your idea? ")
            file_in = open(FILE_PATH, 'a')
            file_in.write(new_answer + '\n')
            file_in.close()
            print("That is a brilliant idea!\n")
        else:
            get_answer()

if __name__ == "__main__":
    main()