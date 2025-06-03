#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define QueueLimit 20
#define LabelLimit 6

typedef struct {
    char label[LabelLimit];
} QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue, const char *name);

int main()
{
    QueueType mainBelt, skgBelt, athBelt;
    QueueElementType item;
    char label[LabelLimit];

    CreateQ(&mainBelt);
    CreateQ(&skgBelt);
    CreateQ(&athBelt);

    while(1)
    {
        printf("Give Airport Name(SKG or ATH , END to finish!):");
        scanf("%s", label);

        if(strcmp(label, "END") == 0) break;

        if(strcmp(label, "SKG")== 0 || strcmp(label, "ATH") == 0)
        {
            strcpy(item.label, label);
            AddQ(&mainBelt,item);

        }else{
            printf("Wrong Label, Try again!\n");
        }
    }

    printf("Belt\n");
    TraverseQ(mainBelt, "Main Belt");

    while (!EmptyQ(mainBelt)) {
        RemoveQ(&mainBelt, &item);
        if (strcmp(item.label, "SKG") == 0) {
            AddQ(&skgBelt, item);
        } else if (strcmp(item.label, "ATH") == 0) {
            AddQ(&athBelt, item);
        }
    }

    printf("Belt ATH\n");
    TraverseQ(athBelt, "ATH Belt");

    printf("Belt SKG\n");
    TraverseQ(skgBelt, "SKG Belt");

    printf("Belt\n");
    TraverseQ(mainBelt, "Main Belt");





    return 0;
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

bool EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

bool FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue, const char *name)
{
    int current = Queue.Front;
    if(EmptyQ(Queue))
    {
        printf("Empty Queue!\n");
        return;
    }

    while(current != Queue.Rear)
    {
        printf("%s\n", Queue.Element[current].label);
        current = (current +1) % QueueLimit;
    }
}
