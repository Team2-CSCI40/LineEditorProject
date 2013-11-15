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
void Substitute(string [], int, string); 
void Type(string[], int, int&); 
void Copy();
void Paste();
void Locate(string[], string, int&, int); // ASSIGNED TO Levi/Atef - Somewhat difficult //find while and if
void Insert(string[],int ,int &,int &); 
void Delete(string[], int &, int, int &); 
void Replace(string[], int &, int); 
void Move(string[],int &,int); 
void Quit(string[], int);
void Open(string[], int);
void Save(string[], int); 

////////////////////////////////////////////////<IDEAS>
// // // (Feel free to add to this field)
//
//
// Post to Facebook function (can probably be done with PHP)
// animation things (no idea where to start with this)
// word count/char count?
// Redirect to project wiki
// 
//  
///////////////////////////////////////////////</IDEAS>

int main() // Main program
	{
		string txtFile[MAX];
		int currentLineIndex=0, total=0, inputValue;
		
		string inputString;
		
		char inputChar;
		char openCreateInput;
		
		inputChar=' '; // Initializes variable as a space, 
			// uses ' ' to welcome the user in switch. 
		while(inputChar!='Q') // Main event loop. //"if not quit"
			{
				switch(inputChar)
				{
					case ' ': 
						cout<<"Welcome. \n";
						/*cout<<"Would you like to open an existing file? "
							<<endl;
						cin>>openCreateInput;
						//cin.getline();
						openCreateInput=toupper(openCreateInput);
						cin.ignore(1000, '\n');
						if(openCreateInput='Y')
							{
								Open(txtFile, total); // Total is sent in because it may be altered if there is content in the file. 
							}*/
						break;
					case 'S': 
						inputValue=Reader(inputString);
						Substitute(txtFile,currentLineIndex,inputString);
						break;
					case 'T':
						inputValue=Reader(inputString);
						Type(txtFile, inputValue, currentLineIndex);
						break;
					case 'C':
						Copy();	
						break;
					case 'P':
						Paste();
						break;
					case 'L':
						inputValue=Reader(inputString);
						Locate(txtFile, inputString, currentLineIndex, total);
						break;
					case 'I':
						inputValue=Reader(inputString);
						Insert(txtFile, inputValue, currentLineIndex, total);
						break;
					case 'D':
						inputValue=Reader(inputString);
						Delete(txtFile, currentLineIndex, inputValue, total);
						break;	
					case 'R':
						inputValue=Reader(inputString);
						Replace(txtFile, currentLineIndex, inputValue);
						break;	
					case 'M':
						inputValue=Reader(inputString);
						Move(txtFile, currentLineIndex, inputValue);	
						
						break;
					case '*': // * saves file to disk
						Save(txtFile, total);
						cin.ignore(1000, '\n');////////////////////////////////////////////////////////////////////////////////////////////
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
				getline(cin, inputString);
				
				inputChar=inputString.at(0);
				inputChar=toupper(inputChar);	
			}

			Quit(txtFile, total); // calls quit function, Y or N to save. 	
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
	
int Reader(string inputString) 
	{ 
		int i, inputValue=0, signChange=1, temp;
		
		for(i=0; i<=inputString.length()-1; i++)
			{
				inputString.at(i)=toupper(inputString.at(i));
				temp=inputString.at(i);
				temp=temp-'0';
					
				if(inputString.at(i)=='-')
					{
						signChange=-1;
					}
				if(temp>=0 and temp<=9)
					{	
						inputValue=inputValue*10;
						inputValue=inputValue+temp;
					}	
			}
		inputValue=inputValue*signChange;
		
		return inputValue;
	}
	
void Substitute(string txtfile[], int current_line, string input_string)
	{
		int pos, pos_2, pos_3, pos_old_string, txtfile_length;
		pos = input_string.find('/');
		string temp_1, new_string, temp_2, old_string;
		temp_1 = input_string.substr(pos + 1);
		pos_2 = temp_1.find('/');
		old_string = temp_1.substr(0,pos_2);
		
		if(DEBUG)
			{
				cout<<"This is the old string: "<<old_string<<endl;
			}
			
		temp_2 = temp_1.substr(pos_2+1);
		new_string = temp_2.substr(0,temp_2.length()-1);
		
		if(DEBUG)
			{
				cout<<"This is the new string: "<<new_string<<endl;
			}
			
		int i_for_loop;
		int new_string_length,old_string_length;
		old_string_length = old_string.length();
		new_string_length = new_string.length();
		bool check;
		int start_from ;
		i_for_loop = current_line;
		start_from = 0;
		check = true;
		string the_original_string = txtfile[i_for_loop];
		if(txtfile[i_for_loop].find(old_string) == -1)//to show if no match string for the old_string.
			{
				cout<<"'"<<old_string<<"' doesn't occur on line "<<i_for_loop<<". "<<endl;
			}
		if(txtfile[i_for_loop].empty() == true)//to leave if it empty.
			{
				cout<<"Line number "<<i_for_loop<<" is empty."<<endl;
				check = false;
			}
		txtfile_length = txtfile[i_for_loop].length();
				
		while(check)
			{
				txtfile_length = txtfile[i_for_loop].length();
				if(DEBUG)
				 	{
						cout<<"This is the string length: "<<txtfile_length<<endl;
					}
			 	pos_old_string = txtfile[i_for_loop].find(old_string,start_from);//the position of the old_string in the string.
			 	if(DEBUG)
			 		{
						cout<<"this is the position of old string: "<<pos_old_string<<endl;
					}
		 		if(pos_old_string == -1) // bool instead of break else
		 			{
			 			break; // CANNOT USE BREAK. 
		 			}
			 	if(new_string.empty())
			 		{
				 		txtfile[i_for_loop].replace(pos_old_string,old_string_length,"");
				 		if(DEBUG)
				 			cout<<"What happened: "<<txtfile[i_for_loop]<<endl;
				 		start_from = 0;
			 		}
			 	else
			 		{
						txtfile[i_for_loop].replace(pos_old_string,old_string_length,new_string);
						if(DEBUG)
							{
								cout<<"This is the new string: "<<txtfile[i_for_loop]<<endl;
							}
						if(txtfile[i_for_loop].at(pos_old_string + new_string_length - 1) == '\0')
							{
								check = false;
							}
						else
							{
								start_from = pos_old_string + new_string_length;
							}
		 			}
					
					if(DEBUG)
						{
							cout<<"The position of the start_from in the txtfile: "<<start_from<<endl;
						}
			}			
		if(txtfile[i_for_loop] != the_original_string)
			cout<<"Text from current line: "<<endl<<"> "<<txtfile[i_for_loop]<<endl;	
		if(DEBUG)
			{
				cout<<"Position of the first / in the string: "<<pos<<endl;
			}
	}


void Type(string txtFile[], int type_number, int&currentLineIndex) 
	{ 
		int i;
		int otherCounter=0;
		for(i=currentLineIndex; i<(currentLineIndex+type_number); i++)
			{
				otherCounter++;
				if(currentLineIndex+otherCounter-1>=MAX)
					{
						cout<<"You have reached the end of the file. "<<endl;
						break;
					}	
				
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

void Locate(string txtFile[], string inputString, int &currentLineIndex, int total)
	{
		int firstPosition, secondPosition, found, i=currentLineIndex;
		string tempOne, searchString;
		
		firstPosition = inputString.find('/');
		tempOne = inputString.substr(firstPosition + 1);
		secondPosition = tempOne.find('/');
		
		searchString = tempOne.substr(0, secondPosition);
	
		found = -1;
		
		while(found == -1 and i<=total)
			{
				i++;
				found=txtFile[i].find(searchString);
			}
			
		if(found == -1)
			{
				cout<<"No instance of "<<searchString<<" was found. "<<endl;
			}
		else 
			{
				currentLineIndex=i;
			}
		cout<<"> "<<txtFile[currentLineIndex]<<endl;
		if(DEBUG)
			{
				cout<<"Search string was: "<<searchString<<". "<<endl;		
			}
	}

void Insert(string txtFile[], int insert_number, int &currentLineIndex,int &total) 
	{ 
		int i, otherCounter=0;
		/*
			otherCounter++;
				if(currentLineIndex+otherCounter-1>=MAX)
					{
						cout<<"You have reached the end of the file. "<<endl;
						break;
					}	
		*/
			for(i=total; i>currentLineIndex; i--)
				{
					txtFile[i+insert_number]=txtFile[i];
					otherCounter++;
					/*if(currentLineIndex+otherCounter-1>=MAX)
						{
							break;
						}*/
				}
				
			otherCounter=0;
			
			//cin.ignore(1000,'\n');
			for(i=currentLineIndex+1; i<=insert_number+currentLineIndex; i++) 
				{
					//otherCounter++;
					/*if(currentLineIndex+otherCounter-1>=MAX)
						{
							cout<<"You have reached the end of the file. "<<endl;
							break;
						}*/
					cout<<"> ";
					getline(cin,txtFile[i]);
				}
			total = total + insert_number;
			
			currentLineIndex = insert_number+currentLineIndex;
			//cout<<"the current line"<<currentLineIndex<<endl;
			/*
			if(currentLineIndex>=MAX-1)
				{
					currentLineIndex = 99;					
				}
			*/
			if(DEBUG)
				{
					cout<<"total = "<<total<<endl;
					cout<<"currentLineIndex = "<<currentLineIndex<<endl;
				}
	}

void Delete(string txtFile[], int &currentLineIndex, int delete_number, int&total)
	{
		int i;
		total=total-delete_number;
		for(i=currentLineIndex; i<=currentLineIndex+delete_number-1; i++)
			{
				txtFile[i]=txtFile[i+delete_number];
			}
		/*	
		if(currentLineIndex+delete_number-1>=MAX-1) // if lines all the way up to 99 are deleted
				currentLineIndex=currentLineIndex-1; // 
		
		else*/
			//currentLineIndex=currentLineIndex+delete_number;
		
		while(txtFile[currentLineIndex]=="" and currentLineIndex>=2) // if no lines, will default to line 1
			{
				currentLineIndex--;
			}
		
		
		if(DEBUG)
		{
			cout<<"currentLineIndex = "<<currentLineIndex<<endl;
			cout<<"total = "<<total<<endl;
		}
				
				
				
	}

void Replace(string txtFile[], int &currentLineIndex, int replace_number)
	{
		int i;
		for(i=currentLineIndex; i<=currentLineIndex+replace_number-1; i++)
			{
				cout<<"> ";
				getline(cin,txtFile[i]);
			}
			
			currentLineIndex=currentLineIndex+replace_number-1;
		
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

void Quit(string txtFile[], int total)  
	{
		char yesNo;
		
		cout<<"You have asked to quit, "
			<<"would you like to save first? "
			<<endl;
			
		cin>>yesNo;
		//cin.getline();
		//cin.ignore(1000,'\n');
		yesNo=toupper(yesNo);
		
		switch(yesNo)
			{	
				case 'Y':
					Save(txtFile, total);
					break;
				case '*':
					Save(txtFile, total);
					break;
				case 'S':
					Save(txtFile, total);
				case 'N':
					cout<<"Your file HAS NOT been saved. "<<endl;
				default:
					break;
			}
		cout<<"Have a nice day!"<<endl;	
	}

void Open(string txtFile[], int total)
	{
		if(DEBUG)
			{
				cout<<"Open has been called. "<<endl;
			}
	}
	
void Save(string txtFile[], int total) 
	{	// a separate save function 
		// so that users can save without quitting. 
		int i;
		ofstream fout;
		fout.open("file.txt");	
		for(i=1; i<=total; i++)
			{
				fout<<txtFile[i];
				fout<<"\n";
			}	
		cout<<"Your file HAS been saved. "<<endl;

	}

