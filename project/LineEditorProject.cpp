// -- GROUP 2 -- Line Editor -- //
// Nicholas Roberts
// Cisty Vue
// Levi Ruiz
// Atef Alrwashdeh
// Phoebe Ruggeberg
// Alex Yang

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

const bool DEBUG = false;
const int MAX = 100;

struct file // This contains the file information and contents
	{
		string contents[MAX]; 
		string fileName;
		int currentLineIndex;
		int total;
		bool markupHighlighting;
	};

int NumberInputReader(string); // Reads the numbers from user input
void Help(); // Prints out a help menu
void Markup(file&, int); // Does HTML highlighting
void MarkupApply(file&, string, int); // Applies the HTML highlighting to the file
void Substitute(file&, string); // substitutes portions of lines of text
void Type(file&, int); // prints text to the screen
void Copy(file, string[], int&); // copies text
void Paste(file&, string[], int); // pastes text
void Locate(file &, string); // finds text
void Insert(file &, int); // inputs text to the array
void Delete(file &, int); // deletes text
void Replace(file &, int); // replaces while lines of text text
void Move(file &, int); // moves the current line 
void Quit(file); // quits the program, asks the users if they want to save. 
void Open(file &); // allows the user to open a file
void New(file &); // allows the user to create a file
void Save(file); // saves the array to a file. 
void IndexPrint(file); // for debugging, this prints the contents of the array. 

