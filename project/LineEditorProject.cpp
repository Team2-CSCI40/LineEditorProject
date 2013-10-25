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
void Type(string[], int, int &); // ASSIGNED TO Cisty
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
		int insert_number = 0; //this is show how many line we will insert in the array. 
		int base = 0; // this is show where we gonna start the insert in the array and by defult it will statrt from the zero element.
		int total = 0; // this is show how many lines is in the string array.
		int move_the_base_number;//this will send with the move statment to make the offset for the base_number
		int type_number;
		
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
						cin>>type_number;
						//inputNum=splitToNum(inputString);
						Type(txtFile, type_number, base);
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
						//inputNum=splitToNum(inputString);
						cin>>insert_number;
						Insert(txtFile, insert_number,base,total);
						break;
					case 'D':
						Delete();
						break;	
					case 'R':
						Replace();
						break;	
					case 'M':
						//inputNum=splitToNum(inputString);
						cin>>move_the_base_number;
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

void Type(string txtEdit[], int type_number, int &base_number) // NEEDS SOME WORK
	{
		
		cout<<"'Type has been called. "
		<<endl;
		int i;
		for(i=base_number; i<=(base_number+(type_number-1))/*base_number+type_number*/; i++)
			{
				cout<<txtEdit[i]
					<<endl;
			}
		
		
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
		cout<<"'Insert' has been called. "<<endl;
		int z,x;
		total_number = total_number + insert_number;
		
			for (x = total_number  ; x >= base_number +1 ; x--)
				{
					txtEdit [ x + insert_number] = txtEdit [x];
				}
			for( z = base_number + 1; z <= insert_number;z++)
				{
					getline(cin,txtEdit[z]);
				}
			base_number = z;
			
			cin.ignore(1000,'\n');
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
		// the below line is temporary
		cout<<"base num: "<<base_number<<endl;
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

