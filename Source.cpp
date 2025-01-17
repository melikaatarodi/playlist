#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime>


using namespace std;

class Node {
public:
    string songname;
    string artistname;
    string time;
    string genre;
    Node* past;
    Node* next;

    Node(string song, string artist, string time, string genre)
        : songname(song), artistname(artist), time(time), genre(genre), past(nullptr), next(nullptr) {}
};

class Playlist {
private:
    Node* top;
    Node* down;
	Node* thiss;
	int tedad;
	
public:
    Playlist() : top(nullptr), down(nullptr) , thiss(nullptr) , tedad(0) {}

    void addSong(const string& song, const string& artist, const string& duration, const string& genre) {
        Node* newnode = new Node(song, artist, duration, genre);
        if (!top) {
            top = down = newnode;
			thiss = newnode;
        } else {
            down->next = newnode;
            newnode->past = down;
            down = newnode;
        }
		tedad++;
		
    }

   void removeSong(const string& cut) { 
        Node* x = top;
		
        while (x) {
            
		    if (x->songname == cut )
			{ 
				
                if (x->past) {
                    x->past->next = x->next;
                } else {
                    top = x->next; 
                }
                
                if (x->next) {
                    x->next->past = x->past; 
                } else {
                    down = x->past; 
                }
				x = x->next; 
				cout << "Song removed: " << cut << endl; 
				tedad--;
			return;
            }
		x = x->next; 
   		}
        cout << "Song not found: " << cut << endl; 
   }
    void removeSongsArtist(const string& cut2) {
        Node* x = top; 
        bool f = false;

        while (x) {
            if (x->artistname == cut2) { 
                f = true;

                if (x->past) {
                    x->past->next = x->next; 
                } else {
                    top = x->next; 
                }

                if (x->next) {
                    x->next->past = x->past;
                } else {
                    down = x->past;
                }
                x = x->next;
               
            } else {
                x = x->next;
            }
        }
	
        if (f) {
            cout << "songs by '" << cut2 << "' removed." << endl;
        } else {
            cout << "No songs found for artist: " << cut2 << endl;
        }
    }
	void removeSongsGenre(const string& cut3) {
        Node* x = top; 
        bool h = false;

        while (x) {
            if (x->genre == cut3) {
                h = true;
                if (x->past) {
                    x->past->next = x->next;
                } else {
                    top = x->next;
                }

                if (x->next) {
                    x->next->past = x->past; 
                } else {
                    down = x->past;
                }
                x = x->next; 
               
            } else {
                x = x->next; 
            }
        }

        if (h) {
            cout << "songs of '" << cut3 << "' removed." << endl;
        } else {
            cout << "No songs found for genre: " << cut3 << endl; // اگر آهنگ پیدا نشد
        }
    }

   
    void searchSong(const string& search) const {
        Node* x = top; 
        bool p = false;
        while (x) {
          
            if (x->songname == search || x->artistname == search || x->genre == search) {
                cout << "Found Song: " << x->songname 
                     << ", Artist: " << x->artistname 
                     << ", Duration: " << x->time 
                     << ", Genre: " << x->genre << endl;
                p = true;
            }
            x = x->next; 
        }
        if (!p) {
            cout << "No songs found for: " << search << endl; 
        }
    }
	  void sortBySongName() {
        if (!top) return; 

        bool s;
        do {
            s = false;
            Node* x = top;
            while (x->next) {
                if (x->songname > x->next->songname) {
                    swap(x->songname, x->next->songname);
                    swap(x->artistname, x->next->artistname);
                    swap(x->time, x->next->time);
                    swap(x->genre, x->next->genre);
                    s = true;
                }
                x = x->next;
            }
        } while (s);
    }

