#!/bin/python3

from argparse import *
from os import listdir
from re import search

def main() -> int:
    parser = ArgumentParser()
    parser.add_argument("songname", type = str)
    args = parser.parse_args()

    temp_f = open("temp.c", "w+t")
    main = open("main.c", "r+t").read()
    temp_f.write(main)

    if f"{args.songname}.txt" not in listdir("songs"):
        print(f'No song with name "{args.songname}.txt" found')
        return 1

    temp_f = open("temp.c", "w+t")
    main = open("main.c", "r+t").read()
    song = open(f"songs/{args.songname}.txt", "r+t").read()

    if search(r"\w+?[(]", song):
        print("DON'T U DARE PUT STANDARD LIBRARY FUNCTIONS IN C-COMPATIBLE BYTEBEAT!!!!!!!")
        return 1

    main = main.replace("t&t>>8", song)
    temp_f.write(main)

if __name__ == "__main__":
    main()
