class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> boo;
        stack<char> oop;
        for(auto i : expression){
            if(i == '!' || i == '&' || i == '|'){
                oop.push(i);
            }
            else if(i != ',' && i != ')'){
                boo.push(i);
            }
            else if(i == ')'){
                char ft = boo.top();
                boo.pop();
                bool ex = (ft == 'f') ? false : true;
                bool result = ex;
                if(oop.top() == '!'){
                    result = !ex;
                    oop.pop();
                } else {
                    while(boo.top() != '('){
                        ft = boo.top();
                        boo.pop();
                        ex = (ft == 'f') ? false : true;
                        if(oop.top() == '&'){
                            result = result & ex;
                        }
                        else if(oop.top() == '|'){
                            result = result | ex;
                        }
                    }
                    oop.pop(); // pop the operator
                }
                boo.pop(); // pop the '('
                boo.push((result == false) ? 'f' : 't');
            }
        }
        return (boo.top() == 't');
    }
};
