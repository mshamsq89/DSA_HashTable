#include<stdio.h>
#include<stdlib.h>

#define MAX 20

typedef struct {
    int key;
    int data;
}DataItem;

DataItem* hashArray[MAX];
DataItem* dummyItem;
DataItem* item;

int hashCode(int key)
{
    return (key % MAX);
}

void display()
{
    int i = 0;
    for(i=0; i<MAX; i++)
    {
        if(hashArray[i] != NULL)
            printf("(%d, %d))",hashArray[i]->key,hashArray[i]->data);
        else
            printf("(~,~)");
    }
    printf("\n");
}
void insert(int key, int data)
{
    item = (DataItem *)malloc(sizeof(DataItem));
    item->data = data;
    item->key = key;

    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        hashIndex++;
        hashIndex % MAX;
    }
    hashArray[hashIndex] = item;
}

DataItem* search(int key)
{
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key)
        {
            return hashArray[hashIndex];
        }
        hashIndex++;
        hashIndex %= MAX;
    }
    return NULL;
}

void delete(int key)
{
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key)
        {
            item = hashArray[hashIndex];
            free(item);
            hashArray[hashIndex] = dummyItem;
            return;
        }
        hashIndex++;
        hashIndex %= MAX;
    }
}
int main()
{
    dummyItem = (DataItem *)malloc(sizeof(DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;

    insert(5,55);
    insert(1,11);
    insert(4,44);
    insert(3,33);
    insert(6,66);
    insert(7,77);
    insert(2,22);
    display();
    delete(3);
    delete(7);
    display();   
    return 0;
}