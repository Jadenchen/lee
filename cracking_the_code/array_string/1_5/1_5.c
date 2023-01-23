#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isOneEditDistance(char * s, char * t)
{
    int lens = strlen(s);
    int lent = strlen(t);
    int cnt = 0;
    if (lent == 0 && lens == 0)
        return false;
    
    if (lens == lent) {
        int cnt = 0;
        for (int i = 0; i < lens; i++) {
            if(s[i] != t[i])
                cnt++;
        }
        return cnt == 1;
    } else if (abs(lens - lent) == 1) {
        int cnt = 0;
        int llen = lens > lent ? lens : lent;
        int slen = lens > lent ? lent : lens;
        char *scur = lens > lent ? t : s;
        char *lcur = lens > lent ? s : t;
        int index = 0;
        for (int i = 0; i < llen; i++) {
            if (scur[cnt] == lcur[i]) {
                cnt++;
            }  
        }
        return cnt == slen;
    } else 
        return false;

}

int main(void)
{
	char a[] = {"pale"};
	char b[] = {"pie"};
	//! insert 
	//! remove
	//! replace 
	if (isOneEditDistance(a, b)) 
		printf("yes one edit\n");
	else 
		printf("No\n");
	return 0;
}
