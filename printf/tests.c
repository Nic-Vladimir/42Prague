#include <stdio.h>

int main()
{
    int result = printf("Am multe mere. Mai exact atatea %+0% e plin de mere \n", -123);
    
    printf("%d characters were written", result);
}