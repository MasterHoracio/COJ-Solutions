#include <bits/stdc++.h>

using namespace std;

int main(){
    int players, board, n_deck, positions[4], index, len, p_len, winner, cards;
    string str_board, deck[202], curr;
    //map<int, bool> ocupado;
    bool find_position, win;

    while(cin >> players >> board >> n_deck){
        if(players == 0)
            break;
        cin >> str_board;
        memset(positions, 0, sizeof(positions));
        for(int i = 0; i < n_deck; i++)
            cin >> deck[i];
        win = false;
        for(int i = 0; i < n_deck && !win; i += players){
            index = 0;
            for(int j = i; j < i + players && j < n_deck && !win; j++){
                curr = deck[j];
                len = curr.length();
                find_position = p_len = 0;
                for(int k = positions[index]; k < board && !find_position; k++){
                    if(str_board[k] == curr[p_len]){
                        //ocupado[k] = true;
                        ++p_len;
                        if(p_len == len){
                            positions[index] = k + 1;
                            find_position = true;
                        }
                    }
                }
                if(find_position == false || (find_position == true && positions[index] == board)){
                    win = true;
                    winner = index + 1;
                    cards = j + 1;
                }
                ++index;
            }
        }
        //ocupado.clear();
        (win) ? cout << "Player " << winner << " won after " << cards << " cards." << endl:
            cout << "No player won after " << n_deck << " cards." << endl;
    }
    return 0;
}
