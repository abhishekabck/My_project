# include <stdio.h>
# include <stdlib.h>

// Defining the structure of the node containing the polynomial
struct node {
    float coff;      // Defining the coff as float so the fractional part can also be calculated
    int degree;      // Degree of the and node or term of polynomial
    struct node* next;     // Linking node block
};


/*----------Defining various helping functions---------------*/

// Function to create a node in heap which can be linked to other node
struct node* NewNode(float coff, int degree){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coff = coff;
    new_node->degree = degree;
    return new_node;
}


// Defining function prototype to avoid order issue
struct node* input_polynomial();
// struct node* insert_after(struct node* node, struct node* newNode);
struct node* insert_in(struct node* poly, struct node* node);
struct node* poly_addition(struct node* poly1, struct node* poly2);
struct node* multiply_scalar(struct node* poly, float scalar);
struct node* multiply_poly(struct node* poly1, struct node* poly2);
struct node* divide_scalar(struct node* poly, float scalar);
void display(struct node* polynomial);



void display(struct node* polynomial){
    // definition for displaying function
}


// Defining various functions which can be used to perform calculations for polynomial
struct node* input_polynomial(){
    struct node* poly = NULL;
    float coff;
    int degree;
    char choice;
    int p_degree = INT_MAX;
    do {
        printf("\nEnter Coff. of the term : ");
        scanf("%d", &coff);
        printf("\nEnter Degree of the term : ");
        scanf("%f", &degree);
        // Inserting values of polynomial in the linked list
        poly = insert_in(poly, NewNode(coff, degree));
        printf("\n Do you want to add another term (y/n): ");
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

struct node* insert_in(struct node* poly, struct node* node){
    /* Function which efficiently adds new Polynomial term to the newNode */
    // Case First: If Either of them is NULL
    if (poly == NULL || node == NULL){
        return (poly == NULL)? node: poly;
    }
    
    // Case Last: None of them are NULL
    struct node* temp = poly;
    while (temp->next != NULL){
        temp = temp->next;
    }temp->next=node;
    return poly;
}



struct node* poly_addition(struct node* poly1, struct node* poly2){
    /*
    Function which efficiently adds all the nodes of the both
    polynomials and then returns a new polynomial as their addition.*/
    if (poly1 == NULL || poly2 == NULL){
        return (poly1 == NULL)?poly2:poly1;
    }

    // case when none of the polynomial is empty
    struct node* result = NULL, *temp1 = poly1, *temp2 = poly2;
    while (temp1 == NULL || temp2 == NULL){
        if (temp1->degree>temp2->degree){
            result = insert_in(result, NewNode(temp1->coff, temp1->degree));
            temp1 = temp1->next;
        }else if (temp1->degree == temp2->degree){
            result = insert_in(result, NewNode(temp1->coff + temp2->coff, temp1->degree));
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else {
            result = insert_in(result, NewNode(temp2->coff, temp2->degree));
            temp2 = temp2->next;
        }
    }
    return result;
}

int main(){
    struct node* poly = input_polynomial();
    struct node* poly2 = input_polynomial();
    struct node* add = poly_addition(poly, poly2);
    struct node* temp = add;
    while (temp->next != NULL){
        printf("%.2fx^(%d) + ", temp->coff, temp->degree);
        temp = temp->next;
    }
    printf("%.2f", temp->coff);

    return 0;
}