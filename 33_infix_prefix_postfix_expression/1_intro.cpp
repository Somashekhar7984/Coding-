#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//          THIS IS JUST NOTES FOR INFIX PREFIX POSTFIX
/*
    Infix Expression :
        operend    operator   operend    
        eg: 2 + 3, a * c + d, (8/2) - 5

    precedence:         Associativity
        1 --> ()            
        2 --> ^             right to left  ==>  2^3^2 --> 2^(3^2) --> 2^(9) --> 512
        3 --> * , /         left to right
        4 --> + , -         left to right

    Prefix Expression :     (Polish Notation)
        operator   operend   operend

        Infix to Prefix Conversion:

        4 * 2 + 3(Infix) ===> + * 4 2 3 (Prefix)   
        Initially
            make parentheses to the infix expression as per precedence and associativity

            ((4*2)+3)       --> Now take the operator out of the brackets and put them to the left of the brackets
                                Like (4*2) --> * (4 2) --> Remove brackets --> * 4 2
            ( * 4 2 + 3 ) ==> + * 4 2 3  

        5 - 6 / 3 ==> (5 - (6/3)) ==> - 5 (6/3) ==>  - 5 / 6 3

    Postfix Expression:     (Reverse Polish Expression)
        operend     operend     operator

        4 * 2 + 3   ==> For conversion same as infix to prefix  But The operator is shifted to right side of the brackets

       ((4 * 2) + 3) -->  (4 2 * + 3) -->  4 2 * 3 +
       (5 - (6 / 3)) -->  (5 - 6 3 /) -->  5 6 3 / -
*/
int main(){
    
    return 0;
}