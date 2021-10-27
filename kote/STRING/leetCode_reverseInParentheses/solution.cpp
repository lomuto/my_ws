string reverseInParentheses(string inputString) {
    stack<int> stk;

    int pivot = 0;
    while (pivot < inputString.size()) {
        if (inputString[pivot] == '(') {
            stk.push(pivot);
        }

        if (inputString[pivot] == ')') {
            int matchParentheseIndex = stk.top();
            stk.pop();

            reverse(inputString.begin() + matchParentheseIndex + 1, inputString.begin() + pivot);
        }

        pivot++;
    }