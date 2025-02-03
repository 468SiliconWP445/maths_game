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

char message1[] = "Welcome to the gold mining game!\n";
char message2[] = "Mine as much gold as possible to win.\n";
char message3[] = "Mine gold by answering maths questions correctly.\n";
int i = 0;
int gold = 0;
char sign;
char message4[] = "What is %d%c%d?\n";
int user_ans;
int ans;
char message5[] = "%d";
char correct_message[] = "Correct answer!\n";
char incorrect_message[] = "Incorrect Answer!\n";
char message6[] = "Your Gold : ";
char message7[] = "%d";
char message8[] = "\n\n";
int a;
int b;
int sign_id;

int main() {
	__asm {
	    forever:
		    push offset message1
			call printf
			add esp, 4

			push offset message2
			call printf
			add esp, 4

			push offset message3
			call printf
			add esp, 4

			call get_random
			mov a, eax

			call get_random
			mov b, eax

			call get_sign

			mov sign_id, eax

			mov eax, sign_id

			cmp eax, 1
			je sign_equals_minus

			cmp eax, 2
			je sign_equals_plus

			jmp sign_equals_multiply

		sign_equals_minus:
			mov byte ptr [sign], '-'
			jmp next

		sign_equals_plus:
			mov byte ptr [sign], '+'
			jmp next

		sign_equals_multiply:
			mov byte ptr [sign], '*'
			jmp next

		next:
			push b
			push sign
			push a
			push offset message4
			call printf
			add esp, 16

			mov eax, sign_id

			cmp eax, 1
			je answer_minus

			cmp eax, 2
			je answer_plus

			jmp answer_multiply

		answer_minus:
			mov eax, a
			mov ebx, b
			sub eax, ebx
			mov ans, eax
			jmp three

		answer_plus:
			mov eax, a
			mov ebx, b
			add eax, ebx
			mov ans, eax
			jmp three

		answer_multiply:
			mov eax, a
			mov ebx, b
			mul ebx
			mov ans, eax
			jmp three

		three:
			push offset user_ans
			push offset message5
			call scanf_s
			add esp, 8

			mov eax, [ans]
			cmp eax, [user_ans]
			je correct_ans

			jmp incorrect_ans

		correct_ans:
			push offset correct_message
			call printf
			add esp, 4

			lea eax, gold
			inc dword ptr [eax]

			push offset message6
			call printf
			add esp, 4

			push gold
			push offset message7
			call printf
			add esp, 8

			push offset message8
			call printf
			add esp, 4

			jmp forever

		incorrect_ans:
			push offset incorrect_message
			call printf
			add esp, 4

			lea eax, gold
			dec dword ptr [eax]

			lea eax, gold
			cmp dword ptr [eax], 1
			jl reset_gold
			
			push offset message6
			call printf
			add esp, 4

			push gold
			push offset message7
			call printf
			add esp, 8

			push offset message8
			call printf
			add esp, 4

			jmp forever

		reset_gold:
			mov dword ptr [eax], 0

			push offset message6
			call printf
			add esp, 4

			push gold
			push offset message7
			call printf
			add esp, 8

			push offset message8
			call printf
			add esp, 4

			jmp forever
	}
}