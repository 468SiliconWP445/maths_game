#include <stdio.h>
#include <stdlib.h>

int get_random() {
	unsigned int number = 0;
	rand_s(&number);
	int return_number;
	return_number = number % 12; //Random number between 0 and 11
	return_number++; //Makes it between 1 and 12
	return return_number;
}

int get_sign() {
	unsigned int number_2 = 0;
	rand_s(&number_2);
	int return_number_2;
	return_number_2 = number_2 & 3; //Between 0 and 2
	return_number_2++; //Between 1 and 3
	return return_number_2;
}

int main() {
	int i = 0;
	int gold = 0;
	while (i < 1) {
		printf("Welcome to the gold mining game!\n");
		printf("Mine as much gold as possible to win.\n");
		printf("Mine gold by answering maths questions correctly.\n");
		int a = get_random();
		int b = get_random();
		int sign_id = get_sign();
		char sign;
		if (sign_id == 1) {
			sign = '-';
		}
		else if (sign_id == 2) {
			sign = '+';
		}
		else {
			sign = '*';
		}
		printf("What is %d%c%d?\n", a, sign, b);
		int user_ans;
		int ans;
		if (sign_id == 1) {
			ans = a - b;
		}
		else if (sign_id == 2) {
			ans = a + b;
		}
		else {
			ans = a * b;
		}
		scanf_s("%d", &user_ans);
		if (ans == user_ans) {
			printf("Correct answer!\n");
			gold++;
			printf("Your Gold: ");
			printf("%d", gold);
			printf("\n\n");
		}
		else {
			printf("Incorrect Answer!\n");
			gold--;
			if (gold < 1) {
				gold = 0;
			}
			printf("Your Gold: ");
			printf("%d", gold);
			printf("\n\n");
		}
	}
}