    void sortByArtist() {
        if (!top) return; 

        bool s;
        do {
            s = false;
            Node* x = top;
            while (x->next) {
                if (x->artistname > x->next->artistname) {
                    swap(x->songname, x->next->songname);
                    swap(x->artistname, x->next->artistname);
                    swap(x->time, x->next->time);
                    swap(x->genre, x->next->genre);
                    s = true;
                }
                x = x->next;
            }
        } while (s);
    }
	void showThisSong() const { 
        if (thiss) {
            cout << "This Song: " << thiss->songname 
                 << ", Artist: " << thiss->artistname 
                 << ", Duration: " << thiss->time 
                 << ", Genre: " << thiss->genre << endl;
		}
	}
	   void moveDown() {
			 if(thiss->next){
            thiss = thiss->next;
            cout << "After move down: " << thiss->songname 
                 << ", Artist: " << thiss->artistname 
                 << ", Duration: " << thiss->time 
                 << ", Genre: " << thiss->genre << endl;
        } else {
            cout << "It's the last song." << endl;
		}
	
    }

    void moveUp() {
		if(thiss->past){ 
		    thiss = thiss->past;
            cout << "After move up: " << thiss->songname 
                 << ", Artist: " << thiss->artistname 
                 << ", Duration: " << thiss->time 
                 << ", Genre: " << thiss->genre << endl;
        } else {
            cout << "It's the first song." << endl;
		 }
    }
    void displayPlaylist() const {
        Node* x = top;
        while (x) {
				 cout << "Song: " << x->songname 
                 << ", Artist: " << x->artistname 
                 << ", Duration: " << x->time 
                 << ", Genre: " << x->genre << endl;
            x = x->next;
        }
	}
	void random() {
        if (tedad == 0) {
            cout << "There is no songs" << endl;
            return;
        }

        srand(static_cast<unsigned int>(time(0)));
        int random = rand() % tedad; 

        Node* r = top;
		
        for (int i = 0; i < random; i++) {
            r = r->next; 
        }

        thiss = r; 
        cout << "Playing Random Song: " << thiss->songname 
             << ", Artist: " << thiss->artistname 
             << ", Duration: " << thiss->time 
             << ", Genre: " << thiss->genre << endl;
    
	}
	 void repetitive() {
        Node* x = top; 

        while (x) {
            Node* y = x->next; 
            Node* z = x; 

            while (y) {
                if (y->songname == x->songname) { 
                    Node* v = y;
                    z->next = y->next; 
                    if (y->next) {
                        y->next->past = z; 
                    } else {
                        down = z;
                    }

                    y = y->next; 
                    tedad--; 
                } else {
                    z = y; 
                    y = y->next; 
                }
            }
            x = x->next; 
        }
	 }
	  
};

int main() {
	srand(static_cast<unsigned int>(time(0)));
    Playlist myPlaylist;
    myPlaylist.addSong("khalegh", "ebi", "3:39", "pop");
	myPlaylist.addSong("morgh sahar", "shajarian", "5:43", "sonati");
	myPlaylist.addSong("ziba", "arman garshasbi", "4:17", "pop");
    myPlaylist.addSong("khanom gol", "ebi", "4:12", "pop");
	myPlaylist.addSong("ziba", "arman garshasbi", "4:17", "pop");
	myPlaylist.addSong("dar khial", "shajarian", "6:38", "sonati");
	myPlaylist.addSong("badbin", "ebi", "4:23", "pop");
	myPlaylist.addSong("ziba", "arman garshasbi", "4:17", "pop");
	
    
   
	cout  << "Playlist:" << endl;
    myPlaylist.displayPlaylist();
	cout << endl;
	myPlaylist.removeSong("badbin");
	cout << endl;
	myPlaylist.removeSongsArtist("shajarian");
	cout << endl;
	myPlaylist.removeSongsGenre("metal");
	cout << endl;
	myPlaylist.displayPlaylist();
	cout << endl;
    myPlaylist.searchSong("morgh sahar"); 
	cout << endl;
    myPlaylist.searchSong("ebi");
	cout << endl;
    myPlaylist.searchSong("Rock"); 
	cout << endl;
    //myPlaylist.sortByArtist();
	myPlaylist.sortBySongName();
	myPlaylist.showThisSong();
	myPlaylist.moveDown(); 
    cout << "\nNew Playlist:" << endl;

    myPlaylist.displayPlaylist();
	cout << endl;
	//myPlaylist.random();
	cout << endl;
	myPlaylist.repetitive();
	cout<<"After remove repetitive songs: "<<endl;
	myPlaylist.displayPlaylist();
	system("pause");
}