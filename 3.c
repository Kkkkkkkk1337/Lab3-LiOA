// '+' - добавить элемент
// '-' - удалить элемент
// 'f' - найти элемент
// '+' , 'print' - вывести стек на экран

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <malloc.h>
#include <string.h>

struct node
{
	char inf[256];  // информация
	struct node* next;  // ссылка на следующий элемент 
};

/* Функция просмотра всего стека */
int review(struct node** top) {
	struct node* gg = *top;
	if (gg == NULL) {
		printf("Стек пуст!\n");
		return 0;
	}
	printf("\n");
	while (gg) {
		printf("%s\n", gg->inf);
		gg = gg->next;
	}
	printf("\n");
	return 0;
}

/* Функция для создания элемента стека */
struct node* get_struct(struct node** top)
{
	struct node* p = NULL;
	p = (node*)malloc(sizeof(struct node));  // создаем новый узел

	char s[256];
	printf("Введите название объекта: ");  // вводим данные
	scanf("%s", &s);
	if (*s == 0) {
		printf("Запись не была произведена!\n");
		return 0;
	}

	if (strcmp("print", s) == 0) {
		review(top);
		return 0;
	}

	if (p != NULL) {
		strcpy(p->inf, s);
		p->next = *top;  // устанавливаем указатель next так, чтобы он указывал на текущий верхний узел списка
		*top = p;  // обновляем верхний указатель
	}
	else {
		printf("\nHeap Overflow");
		exit(1);
	}
}

/* Функция поиска элемента стека */
struct node* find(struct node** top)
{
	struct node* struc = *top;
	if (top == NULL)
	{
		printf("Стек пуст!\n");
	}

	char name[20];
	printf("Введите название элемента для поиска: ");
	scanf("%s", &name);

	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			printf("Элемент найден)\n");
			return 0;
		}
		struc = struc->next;
	}
	printf("Элемент не найден(\n");
	return 0;
}

/* Функция удаления элемента стека (последнего) */
void pop(struct node** top)
{
	struct node* node = *top;
	if (*top == NULL)
	{
		printf("Стек пуст!\n");
		exit(1);
	}

	printf("Верхний удаляемый элемент: %s\n", (*top)->inf);  // принять к сведению данные верхнего узла
	node = *top;
	*top = (*top)->next;  // обновляем верхний указатель, чтобы он указывал на следующий узел
	free(node);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct node* top = NULL;
	while (true) {
		int i = _getch();
		switch (i) {
		case '+':
			get_struct(&top);
			break;
		case '-':
			pop(&top);
			break;
		case 'f':
			find(&top);
			break;
		default:
			break;
		}
	}
	return 0;
}