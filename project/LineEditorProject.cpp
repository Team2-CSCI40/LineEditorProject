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
void Type(string[], string, int); // ASSIGNED TO Cisty
void Copy();
void Paste();
void Locate();
void Insert(string[], string, int); // ASSIGNED TO Atef/Levi
void Delete();
void Replace();
void Move(string[], string, int); // ASSIGNED TO Phoebe/Alex
void Quit(string[]);
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
		int currentLineIndex;
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
						Type(txtFile, inputString, currentLineIndex);
						// split up the user input here, rather than in the function. 
						// for now I'm leaving the input string here, but once you 
						// split it up, send it to the function as another int. 
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
						Insert(txtFile, inputString, currentLineIndex);
						// split up the user input here, rather than in the function. 
						// for now I'm leaving the input string here, but once you 
						// split it up, send it to the function as another int. 
						break;
						
					case 'D':
						Delete();
						break;
						
					case 'R':
						Replace();
						break;
						
					case 'M':
						Move(txtFile, inputString, currentLineIndex);	
						// split up the user input here, rather than in the function. 
						// for now I'm leaving the input string here, but once you 
						// split it up, send it to the function as another int. 
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
			
			Quit(txtFile); // calls quit function, Y or N to save. 
			
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
void Type(string txtEdit[], string userInput, int currentLineIndex) // try changing the array to a reference variable
	{
		cout<<"'Type' has been called. "
		
		// takes the number from the user input, which was split up in the main program
			// we're supposed to print the surrounding lines? Not sure how that's supposed to work. 
			// Talk to Jamison on Wednesday about the above question^^^
			// perhaps it's supposed to override whatever content is on a specific line, if there is any. 
		// cin>>txtEdit[lineNumber];
		
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
void Insert(string txtEdit[], string userInput, int currentLineIndex)
	{
		cout<<"'Insert' has been called. "
		// Atef, you will most likely need to do a lot of the work on this one. 
		// I say that because Levi has been gone for a while due to illness, 
		// so he is probably going to be very confused about what is going on
		// once he returns, if he does in the near future. 
		
		// Anyway, this mostly revolves around figuring out how to move the indexes down. 
		// This can be done with a for loop, I'm pretty sure. 
		// If I get a chance, I'll make a branch of this repository so I can try this. 
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
void Move(string txtEdit[], string userInput, int currentLineIndex)
	{
		cout<<"'Move' has been called. "
		// All this does is changes the current line index inside the array. 
		// If there are complications with this, we should ask Jamison. 
		// I'm not totally sure if having the current line index thing is the way to go, because 
		// I didn't get a chance to talk to Jamison today, but if you see any reason it shouldn't work
		// let me know immediately. More importantly, if you have a solution, let me know. 
		
		<<endl;
	}
void Quit(string txtEdit[])
	{
		char yesNo;
		
		cout<<"You have asked to quit, "
		<<"would you like to save first? "
		<<endl;
		
		cin>>yesNo;
		cin.ignore(1000,'\n');
		yesNo=toupper(yesNo);
		
		switch(yesNo)
			{
				case 'Y':
					Save(txtEdit);
					break;
				case 'S':
					Save(txtEdit);
					break;
				case 'N':
					break;
				
			}
			
		
		/*
		if(yesNo=='Y' or 'S') // 'Yes' or 'Save' are valid responses. 
			{
				Save(txtEdit);
			}
		else
			{
				cout<<"Have a nice day!"<<endl;
			}
		*/
	}
void Save(string txtEdit[]) // a separate save function 
	// so that users can save without quitting. 
	{
		cout<<"'Save' has been called "
		
		
		
		// 'Apply string array to file' routine goes here. 
		// IF ANYONE KNOWS HOW TO DO THIS, DO IT, I DON'T THINK IT'S VERY HARD, 
		// BUT I LOST MY NOTES. 
		
		<<endl;
	}

