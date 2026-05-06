#include<iostream>
#include<ios>
#include<cstring>
#include<limits>
#define MAX 20
using namespace std;
typedef struct Node{
    struct Node *LC;
    char data;
    struct Node *RC;
}NODE;
class Stack{
    private:
    NODE *stk[MAX];
    int top;
    public:
    Stack(){
        top=-1;
    }
        void push(NODE *val){
        if(!isFull())
        stk[++top]=val;
        else
        cout<<"Stack is Full!";
        }
        NODE* pop(){
            if (!isEmpty())
        return stk[top--];
        else
        cout<<"\nStack is Empty!";
        return NULL;
        }
        bool isFull(){
            return (top==MAX-1);
        }
        bool isEmpty(){
            return (top==-1);
        }
    };
    class ExpressionTree
    {
        private:
        char exp[20];
        NODE* root;
        public:
        ExpressionTree(){
            root=NULL;
        }
        void readPrefixExp(){
            cout<<"Enter the expressionPrefix::";
            cin>>exp;
        }
    void printPrefixExp(){
        cout<<"The expressionin Pefix is:"<<exp;
    }
    bool isOperator(char token){
        return (token=='+'||token=='-'||token=='*'||token=='/');
    }
    bool isOperand(char token){
        return(token<='z' && token>='a')||(token<='Z' && token>='A');
    }
    void generateExpTree(){
        Stack S;
        NODE* p;
        for(int i=strlen(exp)-1;i>=0;i--){
            p=new NODE;
            p->LC=NULL;
            p->data=exp[i];
            p->RC=NULL;
            if(isOperand(exp[i]))
            S.push(p);
            else if(isOperator(exp[i])){
            p->LC=S.pop();
            p->RC=S.pop();
            S.push(p);
            }
        }
        root=S.pop();
    }
    void displayET(NODE* t){
        if(t){
            displayET(t->LC);
            cout<<t->data<<" ";
            displayET(t->RC);   

        }
        }
        NODE* getroot(){
            return root;
        }
       void nonRecursivePost(NODE* root)
		{
			if (root == NULL)
				return;

			//Local stacks - stack1 and stack2
			Stack stack1, stack2;
            NODE* node;
			// Push root to first stack
			stack1.push(root);
			

			// Repeat untill first stack is not empty
			while (!stack1.isEmpty()) {
				// pop node from stack1 and push to stack2
				node = stack1.pop();//pop or remove that node from stack1
				stack2.push(node);//save it in stack2

				// push left and right node of current node popped from stack1 
				if (node->LC)
					stack1.push(node->LC);
				if (node->RC)
					stack1.push(node->RC);
			}

			// if stack2 is not empty print the nodes
			while (!stack2.isEmpty()) {
				node = stack2.pop();
				cout << node->data << " ";
			}	
		}
	
};

int main(){
	ExpressionTree e1;
  	int choice=0;
	
  	while(choice!=6)
  	{	
  		cout<<"\n*************Expression Tree***************";
  		cout<<"\n1. Read Expression";
  		cout<<"\n2. Print Expression";
  		cout<<"\n3. Build Tree ";
  		cout<<"\n4. Print Tree Inorder";
		cout<<"\n5. Print Tree Non Recurssive Postorder";
  		cout<<"\n6. Exit Application";
  		cout<<"\nEnter your choice::";
		cin>>choice;
  		switch (choice){
  			case 1:
				e1.readPrefixExp();
  			 	break;
  			case 2:
  			 	e1.printPrefixExp();
  			 	break;
  			case 3:
  			 	e1.generateExpTree();
  			 	break;
  			case 4:
  			 	e1.displayET(e1.getroot());
  			 	break;
			case 5:
  			 	e1.nonRecursivePost(e1.getroot());
  			 	break;
  			case 6:
				cout<<"\nThanks for using Application!";
  			 	break;
  			default :
  			    cout<<"\nWrong choice!!";
  		}
  	}
	
	return 0;
}

