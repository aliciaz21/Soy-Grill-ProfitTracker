/********************************************************************************************************************************************************************************
# Author:       Alicia Zhang
# Assignment:   Assignment 5
# Date:         11/20/2022

# Description:  My program will calculate the total profit a teriyaki 
restaurant makes for the total amount of menu items sold. 
The user has 3 options: 
1. input item info, 2. print total profit, and 3.quit. 

# Sources:      Assignment 5 instructions, temperatures warmup, zybooks
#***************************************************************************************************************************************************************************/

#include <iomanip>
#include <string>
#include <iostream>
#include "valid.h"
using namespace std;

//user options for main menu
const int ITEMMENU = 1;
const int PRINT_PROFIT = 2;
const int QUIT = 3;

//menu items 
const int CHICKEN = 1;
const int BEEF = 2;
const int PORK = 3;
const int GYOZA = 4;
const int B_SHRIMP = 5;
const int MISO = 6;
const int MAX = 6;

//size of array
const int SIZE = 6;

//function prototypes for program implementation functions
void printMenu();
int getChoice();
void printItemsMenu(string itemNames[], double profitMargin[]);
int getItem();
int getQuantity(string itemNames[]);
void printResults(string itemNames[], int quantity[], 
		double profitMargin[], double totalProfit);


int main() {
	int choice = 0; //user choice for menu option
	int item = 0; //menu item option (i.e. 1 is to choose chicken teriyaki from the menu items
	int quantity[SIZE] = {0}; //quantity of items sold
	double totalProfit = 0.0; //total profit of the day

	string itemNames[] = {"Chicken teriyaki", "Beef Teriyaki", "Pork Teriyaki","Gyoza", "Butterfly shrimp", "Miso Soup"}; //names displayed for the results
	double profitMargin[] = {6.45, 7.45, 7.45, 4.45, 4.45, 2.45}; //profit margin for each item used in calculations for total profit

	//allow the user to redo their choices while the user doesn't choose to quit the program
	while (choice != QUIT) {
		printMenu();
		choice = getChoice();
		if (choice == ITEMMENU) {
			printItemsMenu(itemNames, profitMargin);
			item = getItem();
			quantity[item - 1] = getQuantity(itemNames);
		}

		if (choice == PRINT_PROFIT) {
			printResults(itemNames, quantity, profitMargin, totalProfit); 
		}
	}
	cout << "Thank you! Have a good day!" << endl;
}


//print the main menu 
void printMenu() {
	cout << "\n1. Item menu" << endl;
	cout << "2. Print total profit" << endl;
	cout << "3. Quit" << endl;
}


//get user choice for main menu option: 1. choose from item menu, 2. print total profit, 3. quit
int getChoice() {
	int choice = 0;
	choice = getInteger("\nEnter choice: ");
	while (choice < 1 || choice > 3) {
		cout << "Invalid choice!" << endl;
		choice = getInteger("\nEnter choice: ");
	}
	return choice;
}


//print the menu of food items
void printItemsMenu(string itemNames[], double profitMargin[]) {
	cout << setw(26) << left << "\n[Menu Items]" <<
		setw(14) << "[Profit Margin]" << endl;
	cout << setw(25) << left << "------------" <<
		setw(14) << "---------------" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << i + 1 << ". " << setw(28) << left << itemNames[i] <<
			"$" << setw(14) << profitMargin[i] << endl;
	}
}


//get the menu item
int getItem() {
	int item = 0;
	item = getInteger("\nEnter item choice: ");

	while (item < 1 || item > SIZE || item == '\n') {
		cout << "Invalid Choice" << endl;
		item = getInteger("\nEnter item choice: ");
	}
	return item;
}


//get quantity of the items sold
int getQuantity(string itemNames[]) {
	int quantity = 0;

	for (int i = 0; i < SIZE; i++) {
		quantity = getInteger("Enter total units sold: ");
		while (quantity < 0) {
			cout << "Invalid choice" << endl;
			quantity = getInteger("Enter total units sold: ");
		} 
		return quantity;
	} 
}

//prints the results of the calculations
void printResults(string itemNames[], int quantity[], double profitMargin[],
		double totalProfit) {
	cout << fixed << setprecision(2);
	cout << setw(22) << left << "\n[Item Name]" << setw(14) << "[Quantity]" <<
		setw(14) << "[Unit Profit]" << endl;
	cout << setw(21) << left << "-----------" << setw(14) <<
		"----------" << setw(13) << "-------------" << endl;

	for (int i = 0; i < SIZE; i++) {
		if (quantity[i] != 0) {
			cout << setw(26) << left << itemNames[i] << setw(14) <<
				quantity[i] << "$" << setw(14) << quantity[i] * profitMargin[i] << endl;
			totalProfit = totalProfit + quantity[i] * profitMargin[i];
		}
	}
	cout << "\nThe total profit for the day is $ " << totalProfit <<
		"." << endl;
}
