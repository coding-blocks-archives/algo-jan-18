#include<iostream>
using namespace std;

//Defines the blueprint 
//Public and Private are acess-modifers
// Protected : Read about it later as HW

//Every class has 4 hidden functions
// 1. Constructor - Init data members of class, constructor - name is same class name
// 2. Copy-Constructor - Copies entire object
// 3. Copy - Assignment Operator
// 4. Destructor


class Car{

private:
	string name;
	int price;
public:
	//Over-riding the default constructor
	Car(){
		//cout<<"Making one Car";
	}
	//Parameterised Construtor
	Car(int p,string n){
		price = p;
		name = n;
	}
	// Copy Constructor
	Car(const Car &X){
		cout<<"In Copy Constructor" <<endl;
		name = X.name;
		price = X.price;
	}

	// Function Overloading - When you multiple fn's with same name
	
	void operator=(const Car &X){
		name = X.name;
		price = X.price;
	}


	// Const Fn - It doesnt update class data members
	void print() const{
		cout<<name<<endl;
		cout<<price<<endl;
	}

	//Setters
	void setName(string n){
		if(n!=""){
			name = n;
		}
	}
	void setPrice(int p){
		if(p>100){
			price = p;
		}
	}
	//Getters
	int getPrice(){
		return price;
	}
	~Car(){
		cout<<"Destroying Car "<<name<<endl;
	}
};

int main(){



	Car A; //Constructor
	Car B(300,"Audi"); // Parametrised Construcotr
	

	A.setName("BMW");
	A.setPrice(400);
	A.print();
	B.print();

	//cout<<A.getPrice()<<endl;

	Car C(B); // Call Copy Constructor
	C.print();

	Car D = B; // Call Copy Constructor

	D.print();

	Car E;	//Normal Constructor
	E = D; // Copy Assignment Operator
	E.print(); 


	//Dynamic Car
	Car *x = new Car(10000000,"Porsche");

	delete x;
	
return 0;
}