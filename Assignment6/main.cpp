#include<iostream>
#include"MyString.h"
using namespace std;

int main()
{
	char string1[100],string2[100],string3[100];
	char option;
	do
	{
		cout<<endl;
	    cout<<"1)Concatenate the Strings"<<endl;
		cout<<"2)Reverse the String"<<endl;
		cout<<"3)Get Length of the string "<<endl;
		cout<<"4)Compare two strings"<<endl;
		cout<<"5)Search and replace"<<endl;
		cout<<"6)subtract the strings"<<endl;
		cout<<"7)Exit"<<endl;
		cin>>option;
		cin.ignore();

		switch(option)
		{
		
		case '1': 
			{
				cout<<"\nEnter the String 1: ";
				cin.getline(string1,100);

				cout<<"\nEnter the String 2: ";
				cin.getline(string2,100);

				MyString str1(string1);
				MyString str2(string2);

				str1.StringConcatenate(str2);
				cout<<"\nConcatenated string is :";
				str1.GetString();
				break;
			}
		 
		case '2':
			{
				cout<<"\nEnter the String to reverse : ";
				cin.getline(string1,100);

				MyString strRev(string1);

				strRev.StringReverse();
				
				cout<<"\nReversed string is :";
				strRev.GetString();
				break;
				
			}
		case '3':
			{
				cout<<"\nEnter the String to find the length : ";
				cin.getline(string1,100);
				
				MyString strLength(string1);
				
				cout<<"\nLength of your string is :"<<strLength.StringLength(string1)<<endl;
				
				break;
				
			}
		
		case '4': 
			{
				cout<<"\nEnter the String 1: ";
				cin.getline(string1,100);

				cout<<"\nEnter the String 2: ";
				cin.getline(string2,100);

				MyString str1(string1);
				MyString str2(string2);

				bool result=str1.CompareStrings(str2);
				if(result)
				{
					cout<<"Both strings are equal ..."<<endl;
				}
				else
				{
					cout<<"Both strings are not equal ..."<<endl;
				};
				break;
			}

		case '5':
			{
				cout<<"\nEnter the String 1: ";
				cin.getline(string1,100);

				cout<<"\nEnter the substring: ";
				cin.getline(string2,100);

				MyString str1(string1);

			
				
				if((str1.StringSearch(string2))==-1)
				{
					cout<<"\nThe given substring is not present in main string.";
				}
				else
				{
					

					cout<<"\nThe given substring is present at "<<str1.StringSearch(string2)<<" index";

					cout<<"\nEnter the string to replace:";
					cin.getline(string3,100);

					str1.StringRelpace(string2,string3,str1.StringSearch(string2));
					cout<<"\nThe new string is : ";
					str1.GetString();
					cout<<endl;

				}
				break;
			}

		case '6':
			{
				cout<<"\nEnter the String 1: ";
				cin.getline(string1,100);

				cout<<"\nEnter the String to subtract: ";
				cin.getline(string2,100);

				MyString str1(string1);
				MyString str2(string2);

				
				if((str1.StringSearch(string2))==-1)
				{
					cout<<"\nThe given substring is not present in main string.";
				}
				else
				{
				
					str1-str2;
					cout<<"\nstring after subtraction :";
					str1.GetString();
				}
				
				break;
			}
		case '7':
			{
				return 0;
			}
		
		default:
			{
				cout<<"\nPlease Enter the valid option ........."<<endl;
			}
		
		}
	
	}while(true);

	return 0;
}