int main() // Main program
	{
		file txtFile;
		txtFile.currentLineIndex=-1;
		txtFile.total=0;
		int inputValue=0, copyNumber;
		string inputString, openYN, copyQue[MAX];
		char inputChar, openYNtemp;
		
		
		cout<<"~~~\033[1;32m Welcome \033[0m~~~\n"; // first use of colors in the program
			// these colors are represented as '\033[1;32m' which initiates a certain color based
			// on the value '32' in this case. The color reverts back to normal when 
			// '\033[0m' is used. 
		
		cout<<"Would you like to open an existing file? "
			<<endl;
		getline(cin, openYN);
		if(openYN == "") // if the user simply presses enter, a new file is automatically created
			{ // because if the user really did this, they were probably trolling. 
				cout<<"\033[1;31m-You'll have to be more specific next time.-\033[0m "<<endl;
				New(txtFile);
			}
		else // Wow, the user entered valid input. 
			{
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
		
		inputChar=' '; // Initializes variable as a space just as an entry point. 
		while(inputChar!='Q') // Main event loop. //"if not quit"
			{
				switch(inputChar)
				{
					case ' ': 
						break;
					case 'S': 
						Substitute(txtFile,inputString);
						break;
					case 'T':
						Type(txtFile, inputValue);
						break;
					case 'C':
						copyNumber=NumberInputReader(inputString); // Special variable for copy 
							// because it is used again with paste. 
						Copy(txtFile, copyQue, copyNumber);	
						break;
					case 'P':
						Paste(txtFile, copyQue, copyNumber);
						break;
					case 'L':
						Locate(txtFile, inputString);
						break;
					case 'I':
						Insert(txtFile, inputValue);
						break;
					case 'D':
						Delete(txtFile, inputValue);
						break;	
					case 'R':
						Replace(txtFile, inputValue);
						break;	
					case 'M':
						Move(txtFile, inputValue);	
						break;
					case 'O':
						Open(txtFile);
						break;
					case 'N':
						New(txtFile);
						break;
					case '<': // Highlight
						txtFile.markupHighlighting=true; // highlights the markup in the file '</>'
						Markup(txtFile, inputValue);
						break;
					case '>': // Unhighlight 
						txtFile.markupHighlighting=false; // if false, it'll go through the motions
						Markup(txtFile, inputValue); // again, but revert to the original array
						break; // afterward. 
					case '*': // * saves file to disk
						Save(txtFile);
						break;
					case '?': 
						Help(); // "I seem to be having difficulty with my lifestyle." -Arthur Dent
						break;
					case'.': // default for re-looping
						break;
					default:  
						cout<<"\033[1;31m'"<<inputString<<"'\033[0m"
							<<" is not a valid command. "
							<<endl
							<<"Enter 'Help' for a list of valid commands. "
							<<endl;
						break;	
				}
				
				if(DEBUG)
					{
						cout<<"\033[1;31m";
						cout<<"--(DEBUG)--> total: "<<txtFile.total<<endl;
						cout<<"--(DEBUG)--> currentLineIndex: "<<txtFile.currentLineIndex<<endl;
						IndexPrint(txtFile);
						cout<<"\033[0m";
					}
				
				cout<<"Command? "<<endl;	
				getline(cin, inputString);
				
				if(inputString == "")
					{
						cout<<"\033[1;31m-You'll have to be more specific.-\033[0m "<<endl;
						inputChar='.'; // resets the loop because the user was being unfriendly
					}
				else if(inputString.length()>=19)
					{
						cout<<"\033[1;31m-That's a very long command, "
							<<"I'm just but a humble Line Editor.-\033[0m "<<endl;
						inputChar='.'; // resets the loop because the user was being unfriendly
					}
				else
					{
						inputChar=inputString.at(0);
						inputChar=toupper(inputChar);	
						
						inputValue=NumberInputReader(inputString);
					}
				
			}

			Quit(txtFile); // calls quit function, Y or N to save. 	
			cout<<"Have a nice day!"<<endl;	
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

void Help()
	{
		cout<<endl
			<<"Here is a list of valid commands (and their formats): "<<endl
			<<"\033[1;32mInsert\033[0m (Insert #)"<<endl
			<<"...Inserts # lines after the current line. "<<endl
			<<"\033[1;32mType\033[0m (Type #)"<<endl
			<<"...Prints # lines, including the current line, onto the screen. "<<endl
			<<"\033[1;32mMove\033[0m (Move +-#)"<<endl
			<<"...Moves # lines forward or backward from the current line. "<<endl
			<<"\033[1;32mReplace\033[0m (Replace #)"<<endl
			<<"...Replaces # lines beginning with the current line with input. "<<endl
			<<"\033[1;32mDelete\033[0m (Delete #)"<<endl
			<<"...Deletes the next # lines beginning with the current line. "<<endl
			<<"\033[1;32mLocate\033[0m (Locate /text/)"<<endl
			<<"...Locates the next occurrence of /text/. "<<endl
			<<"\033[1;32mSubstitute\033[0m (Substitute /Original text/Substituted text/)"<<endl
			<<"...Substitutes the all occurrences of /Original text/ "<<endl
			<<"...with /Substituted text/ in the current line. "<<endl
			<<"\033[1;32mCopy\033[0m (Copy #)"<<endl
			<<"...Copies the next # lines beginning with the current line. "<<endl
			<<"\033[1;32mPaste\033[0m (Paste)"<<endl
			<<"...Pastes whatever has been copied last. "<<endl
			<<"\033[1;32m<Markup Highlighting\033[0m (<#)"<<endl
			<<"...Highlights all markup </> in the document according"<<endl
			<<"...to the color options, which are #0-7. "<<endl
			<<"\033[1;32m>Markup Unhighlighting\033[0m (>)"<<endl
			<<"...Unhighlights markup </>. "<<endl
			<<"\033[1;32mQuit\033[0m (Quit)"<<endl
			<<"...Exits the editor. "<<endl
			<<"\033[1;32mOpen\033[0m (Open)"<<endl
			<<"...Opens a new file. "<<endl
			<<"\033[1;32mNew\033[0m (New)"<<endl
			<<"...Creates a new file. "<<endl
			<<"\033[1;32m* Save\033[0m (*)"<<endl
			<<"...Saves the current file to disk. "<<endl
			<<"\033[1;32m? Help\033[0m (?)"<<endl
			<<"...Prints the above help menu. "<<endl
			<<endl
			<<"\"I seem to be having tremendous difficulty with my lifestyle.\" -Arthur Dent "<<endl
			<<"...Happy editing! "<<endl
			<<endl; // UPDATE HELP MENU
		
	}
	
void Markup(file &txtFile, int inputColor) // Locates the markup and changes the color based on 
	{ // user input. Then calls MarkupApply. 
		int i, openFind, closeFind, len;
		bool end;
		string beginColor, endColor = "\033[0m";
		string toBeReplaced, replacement, unhighlightedContents[MAX], finalString;
		
		fabs(inputColor);
		
		for(i=0; i<=txtFile.total-1; i++)
					{
						unhighlightedContents[i]=txtFile.contents[i];
					}
		
		if(inputColor<=-1 or inputColor>=8)
			{
				inputColor=0; // Default color
				cout<<"\033[1;31m-Invalid color. Color set to default.-\033[0m"<<endl;
			}
			
		switch(inputColor)
			{
				case 0:
					beginColor="\033[1;32m"; // colors two and zero are switched
					break;
				case 1:
					beginColor="\033[1;31m";
					break;
				case 2:
					beginColor="\033[1;30m"; // because if no colors are entered the 
					break; // default should be color two
				case 3:
					beginColor="\033[1;33m";
					break;
				case 4:
					beginColor="\033[1;34m";
					break;
				case 5:
					beginColor="\033[1;35m";
					break;
				case 6:
					beginColor="\033[1;36m";
					break;
				case 7:
					beginColor="\033[1;37m";
					break;
				default:
					cout<<"\033[1;31m-There seems to have been an error.-\033[0m"<<endl;
					break;
			}
			
		if(DEBUG)
			{
				cout<<beginColor<<"Test"<<endColor<<endl;
			}
		
		// user input colors (0-7)
		// firstPosition = inputString.find('/');
		// secondPosition = tempOne.find('/');
		// 
		
		i=0;
		
		while(i<=txtFile.total-1) // or reaches end, or none on the line
			{
				openFind=0;
				closeFind=0;
				while(openFind != -1)
					{
						openFind = txtFile.contents[i].find('<', closeFind);
						closeFind = txtFile.contents[i].find('>', openFind)+1;
						len=closeFind-openFind;
						
						if(openFind >= 0 and closeFind >= 0)
							{
								toBeReplaced = txtFile.contents[i].substr(openFind, closeFind);
								/*cout<<toBeReplaced
									<<" : ("<<openFind<<","<<closeFind<<")"<<endl;*/
								replacement=beginColor+toBeReplaced+endColor;
								
								finalString="|"+toBeReplaced+"|"+replacement+"|";
								//MarkupApply(txtFile, finalString, i);
								txtFile.contents[i].replace(openFind, len, replacement);
							}
					}	
				i++;
			}
		
		if(txtFile.markupHighlighting=false)
			{
				for(i=0; i<=txtFile.total-1; i++)
					{
						txtFile.contents[i]=unhighlightedContents[i];
					}
			}
		
	}
	
void MarkupApply(file &txtFile, string input_string, int line) // Pretty much the same as Substitute
	{ // this is only called by Makrup. 
		int pos, pos_2, pos_3, pos_old_string, txtfile_length;
		pos = input_string.find('|');
		string temp_1, new_string, temp_2, old_string;
		temp_1 = input_string.substr(pos + 1);
		pos_2 = temp_1.find('|');
		old_string = temp_1.substr(0,pos_2);
			
		temp_2 = temp_1.substr(pos_2+1);
		new_string = temp_2.substr(0,temp_2.length()-1);
			
		int i_for_loop;
		int new_string_length,old_string_length;
		old_string_length = old_string.length();
		new_string_length = new_string.length();
		bool check, exit;
		int start_from ;
		i_for_loop = line;
		start_from = 0;
		check = true;
		exit = false;
		string the_original_string = txtFile.contents[i_for_loop];
		if(txtFile.contents[i_for_loop].empty() == true)//to leave if it empty.
			{
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
	}

void Substitute(file &txtFile, string input_string) // substitutes '/string/' with '/other string/'
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
				cout<<"\033[1;31m-'"<<old_string<<"'\033[0m does not occur on line \033[1;31m"
					<<i_for_loop<<"\033[0m.- "<<endl;
			}
		if(txtFile.contents[i_for_loop].empty() == true)//to leave if it empty.
			{
				cout<<"\033[1;31m-Line number "<<i_for_loop+1<<" is empty.-\033[0m"<<endl;
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
			cout<<"Text from current line: "<<endl
				<<"\033[1;36m>\033[0m "<<txtFile.contents[i_for_loop]<<endl;	
	}


void Type(file &txtFile, int type_number) // prints to the screen. 
	{ 
		int i;
		int otherCounter=0;
		bool exit=false;
		
		type_number=fabs(type_number);
		
		if(txtFile.currentLineIndex<=0)
			{
				txtFile.currentLineIndex=0;
			}
			
		i=txtFile.currentLineIndex;
		while(i<=txtFile.currentLineIndex+type_number-1 and exit !=true)
			{
				if(i<= txtFile.total-1)
					{
						cout<<"\033[1;36m>\033[0m "<<txtFile.contents[i]<<endl;
						i++;
					}
				else 
					{
						cout<<"\033[1;31m-End of document.-\033[0m "<<endl;
						exit = true;
					}
			}
			
		txtFile.currentLineIndex=i-1;
	}

void Copy(file txtFile, string copyQue[], int &copyNumber) // copies text
	{
		int i;
		
		copyNumber=fabs(copyNumber);
		
		while(copyNumber+txtFile.currentLineIndex-1>=txtFile.total)
			{
				copyNumber--;
			}
		
		for(i=0; i<=copyNumber-1; i++)
			{
				copyQue[i]="";
			}
			 
		for(i=0; i<=copyNumber-1; i++)
			{
				copyQue[i]=txtFile.contents[i+txtFile.currentLineIndex];
			}
			
	}

void Paste(file &txtFile, string copyQue[], int pasteNumber) // pastes text
	{
		int i;
		
		if(pasteNumber+txtFile.total-1>=MAX)
			{
				cout<<"\033[1;31m-You cannot exceed the total number of lines.- \033[0m"<<endl;
			}
		else
			{
				for(i=txtFile.total-1; i>=txtFile.currentLineIndex+1; i--)
					{
						txtFile.contents[i+pasteNumber]=txtFile.contents[i];
					} 
				for(i=txtFile.currentLineIndex+1; i<=txtFile.currentLineIndex+pasteNumber; i++)
					{
						txtFile.contents[i]=copyQue[i-txtFile.currentLineIndex-1];
					}
				txtFile.total=txtFile.total+pasteNumber;
				txtFile.currentLineIndex=i-1;
			}
	}

void Locate(file &txtFile, string inputString) // finds text. 
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
				cout<<"\033[1;31m-No instance of '"<<searchString<<"' was found.-\033[1;31m "<<endl;
			}
		else 
			{
				txtFile.currentLineIndex=i-1;
			}
		cout<<"\033[1;36m>\033[0m "<<txtFile.contents[txtFile.currentLineIndex]<<endl;
		
	}

