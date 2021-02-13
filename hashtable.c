#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void insert(int,char);
int hashCode(int);
void display();
struct Data *search(int);

struct Data {

    char data;
    int key;

};

struct Data* table[SIZE];
struct Data* init;
struct Data* item;




int main()
{
   init = (struct Data*) malloc(sizeof(struct Data));
   init->data = 'o';
   init->key = -1;

   insert(1, 'a');
   insert(2, 'l');
   insert(42, 'i');
   insert(4, 'e');
   insert(12, 'n');
   insert(14, 'u');
   insert(17, 'm');

   item = search(1);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
   //display();

    return 0;
}

int hashCode(int key){
    return key % SIZE;
}

void insert(int key, char data){

    struct Data *item = (struct Data*) malloc (sizeof(struct Data));
    item->data = data;
    item->key = key;

    int index = hashCode(key);

    while(table[index] != NULL && table[index]->key != -1){

        ++index;
        index %=SIZE;

    }

    table[index] = item;


}

void display() {
   int i = 0;

   for(i = 0; i<SIZE; i++) {

      if(table[i] != NULL){
         printf("[%d] -> [%c]\n",table[i]->key,table[i]->data);
      }
   }

   printf("\n");
}

struct Data *search(int key) {
   //get the hash
   int index = hashCode(key);

   //move in array until an empty
   while(table[index] != NULL) {

      if(table[index]->key == key)
         return table[index];

      //go to next cell
      ++index;

      //wrap around the table
      index %= SIZE;
   }

   return NULL;
}
