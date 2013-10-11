/**
 * S -> aAaB|bAbB
 * A -> S|db
 * B -> bB|a
 * 
 * 递归下降分析程序。
 */

void S()
{
    if (sym == 'a' || sym == 'b') {
        getsym();
        A();
        if (sym == 'a' || sym == 'b') {
            getsym();
            B();
        } else {
            error();
        }
    } else {
        error();
    }
}
void A()
{
    if (sym == 'd') {
        getsym();
    } else if (sym == 'a' || 'b') {
        S();
    } else {
        error();
    }
}
void B()
{
    if (sym == 'b') {
        getsym();
        B();
    } else if (sym == 'a') {
        getsym();
    } else {
        error();
    }
}
