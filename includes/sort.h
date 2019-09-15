#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define TIME_OUT 500

void swap(int*, int*);
void bubbleSort(int[], int);
void insertionSort(int[], int);
void mergeSort(int[], int, int, int);
void quickSort(int[], int, int, int);
void selectionSort(int[], int);

void executeAlgo(int);
void printMenu(WINDOW*, int);
void createMenu();

void checkUserResponse()