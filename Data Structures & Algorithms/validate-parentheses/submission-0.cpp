class Solution {
public:
    bool isValid(string s) {
         char stack[10001];
        int top = 0; //top 永遠指向下一個可以放入元素的空位置

        for (int i = 0; s[i] != '\0'; i++)
        {
            char c = s[i];

            // 左括號：Push
            if (c == '(' || c == '[' || c == '{')
            {
                stack[top++] = c; //Push 先放再加
            }
            else
            {
                // 沒有左括號可以配對
                if (top == 0)
                    return false;

                // 右括號：Pop
                char left = stack[--top]; //Pop 先減再取

                // 檢查括號是否配對
                if ((c == ')' && left != '(') ||
                    (c == ']' && left != '[') ||
                    (c == '}' && left != '{'))
                    return false;
            }
        }

        // Stack 必須為空
        return top == 0;
    }
};
