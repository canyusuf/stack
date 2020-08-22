// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct s {
	int StackLimit;
	int StackLimit2;
	int top;
	int top2;
	int *stack1;
	int *stack2;
	int *stackyd;

};
typedef s stack;


stack * tanim() {
	stack *s = (stack *)malloc(sizeof(stack)); //belleckte stack oluşturuyorum
	s->stack1 = NULL;
	s->stack2 = NULL;
	s->stackyd = NULL;
	s->StackLimit = 3;
	s->StackLimit2 = 3;
	s->top = -1;
	s->top2 = -1;
	return s;
}

int StackLimit = 3; // numaramuın son harfi 3 olduğu için 3 boyutlu stack
int StackLimit2 = 3;
int *stack1;
int *stack2;// pointer olarak kullanıyorum
int *stackyd;
int top = -1;
int top2 = -1;

int isFull() {
	if (top >= (StackLimit - 1)) {
		return 1;

	}
	else {
		return 0;

	}
}
int isFull2() {
	if (top2 >= (StackLimit2 - 1)) {
		return 1;

	}
	else {
		return 0;

	}
}

int isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
int isEmpty2() {
	if (top2 == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int item, stack *s) {
	if (isFull()) {
		
		//int değer tipinde dinamki olarak bellekde benim istediğim kadar yer ayırıyorum
		int *stack3; //stack3 tanımlıyorum
		StackLimit = StackLimit * 2; //tanımladığım stacğin boyutunu 2 katına çıkarıyorum
		stack3 = (int*)malloc(sizeof(int)*s->StackLimit);// stack2 ye bellekde yer açıyorum
		for (int i = 0; i <= s->top; i++) {
			stack3[i] = s->stack1[i];

		}// stackdeki elemanları stack 2 ye dolduruyorum
		free(s->stack1);//stack null oldu
		s->stack1 = stack3; // stack artık stack2 oldu burdada 

	}
	top++;
	stack1[top] = item;
	printf("---- INT Stack'in Boyutu=%d ---- \n", StackLimit);
	printf("---- Toplam Eklenen Int Sayisi==>%d ----\n", top);
	printf("---- Eklenen Int==>%d ---- \n", item);

}
void push1(int item2, stack *s) {
	if (isFull2()) {

		//int değer tipinde dinamki olarak bellekde benim istediğim kadar yer ayırıyorum
		int *stack3; //stack3 tanımlıyorum
		StackLimit2 = StackLimit2 * 2; //tanımladığım stacğin boyutunu 2 katına çıkarıyorum
		stack3 = (int*)malloc(sizeof(int)*s->StackLimit2);// stack2 ye bellekde yer açıyorum
		for (int i = 0; i <= s->top2; i++) {
			stack3[i] = s->stack2[i];

		}// stackdeki elemanları stack 2 ye dolduruyorum
		free(s->stack2);//stack null oldu
		s->stack2 = stack3; // stack artık stack2 oldu burdada 

	}
	

	top2++;
	stack2[top2] = item2;
	printf("---- Char Stack'in Boyutu=%d ----\n", StackLimit2);
	printf("---- Toplam Eklenen Char Sayisi==>%d ----\n", top2);
	printf("---- Harfe Donusmeden Onceki Sayi Hali==>%d ----\n", item2);
	char ch = item2;
	printf("---- Eklenen Char==> %c  ---- \n", ch);

}


void pop(stack *s) {
	if (isEmpty()) {
		printf("\n Stack Bos Eleman Cıkaramazsiniz");

	}
	else {
		if (s->top <= s->StackLimit / 3) {
			s->StackLimit = s->StackLimit / 2;
			int *stack2 = (int*)malloc(sizeof(int)*s->StackLimit);
			for (int i = 0; i <= s->top; i++) {
				stack2[i] = s->stack1[i];

			}// eleman çıkarmaya başladığımda boyutun3 de 1 ine düştüğü an stanğin boyutunu yarıya indiriyoruz push dakinin tam tersi işlem
			free(s->stack1); // belleği etkin şekilde kullanıyoruz;
			s->stack1 = stack2;

		}
		printf("\n Cıkardiginiz Eleman = %d", s->stack1[top]);
		s->top--;
		printf("------ top==>%d", s->top);
		printf("\n Stack Boyutu=%d ", s->StackLimit);
	}
}

void peek() {
	if (isEmpty()) {
		printf("\n Stack Bos En Tepede Eleman Yok");

	}
	else {
		printf("\n Stack Tepesindeki Eleman = %d \n", stack1[top]);
	}
}


void PrintStack(stack *s) {
	printf("\n***********\n");
	for (int i = 0; i <= s->top; i++) {

		printf("%c ==>", s->stack1[i]);
	}
	printf("\n *********** \n");
}

void yerDegistir(stack *s, stack * s1) {
	stackyd = (int*)malloc(sizeof(int)*StackLimit);
	stack *stackyd = tanim();
	
	printf("---------- Yer Degistirme-----------------\n");
	for (int i = 0; i < s->top; i++) {

		push(stack1[i], stackyd);


		
	}

	
}







int main() {

	stack1 = (int*)malloc(sizeof(int)*StackLimit);//Int larımı tutuyor
	stack2 = (int*)malloc(sizeof(int)*StackLimit);//charlarımı tutuyor
	

	stack *stack1 = tanim();
	stack *stack2 = tanim();
	
	int i = 0;
	srand(time(0));// srand kullandım her defasında farklı rastgele sayı üretsin diye
	for (i = 0; i<100; i++) {// 100 tane sayı  üretiyor
		int sayi = rand() % 209 + 47; // burda da 48ve 255 arası rastgele sayılar üretiyor
		if (96 < sayi && sayi< 123) {
			printf("\n---CHAR Stack----- \n");
			push1(sayi, stack2);
		}else {
			printf("\n---INT Stack----- \n");
			push(sayi, stack1);
				

		}
	}
	yerDegistir(stack1, stack2);
	

	
	

	getchar();

}