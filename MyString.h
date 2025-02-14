class MyString
{
	private:
		char *m_str;
		int m_length;
	
	public:
		//default constructor
		MyString():m_str(0),m_length(0){};
		
		//parameterized constructor
		MyString(const char* str);

		//destructor
		~MyString();

	    //To calculate the length of the string
		int StringLength(const char* str);

		//To concatenate the two strings
		MyString& StringConcatenate(const MyString& other);

		//To print the string and its length
		void GetString();

		//To compare two strings
		bool CompareStrings(const MyString& other);

		//To reverse the string
		void StringReverse();

		//To search the string and return its index
		int StringSearch(const char* str);

		//To replace the string
		void StringRelpace(const char* str,const char* str2,const int &index);

		//To overload the '-' operator
		MyString& operator-(const MyString& other);
};