void Insert(file &txtFile, int insert_number) // inserts text
	{ 
		int i, reductionDifference=0;
		bool reduction=false;
		
		insert_number=fabs(insert_number);
		
		if(txtFile.total==0 and txtFile.currentLineIndex<=0)
			{
				txtFile.currentLineIndex=-1;
			}
	
		while(txtFile.currentLineIndex+insert_number-1>=MAX-1)
			{
				insert_number--;
				reduction=true;
			}

		if(reduction==true and insert_number>=1)
			{
				cout<<"\033[1;31m-You may only add "<<insert_number
					<<" more lines.-\033[1;31m "<<endl;
			}
		else if(reduction==true and insert_number<=0)
			{
				cout<<"\033[1;31m-You have reached the maximum number of lines.-\033[1;31m "<<endl;
			}
		for(i=txtFile.total-1; i>=txtFile.currentLineIndex+1; i--)
			{
				txtFile.contents[i+insert_number]=txtFile.contents[i];
			}
		
		for(i=txtFile.currentLineIndex+1; i<=insert_number+txtFile.currentLineIndex; i++) 
			{
				cout<<"\033[1;36m>\033[0m ";
				getline(cin,txtFile.contents[i]);
			}
			
		txtFile.total = txtFile.total + insert_number;
		
		txtFile.currentLineIndex = insert_number + txtFile.currentLineIndex;
			
	}

