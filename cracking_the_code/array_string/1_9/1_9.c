#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotateString(char * s, char * goal)
{
    int lens = strlen(s);
    int leng = strlen(goal);
    int size = lens*2;
    char tmp[size];
    
    int cnt = 0;
    if (lens != leng)
        return 0;
    //! copy
    for (int i = 0; i < size; i++) {
        int index = i % lens;
        tmp[i] = goal[index];
    }

    for (int i = 0; i < lens; i++) {
        if (!strncmp(s, &tmp[i], lens)) {
            cnt++;
            break;
        }
    }
    return cnt == 1;
}

//! time O(n) space O(1)
int main(void)
{
	char a[12] = "waterbottle";
	char b[12] = "erbottlewat";
	if (rotateString(a, b)) 
		printf("yes\n");
	else 
		printf("no\n");	
	return 0;
}
