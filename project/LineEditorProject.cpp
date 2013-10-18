// -- GROUP 2 -- 
// Nicholas Roberts
// Cisty Vue
// Levi Ruiz
// Atef Alrwashdeh
// Phoebe Ruggeberg
// Alex Yang
// Main program for line editor project

#include <iostream>
using namespace std;

char I_O(char);
void Substitute();
void Type();
void Copy();
void Paste();
void Locate();
void Insert();
void Delete();
void Replace();
void Move();

////////////////////////////////////////////////<IDEAS>
// (Feel free to add to this field)
//
// Post to Facebook function
// fun little animation things
// 
//  
///////////////////////////////////////////////</IDEAS>

// I suspect that some of the functions will have to be char, rather than void...
// Such as a 'Save?' option. 


int main() // Main program
	{
				
		char input;
		input=' '; // Initializes variable as a space, uses initialization to welcome the user in switch. 
		
		while(input!='Q') // Main event loop. 
			{
				switch(input)
				{
					case ' ': 
						cout<<"Welcome. " // Uses variable initialization, as described above. 
						<<endl;
						break;
						
					case 'S':
						Substitute();
						break;
						
					case 'T':
						Type();
						break;
						
					case 'C':
						Copy();	
						break;
						
					case 'P':
						Paste();
						break;
						
					case 'L':
						Locate();
						break;
						
					case 'I':
						Insert();
						break;
						
					case 'D':
						Delete();
						break;
						
					case 'R':
						Replace();
						break;
						
					case 'M':
						Move();	
						break;
					
					default:
						cout<<"I don't know what that means. " 
							<<endl
							<<"Please enter something more reasonable. "
							<<endl;
						// Perhaps we can later add something that 
						// IDEALLY it repeats what the user typed in, as a string. Will add later. 
						break;
						
				}	
				cout<<"Command?"
					<<endl;		
				cin>>input;
				cin.ignore(1000,'\n');
				input=toupper(input);
			}
		return 0;
	}
	
/////////////////////// ANYTHING BELOW THIS FIELD IS EDITABLE WITHOUT PERMISSION ////////////////////////	
	
	
	
void Substitute()
	{
		cout<<"'Substitute' has been called. "
		<<endl;
	}
void Type()
	{
		cout<<"'Type' has been called. "
		<<endl;
	}
void Copy()
	{
		cout<<"'Copy' has been called. "
		<<endl;
	}
void Paste()
	{
		cout<<"'Paste' has been called. "
		<<endl;
	}
void Locate()
	{
		cout<<"'Locate' has been called. "
		<<endl;
	}
void Insert()
	{
		cout<<"'Insert' has been called. "
		<<endl;
	}
void Delete()
	{
		cout<<"'Delete' has been called. "
		<<endl;
	}
void Replace()
	{
		cout<<"'Replace' has been called. "
		<<endl;
	}
void Move()
	{
		cout<<"'Move' has been called. "
		<<endl;
	}
