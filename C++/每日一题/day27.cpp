链接：https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
来源：牛客网

public class Solution {
    public int Add(int num1,int num2) {
        while (num2!=0) {
            int temp = num1^num2;
            num2 = (num1&num2)<<1;
            num1 = temp;
        }
        return num1;
    }
}