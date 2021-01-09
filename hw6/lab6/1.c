/*
I'm level 1 test.
*/
int main() {
    int a,s;
    a = 10;
    s = 0;
    char ch;
    scanf("%c", &ch);
    printf("%c\n", ch);
    while(a>0 && a<=10 || a%100==10) {
        a -= 1;
        s += a;
        if(s > -10) {
            printf("result is: %d\n", s);
            int b;
            b = 10;
            int i;
            for(i=0; i<b; i++) {
                printf("Have fun: %d\n", i);
            } 
        } 
    } 
    return 0;
}
// No more compilation error.
