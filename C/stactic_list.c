# include <stdio.h>
# define MAX 100

struct list {
    float arr[MAX];
    int count;
};

struct list* createList();
int insert(struct list *l1, float n);
int find(struct list *l1, float n);
int valueAt(struct list *l1, int index);
int delete(struct list *l1, float n);

struct list* createList(){
    // Function to set value of count as zero or to initialize the array;
    struct list l1;
    l1.count = 0;   //*l1.count = 0;
    return l1;
}

int insert(struct list *l1, float n) {
    // Function to insert the value n at ordered position
    int low = 0, high = l1->count-1;
    
}