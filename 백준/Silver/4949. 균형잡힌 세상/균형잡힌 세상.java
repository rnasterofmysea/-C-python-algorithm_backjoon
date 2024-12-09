import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        String input = "";
        while (!(input = br.readLine()).equals(".")) {
            Stack<Character> stack = new Stack<>();
            
            for (int i = 0; i < input.length(); i++) {
                char ch = input.charAt(i);

                if (ch == '(' || ch == '[') {
                    stack.push(ch);
                }

                if (ch == ')') {
                    if (stack.empty()) {
                        stack.push(ch);
                        break;
                    }

                    if (stack.peek() == '(') {
                        stack.pop();
                    } else {
                        break;
                    }
                } else if (ch == ']') {
                    if (stack.empty()) {
                        stack.push(ch);
                        break;
                    }

                    if (stack.peek() == '[') stack.pop();
                    else break;
                }
            }

            if (stack.isEmpty()) sb.append("yes").append("\n");
            else sb.append("no").append("\n");
        }
        System.out.println(sb);
    }

}