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

struct file 
	{
		string contents[MAX-1]; // segmentation fault w/ some values subtracted from MAX...
		string fileName;
		int currentLineIndex;
		int total;
	};

int NumberInputReader(string);
void Substitute(file&, string); 
void Type(file&, int); 
void Copy(file, string&, int);
void Paste(file&, string, int);
void Locate(file &, string); 
void Insert(file &, int); 
void Delete(file &, int); 
void Replace(file &, int); 
void Move(file &, int); 
void Quit(file);
void Open(file &);
void New(file &);
void Save(file); 



////////////////////////////////////////////////<IDEAS>
// // // (Feel free to add to this field)
//
//
// Post to Facebook function (can probably be done with PHP)
// animation things (no idea where to start with this)
// word count/char count?
// Redirect to project wiki
// HTML highlighting
// 
//  
///////////////////////////////////////////////</IDEAS>

int main() // Main program
	{
		file txtFile;
		txtFile.currentLineIndex=-1;
		txtFile.total=0;
		int inputValue=0, copyNumber;
		string inputString, openYN, copyQue[copyNumber];
		char inputChar, openYNtemp;
		
		cout<<"Welcome. \n";
		
		inputChar=' '; // Initializes variable as a space, 
			// uses ' ' to welcome the user in switch. 
		while(inputChar!='Q') // Main event loop. //"if not quit"
			{
				switch(inputChar)
				{
					case ' ': 
						if(not DEBUG)
							{
								cout<<"Would you like to open an existing file? "
									<<endl;
								getline(cin, openYN);
								openYNtemp=openYN.at(0);
								openYNtemp=toupper(openYNtemp);
								
								switch(openYNtemp)
									{
										case 'Y':
											Open(txtFile);
											break;
										default:
											New(txtFile);
											break;
									}
							}
						break;
					case 'S': 
						inputValue=NumberInputReader(inputString);
						Substitute(txtFile,inputString);
						break;
					case 'T':
						inputValue=NumberInputReader(inputString);
						Type(txtFile, inputValue);
						break;
					case 'C':
						copyNumber=NumberInputReader(inputString); // Special case for copy, 
							// because it is used again with paste. 
						Copy(txtFile, copyQue[copyNumber], copyNumber);	
						break;
					case 'P':
						Paste(txtFile, copyQue[copyNumber], copyNumber);
						break;
					case 'L':
						inputValue=NumberInputReader(inputString);
						Locate(txtFile, inputString);
						break;
					case 'I':
						inputValue=NumberInputReader(inputString);
						Insert(txtFile, inputValue);
						break;
					case 'D':
						inputValue=NumberInputReader(inputString);
						Delete(txtFile, inputValue);
						break;	
					case 'R':
						inputValue=NumberInputReader(inputString);
						Replace(txtFile, inputValue);
						break;	
					case 'M':
						inputValue=NumberInputReader(inputString);
						Move(txtFile, inputValue);	
						break;
					case 'O':
						Open(txtFile);
						break;
					case 'N':
						New(txtFile);
						break;
					case '*': // * saves file to disk
						Save(txtFile);
						//cin.ignore(1000, '\n');
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
				
				if(DEBUG)
					{
						cout<<"--(DEBUG)--> total: "<<txtFile.total<<endl;
						cout<<"--(DEBUG)--> currentLineIndex: "<<txtFile.currentLineIndex<<endl;
					}
				
				
				cout<<"Command? "<<endl;	
				getline(cin, inputString);
				
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
	
int NumberInputReader(string inputString) // Reads the number value input from input string
	{ 
		int i, inputValue=0, signChange=1, temp;
		
		for(i=0; i<=inputString.length()-1; i++)
			{
				inputString.at(i)=toupper(inputString.at(i));
				temp=inputString.at(i);
				temp=temp-'0';
					
				if(inputString.at(i)=='-')
					{
						signChange=signChange*-1;
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
	
void Substitute(file &txtFile, string input_string)
	{
		int pos, pos_2, pos_3, pos_old_string, txtfile_length;
		pos = input_string.find('/');
		string temp_1, new_string, temp_2, old_string;
		temp_1 = input_string.substr(pos + 1);
		pos_2 = temp_1.find('/');
		old_string = temp_1.substr(0,pos_2);
			
		temp_2 = temp_1.substr(pos_2+1);
		new_string = temp_2.substr(0,temp_2.length()-1);
			
		int i_for_loop;
		int new_string_length,old_string_length;
		old_string_length = old_string.length();
		new_string_length = new_string.length();
		bool check, exit;
		int start_from ;
		i_for_loop = txtFile.currentLineIndex;
		start_from = 0;
		check = true;
		exit = false;
		string the_original_string = txtFile.contents[i_for_loop];
		if(txtFile.contents[i_for_loop].find(old_string) == -1)//to show if no match string for the old_string.
			{
				cout<<"'"<<old_string<<"' doesn't occur on line "<<i_for_loop<<". "<<endl;
			}
		if(txtFile.contents[i_for_loop].empty() == true)//to leave if it empty.
			{
				cout<<"Line number "<<i_for_loop<<" is empty."<<endl;
				check = false;
			}
		txtfile_length = txtFile.contents[i_for_loop].length();
				
		while(check and not exit)
			{
				txtfile_length = txtFile.contents[i_for_loop].length();
				
			 	pos_old_string = txtFile.contents[i_for_loop].find(old_string,start_from);
					//the position of the old_string in the string.
				
		 		if(pos_old_string == -1) 
		 			{
			 			exit=true;
		 			}
				else
					{
						if(new_string.empty())
							{
								txtFile.contents[i_for_loop].replace(pos_old_string,old_string_length,"");
								start_from = 0;
							}
						else
							{
								txtFile.contents[i_for_loop].replace(pos_old_string,old_string_length,new_string);
								if(txtFile.contents[i_for_loop].at(pos_old_string + new_string_length - 1) == '\0')
									{
										check = false;
									}
								else
									{
										start_from = pos_old_string + new_string_length;
									}
							}
					}
			}			
		if(txtFile.contents[i_for_loop] != the_original_string)
			cout<<"Text from current line: "<<endl<<"> "<<txtFile.contents[i_for_loop]<<endl;	
	}


void Type(file &txtFile, int type_number) 
	{ 
		int i;
		int otherCounter=0;
		if(txtFile.currentLineIndex<=0)
			txtFile.currentLineIndex=0;
		for(i=txtFile.currentLineIndex; i<(txtFile.currentLineIndex+type_number); i++)
			{		
				cout<<"> "<<txtFile.contents[i]<<endl;
			}
		txtFile.currentLineIndex=txtFile.currentLineIndex+type_number-1;
		
	}

void Copy(file txtFile, string &copyQue, int copyNumber)
	{
		// declare any variables you might need right here: (int i, etc)
		
		// for loop that nullifies the copyQue array (to erase any previous copies first)
		
		// for loop that copies contents of txtFile, starting at the current line, ending with 
			// copyNumber-1, to copyQue. 
	}

void Paste(file &txtFile, string copyQue, int copyNumber)
	{
		// declare any variables you might need right here: (int i, etc)
		
		// for loop that moves the contents of txtFile down copyNumber digits
			// starting with currentLineIndex+copyNumber(+1?)
			// ending with currentLineIndex+1
			// the for loop should work backwards (i--)
		// for loop that pastes the content of copyQue into txtFile.contents
			// the loop should have the opposite conditions of the previous for loop (i++)
				// starts with currentLineIndex+1
				// ends with currentLineIndex+copyNumber(+1?)
	}

void Locate(file &txtFile, string inputString)
	{
		int firstPosition, secondPosition, found, i=txtFile.currentLineIndex;
		string tempOne, searchString;
		
		firstPosition = inputString.find('/');
		tempOne = inputString.substr(firstPosition + 1);
		secondPosition = tempOne.find('/');
		
		searchString = tempOne.substr(0, secondPosition);
	
		found = -1;
		
		while(found == -1 and i<=txtFile.total)
			{
				found=txtFile.contents[i].find(searchString);
				i++;
			}
			
		if(found == -1)
			{
				cout<<"No instance of '"<<searchString<<"' was found. "<<endl;
			}
		else 
			{
				txtFile.currentLineIndex=i-1;
			}
		cout<<"> "<<txtFile.contents[txtFile.currentLineIndex]<<endl;
		
	}

void Insert(file &txtFile, int insert_number) 
	{ 
		int i;
		
		if(txtFile.total==0)
			{
				txtFile.currentLineIndex=-1;
			}
	
		for(i=txtFile.total; i>=txtFile.currentLineIndex; i--)
			{
				txtFile.contents[i+insert_number]=txtFile.contents[i];
			}
		
		for(i=txtFile.currentLineIndex+1; i<=insert_number+txtFile.currentLineIndex; i++) 
			{
				cout<<"> ";
				getline(cin,txtFile.contents[i]);
			}
			
		txtFile.total = txtFile.total + insert_number;
		
		txtFile.currentLineIndex = insert_number + txtFile.currentLineIndex;
				
	}

void Delete(file &txtFile, int delete_number)
	{
		int i, realLinesDeleted=0;
		while(txtFile.currentLineIndex + delete_number >= MAX-1)
			{
				delete_number--;
			}
		for(i=txtFile.currentLineIndex; i<=txtFile.currentLineIndex+txtFile.total-1; i++)
			{
				txtFile.contents[i]=txtFile.contents[i+delete_number];
				
			}	
		while(txtFile.contents[txtFile.currentLineIndex]=="" and txtFile.currentLineIndex>=0) 
			// if no lines, default to line 0 (index -1),
			// so that lines can be inserted from the beginning. 
			{
				txtFile.currentLineIndex--;
			}
			
			txtFile.total = txtFile.total - delete_number;
			if(txtFile.total<=0)
				{
					txtFile.total=0;
				}
	}

void Replace(file &txtFile, int replace_number)
	{
		int i;
		for(i=txtFile.currentLineIndex; i<=txtFile.currentLineIndex+replace_number-1; i++)
			{
				cout<<"> ";
				getline(cin,txtFile.contents[i]);
			}
		if(txtFile.currentLineIndex+replace_number>=txtFile.total)
			{
				txtFile.total=txtFile.currentLineIndex+replace_number;
			}
			
		txtFile.currentLineIndex=txtFile.currentLineIndex+replace_number-1;
		
	}

void Move(file &txtFile, int move_number) 
	{
		if(txtFile.currentLineIndex + move_number <= -1)
			{
				txtFile.currentLineIndex = 0;
			}
		else if(txtFile.currentLineIndex + move_number >= MAX-1)
			{
				txtFile.currentLineIndex = MAX-2;
			}
		else
			{
				txtFile.currentLineIndex = txtFile.currentLineIndex + move_number;
			}
			
		cout<<"Text from current line: "<<endl<<"> "<<txtFile.contents[txtFile.currentLineIndex]<<endl;
	}

void Quit(file txtFile)  
	{
		string yesNo;
		char yesNoTemp;
		
		cout<<"You have asked to quit, "
			<<"would you like to save first? "
			<<endl;
			
		getline(cin, yesNo);
		yesNoTemp=yesNo.at(0);
		yesNoTemp=toupper(yesNoTemp);
		
		switch(yesNoTemp)
			{	
				case 'Y':
					Save(txtFile);
					break;
				case '*':
					Save(txtFile);
					break;
				case 'S':
					Save(txtFile);
				case 'N':
					cout<<"Your file HAS NOT been saved. "<<endl;
				default:
					break;
			}
		cout<<"Have a nice day!"<<endl;	
	}

void Open(file &txtFile)
	{
		int i;
		
		cout<<"Please enter the name of the file which you would like to open. "
			<<endl;
		getline(cin, txtFile.fileName);
		ifstream fin;
		fin.open(txtFile.fileName.c_str());
		
		for(i=0; i<=txtFile.total-1; i++)
			{
				txtFile.contents[i]="";
			}
		i=0;
		while(not fin.eof() and i<=MAX) // Loads file contents into array. 
			{ // Reads from file. 
				getline(fin, txtFile.contents[i]); 
				i++; 
			}
		txtFile.total=i;
		while(txtFile.contents[txtFile.total-1] == "")
			{
				txtFile.total--;
			}
		txtFile.currentLineIndex=-1;
	}
	
void New(file &txtFile)
	{
		int i;
		for(i=0; i<=txtFile.total-1; i++)
			{
				txtFile.contents[i]="";
			}
		txtFile.total=0;
		cout<<"A new file will be created. "<<endl
			<<"Please enter the name of this new file. "<<endl
			<<"> ";
		getline(cin, txtFile.fileName);
		txtFile.currentLineIndex=-1;

	}
	
void Save(file txtFile) 
	{	// a separate save function 
		// so that users can save without quitting. 
		
		int i;
		
		ofstream fout;
		fout.open(txtFile.fileName.c_str());
		
		for(i=0; i<=txtFile.total-1; i++)
			{
				fout<<txtFile.contents[i];
				fout<<"\n";
			}	
			
		cout<<"Your file HAS been saved. "<<endl;

	}

