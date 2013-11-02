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
const bool DEBUG = true;
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
						cin>>type_number;
						//inputNum=Reader(inputString);
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
						//inputNum=Reader(inputString);
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
						//inputNum=Reader(inputString);
						cin>>move_number;
						Move(txtFile,base,move_number);	
						
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
				cin>>inputChar;
				
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
	
int Reader(string userInput)
	{
		int i, inputNum, signChange=1, temp;
		
		for(i=0; i<=userInput.length()-1; i++)
			{
				temp=userInput.at(i);
				if(temp=='-')
					{
						signChange=-1;
					}
				temp=temp-'0';
				if(temp<=9)
					{
						inputNum=inputNum*10;
						inputNum=inputNum+temp;
					}
			}
		inputNum=inputNum*signChange;
		
		if(DEBUG)
			{
				cout<<"'Reader' has been called"<<endl;
			}
		return inputNum;
	}
	
void Substitute()
	{
		if(DEBUG)
			{
				cout<<"'Substitute' has been called. "<<endl;
			}
	}

void Type(string txtFile[], int type_number, int&base) 
	{ 
		int i;
		for(i=base; i<(base+type_number); i++)
			{
				cout<<"> "<<txtFile[i]<<endl;
			}
		base=base+type_number-1;
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

void Move(string txtFile[], int &base,int move_number) 
	{
		base =base+ move_number;
		
		if(DEBUG)
			{
				cout<<"Line: "<<base<<endl;
			}
			
		cout<<"Text from current line: "<<endl<<"> "<<txtFile[base]<<endl;
	}

void Quit(string txtFile[]) // this doesn't work right for some reason. 
	{
		char yesNo;
		
		yesNo=' ';
		while(yesNo=='N' or 'Y' or '*')
			{
				switch(yesNo)
					{
						case ' ':
							cout<<"You have asked to quit, "
								<<"would you like to save first? "
								<<endl;
							break;
						case 'Y':
							Save(txtFile);
							break;
						case '*':
							Save(txtFile);
							break;
						case 'N':
							break;
						default:
							cout<<"Please enter a valid command. "<<endl;
							break;
					}
					
				cin>>yesNo;
				cin.ignore(1000,'\n');
				yesNo=toupper(yesNo);
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
		
		
		
		// 'Apply string array to file' routine goes here. 
		// IF ANYONE KNOWS HOW TO DO THIS, DO IT, I DON'T THINK IT'S VERY HARD, 
		// BUT I LOST MY NOTES. 
		
		
	}

