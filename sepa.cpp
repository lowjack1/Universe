#include <bits/stdc++.h>

using namespace std;

int permute(string &str, int len)
{
    int key = len - 1;
    int newkey = len - 1;

    /* The key value is the first value from the end which
       is smaller than the value to its immediate right        */

    while( (key > 0) && (str[key] <= str[key-1])) {
        key--;
    }

    key--;

    /* If key < 0 the data is in reverse sorted order, 
       which is the last permutation.                          */

    if( key < 0 ) {
        return 0;
    }

    /* str[key+1] is greater than str[key] because of how key 
       was found. If no other is greater, str[key+1] is used   */

    newkey = len - 1;
    while( (newkey > key) && (str[newkey] <= str[key]) ) {
        newkey --;
    }

    swap(str[key], str[newkey]);

    /* variables len and key are used to walk through the tail,
       exchanging pairs from both ends of the tail.  len and 
       key are reused to save memory                           */

    len--;
    key++;

    /* The tail must end in sorted order to produce the
       next permutation.                                       */

    while(len>key) {
        swap(str[len], str[key]);
        key++;
        len--;
    }

   return 1;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   string s = "0123456789";

    /* A short test loop to print each permutation, which are
       created in sorted order.                                */

    do  {
        cout << s << "\n";
    } while( permute(s, 10) );

    return 0;
}
