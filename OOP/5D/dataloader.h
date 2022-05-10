#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include<sstream>
#include<map>

using namespace std;



// Change this file as you want or add more files






class Vocabulary
{
private:
    // Choose a proper container from STL.
    static int id;
    map<int, string> voc;

public:
    vector<int> insertSentReturnIds(string sentence){
        //Enter your code here.
        //This function should build vocabulary and at the same time return a sentence encoding.
    }
};
int Vocabulary::id = 1;


class DataLoader{
private:
    vector<int> _rand_order;
    int batch_size=0;
    //Enter your code here
public:
    void setBatchSize(int N){
        this->batch_size = N; // can also change
    }

    void setOrder(vector<int>& x){
        _rand_order = x; // can also change
    }

    void addData(vector<int> sent_encoding){
        //Enter you code here;
    }

    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        // Add more using statement here
        // hint: using value_type = ?
        //       using reference = ?

        //Define your constructor and functions that are needed for a Iterator.


        private:
        // Add what where variable you want here to make the Iterator functional.

    };

    Iterator begin() {
        //Enter your code here.
    }
    Iterator end() {
        //Enter your code here.
    }

};






