#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include<sstream>
#include<map>

using namespace std;

class Vocabulary
{
private:
    // Choose a proper container from STL.
    static int id;
    map<string, int> voc;

public:
    vector<int> insertSentReturnIds(string sentence){
        vector<int> returnvalue;
        istringstream str(sentence);
        vector<string> words;
        string word;
        while(str >> word) {
            if(voc.count(word) == 0) {
                voc[word] = id;
                id++;
            }
            returnvalue.push_back(voc[word]);
        }
        return returnvalue;
    }
};
int Vocabulary::id = 1;

class DataLoader{
private:
    vector<int> _rand_order;
    int batch_size=0;
    vector<vector<int>> sentences;
    vector<vector<int>> sorted;
    vector<vector<vector<int>>> _result;
    //Enter your code here
public:
    void setBatchSize(int N) {
        this->batch_size = N; // can also change
        int a;
        if (sentences.size() % batch_size == 0) a = sentences.size() / batch_size;
        else a = (sentences.size() - sentences.size() % batch_size) / batch_size + 1;
        _result = vector<vector<vector<int>>>(a);
        for (int i = 0; i < sentences.size(); i++) {
            _result[i / batch_size].push_back(sorted[i]);
        }
        for(int i = 0; i < _result.size(); i++) {
            int maxn = 0;
            for(int j = 0; j < _result[i].size(); j++) {
                if(_result[i][j].size() > maxn) maxn = _result[i][j].size();
            }
            for(int j = 0; j < _result[i].size(); j++) {
                int a = _result[i][j].size();
                if(_result[i][j].size() < maxn) {
                    for(int k = 0; k < maxn - a; k++)
                        _result[i][j].push_back(0);
                }
            }
        }
    }

    void setOrder(vector<int>& x) {
        _rand_order = x; // can also change
        sorted.clear();
        _result.clear();
        for(int i = 0; i < sentences.size(); i++) {
            sorted.push_back(sentences[_rand_order[i]]);
        }
    }

    void addData(vector<int> sent_encoding) {
        //Enter you code here;
        sentences.push_back(sent_encoding);
    }

    struct Iterator
    {
        //Define your constructor and functions that are needed for a Iterator.
        bool operator!= (Iterator other) const {return this->begin != other.begin;}
        bool operator== (Iterator other) const {return this->begin == other.begin;}
        Iterator(vector<vector<vector<int>>>::iterator b) : begin(b) {}
        Iterator operator++() {
            return Iterator(begin++);
        }
        vector<vector<int>> operator* () {
            return *begin;
        }

    private:
        vector<vector<vector<int>>>::iterator begin;
    };

    Iterator begin() {
        //Enter your code here.
        return Iterator(_result.begin());
    }
    Iterator end() {
        //Enter your code here.
        return Iterator(_result.end());
    }
};