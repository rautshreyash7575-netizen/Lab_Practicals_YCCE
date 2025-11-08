#include <stdio.h>
#define SIZE 7

void display(int hashTable[]) {
    printf("\nFinal Hash Table:\n");
    for (int i=0;i<SIZE;i++) {
        if (hashTable[i]==-1)
            printf("Slot %d : Empty\n",i);
        else
            printf("Slot %d : %d\n",i,hashTable[i]);
    }
}

void insert(int hashTable[],int key) {
    int index=key%SIZE;
    int start=index;
    while(hashTable[index]!=-1) {
        index=(index+1)%SIZE;
        if(index==start) {
            printf("Hash table full! Cannot insert %d\n",key);
            return;
        }
    }
    hashTable[index]=key;
    printf("Inserted %d at slot %d\n",key,index);
}

int main() {
    int hashTable[SIZE];
    int n,key;
    for(int i=0;i<SIZE;i++)
        hashTable[i]=-1;
    printf("Enter number of keys: ");
    scanf("%d",&n);
    printf("Enter %d keys:\n",n);
    for(int i=0;i<n;i++) {
        scanf("%d",&key);
        insert(hashTable,key);
    }
    display(hashTable);
    return 0;
}
