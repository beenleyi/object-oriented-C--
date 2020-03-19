#include <iostream>
using namespace std;
// 在此处补充你的代码
class Dog{
    public:
    static int number;
	Dog();
	~Dog();
};
class Cat{
    public:
    static int number;
    friend Animal;
	Cat();
	~Cat();
};
class Animal{
    public:
    static int number;
    Animal(){}
    ~Animal(){
        number--;
        Animal::number--;
    }
};

Cat::Cat(){
        number++;
        Animal::number++;
    }
Cat::~Cat(){
        number--;
        Animal::number--;
    }
Dog::Dog(){
        number++;
        Animal::number++;
    }
Dog::~Dog(){
        number--;
        Animal::number--;
    }

void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;//to Dog()
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}
