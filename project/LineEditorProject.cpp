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

int splitToNum(string);
void Substitute();
void Type(string[], int, int&); // ASSIGNED TO Cisty
void Copy();
void Paste();
void Locate();
void Insert(string[],int &,int &,int &); // ASSIGNED TO Atef/Levi
void Delete();
void Replace();
void Move(int &,int); // ASSIGNED TO Phoebe/Alex
void Quit(string[]);
void Save(string[]); 

////////////////////////////////////////////////<IDEAS>
// // // (Feel free to add to this field)
//
//
// Post to Facebook function (can probably be done with PHP)
// animation things (no idea where to start with this)
// 
//  
///////////////////////////////////////////////</IDEAS>

int main() // Main program
	{
		string txtFile[100];
		int insert_number; //this is show how many line we will insert in the array. 
		int base = 0; // this is show where we gonna start the insert in the array and by defult it will statrt from the zero element.
		int total = 0; // this is show how many lines is in the string array.
		int move_the_base_number;//this will send with the move statment to make the offset for the base_number
		
		//---------------------------------------------
		// These variables may or may not be used.  
		//
		int currentLineIndex, inputNum;
		//
		//
		//---------------------------------------------
		string inputString;
		
		char inputChar;
		char inputCharSecond;
		
		inputChar=' '; // Initializes variable as a space, 
			// uses ' ' to welcome the user in switch. 
		while(inputChar!='Q') // Main event loop. //"if not quit"
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
						inputNum=splitToNum(inputString);
						Type(txtFile, inputNum, base);
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
						inputNum=splitToNum(inputString);
						Insert(txtFile, insert_number,base,total);
						break;
					case 'D':
						Delete();
						break;	
					case 'R':
						Replace();
						break;	
					case 'M':
						inputNum=splitToNum(inputString);
						Move(base,move_the_base_number);	
						
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
				cin>>inputString;//getline
				cin.ignore(1000,'\n');
				
				inputChar=inputString.at(0);
				inputChar=toupper(inputChar);	
			}

			Quit(txtFile); // calls quit function, Y or N to save. 	
		return 0;
	}
	
//	
////	
//////
////////	
//////////
////////////
//////////////
//Functions/////
//////////////
////////////
//////////
////////
//////
////
//
	
int splitToNum(string userInput)
	{
		int inputNum;
		inputNum=11; // as a test, I have this sending the number 11
			// into anything that calls it. 
			// If you figure out how to split the user input number from the 
			// input string, let me know. 
				
		cout<<"'Split' has been called"
		<<endl;
		return inputNum;
	}
	
void Substitute()
	{
		cout<<"'Substitute' has been called. "
		<<endl;
	}

void Type(string txtEdit[], int numInput, int &base_number) // NEEDS SOME WORK
	{
		cout<<"'Type - "<<numInput<<"' has been called. "
		
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

void Insert(string txtEdit[], int &insert_number, int &base_number,int &total_number) // NEEDS SOME WORK
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
		int i,z,x;
		total_number = total_number + insert_number;
		/*if(base_number == 0)
		{ for( i = 0; i <= insert_number-1; i++)
		{
			getline(cin,txtEdit[i]);
		}
		base_number = insert_number - 1;
		}
		else*/ 
		//{
			for (x = total_number -1 ; x >= base_number + 1 ; x--)
				{
					txtEdit [ x + insert_number] = txtEdit [x];
				}
			for( z = base_number + 1; z <= insert_number;z++)
				{
					getline(cin,txtEdit[z]);
				}
			base_number = z;
		//}
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

void Move(int &base_number,int move_offset) // MORE OR LESS DONE. 
	{
		cout<<"'Move' has been called. "
		<<endl;
		base_number = base_number + move_offset;
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
		cout<<"Have a nice day!"<<endl;	
		
	}

void Save(string txtEdit[]) // NEEDS SOME WORK 
	// a separate save function 
	// so that users can save without quitting. 
	{
		cout<<"'Save' has been called "
		
		
		
		// 'Apply string array to file' routine goes here. 
		// IF ANYONE KNOWS HOW TO DO THIS, DO IT, I DON'T THINK IT'S VERY HARD, 
		// BUT I LOST MY NOTES. 
		
		<<endl;
	}

