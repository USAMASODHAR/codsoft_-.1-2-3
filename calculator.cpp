#include<iostream>
using namespace std;
void calculator(float num1,float num2,char op){
	switch(op){
		case '+':
			cout<<"THE ADDITION OF THE NUMBERS IS: "<<num1+num2;
			break;
		case '-':
			cout<<"THE SUBTRACTION OF THE NUMBERS IS: "<<num1-num2;
			break;
		case '*':
			cout<<"THE MULTIPLICATION OF THE NUMBERS IS: "<<num1*num2;
			break;
		case '/':
			cout<<"THE DIVISION OF THE NUMBERS IS: "<<num1/num2;
			break;
	}
}

int main(){
	float num1,num2;
	//taking numbers as input from the user
	cout<<"ENTER THE FIRST NUMBER: ";
	cin>>num1;
	cout<<"ENTER THE SECOND NUMBER: ";
	cin>>num2;
	
	//taking an operator to perform operations
	char op;
	cout<<"ENTER THE OPERATOR: ";
	cin>>op;
	calculator(num1,num2,op);

	
}
                     