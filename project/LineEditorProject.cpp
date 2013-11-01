// -- GROUP 2 -- Line Editor -- //
// Nicholas Roberts
// Cisty Vue
// Levi Ruiz
// Atef Alrwashdeh
// Phoebe Ruggeberg
// Alex Yang

//THis is a comment

#include <iostream>
#include <fstream>
using namespace std;
const bool DEBUG = false;
const int MAX = 100;

int splitToNum(string);
void Substitute();
void Type(string[], int, int&); // ASSIGNED TO Cisty
void Copy();
void Paste();
void Locate();
void Insert(string[],int &,int &,int &); // ASSIGNED TO Atef/Levi
void Delete();
void Replace();
void Move(string[],int &,int); // ASSIGNED TO Phoebe/Alex
void Quit(string[]);
void Save(string[]); 

////////////////////////////////////////////////<IDEAS>
// // // (Feel free to add to this field)
//
//
// Post to Facebook function (can probably be done with PHP)
// animation things (no idea where to start with this)
// word count/char count?
// 
//  
///////////////////////////////////////////////</IDEAS>

int main() // Main program
	{
		string txtFile[MAX];
		int insert_number = 0; //this is show how many line we will insert in the array. 
		int base = 0; // this is show where we gonna start the insert in the array and by defult it will statrt from the zero element.
		int total = 0; // this is show how many lines is in the string array.
		int move_number;//this will send with the move statment to make the offset for the base_number
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
						//cout<<"Value? > ";
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
						//cout<<"Value? > ";
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
						//cout<<"Value? > ";
						cin>>move_number;
						Move(txtFile,base,move_number);	
						
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
				cin>>inputChar;
				//cin.ignore(1000,'\n');
				
				//inputChar=inputString.at(0);
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
		int i;
		int inputNum=0;
		
		int reader;
		reader=0;
		for(i=1;i<=userInput.length()-1;i++)
			{
				reader*=10;
				reader+=userInput.at(i)-'0';
				
			}
		inputNum=reader;
		/*	
		for(i=0; i<=userInput.length()-1;i++)
			{
				userInput.at(i);
				
			}
			/*
			if(userInput.at(1)=='-')
				{
					inputNum*-1;
				}
			else if(userInput.at(1)=='')
			*/
		cout<<"'Split' has been called"
		<<endl;
		return inputNum;
	}
	
void Substitute()
	{
		cout<<"'Substitute' has been called. "
		<<endl;
	}

void Type(string txtFile[], int type_number, int&base) 
	{ 
		/* //testing zone
		txtFile[0]="Line zero.";
		txtFile[1]="Line one.";
		txtFile[2]="Line two.";
		txtFile[3]="Line three.";
		*/
		
		//cout<<"'Type' has been called. "
		//<<endl;
		int i;
		for(i=base; i<(base+type_number); i++)
			{
				cout<<"> "<<txtFile[i]<<endl;
			}
		base=base+type_number-1;
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

void Insert(string txtFile[], int &insert_number, int &base,int &total) 
	{ 
		int i;
			for (i=total; i>base; i--)
				{
					txtFile[i+insert_number]=txtFile[i];
				}
			cin.ignore(1000,'\n');
			for(i=base+1; i<=insert_number+base; i++) 
				{
					cout<<"> ";
					getline(cin,txtFile[i]);
				}
			base = insert_number+base;
			
			total = total + insert_number;
			if (DEBUG)
				{
					cout<<"total = "<<total<<endl;
					cout<<"base = "<<base<<endl;
				}
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

void Move(string txtFile[], int &base,int move_number) 
	{
		base =base+ move_number;
		
		if(DEBUG)
			{
				cout<<"Line: "<<base<<endl;
			}
		cout<<"Text from current line: "<<endl<<"> "<<txtFile[base]<<endl;
	}

void Quit(string txtFile[])
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
					Save(txtFile);
					break;
				case 'S':
					Save(txtFile);
					break;
				case 'N':
					break;
			}
		cout<<"Have a nice day!"<<endl;	
		
	}

void Save(string txtFile[]) // NEEDS SOME WORK 
	// a separate save function 
	// so that users can save without quitting. 
	{
		cout<<"'Save' has been called "
		
		
		
		// 'Apply string array to file' routine goes here. 
		// IF ANYONE KNOWS HOW TO DO THIS, DO IT, I DON'T THINK IT'S VERY HARD, 
		// BUT I LOST MY NOTES. 
		
		<<endl;
	}

