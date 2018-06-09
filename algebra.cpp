string add(string s1, string s2)
{
    string s3 = "";

    int i = int(s1.length()) - 1;
    int j = int(s2.length()) - 1;
    int carry = 0;

    while(i >= 0 and j >= 0) {
        int c = (s1[i] - '0') + (s2[j] - '0') + carry;
        char cc = (c % 10) + '0';
        carry = c / 10;
        s3 = cc + s3; 
        i --, j --;
    }
    if(j >= 0) {
        i = j;
        s1 = s2;
    }
    while(i >= 0) {
        int c = (s1[i] - '0') + carry;
        char cc = (c % 10) + '0';
        s3 = cc + s3;
        carry = c / 10;
        i --;
    }
    while(carry) {
        char cc = (carry % 10) + '0';
        s3 = cc + s3;
        carry /= 10;
    }
    return s3;
}