void Delete(file &txtFile, int delete_number) // deletes text and moves 
	{ // the other text to the top of the array
		int i;
		
		delete_number=fabs(delete_number);
		
		if(delete_number==0)
			{
				delete_number=1;
			}
		
		while(delete_number+txtFile.currentLineIndex-1>=txtFile.total)
			{
				delete_number--;
			}
		for(i=txtFile.currentLineIndex+delete_number; i<=txtFile.total-1; i++)
			{
				txtFile.contents[i-delete_number]=txtFile.contents[i];	
				
			}
		while(txtFile.total<=0)
			{
				txtFile.total++;
			}
		txtFile.total = txtFile.total - delete_number;
		if(txtFile.currentLineIndex==txtFile.total)
			{
				txtFile.currentLineIndex--;
			}
	}

void Replace(file &txtFile, int replace_number) // replaces text
	{
		int i;
		bool reduced;
		
		replace_number=fabs(replace_number);
		
		if(txtFile.currentLineIndex==-1)
			{
				txtFile.currentLineIndex=0;
			}
		
		while(replace_number+txtFile.currentLineIndex-1>=txtFile.total)
			{
				replace_number--;
				reduced=true;
			}
		
		if(replace_number<=0 and reduced==true)
			{
				cout<<"\033[1;31m-You cannot replace lines that do not exist.-\033[0m"<<endl;
			}
		
		for(i=txtFile.currentLineIndex; i<=txtFile.currentLineIndex+replace_number-1; i++)
			{
				cout<<"\033[1;36m>\033[0m ";
				getline(cin,txtFile.contents[i]); 
			}
		
		if(reduced==true)
			{
				cout<<"\033[1;31m-No more replaceable lines exist past this point.-\033[0m"<<endl;
			}
		
		if(txtFile.currentLineIndex+replace_number>=txtFile.total)
			{
				txtFile.total=txtFile.currentLineIndex+replace_number;
			}
			
		txtFile.currentLineIndex=txtFile.currentLineIndex+replace_number-1;
		
	}

