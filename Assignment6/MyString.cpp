#include"MyString.h"
#include<iostream>
using namespace std;
//---------------------------------------------------------
//parameterized constructor
//---------------------------------------------------------
MyString::MyString(const char* data)
{
	m_length=StringLength(data);
	
	m_str=new char[m_length+1];//dynamically allocating the requird memory

	for(int index=0;index < m_length;++index)
	{
		m_str[index]=data[index];
	}
	
	m_str[m_length] = '\0';//appending the terminating character
}
//---------------------------------------------------------
//Destructor to release the memory
//---------------------------------------------------------
MyString::~MyString()
{
	delete[] m_str;//release the dynamically allocated memeory
}
//---------------------------------------------------------
//Function to calculate the length of the string
//---------------------------------------------------------
int MyString::StringLength(const char* str)
{
       int count=0;
	   while(str[count]!='\0')
	   {
			count++;
	   }
	  
	   return count;
}
//---------------------------------------------------------
//Function to concatenate the two strings
//---------------------------------------------------------
MyString& MyString :: StringConcatenate(const MyString& other)
{
	int newLength = m_length + other.m_length;
	m_length = newLength;

	char * newStr =new char[newLength+1];

	int index=0;
	while(m_str[index] != '\0')
	{
		newStr[index]=m_str[index];

		index++;
	}
	int otherIndex=0;
	while(other.m_str[otherIndex] != '\0')
	{
		newStr[index]=other.m_str[otherIndex];

		index++;
		otherIndex++;
	}
	
	newStr[index]='\0';//terminating character

	delete[] m_str;//releasing the memeory

	m_str=newStr;
	
	return *this ;
}
//---------------------------------------------------------
//Function to get the string and its length
//---------------------------------------------------------
void MyString::GetString()
{
	cout<<m_str<<endl;
}
//---------------------------------------------------------
//Function to compare two strings
//---------------------------------------------------------
bool MyString::CompareStrings(const MyString& other)
{
	//if lengths are not equal then strings are also not equal
	if(m_length != other.m_length)
	{
		return false;
	}

	for(int index=0;index<m_length;++index)
	{
	  if(m_str[index] != other.m_str[index])
	  {
			return false;
	  }
	}

	return true;
	
}
//---------------------------------------------------------
//Function to reverse the string
//---------------------------------------------------------
void MyString::StringReverse()
{
	if(m_length == 0)
	{
		cout<<"Your String is empty !!!"<<endl;
	}

	int start=0;
	int end=m_length-1;
	while(start<end)
	{
		swap( m_str[start] , m_str[end] );
		start++  ;
		end--    ;
	} 

}
//-----------------------------------------------------
//Function to search the string and return its index
//-----------------------------------------------------
int MyString::StringSearch(const char* str)
{
	int strLength=StringLength(str);
	
	//If the substring length is greater than the original string
	if(strLength > m_length)
	{
		return -1;
	}
	int index=0, strIndex=0;
	for(int index=0;index <= m_length-strLength;++index)
	{
		
		for( strIndex  = 0;strIndex < strLength;++strIndex)
		{
			if(m_str[index+strIndex]!=str[strIndex])
			{
				break;
			}
		}
		
		if(strIndex == strLength)
		{
			return index;//substring is present at this index
		}
	}


		return -1;//The substring is not present
}

//-----------------------------------------------------
//Function to replace the string with the given string
//-----------------------------------------------------
void MyString::StringRelpace(const char* searchStr,const char* replaceStr ,const int &index)
{
	int newLength = m_length + (StringLength(replaceStr) - StringLength(searchStr));

    char* newString = new char[newLength + 1];

    // Copy the part of the string before the replacement string
    int i;
    for (i = 0; i < index; ++i) 
	{
        newString[i] = m_str[i];
    }

    // Copy the replacement string
    for (int replaceIndex = 0; replaceStr[replaceIndex] != '\0'; ++i, ++replaceIndex) 
	{
        newString[i] = replaceStr[replaceIndex];
    }

    // Copy the part of the string after the replaced substring
    for (int j = index + StringLength(searchStr); j < m_length; ++j, ++i) 
	{
        newString[i] = m_str[j];
    }

    // Null-terminater
    newString[newLength] = '\0';

    // Delete the old string and assign the new string
    delete[] m_str;
    m_str = newString;
 
   
	

}
//-----------------------------------------------------
//Function to subract the two strings 
//-----------------------------------------------------
MyString& MyString:: operator-(const MyString& other)
{
	int index=StringSearch(other.m_str);
	StringRelpace(other.m_str,"",index);

	return *this;
}
//-----------------------------------------------------
//Function to swap the elements
//-----------------------------------------------------
void swap(char& a,char&b)
{
	char temp;
	temp=a;
	a=b;
	b=temp;
}
