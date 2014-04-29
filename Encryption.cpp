#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>


using namespace std;


const int rot7 = 7;

const int rot13 = 13;


const int character_range_min = 32;
const int character_range_max = 256;



string functionRotEncrypt(string str){

	cout << endl;
	cout << "Encrypting process started " << endl << endl;
	cout << "--------------------------- " << endl;

	//get the string length
	int i = 0;
	int length = str.length();
	int key = rot13 ;
	int k = 5;
	int multiple = 0;
	int count = 0;

	cout << "the text to encrypt is: " << str << endl;
	cout << "text length is: " << length << endl; 
	cout << "using rot13"<<endl;
	cout <<"---------------------------" << endl;
	cout << "using rot13" << endl;

	//traverse the string
	for(i = 0; i < length; i++)
	{

		count ++;

	   cout << left;

	   //if it is a multiple of 5 not the first character change the key 
		if((multiple = (( i % 5 ) == 0)) && (count != 1)  && (key == rot13)){

			key = rot7;
			cout << "key change using rot7" << endl ;

		}
		//if it is a multiple of 5 not the first character change the key 
		else if((multiple = (( i % 5 ) == 0)) && (count != 1) && (key == rot7) ) {

			key = rot13;
			cout << "key change using rot13" << endl ;

		}
		//cout << "string: " << "[" << str[i]<< "]" << " " << "count is: " << count << " " << "multiple is: " << multiple << endl;
		
		
		//check the interval
		if ((str[i] >= character_range_min) && (str[i] <= character_range_max))
		{		
				//check if it goes beyond the character_range_max threshold
				if(str[i] + key > character_range_max){

				//if so reset to be within the range
				str[i] = ((str[i] + key) % character_range_max) + character_range_min;
			}
				else{
						str[i] += key;
				}
			}
		}

	return str;
}

string functionRotDecrypt(string str){

	cout << endl;
	cout << "Decrypting process started " << endl << endl;
	cout << "--------------------------- " << endl;

	//get the string length
	int i = 0;
	int length = str.length();
	int key = rot13;
	int k = 5;
	int multiple = 0;
	int count = 0;

	cout << "the text to decrypt is: " << str << endl;
	cout << "text length is: " << length << endl; 
	cout << "using rot13"<<endl;
	cout <<"---------------------------" << endl;
	cout << "using rot13" << endl;


	//traverse the string
	for(i = 0; i < length; i++)
	{
		count ++;

		//if it is a multiple of 5 not the first character change the key 
		if((multiple = (( i % 5 ) == 0)) && (count != 1) && (key == rot13) ){

			key = rot7;
			cout << "key change using rot7" << left << endl  ;

		}
		//if it is a multiple of 5 not the first character change the key 
		else if((multiple = (( i % 5 ) == 0)) && (count != 1)  && (key == rot7)) {

			key = rot13;
			cout << "key change using rot13" << left <<endl ;

		}
		//cout << "string: " << "[" << str[i]<< "]" << " " << "count is: " << count << " " << "multiple is: " << multiple << left << endl;

		if(str[i] + key > character_range_max){
				str[i] = ((str[i] + key) % character_range_max) + character_range_min;
			}
				else{
						str[i] -= key;
				}
	}
	return str;
}


//
//Function program's entry point
//
int main(int argc, char **argv){


	int option  = 0;

	string text;

	cout << "Enter text : ";
	getline(cin,text);


	string resultEncrypted = functionRotEncrypt(text);

	cout << "the encrypted string is: " << resultEncrypted << endl;

	string resultDecrypted = functionRotDecrypt(resultEncrypted);

	cout << "the unencrypted string is " <<resultDecrypted << endl;

	system("pause");

	return 0;

}