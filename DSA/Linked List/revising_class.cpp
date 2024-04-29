#include<iostream>
using namespace std;
 
class Student{  //user defined data type
public:
    string name;
    int rollno;
    float marks;
    Student(string name, int rollno, float marks){
        this->name = name;
        this->rollno = rollno;
        this->marks = marks;
    }
};

int main(){
    Student* s = new Student("Ayushi", 16, 92.6);
    cout << s->name << endl;

}