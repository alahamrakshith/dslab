#include <stdio.h>
struct node
{
    int data;
    struct node* link;
};
struct node *root=NULL;
struct node *t;
struct node *last;
int main()
{   int n,i;
    printf("Enter no:of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&t->data);
        t->link=NULL;
        if(root==NULL)
            root=t;
        else
            last->link=t;
        last=t;
    }
    struct node *current,*prev=NULL;
    current=root;
    while(current!=NULL)
    {
       prev=root;
       current=root->link;
       root=root->link;
       prev->link=NULL;
       while(root!=NULL)
       {
           root=root->link;
           current->link=prev;
           prev=current;
           current=root;
       }
       root=prev;
    }
    printf("Reversed list is\n");
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("list empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
    printf("\n\n");
}
