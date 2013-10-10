void S()
{
    if (sym == 'a' || sym == 'b') {
        getsym();
        A();
    } else {
        error();
    }
}
void A()
{
    if (sym == 'S')
        S();
    else if (sym == 'd')
    else
        error();
}
void B()
{
    if (sym == 'b') {
        getsym();
        B();
    } else if (sym == 'a') {
    } else {
        error();
    }
}
