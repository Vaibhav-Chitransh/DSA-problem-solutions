bool areRotations(string s1,string s2)
{
    if(s1.length() != s2.length()) {
        return false;
    }
    
    string s3 = s1 + s1;
    return s3.find(s2) != string::npos;
}