#include "four.h"

bool is_4dec(char c){
    return (c >= '0' && c <= '3');
}

bool is_op(char c){
    return (c == '+' or c == '-' or c == '=' or c == '>' or c == '<');
}


int main(){

    string str;

    while(getline(cin, str)){
        Four lpart {"0"}, rpart{"0"};

        string tmp_num = "";
        char operation = 0;
        for(char ch : str){
            if(is_op(ch)){
                try{
                    lpart.add(Four{tmp_num});
                }catch(exception &ex){
                    cerr << "exception in first number: " << ex.what() << '\n';
                }
                operation = ch;
                tmp_num = "";
            }
            else if(is_4dec(ch)) tmp_num += ch;
        }
        try{
            rpart.add(Four{tmp_num});
        }catch(exception &ex){
            cerr << "exception in second number: " << ex.what() << '\n';
        }

        try{
            if(operation == '+') lpart.add(rpart).print(cout) << '\n';
            if(operation == '-') lpart.deduct(rpart).print(cout) << '\n';
            if(operation == '='){
                if(lpart.equal(rpart)) cout << "yes\n";
                else cout << "no\n";
            }
            if(operation == '>'){
                if(lpart.greater(rpart)) cout << "yes\n";
                else cout << "no\n";
            }
            if(operation == '<'){
                if(lpart.less(rpart)) cout << "yes\n";
                else cout << "no\n";
            }
        }catch(exception &ex){
            cerr << "exception in making operation: " << ex.what() << '\n';
        }
    }

    return 0;
}
