#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int u;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int u ) {
        
    if(root == NULL) {
    
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->u = u;

        node->left = NULL;
        node->right = NULL;
        return node;
      
    } else {
      
        struct node* cur;
        
        if(u <= root->u) {
            cur = insert(root->left, u);
            root->left = cur;
        } else {
            cur = insert(root->right, u);
            root->right = cur;
        }
    
        return root;
    }
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int u;
    struct node *left;
    struct node *right;
  
};

*/

int getHeight(struct node* root)
{

int counter_right = 0;
int counter_left = 0;   
    
    if (root == NULL)
    {
        return -1;
    }
    
         counter_left = getHeight(root->left);
        counter_left++;
         
         counter_right = getHeight(root->right);
         counter_right++; 
         
        if (counter_left > counter_right)
        {
            return counter_left;
        }
              
         return counter_right;     
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int u;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &u);
        root = insert(root, u);
    }
  
    printf("%d",getHeight(root));
    return 0;
}