void Move(file &txtFile, int move_number) // moves text
	{
		if(txtFile.currentLineIndex + move_number <= -1)
			{
				txtFile.currentLineIndex = 0;
			}
		else if(txtFile.currentLineIndex + move_number >= txtFile.total)
			{
				txtFile.currentLineIndex = txtFile.total-1;
			}
		else
			{
				txtFile.currentLineIndex = txtFile.currentLineIndex + move_number;
			}
			
		cout<<"Text from current line: "<<endl<<"\033[1;36m>\033[0m "<<txtFile.contents[txtFile.currentLineIndex]<<endl;
	}

void Quit(file txtFile)  // Quit function uses recusion to make sure the user does not
	// accidently make a typo when answering "would you like to save first"
	// and lose their work because of it. 
	{
		string yesNo;
		char yesNoTemp;
		
		cout<<"You have asked to quit, "
			<<"would you like to save first? "
			<<endl;
			
		getline(cin, yesNo);
		if(yesNo == "")
			{
				cout<<"\033[1;31m-You didn't enter a command.-\033[0m "<<endl;
				Quit(txtFile);
			}
		else
			{
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
							break;
						case 'N':
							cout<<"Your file \033[1;31mHAS NOT\033[0m been saved. "<<endl;
							break;
						default:
							cout<<"Saving is serious business and "
								<<"\033[1;31m'"<<yesNo<<"'\033[0m"
								<<" is not an appropriate response. "<<endl
								<<"Please enter an appropriate response. "<<endl;
							Quit(txtFile);
							break;
					}
			}
	}

void Open(file &txtFile) // opens a file
	{
		int i;
		
		cout<<"Please enter the name of the file which you would like to open. "
			<<endl<<"> ";
		getline(cin, txtFile.fileName);
		ifstream fin;
		fin.open(txtFile.fileName.c_str());
		if(fin)
			{
				for(i=0; i<=txtFile.total-1; i++)
					{
						txtFile.contents[i]="";
					}
				i=0;
				while(not fin.eof() and i<=MAX-1) // Loads file contents into array. 
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
		else
			{
				cout<<"\033[1;31m-This file does not exist.-\033[0m"<<endl;
				New(txtFile);
			}
	}
	
void New(file &txtFile) // makes a new file
	{
		int i;
		for(i=0; i<=txtFile.total-1; i++)
			{
				txtFile.contents[i]="";
			}
		txtFile.total=0;
		cout<<"\033[1;32mA new file will be created.\033[0m"<<endl
			<<"Please enter the name of this new file. "<<endl
			<<"\033[1;36m>\033[0m ";
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
		
		cout<<"Your file \033[1;34mHAS\033[0m been saved. "<<endl;

	}

void IndexPrint(file txtFile) // This is for debugging. 
	{
		int i; 
		for (i=0; i<=txtFile.total-1; i++)
			{
				cout<<"--(DEBUG)--"<<i;
				if(i==txtFile.currentLineIndex)
					cout<<">->-> ";
				else
					cout<<"> ";
				cout<<txtFile.contents[i]<<endl;
			}
	}
