#include <iostream>
using namespace std;
class Employee {
public:
    int salary;

    Employee(double salary)
        :salary(salary) {}

    virtual double calculateBonus() {
        std::cout << "Calculating generic bonus" << std::endl;
        return salary * 0.08;
    }

    virtual ~Employee() {} // Virtual destructor for proper cleanup
};

class Manager : public Employee {
public:
    

    Manager(double salary) : Employee(salary){}

    double calculateBonus(){
        return salary * 0.10;
    }
};

class Engineer : public Employee {
public:

    Engineer(double salary) : Employee(salary){}

    double calculateBonus() {
        return salary * 0.07;
    }
};

int main() {
    Employee* emp1 = new Manager( 80000);
    Employee* emp2 = new Engineer(60000);
    Employee* emp3 = new Employee(100000);
    Employee * employees[] = {emp1, emp2, emp3};

    for(Employee * emp: employees) {
        cout << emp -> calculateBonus() << endl;
    }
}
