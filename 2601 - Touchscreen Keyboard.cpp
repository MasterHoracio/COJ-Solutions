#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

using namespace std;

typedef struct{
    string str;
    int dist;
}custom_order;

map <char, pair<int, int> > positions;
string ubication[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

bool cmp(custom_order a, custom_order b){
    if(a.dist < b.dist){
        return true;
    }else if(a.dist > b.dist){
        return false;
    }else{
        if(a.str < b.str)
            return true;
        else
            return false;
    }
}

void computePositions(){
    int len;

    for(int i = 0; i < 3; i++){
        len = ubication[i].length();
        for(int j = 0; j < len; j++){
            positions[ubication[i][j]] = make_pair(i, j);
        }
    }

}

int compute_distance(string word_one, string word_two){
    int contador = 0, len;
    len = word_one.length();
    for(int i = 0; i < len; i++){
        if(word_one[i] != word_two[i]){
            contador += abs(positions[word_one[i]].first - positions[word_two[i]].first) + abs(positions[word_one[i]].second - positions[word_two[i]].second);
        }
    }

    return contador;
}

int main(){
    custom_order words[11];
    int tc, n_words;
    string word;

    computePositions();
    cin >> tc;

    while(tc--){
        cin >> word >> n_words;
        for(int i = 0; i < n_words; i++){
            cin >> words[i].str;
            words[i].dist = compute_distance(words[i].str, word);
        }

        sort(words, words + n_words, cmp);

        for(int i = 0; i < n_words; i++){
            cout << words[i].str << " " << words[i].dist << endl;
        }

    }

    return 0;
}