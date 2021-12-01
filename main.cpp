#include <iostream>
#include <string>
#define MAX 6
using namespace std;


struct Courses{
    int CRN;
    string course;
};
struct Student{
    int studentID;
    string studentName;
    int studentLevel;
    float GPA;
    Courses list[MAX];
};
struct Node{
    Student data;
    Node *pre;
    Node *next;
}*tail=NULL,*head=NULL;

CreateEmpty(){
	Node *temp;
	temp = new Node;
	
	
	cout <<"Enter the name :";
	cin>>temp->data.studentID;
	cout<<"\nEnter the ID :";
	cin>>temp->data.studentID;
	cout<<"\nEnter the GPA :";
	cin>>temp->data.GPA;
	cout<<"\nEnter the Level:";
	cin>>temp->data.studentLevel;
	cout<<"\n Courses :";
	for(int x = 0; x >=5; x++){

		temp->data.list[x];
		
	cout << " Enter the CRN:";
		
	
		cout << " Enter the name of the course:";
	
		

		}
	
	temp->next=NULL;
	temp->pre = NULL;
	
	};
	void InsertRear(Node *tail , Node *head,Node *temp){
		
		CreateEmpty();
		
		if(head == NULL){
			head = temp;
			temp->next=NULL;
			temp->pre=NULL;
			tail = temp;
		}
		else
		{
			temp->pre= tail;
			tail->next= temp;
			temp->next=NULL;
			tail= temp;
			
			
		}
		
		
		
		
}
	
int main(){

}
