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
						
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);
						
						break;
					case 'S':
						Substitute();
						
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);
						
						break;
					case 'T':
						Type();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);	
						
						break;
					case 'C':
						Copy();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);
							
						break;
					case 'P':
						Paste();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);	
						
						break;
					case 'L':
						Locate();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);
							
						break;
					case 'I':
						Insert();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);	
						
						break;
					case 'D':
						Delete();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);
						
						break;
					case 'R':
						Replace();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);
							
						break;
					case 'M':
						Move();
					
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);	
						
						break;
					
					default:
						cout<<"I don't know what that means. " 
						// Perhaps we can later add something that 
						// repeats what the user typed in, as a string. 
						<<endl
						<<"Please enter something more reasonable. "
						<<endl;
						
						cout<<"Command?"
						<<endl;		
						cin>>input;
						cin.ignore(1000,'\n');
						input=toupper(input);
						
						break;
				}	
			}
		return 0;
	}
	
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

/*	
char I_O(char input) // I was hoping to have the basic input/output in a function, 
		     // but it didn't work very nicely. 
	{
		cout<<"Command?"
		<<endl;		
		cin>>input;
		cin.ignore(1000,'\n');
		input=toupper(input);
		return input;
	}
*/
	
