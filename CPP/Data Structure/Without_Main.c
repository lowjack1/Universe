#include <stdio.h>
extern void _exit(register int);
int _start()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	_exit(0);
}

/*It works because _start is building block of program execution it does not need main() 
 It will run using only terminal by
 		gcc b.c -nostartfiles
 		./a.out
  */
===============================================================================================
	
/* We can also use a static initializer to call any call any custom 
   function before main is executed and we can use exit() function 
   inside that custom function, so program will terminate and 
   control will never reach the main(). */

#include <stdio.h>
#include <stdlib.h>
 
int execute()
{
	printf("Inside execute()");
	exit(EXIT_SUCCESS);
}
 
static int s = execute();
 
int main(void)
{
	printf("Inside main() - never executed");
}

==========================================================================================

/* We can also make use of C ++ class constructor to do the same */

#include <iostream>

using namespace std;

class Demo {
public :
	Demo() {
		cout << "Inside Constructor " << "\n";
		exit(EXIT_SUCCESS);
	}	
};

static Demo s;

int main()
{
	cout << "Inside main() - never executed";
}

================================================================================================

/* The ## macro operator concatenates two separate tokens together
   to form a single token. Below function use ## macro operator to 
   hide main method. But the code still does make call to the main
   behind the scenes, but just not in plain sight. */
#include <stdio.h>

#define replace(a, b, c, d) a##b##c##d
#define execute replace(m,a,i,n)

void execute()
{
	printf("Hello World");
	exit(0);
}
