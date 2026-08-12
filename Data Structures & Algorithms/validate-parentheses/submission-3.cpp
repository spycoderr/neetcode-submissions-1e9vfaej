class Solution {
public:
    bool isValid(string s) {                    // FIX 1: "so" -> "s"
    stack<char> st;                              // FIX 2: stack<int> -> stack<char>, "s" -> "st"
    for(int i=0;i<s.size();i++){                 // ab s.size() = string ka size (pehle stack ka tha, hamesha 0)
        if(s[i]=='['||s[i]=='('||s[i]=='{'){
            st.push(s[i]);                       // FIX 3: s.push -> st.push
        }
        else if(s[i]==']' || s[i]=='}'||s[i]==')'){
            if(st.empty()){                      // FIX 4: !s.empty() -> st.empty() (condition ulti thi, aur s->st)
                return false;
            }
            if((s[i]==')'&& st.top()=='(')||      // FIX 5: s.top() -> st.top()
            (s[i]=='}'&& st.top()=='{')||
            (s[i]==']'&& st.top()=='[')){
                st.pop();                         // FIX 6: s.pop -> st.pop
            }
            else{
                return false;                     // FIX 7: duplicate condition hata ke simple else kar diya
            }
        }
    }                                              // FIX 8: "if(!s.empty()) return false;" ye loop ke ANDAR se hata diya
    return st.empty();                             // FIX 9: return true -> return st.empty(), aur ye ab loop ke BAHAR hai
    }
};
