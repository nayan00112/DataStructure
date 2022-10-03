/*======================= STACK =======================*/

#include <stdio.h>
#include <stdlib.h>

void push(int *, int *, int);
void pop(int *, int *);
void peep(int *, int *);
void display(int *, int *);
void change(int *, int *);

void main()
{
    int n, ch;
    int *ptr, *top;
    char test = 'y';
    *top = -1;
    printf("Enter number of max. element: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    while (test == 'y')
    {
        printf("\n1. push\n2. pop\n3. peep\n4. change\n5. display\n6. exit\n");
        printf("Select Number: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(ptr, top, n);
            break;
        case 2:
            pop(ptr, top);
            break;
        case 3:
            peep(ptr, top);
            break;
        case 4:
            change(ptr, top);
            break;
        case 5:
            display(ptr, top);
            break;
        case 6:
            test = 'n';
            break;
        default:
            printf("Invalide Inpute");
            break;
        }
    }
}

void push(int *ptr, int *top, int n) // Verified OK
{
    if (*top < n - 1)
    {
        *top = *top + 1;
        printf("PUSH: Enter Element(%d of %d) Number: ", *top + 1, n);
        scanf("%d", (ptr + (*top)));
    }
    else
    {
        printf("\nPUSH: STACK IS OVERFLOW...\n");
    }
}

void pop(int *ptr, int *top) // Verified OK
{
    if (*top >= 0)
    {
        printf("POP: %d\n", *(ptr + (*top)));
        *top = *top - 1;
    }
    else
    {
        printf("\nPOP: STACK IS UNDERFLOW...\n");
    }
}

void peep(int *ptr, int *top) // Verified OK
{
    if (*top == (0 - 1))
    {
        printf("PEEP: Empty Stack");
    }
    else
    {
        int temp;
        printf("Which Element? ");
        scanf("%d", &temp);
        if (0 <= ((*top) - temp + 1))
        {
            printf("PEEP: Your element is: %d\n", *(ptr + ((*top) - temp + 1)));
        }
        else
        {
            printf("PEEP: UNDEERFLOW...\n");
        }
    }
}

void change(int *ptr, int *top) // Verified OK
{
    if (*top == (0 - 1))
    {
        printf("CHANGE: Empty Stack");
    }
    else
    {
        int temp;
        printf("Which Element? ");
        scanf("%d", &temp);
        if (0 <= ((*top) - temp + 1))
        {
            printf("\nEnter New Value: ");
            scanf("%d", (ptr + ((*top) - temp + 1)));
        }
        else
        {
            printf("CHANGE: UNDEERFLOW...\n");
        }
    }
}

void display(int *ptr, int *top) // Verified OK
{
    if (*top <= (0 - 1))
    {
        printf("DISPLAY: EMPTY...\n");
    }
    else
    {
        printf("\nAll Elements are:");
        for (int i = 0; i <= *top; i++)
        {
            printf("\n%d", *(ptr + i));
        }
        printf("\n");
    }
}
