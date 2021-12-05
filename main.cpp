#include <iostream>
#include <string>
#include <limits>

using namespace std;


struct Course{
    int CRN;
    Course *next = NULL;
};
struct Student{
    int studentID;
    string studentName;
    int studentLevel;
    float GPA;
    Course *list;
};
struct Node{
    Student data;
    Node *pre;
    Node *next;
}*tail=NULL,*head=NULL;

Course *List(int n){
    Course *Head = new Course;
    Head ->next=NULL;

    if (n != 0){
        cout << "Enter CRN: ";
        cin >> Head ->CRN;
        Head -> next = List(n-1); 
    }
    return Head;
}

Node *CreateEmpty(int ID)
{
    Node *temp = new Node;
    temp ->next = NULL;
    temp ->pre = NULL;

    temp ->data.studentID = ID;
    cin.ignore();
    cout << "Name of Student: ";
    getline(cin , temp -> data.studentName);
    cout << "Level: ";
    cin >> temp ->data.studentLevel;
    cout << "GPA: ";
    cin >> temp ->data.GPA;

    int counter = -1;
    cout << "How many coures to regsiter: ";
    cin >> counter;
    temp ->data.list = List(counter);

    return temp;
}
void InsertRear(int ID){
    Node *temp = CreateEmpty(ID);
    if (head == NULL)
        head = tail = temp;
    else{
        temp ->pre = tail;
        tail ->next = temp;
        tail = temp;
    }
    cout << endl;
}
Node *TailSearch(int find){
    Node *cur = tail;
    if (find  > cur->data.studentID )
        return cur;
    while (cur->data.studentID != find && cur->pre != NULL){
        cur = cur -> pre;
    }
    return cur;
}   
Node *HeadSearch(int find){
    Node *cur = head;
    while ( cur->data.studentID != find && cur->next != NULL){
        cur = cur -> next;
    }
    return cur;
}
Node *SearchForID(){
     Node *temp = head;
    if (head != NULL){
        int check = tail ->data.studentID /2;
        int find;
        cout << "ID of student: ";
        cin >> find;
        cout << endl;
        int choice = (check < find) ? 1: 0;
        switch(choice){
            case 0:
                temp = HeadSearch(find);
                break;
            case 1:
                temp = TailSearch(find);
                break;
        }
        if (temp ->data.studentID != find){
            cout << "not found\n";
            return NULL;
        }
        return temp;
    }
    cout << "\nUnderflow\n" << endl;
    return NULL;
}
void Display(Node *node){
    if (node != NULL){
        cout << "Student Info: " << endl;
        cout << "ID: "<<node ->data.studentID << endl;
        cout << "Name: "<<node ->data.studentName<< endl;
        cout << "Level: "<<node -> data.studentLevel<< endl;
        cout << "GPA: "<< node -> data.GPA<< endl;
        Course *temp = node->data.list;
        cout << "\nRegistered courses are:\n";
        while(temp ->next != NULL){
            cout <<"CRN: "<< temp->CRN << endl;
            temp = temp ->next;
        }
        cout << endl;
    }
}
	
int main(){
    int ID = 0;
    int choice;

    do
    {
        try{
            cout << "1.To insert new Student\n2.To search for student using his ID\n3.To search for coures\n4.To search for range GPA\n5.To delete using his ID\n6.To exit\n";
            cout <<"Your Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                    cout << endl;
                    InsertRear(ID+1);
                    ID++;
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                   
                    break;
                case 5:
                    break;
                    
            }
            if (!cin.good())
                throw -1;
        }
        catch (...){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 6);
    
}

