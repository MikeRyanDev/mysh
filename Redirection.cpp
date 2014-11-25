#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

	
int main()
{	
	//file and string variables	
	vector<string> v; 
	string inputFilename;
	string outputFilename;
	string line;		

	//Handle Inputfile
	cout << "File that is being read: ";
	cin >> inputFilename; //inputfile to be read

	ifstream inFile;
	inFile.open(inputFilename, ios_base::in); //open inputfile for reading

	if (inFile.is_open()) //file successfully opened 
	{
			while ( inFile.good() ) //read each line from file and store in vector
			{		 
				getline(inFile, line);
				v.push_back(line);
			}     
	}

	else if (!inFile) //file unalbe to open
	{  
		cout << "Unable to open file";
		return 0;
	}		

	
	//Handle Outputfile
	int choice;	
	ofstream outFile;
	cout << "Select 1 to overwrite data or 2 to append: ";
	cin >> choice;
	cout << "File that is being written to: ";
	cin >> outputFilename; //outputfile that data is being written to


	if (choice == 1) //This will be the '<' case
	{		
		outFile.open(outputFilename, ios_base::out); //open file for writing

		if (outFile.is_open()) //file successfully opened 
		{	  
				for( size_t i = 0; i < v.size(); i++) //loop to print vector
				{
					outFile << v[i] << endl;
				}	 
		}  

		else if (!outFile) //file was unable to open
		{
			cout << "Unable to open file"; 
			return 0;
		}
	}

	else if (choice == 2) //This will be the '<<' case
	{			
		outFile.open(outputFilename, ios_base::app); //open file for appending

		if (outFile.is_open()) //file successfully opened 
		{	  
				for( size_t i = 0; i < v.size(); i++) //loop to print vector
				{
					outFile << v[i] << endl;
				}	 
		}  

		else if (!outFile) //file was unable to open
		{
			cout << "Unable to open file"; 
			return 0;
		}
	}
  
		inFile.close(); 
		outFile.close();
		return 0;
}//end of main



