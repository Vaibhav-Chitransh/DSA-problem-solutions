string removeDuplicates(string str) {
	    string s;
	    s.push_back(str[0]);
	    
	    for(int i=1; i<str.length(); i++) {
	        bool found = 0;
	        
	        for(int j=0; j<s.length(); j++) {
	            if(str[i] == s[j]) {
	                found = 1;
	                break;
	            }
	        }
	        
	        if(found == 0) {
	            s.push_back(str[i]);
	        }
	    }
	    return s;
	}