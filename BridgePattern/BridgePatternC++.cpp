#include <iostream>

using namespace std;

// Class Artist
class Artist
{
public:
	Artist() = default;
	void Bio() { cout << "Base Guitar player.." << endl; }
	void Name() { cout << "Nikhil" << endl; }
};

// Class Book
class Book
{
public:
	Book() = default;
	void Summary() { cout << "A beloved love story... " << endl; }
	void Label() { cout << "Three mistakes of my Life" << endl; }
};


// Abstract class Resource
class Resource
{
public:
	virtual void Snippet() = 0;
	virtual void Title() = 0;
};

// Abstract class View
class View
{
protected:
	Resource* m_resource;
public:
	View(Resource* resource) : m_resource(resource){}
	virtual void Show() = 0;
};

// Class LongFormView
class LongFormView : public View
{
public:
	LongFormView(Resource* resource) : View(resource){}
	void Show() override { cout << "Long Form View " << endl; m_resource->Title(); m_resource->Snippet(); cout << endl; }
};

// Class ShortFormView
class ShortFormView : public View
{
public:
	ShortFormView(Resource* resource) : View(resource) {}
	void Show() override { cout << "Short Form View " << endl; m_resource->Title(); m_resource->Snippet(); cout << endl; }
};

// Class ScrollableView
class ScrollableView : public View
{
public:
	ScrollableView(Resource* resource) : View(resource) {}
	void Show() override { cout << "Scrollable View " << endl; m_resource->Title(); m_resource->Snippet(); cout << endl; }
};


// Class ArtistResource
class ArtistResource : public Resource
{
	Artist* m_artist;

public:
	ArtistResource(Artist* artist) : m_artist(artist){}
	void Snippet() override { m_artist->Bio(); }
	void Title() override { m_artist->Name(); }
};

// Class BookResource
class BookResource : public Resource
{
	Book* m_book;

public:
	BookResource(Book* book) : m_book(book) {}
	void Snippet() override { m_book->Summary(); }
	void Title() override { m_book->Label(); }
};

// Main Method
int main()
{
	ArtistResource* ar = new ArtistResource(new Artist);
	BookResource* br = new BookResource(new Book);

	LongFormView* lfar = new LongFormView(ar);
	lfar->Show();

	LongFormView* lbr = new LongFormView(br);
	lbr->Show();

	ShortFormView* sfar = new ShortFormView(ar);
	sfar->Show();

	ShortFormView* sfbr = new ShortFormView(br);
	sfbr->Show();

	ScrollableView* scar = new ScrollableView(ar);
	scar->Show();

	ScrollableView* scbr = new ScrollableView(br);
	scbr->Show();

	return 0;
}

/* 
Output

Long Form View
Nikhil
Base Guitar player..

Long Form View
Three mistakes of my Life
A beloved love story...

Short Form View
Nikhil
Base Guitar player..

Short Form View
Three mistakes of my Life
A beloved love story...

Scrollable View
Nikhil
Base Guitar player..

Scrollable View
Three mistakes of my Life
A beloved love story...

*/
