// -- GROUP 2 -- 
// Nicholas Roberts
// Cisty Vue
// Levi Ruiz
// Atef Alrwashdeh
// Phoebe Ruggeberg
// Alex Yang
// Main program for line editor project
// This is a test

#include <iostream>
#include <fstream>
using namespace std;

char I_O(char);
void Substitute();
void Type(string[]); // Cisty
void Copy();
void Paste();
void Locate();
void Insert(string[]); // Atef/Levi
void Delete();
void Replace();
void Move(string[]); // Phoebe/Alex
void Quit(string[]);
void Save(string[]); 
void Separate(string[]);


// make quit function, and divide function. 


////////////////////////////////////////////////<IDEAS>
// (Feel free to add to this field)
//
// Post to Facebook function
// fun little animation things
// 
//  
///////////////////////////////////////////////</IDEAS>



int main() // Main program
	{
		string txtFile[99];
		char input;
		input=' '; // Initializes variable as a space, uses initialization to welcome the user in switch. 
		
		while(input!='Q') // Main event loop. //quit
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
						Type(txtFile);
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
						Insert(txtFile);
						break;
						
					case 'D':
						Delete();
						break;
						
					case 'R':
						Replace();
						break;
						
					case 'M':
						Move(txtFile);	
						break;
						
					// add Save case, but not just with 'S', it will conflict with Substitute. 
					
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
			
			Quit(txtFile); // calls quit function, Y or N to save. 
			
		return 0;
	}
	
/////////////////////// ANYTHING BELOW THIS FIELD IS EDITABLE WITHOUT PERMISSION ////////////////////////	
	
	
	
void Substitute()
	{
		cout<<"'Substitute' has been called. "
		<<endl;
	}
void Type(string txtEdit[])
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
void Insert(string txtEdit[])
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
void Move(string txtEdit[])
	{
		cout<<"'Move' has been called. "
		<<endl;
	}
void Quit(string txtEdit[])
	{
		cout<<"'Quit' has been called. "
		<<endl;
		Save(txtEdit);
	}
void Save(string txtEdit[]) // a separate save function so that users can save without quitting. 
	{
		cout<<"'Save' has been called. "
		<<endl;
	}
void Separate(string txtEdit[])
	{

	}
