#include <stdio.h>

int sum (int a, int b)
{
    return a + b;
}
struct hello
{
    void hi()
    {
        printf("Hi\n");
    }
};


int main()
{
    printf("%d\n", sum(3, 5));
    printf("%d\n", sum(2.5, 3.2));

    
    return 0;
}