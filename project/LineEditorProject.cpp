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
const bool DEBUG = false;
const int MAX = 100;

int Reader(string);
void Substitute(); // ASSIGNED TO Levi/Atef
void Type(string[], int, int&); 
void Copy();
void Paste();
void Locate(); // ASSIGNED TO Levi/Atef
void Insert(string[],int &,int &,int &); 
void Delete(); // ASSIGNED TO Phoebe/Alex/Cisty
void Replace(); // ASSIGNED TO Phoebe/Alex/Cisty
void Move(string[],int &,int); 
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
		int currentLineIndex=0, total=0, inputNum;
		
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
					case 'S': 
						Substitute();
					
					// if a case has two possible functions	
						/*
						inputCharSecond=inputString.at(1); // look at the second letter. 
						inputCharSecond=toupper(inputCharSecond);
						if(inputCharSecond=='U')
							Substitute();
						if(inputCharSecond=='A')
							Save(txtFile);*/
						break;
					case 'T':
						inputNum=Reader(inputString);
						Type(txtFile, inputNum, currentLineIndex);
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
						inputNum=Reader(inputString);
						Insert(txtFile, inputNum, currentLineIndex, total);
						break;
					case 'D':
						Delete();
						break;	
					case 'R':
						Replace();
						break;	
					case 'M':
						inputNum=Reader(inputString);
						Move(txtFile, currentLineIndex, inputNum);	
						
						break;
					case '*': // * saves file to disk
						Save(txtFile);
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

				cout<<"Command? "<<endl;	
				cin>>inputString;
				
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
	
int Reader(string userInput) // You will have to add more conditions for substitute and locate. 
	{
		int i, inputNum, signChange=1, temp;
		
		for(i=0; i<=userInput.length()-1; i++)
			{
				temp=userInput.at(i);
				temp=temp-'0';
				if(userInput.at(i)=='-')
					{
						signChange=-1;
					}
				else if(temp>=0 and temp<=9)
					{
						inputNum=inputNum*10;
						inputNum=inputNum+temp;
					}
			}
		inputNum=inputNum*signChange;
		
		return inputNum;
	}
	
void Substitute()
	{
		if(DEBUG)
			{
				cout<<"'Substitute' has been called. "<<endl;
			}
	}

void Type(string txtFile[], int type_number, int&currentLineIndex) 
	{ 
		int i;
		for(i=currentLineIndex; i<(currentLineIndex+type_number); i++)
			{
				cout<<"> "<<txtFile[i]<<endl;
			}
		currentLineIndex=currentLineIndex+type_number-1;
	}

void Copy()
	{
		if(DEBUG)
			{
				cout<<"'Copy' has been called. "<<endl;
			}
	}

void Paste()
	{
		if(DEBUG)
			{
				cout<<"'Paste' has been called. "<<endl;
			}
	}

void Locate()
	{
		if(DEBUG)
		{
			cout<<"'Locate' has been called. "<<endl;
		}
	}

void Insert(string txtFile[], int &insert_number, int &currentLineIndex,int &total) 
	{ 
		int i;
			for (i=total; i>currentLineIndex; i--)
				{
					txtFile[i+insert_number]=txtFile[i];
				}
			cin.ignore(1000,'\n');
			for(i=currentLineIndex+1; i<=insert_number+currentLineIndex; i++) 
				{
					cout<<"> ";
					getline(cin,txtFile[i]);
				}
			currentLineIndex = insert_number+currentLineIndex;
			total = total + insert_number;
			
			if (DEBUG)
				{
					cout<<"total = "<<total<<endl;
					cout<<"currentLineIndex = "<<currentLineIndex<<endl;
				}
	}

void Delete()
	{
		if(DEBUG)
			{
				cout<<"'Delete' has been called. "<<endl;
			}
	}

void Replace()
	{
		if(DEBUG)
			{
				cout<<"'Replace' has been called. "<<endl;
			}
	}

void Move(string txtFile[], int &currentLineIndex,int move_number) 
	{
		currentLineIndex =currentLineIndex+ move_number;
		
		if(DEBUG)
			{
				cout<<"Line: "<<currentLineIndex<<endl;
			}
			
		cout<<"Text from current line: "<<endl<<"> "<<txtFile[currentLineIndex]<<endl;
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
				case '*':
					Save(txtFile);
					break;
				default:
					cout<<"Your file has not been saved. "<<endl;
					break;
			}
				
		
				
		cout<<"Have a nice day!"<<endl;	
		
	}

void Save(string txtFile[]) // NEEDS SOME WORK 
	// a separate save function 
	// so that users can save without quitting. 
	{
		if(DEBUG)
			{
				cout<<"'Save' has been called "<<endl;
			}
		cout<<"Your file has been saved. "<<endl;
		
		
		// 'Apply string array to file' routine goes here. 
		// IF ANYONE KNOWS HOW TO DO THIS, DO IT, I DON'T THINK IT'S VERY HARD, 
		// BUT I LOST MY NOTES. 
		
		
	}

