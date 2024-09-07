class Solution {
public:
    int fib(int n) {
        int a = 1;
        int b = 1;
        if(n == 0) return 0;
        
        if(n == 1 || n == 2){
            return 1;
        }
        cout << "a " << a << "b " << b << endl;

        for(int i = 3 ; i <= n; i++){
            int temp = b;
            b = a + b;
            a = temp;
            cout << "a " << a << "b " << b <<endl;
        }
        return b;
    }
};