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





//
Courses List(Node *list, int n);

Node *CreateEmpty(int ID);
Node *Tailsearch(int find);
Node *HeadSearch(int find);
Node *SearchForID();
void Display(Node *node);
void InsertRear(int ID);



int main(){
    int ID = 0;
    int choice;

    do
    {
        cout <<"Your Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                InsertRear(ID+1);
                ID++;
                break;
            case 2:
                SearchForID();
                break;
        }
    } while (choice != 3);
    
}

Courses List(Node *list, int n){
    Courses *temp = new Courses;
    if (n != -1){
        cout << "Enter CRN: ";
        cin >> temp ->CRN;
        cin.ignore();
        cout << "Enter Name of coures: ";
        getline(cin,temp ->course);
        List(list,n-1);
        return list -> data.list[n];
    }
    return *temp;
}
Node *CreateEmpty(int ID)
{
    Node *temp = new Node;
    temp ->data.studentID = ID;
    cout << temp ->data.studentID;
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
    List(temp,counter-1);

    temp ->next = NULL;
    temp ->pre = NULL;
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
}
Node *TailSearch(int find){
    Node *cur = tail;
    while (cur->data.studentID != find && cur->pre != NULL){
        cur = cur -> pre;
    }
    return cur;
}
Node *HeadSearch(int find){
    Node *cur = head;
    while (cur->data.studentID != find && cur->next != NULL){
        cur = cur -> next;
    }
    return cur;
}
Node *SearchForID(){
    Node *temp = head;
    int check = tail ->data.studentID /2;
    int find;
    cout << "ID of student: ";
    cin >> find;
    int choice = (check <= find) ? 1: 0;
    switch(choice){
        case 0:
            cout << "Head";
            temp = HeadSearch(find);
            Display(temp);
            break;
        case 1:
            cout << "tail";
            temp = TailSearch(find);
            Display(temp);
            break;
    }
    

    if (temp ->data.studentID != find){
        return NULL;
        cout << "Not found";
    }
    return temp;

}

void Display(Node *node){
    cout << node ->data.studentID << endl;
    cout << node ->data.studentName<< endl;
    cout << node -> data.studentLevel<< endl;
    cout << node -> data.GPA<< endl;
}