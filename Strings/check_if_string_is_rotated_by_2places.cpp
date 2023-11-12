bool isRotated(string str1, string str2)
{
    if(str1.length() != str2.length()) {
        return false;
    }
    
    int length = str1.length();
    
    vector<char> temp1(length);
    for(int i=0; i<length; i++) {
        temp1[(i+2)%length] = str1[i];
    }
    string s1;
    for(int i=0; i<length; i++) {
        s1.push_back(temp1[i]);
    }
    if(s1 == str2) {
        return true;
    }
    
    int k = length - 2;
    
    vector<char> temp2(length);
    for(int i=0; i<length; i++) {
        temp2[(i+k)%length] = str1[i];
    }
    string s2;
    for(int i=0; i<length; i++) {
        s2.push_back(temp2[i]);
    }
    
    if(s2 == str2) {
        return true;
    }
    
    return false;
}