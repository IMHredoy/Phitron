#include <iostream>
#include <cstdio>


using namespace std;

class student
{
    public:
        string name;
        char section;
        int roll;
    protected:
        int english_marks;
    private:
        string password;
    public:
        void set_marks(int m)
        {
            english_marks = m;
        }
        void set_password(string p)
        {
            password = p;
        }
        int get_marks()
        {
            return english_marks;
        }
        void update_marks(string pass, int marks)
        {
            if(pass == password)
            {
                english_marks = marks;
            }
            else
            {
                cout << "Your password doesn't match!" << endl;
            }
        }
};

int main()
{
    // Taking all information of students;
    int n;
    cin >> n;
    getchar();
    student pupil[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Enter your Name: ";
        getline(cin, pupil[i].name);
        cout << "Enter your section: ";
        cin >> pupil[i].section;
        cout << "Enter your roll: ";
        cin >> pupil[i].roll;
        cout << "Enter your english Marks: ";
        int m;
        cin >> m;
        pupil[i].set_marks(m);
        string pass;
        cout << "Enter your password: ";
        cin >> pass;
        pupil[i].set_password(pass);
        getchar();
    }
    cout << endl;

    int marks, r;
    string pass;
    //query for individual students.
    while (true)
    {
        cout << "Roll ";
        cin >> r;
        cout << "Marks: ";
        cin >> marks;
        cout << "Password: ";
        cin >> pass;
        bool not_found = true;
        for(int i = 0; i < n; i++)
        {
            if(r == pupil[i].roll)
            {
                pupil[i].update_marks(pass, marks);
                not_found = false;
                break;
            }
        }
        if(not_found)
        {
            cout << "There is no students with this roll" << endl;
        }
        getchar();
        cout << "Do you want terminate : then press t ";
        if(getchar() == 't') break;
    }
    
    //printing information of students.
    for(int i = 0; i < n; i++)
    {
        cout << "Student " << i+1 << " details:" << endl;
        cout << "Name : " << pupil[i].name << endl;
        cout << "Section : " << pupil[i].section << endl;
        cout << "Roll : " << pupil[i].roll << endl;
        cout << "English Marks: " << pupil[i].get_marks() << endl;
    }
    return 0;
}
