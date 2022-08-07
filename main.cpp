#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>

enum Day {Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6};
template <typename T, typename U> // template function, usign 2 different data types

// added in VS Code through github, test

auto max(T x, U y){
    return (x > y) ? x : y;
}

void sortBubble(int arraySort[], int size);

struct student{ // default public objects
    std::string name;
    double gpa;
    bool enrolled;
};

class Human{
    private:
        int social = 404112385;

    public:
        std::string name;
        std::string occupation;
        int age;

        void eat(){
            std::cout << "this person is eating" << std::endl;
        }
        void sleep(){
            std::cout << "this person is sleeping" << std::endl;
        }
        int getSocial(){ // this is a getter
            return social;
        }
        void setSocial(int social){ // this is a setter
            this->social = social;
        }
        // constructor
        Human(std::string name, std::string occupation, int age){
            this->name = name;
            this->occupation = occupation;
            this->age = age;
        }
        // can overload constructors, ie have more than one constructor with different args, very similar to function overloading
};

// inheritance
/*
class Kid : public Human{
    public:
        Kid(int age){
            this->age = age;
        }
        void talk(){
            std::cout << "the kid is talking\n";
        }

};
*/


int main(){
    std::string name;
    int age;
    std::cout << "What is your age?: ";
    std::cin >> age;

    std::cout << "What is your name?: ";
    std::getline(std::cin >> std::ws, name);
    // get line doesnt stop "grabbing" after a whitespace is encountered
    // std::ws is used because there is a \n character after the first cin

    double x = 10.314;
    double y = 4;
    double z;
    z = std::max(x, y);
    //z = std::min(x, y);
    //z = pow(2, 4);
    //z = sqrt(9);
    //z = round(x); // = 10
    //z = ceil(x); // = 11 (rounds up)

    int month;
    std::cout << "Enter a month" << std::endl;
    std::cin >> month;
    switch(month){ // what value would you like to examine against mulitple cases
        case 1:
            std::cout << "It is January";
            break;
        case 2:
            std::cout << "It is Feburary";
            break;
        //...
        default:
            std::cout << "Please enter in numbers only 1-12";
    }

    // ternerary operator
    // condition ? expression 1(true) : expression2(false);
    int grade = 77;
    grade > 75 ? std::cout << "You Passed! " << std::endl : std::cout << "You failed :(" << std::endl ;

    bool hungry = true;
    hungry ? std::cout << "You are hungry" << std::endl : std::cout << "You are full" << std::endl;;

    // string operators
    std::string thisString;
    std::cout << "Enter a string: ";
    std::cin >> thisString;
    name.empty() ? std::cout << "You didnt enter a name" : std::cout << "Your string: " << thisString << std::endl;
    thisString.append("@gmail.com");
    std::cout << "Your Username is now: " << thisString << std::endl;
    std::cout << "Username at index 0 is: " << thisString.at(0) << std::endl;
    thisString.insert(0,"ggEZ");
    std::cout << thisString << std::endl;
    //std::cout << name.find(' ') //returns the position of the first whitespace
    //thisString.erase(starting index, ending index)

    do{
        std::cout << "in do-while loop\n";
    }while(0 == 1);

    // for loop
    for(int i = 0; i < 10; i++){
        if(i == 3){
            continue; // this skips the rest of the code in the for-loop and moves on to the next iteration
        }
    }

    srand(time(NULL));
    int num = rand() % 6; //range you want, add + to offset range, ie dice would be (rand() % 6) +1

    // function overloading
    // basically having two functions with the same name but different args, when function is called it matches the fucntion with the expected args

    // variable scope
    // if two vars have the same name (one global, one local), to specify global, use ::variableName (double colons in front)

    // std::setprecision(2) << std::fixed << variableName 

    // use std::cin.clear(); followed by fflush(stdin); to clear cin if the interpreter cannot resolve input and to clear out the automatic new line \n 

    // arrays must declare size on initialization
    std::string car[] = {"RedBull Racing Oracle RB18", "Mercedes Petronas AMG W-11", "Ferrari F1-75"};
    // when passing an array to a function, it decays into a pointer

    // foreach loop
    // easier to traverse an entire iterable data set
    for(std::string cars : car){
        std::cout << cars << std::endl;
    }

    /*
    int grades[] = {1, 2, 5, 2, 6, 9, 2};
    for(int grade : grades){
        std::cout << grade << ", ";
    }
    */

    // bubblesort
    int arraySort[] = {10, 3, 5, 2, 7, 8, 5};
    int size = sizeof(arraySort)/sizeof(arraySort[0]);
    sortBubble(arraySort, size);
    for(int element : arraySort){
        std::cout << element << " ";
    }
    std::cout << "\n";

    //pointers, use same data type for the var and the pointer to the var
    std::string user = "Me";
    int subtens = 69;
    std::string pizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"}; //an array is already a pointer

    std::string *pUser = &user; // * is the dereference operator and & is the address-of operator
    // so "pUser" is a variable whos value is the memory location of the variable "user"
    int *pSubtens = &subtens;
    std::string *pPizzas = pizzas; //dont use & because an array is already a pointer

    std::cout << "pUser: " << pUser << std::endl;
    std::cout << "pUser references: " << *pUser << std::endl; // accessing the value at this address
    std::cout << "pizzas: " << pizzas << std::endl;
    std::cout << "1st pizza: " << *pizzas << std::endl;

    // null pointer
    int *ptr = nullptr;
    if(ptr == nullptr){
        std::cout << "no address assigned" << std::endl;
    }

    // dynamic memory, uses memory on heap instead of stack
    int *ptr2 = NULL;
    ptr2 = new int;
    *ptr2 = 22;
    std::cout << "address: " << ptr2 << std::endl;
    std::cout << "value: " << *ptr2 << std::endl;
    delete ptr2; // delete because we dont want to use up memory on stack if no longer using it

    int sizeOf;
    char *arr1 = nullptr;
    std::cout << "Enter the size of array: " << std::endl;
    std::cin >> sizeOf;
    arr1 = new char[sizeOf];
    delete[] arr1;

    // function template
    // crate a function that work with multiple data types

    // struct
    student student1;
    student1.name = "Enrique";
    student1.gpa = 2.6;
    student1.enrolled = true;

    // enum
    // user-defined, of paired named-integer constants
    Day today = Sunday;
    switch(today){
        case Sunday:   
            std::cout << "it is sunday!\n";
            break;
        default: 
            std::cout << "it is not sunday\n";
    }

    // class
    Human human1("Rick", "Scientist", 44);
    // dont need anymore because of constructor
    //human1.name = "Rick";
    //human1.occupation = "Scientist";
    //human1.age = 44;
    human1.eat();

    // abstraction = hiding unnecessary dat from outside a class
    // getter = fucntion tha makes a private attribute READABLE
    // setter = fucntion tha make aprivate attribute WRITEABLE

    return 0;
}

void sortBubble(int arraySort[], int size){
    int tmp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arraySort[j] > arraySort[j + 1]){
                tmp = arraySort[j];
                arraySort[j] = arraySort[j + 1];
                arraySort[j + 1] = tmp;
            }
        }
    }
}