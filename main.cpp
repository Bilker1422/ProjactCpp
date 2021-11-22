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

int main(){

}