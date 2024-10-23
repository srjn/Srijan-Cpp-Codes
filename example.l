%{
#include <iostream>
#include <string>
%}

%%

[0-9]+          { std::cout << "Number: " << yytext << std::endl; }
[a-zA-Z]+       { std::cout << "Word: " << yytext << std::endl; }
\n              { /* ignore newlines */ }
.               { std::cout << "Unknown character: " << yytext << std::endl; }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
