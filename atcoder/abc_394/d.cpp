#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  stack<char> st;
  for (int i = 0; i<n; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '<') {
      st.push(s[i]);
    } else {
      if (st.empty()) {
        cout << "No" << endl;
        return 0;
      }
      char c = st.top();
      if (c == '(' && s[i] == ')') {
        st.pop();
      } else if (c == '[' && s[i] == ']') {
        st.pop();
      } else if (c == '<' && s[i] == '>') {
        st.pop();
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << (st.empty() ? "Yes" : "No") << endl;
}
