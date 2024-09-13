#include <bits/stdc++.h>

using namespace std;

void to_lowercase(string& input) {
    transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
        return tolower(c);
    });
}

vector<pair<size_t, size_t>> find_all_occurrences(const string &str, const string &substring) {
    vector<pair<size_t, size_t>> positions;
    size_t start_pos = 0;

    while ((start_pos = str.find(substring, start_pos)) != string::npos) {
        size_t end_pos = start_pos + substring.size() - 1;
        positions.emplace_back(start_pos, end_pos);
        start_pos += substring.size();
    }

    return positions;
}

void solve(vector<pair<size_t, size_t>>& all_occurrences, vector<pair<int, int>>& gaps, string& str, const string& new_string) {
    // Sort occurrences in reverse order to avoid invalidating subsequent positions
    sort(all_occurrences.rbegin(), all_occurrences.rend());

    for (auto g : gaps) {
        for (auto a : all_occurrences) {
            if (a.first >= g.first && a.second <= g.second) {
                size_t len = a.second - a.first + 1;
                str.replace(a.first, len, new_string);

                if (len != new_string.size()) {
                    // Adjust all subsequent positions
                    for (auto& occ : all_occurrences) {
                        if (occ.first > a.first) {
                            occ.first += new_string.size() - len;
                            occ.second += new_string.size() - len;
                        }
                    }
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input, number, tag;

    cin >> input >> number;
    cin.ignore();
    getline(cin, tag);

    to_lowercase(input);
    to_lowercase(tag);

    vector<pair<size_t, size_t>> sub_string = find_all_occurrences(tag, input);

    // Debugging output
    /*for (auto c : sub_string) {
        cout << c.first << " " << c.second << endl;
    }
    cout << endl;*/

    vector<pair<int, int>> finalize;
    bool flag = false;
    int x;

    for (int i = 0; i < tag.size(); ++i) {
        if (tag[i] == '<') {
            flag = true;
            x = i;
        } else if (tag[i] == '>' && flag) {
            finalize.emplace_back(x, i);
            flag = false;
        }
    }

    // Debugging output
   /* for (auto pair : finalize) {
        cout << pair.first << " " << pair.second << endl;
    }*/

    solve(sub_string, finalize, tag, number);

    cout << tag << endl;

    return 0;
}
