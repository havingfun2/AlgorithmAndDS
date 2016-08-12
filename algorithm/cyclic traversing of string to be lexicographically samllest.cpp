    #include <iostream>
    using namespace std;
     
    int main() {
    	// your code goes here
    	int t;
    	cin>>t;
    	while(t--){
    		int N;
    		cin>>N;
    		string s;
    		cin>>s;
    		int i=0,j=1,k=0;
    		while(j<N&&i+k+1<N){
    			if(s[i + k] == s[(j + k) % N]) ++k;
		 	   else if(s[i + k] < s[(j + k) % N]){
        	    j = j + k + 1;
        	    k = 0;
        	}	else{
            		i = max(i + k + 1,j);
            		j = i + 1;
            		k = 0;
        	}
    	}
    		cout<<i<<endl;
    	}
    	return 0;
    }
