// -- GROUP 2 -- Line Editor -- //
// Nicholas Roberts
// Cisty Vue
// Levi Ruiz
// Atef Alrwashdeh
// Phoebe Ruggeberg
// Alex Yang

#include <iostream>
#include <fstream>
using namespace std;

char I_O(char);
void Substitute();
void Type(string[], string); // ASSIGNED TO Cisty
void Copy();
void Paste();
void Locate();
void Insert(string[], string); // ASSIGNED TO Atef/Levi
void Delete();
void Replace();
void Move(string[], string); // ASSIGNED TO Phoebe/Alex
void Quit();
void Save(string[]); 



////////////////////////////////////////////////<IDEAS>
// (Feel free to add to this field)
//
//
// Post to Facebook function (can probably be done with PHP)
// fun little animation things
// 
//  
///////////////////////////////////////////////</IDEAS>



int main() // Main program
	{
		string txtFile[99];
		
		string inputString;
		char inputChar;
		char inputCharSecond;
		
		inputChar=' '; // Initializes variable as a space, 
			// uses initialization to welcome the user in switch. 
		
		while(inputChar!='Q') // Main event loop. //quit
			{
				switch(inputChar)
				{
					case ' ': 
						cout<<"Welcome. " // Uses variable initialization, 
							// as described above. 
						<<endl;
						break;
						
					case 'S': // if a case has two possible functions
						inputCharSecond=inputString.at(1); // look at the second letter. 
						inputCharSecond=toupper(inputCharSecond);
						if(inputCharSecond=='U')
							Substitute();
						if(inputCharSecond=='A')
							Save(txtFile);
						break;
						
					case 'T':
						Type(txtFile, inputString);
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
						Insert(txtFile, inputString);
						break;
						
					case 'D':
						Delete();
						break;
						
					case 'R':
						Replace();
						break;
						
					case 'M':
						Move(txtFile, inputString);	
						break;
					
					default: // maybe we can add something that 
						// redirects the user to the 
						// project's wiki page, opening their browser... 
						cout<<"'"<<inputString<<"'"
							<<" is not a valid command. "
							<<endl
							<<"Please enter a valid command. "
							<<endl;
						break;
						
				}	
				
				
				cout<<"Command? "
					<<endl;		
				cin>>inputString;
				cin.ignore(1000,'\n');
				
				inputChar=inputString.at(0);
				inputChar=toupper(inputChar);
				
				
			}
			
			Quit(); // calls quit function, Y or N to save. 
			
		return 0;
	}
	
	
	
	
	/////////////////
	//-----Functions
	//
	//
	//
	////////
	//////
	////
	//
	
	
void Substitute()
	{
		cout<<"'Substitute' has been called. "
		<<endl;
	}
void Type(string txtEdit[], string userInput)
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
void Insert(string txtEdit[], string userInput)
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
void Move(string txtEdit[], string userInput)
	{
		cout<<"'Move' has been called. "
		<<endl;
	}
void Quit()
	{
		char yesNo; 
		
		cout<<"You have asked to quit, "
		<<"would you like to save first? "
		<<endl;
		cin>>yesNo;
		cin.ignore(1000,'\n');
		yesNo=toupper(yesNo);
		
		if(yesNo=='Y' or 'S') // 'Yes' or 'Save' are valid responses. 
			Save(txtEdit);
		
	}
void Save(string txtEdit[]) // a separate save function 
	// so that users can save without quitting. 
	{
		cout<<"'Save' has been called "
		
		// 'Apply string array to file' routine goes here. 
		
		<<endl;
	}

