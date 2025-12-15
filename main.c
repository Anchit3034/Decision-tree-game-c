#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char *question;
    struct node *yes;
    struct node *no;
}node;
int yes_no(char *question){
    char answer[3];
    printf("%s ? (y/n):",question);
    fgets(answer,3,stdin);
    return answer[0]=='y';
}
node* create(char *question){
    node *temp=malloc(sizeof(node));
    temp->question=strdup(question);
    temp->yes=NULL;
    temp->no=NULL;
    return temp;
}
void release(node *temp){
    if (temp)
    {
        if(temp->no){
            release(temp->no);
        }
        if(temp->yes){
            release(temp->yes);
        }
        if(temp->question){
            free(temp->question);
        }
        free(temp);
    }
    
}
int main(){
    char question[80];
    char suspect[20];
    puts("Criminal records: (With Questions)");
    node *startnode=create("Does He have mustache");
    startnode->yes=create("Mickey");
    startnode->no=create("Donald");
    node *current;
    do{
        current=startnode;
        while(1){
            if(yes_no(current->question)){
                if(current->yes){
                    current=current->yes;  
                }else{
                    printf("Suspect identified\n");
                    break;
                }
            }else if(current->no){
                current=current->no;
            }else{
                /*Make the yes-node the new suspect name*/
                printf("Who's the suspect?");
                fgets(suspect,20,stdin);
                node *yes_node=create(suspect);
                current->yes=yes_node;
                /*Make the no_node a copy of current node's question*/
                node *no_node=create(current->question);
                current->no=no_node;
                /*Then replace the current question with new qeustion*/
                printf("Give me a question that is True for %sbut not for %s : ",suspect,current->question);
                fgets(question,80,stdin);
                free(current->question);
                current->question=strdup(question);
                break;
            }

        }
    }while(yes_no("Run again?"));
    release(startnode);
    return 0;
}




