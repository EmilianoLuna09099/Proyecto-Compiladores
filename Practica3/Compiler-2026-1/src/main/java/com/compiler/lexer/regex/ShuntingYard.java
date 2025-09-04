package com.compiler.lexer.regex;


import java.util.HashMap;
import java.util.Map;
import java.util.Deque;
import java.util.ArrayDeque;

/**
 * Utility class for regular expression parsing using the Shunting Yard
 * algorithm.
 * <p>
 * Provides methods to preprocess regular expressions by inserting explicit
 * concatenation operators, and to convert infix regular expressions to postfix
 * notation for easier parsing and NFA construction.
 */
/**
 * Utility class for regular expression parsing using the Shunting Yard
 * algorithm.
 */
public class ShuntingYard {


    public static Deque<Character> pila = new ArrayDeque<>();
    /**
     * Default constructor for ShuntingYard.
     */
    public ShuntingYard() {
        // TODO: Implement constructor if needed
    }

    /**
     * Inserts the explicit concatenation operator ('·') into the regular
     * expression according to standard rules. This makes implicit
     * concatenations explicit, simplifying later parsing.
     *
     * @param regex Input regular expression (may have implicit concatenation).
     * @return Regular expression with explicit concatenation operators.
     */
    public static String insertConcatenationOperator(String regex) {
        // TODO: Implement insertConcatenationOperator
        /*
            Pseudocode:
            For each character in regex:
                - Append current character to output
                - If not at end of string:
                        - Check if current and next character form an implicit concatenation
                        - If so, append '·' to output
            Return output as string

         */     
        if (regex == null || regex.isEmpty())
            return regex;

        String salida = "";
        for (int i = 0; i < regex.length(); i++) {
            char c = regex.charAt(i);
            salida += c;        
            if (i < regex.length() - 1) {
                char next = regex.charAt(i + 1);
                
                if ((isOperand(c) || c == ')' || c == '*' || c == '+' || c == '?') && (isOperand(next) || next == '(')) {
                    salida += '·';
                }
            }
        }
        return salida;
    }


    /**
     * Determines if the given character is an operand (not an operator or
     * parenthesis).
     *
     * @param c Character to evaluate.
     * @return true if it is an operand, false otherwise.
     */
    private static boolean isOperand(char c) {
        // TODO: Implement isOperand
        /*
        Pseudocode:
        Return true if c is not one of: '|', '*', '?', '+', '(', ')', '·'
         */
        if(c =='|' || c =='*'|| c =='?'|| c =='+'|| c =='('||c == ')'||c == '·' )
            return false;
        return true;
    }



    public static String  salida="";
    public static Map<Character, Integer> precedencias = Map.of('|', 1, '·', 2, '*', 3,  '+', 3, '?', 3);

    /**
     * Converts an infix regular expression to postfix notation using the
     * Shunting Yard algorithm. This is useful for constructing NFAs from
     * regular expressions.
     *
     * @param infixRegex Regular expression in infix notation.
     * @return Regular expression in postfix notation.
     */
    public static String toPostfix(String infixRegex) {
        // TODO: Implement toPostfix
        /*
        Pseudocode:
        1. Define operator precedence map
        2. Preprocess regex to insert explicit concatenation operators
        3. For each character in regex:
            - If operand: append to output
            - If '(': push to stack
            - If ')': pop operators to output until '(' is found
            - If operator: pop operators with higher/equal precedence, then push current operator
        4. After loop, pop remaining operators to output
        5. Return output as string
         */

        String preprocesado = insertConcatenationOperator(infixRegex);

        for (char c : preprocesado.toCharArray()) {
            if (isOperand(c)) {
                salida+=c;
            } else if (c == '(' || c== ')') {
                handleParenthesis(c);
            } else if (precedencias.containsKey(c)) {
                handleOperator(c);
            }
        }

        while (!pila.isEmpty()) {
            salida+=pila.pop();
        }

        return salida;
    }

    private static void handleParenthesis(char c) {
        if (c == '(') {
            pila.push(c);
        } else {
            while (!pila.isEmpty() && pila.peek() != '(') {
                salida += pila.pop();
            }
            pila.pop();
        }
    }

    private static void handleOperator(char c) {
        while (!pila.isEmpty() && pila.peek() != '(' && 
            precedencias.getOrDefault(pila.peek(), 0) >= precedencias.get(c)) {
            salida += pila.pop();
        }
        pila.push(c);
    }
}
