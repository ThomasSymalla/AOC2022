# Advent of Code 2022
This repository contains my personal work for the [Advent of Code](https://adventofcode.com/) 2022 challenge. Each day is organized into its own folder.
Problems increase in complexity as days goes on. Global ranking is based on how long it took for you to submit the right answer, with penalties for incorrect guesses.
Problems all have two parts, and the difficulty of the problems goes from easy to very difficult as the days go on.

Personally, I attempted to solve the problems as fast as possible to get a good ranking then went back afterwards to clean the solutions up and attempt better solutions (in both time and space complexity).
Here's a basic description of each day's problem as well as my personal timed rankings:
1. Parse input and determine the amount of "calories" each elf is holding.
Global Rankings for Part 1: 833 Part 2: 1785
2. Parse rock-paper-scissors games in letter format and calculate score based on scoring system.
--- Global Rankings for Part 1: 207 Part 2: 213
3. Parse string of random characters representing two rucksacks of items and find common item, then calculate the score of these items.
--- Global Rankings for Part 1: 8670 Part 2: 7936
4. Given ranges of numbers representing elf bunking assignments (i.e. 2-4, 6-10), determine how many of these ranges both overlap and completely overlap another.
--- Global Rankings for Part 1: 126597 Part 2: 124591
5. Given a number of "crate stacks" and a list of commands that moves X crates from the top of one stack to another, determine the final state of each stack after the commands are executed.
--- Global Rankings for Part 1: 2796 Part 2: 2257
6. Given an "encrypted string" of random characters, determine the first substring of X characters where each character is unique.
--- Global Rankings for Part 1: 13308 Part 2: 12488
7. Given "filesystem commands" (cd, dir, and a command to create a file), determine the final size of various sections of the filesystem after every given command is executed. 
--- Global Rankings for Part 1: 3752 Part 2: 3630
8. Given a 2D grid of numbers with each number representing a tree height, find index with the best "scenic score" (which is based on what it can see in 4 cardinal directions without being blocked by another tree)
--- Global Rankings for Part 1: 423 Part 2: 792
9. Given a 2D array and rules that determine "rope physics", determine how many tiles in a 2d array are visited by a "rope physics" simulation with certain parameters.
--- Global Rankings for Part 1: 2506 Part 2: 1123
10. Given a number of commands (i.e. addX 40, addX -10, noop) and rules to determine how these commands draw to a screen, write code that prints this to the console and see what letters it prints.
--- Global Rankings for Part 1: 4547 Part 2: 3221
11. Given a number of monkeys who each have their own behavior and effect on your "worry score", determine your "worry score" after 10000 rounds of "monkey tossing". 
--- Global Rankings for Part 1: 7777 Part 2: 5833
12. Given a 2d map of characters representing the height map of the hill, find the fewest steps required to go to any given tile with a required elevation (you can only move up and down 1 elevation level adjacent to you)
--- Global Rankings for Part 1: 2343 Part 2: 2272
13. Given a number of nested lists and integers in these lists, determine which lists are in "correct order" according to the rules.
--- Global Rankings for Part 1: 3061 Part 2: 2743
14. Given a 2d array representing a 2d map, simulate sand falling with certain physics. How many sand particles will fall until the entire map is filled up assuming sand can expand infinitely in either direction?
--- Global Rankings for Part 1: 4863 Part 2: 4558

Other files:
Helpers.h/cpp: Various functions to help parse inputs and other things.
