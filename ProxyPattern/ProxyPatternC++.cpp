#include <iostream>

using namespace std;

// Abstract class IBookParser
class IBookParser
{
public:

	virtual int RequestNoOfPages() = 0;

};

// Concrete class BookParser
class BookParser : public IBookParser
{
public:

	BookParser(string bookStr) 
	{ 
		/* Let's assume that creating this object is very expensive */ 
		cout << "Created a very expensive BookParser object !!! " << endl;
	}

	int RequestNoOfPages() { return 100; }

};

// Proxy class ProxyParser
class ProxyParser : public IBookParser
{
	BookParser* m_bookParser = nullptr;
	string m_bookStr;

public:

	ProxyParser(string bookStr) : m_bookStr(bookStr){}

	int RequestNoOfPages()
	{
		if (m_bookParser == nullptr)
			m_bookParser = new BookParser(m_bookStr);
		else
			cout << "Reusing the cached object ..." << endl; 
		return m_bookParser->RequestNoOfPages(); 
	}
};

// Main Method
int main()
{
	ProxyParser* parser = new ProxyParser("Really long string");

	cout << parser->RequestNoOfPages() << endl << endl;

	cout << parser->RequestNoOfPages() << endl << endl;

	return 0;
}

/*
Output

Created a very expensive BookParser object !!!
100

Reusing the cached object ...
100

*/
