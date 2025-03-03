#include<iostream>
#include <vector>
#include <cassert>

using namespace std;


vector<int> getLps(string& pat){

    int n = pat.size();
    int i = 1;
    int j = 0;
    vector<int> ans;

    if(n == 0){
        return ans;
    }

    ans.push_back(0); // this is because for the starting element definition wise

    while(i<n){

        if(pat[i] == pat[j]){

            ans.push_back(++j);
            i++;
    
        }
        else{
            if(j == 0){
                ans.push_back(0);
                i++;
            }
            else{
                j = ans[j-1];
            }
        }

    }

    return ans;
}

vector<int> kmp(string& text, string& pat){

    

    int n=  text.size();
    int m = pat.size();


    vector<int> lps = getLps(pat);
    vector<int> ans; // This will store all the matched patterns starting point

    assert(lps.size() == m);
    

    int i = 0;
    int j = 0;

    
    while(i < n){

        // Check if current char matches
        if(text[i] == pat[j]){

            i++;
            j++;

            if(j == m){
                // This means that we got one match
                ans.push_back(i - m);
                j = lps[j-1];
            }
        }
        else{

            if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }

        }

    }

    return ans;

}

int main(){


    string text = "ABABABCABABABCABABABC";
    string pat = "ABABAC";

    // Below are the positions at which the pat appears in the text

    vector<int> ans = kmp(text, pat);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}