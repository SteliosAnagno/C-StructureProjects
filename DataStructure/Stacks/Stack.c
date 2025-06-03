#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int Boxes;
    float totalWeight;
    char expiryDate[11];
}Cargo;

typedef Cargo StackElementType;
typedef struct StackNode *StackPointer;

typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

void CreateStack(StackPointer *Stack);
bool EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);
int IndexOfMin(StackPointer S1, StackPointer S2, StackPointer S3);
int StackSize(StackPointer Stack);


int main()
{
    StackPointer warehouse1, warehouse2, warehouse3;
    int n, i;
    Cargo cargo;
    int index;

    CreateStack(&warehouse1);
    CreateStack(&warehouse2);
    CreateStack(&warehouse3);

    printf("PLithos Fortiwn: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Arithmos kivwtiwn gia to %do fortio: ", i+1);
        scanf("%d", &cargo.Boxes);
        printf("Synoliko baros gia to %do fortio: ", i+1);
        scanf("%f", &cargo.totalWeight);
        printf("Imeromhnia liksis gia to %do fortio: ", i+1);
        scanf("%s", cargo.expiryDate);

        index = IndexOfMin(warehouse1, warehouse2, warehouse3);

        if (index == 1)
            Push(&warehouse1, cargo);
        else if (index == 2)
            Push(&warehouse2, cargo);
        else
            Push(&warehouse3, cargo);
    }

    printf("\nWAREHOUSE 1\n");
    TraverseStack(warehouse1);

    printf("\nWAREHOUSE 2\n");
    TraverseStack(warehouse2);

    printf("\nWAREHOUSE 3\n");
    TraverseStack(warehouse3);


    return 0;
}

int StackSize(StackPointer Stack)
{
    int sum=0;
    while(Stack != NULL)
    {
        sum += Stack->Data.Boxes;
        Stack = Stack->Next;
    }
    return sum;
}

int IndexOfMin(StackPointer S1, StackPointer S2, StackPointer S3)
{
    int size1, size2, size3;
    size1 = StackSize(S1);
    size2 = StackSize(S2);
    size3 = StackSize(S3);
    int minSize = size1;
    int minIndex = 1;

    if(size2 <= minSize)
    {
        minSize = size2;
        minIndex = 2;
    }
    if(size3 <= minSize)
    {
        minSize = size3;
        minIndex = 3;
    }

    return minIndex;

}

void TraverseStack(StackPointer Stack)
{
    while(Stack != NULL)
    {
        printf("%d  %.2f  %s", Stack->Data.Boxes, Stack->Data.totalWeight, Stack->Data.expiryDate);
        Stack = Stack->Next;
    }
}


void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

bool EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

