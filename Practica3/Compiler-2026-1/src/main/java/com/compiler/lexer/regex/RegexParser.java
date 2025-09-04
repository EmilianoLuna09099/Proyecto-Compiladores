package com.compiler.lexer.regex;

import java.util.Stack;

import com.compiler.lexer.nfa.NFA;
import com.compiler.lexer.nfa.State;
import com.compiler.lexer.nfa.Transition;
import java.util.Stack;
/**
 * RegexParser
 * -----------
 * This class provides functionality to convert infix regular expressions into nondeterministic finite automata (NFA)
 * using Thompson's construction algorithm. It supports standard regex operators: concatenation (·), union (|),
 * Kleene star (*), optional (?), and plus (+). The conversion process uses the Shunting Yard algorithm to transform
 * infix regex into postfix notation, then builds the corresponding NFA.
 *
 * Features:
 * - Parses infix regular expressions and converts them to NFA.
 * - Supports regex operators: concatenation, union, Kleene star, optional, plus.
 * - Implements Thompson's construction rules for NFA generation.
 *
 * Example usage:
 * <pre>
 *     RegexParser parser = new RegexParser();
 *     NFA nfa = parser.parse("a(b|c)*");
 * </pre>
 */
/**
 * Parses regular expressions and constructs NFAs using Thompson's construction.
 */
public class RegexParser {
    /**
     * Default constructor for RegexParser.
     */
        public RegexParser() {
            // TODO: Implement constructor if needed
        }

    /**
     * Converts an infix regular expression to an NFA.
     *
     * @param infixRegex The regular expression in infix notation.
     * @return The constructed NFA.
     */
    public NFA parse(String infixRegex) {
    // TODO: Implement parse
    // Pseudocode: Convert infix to postfix, then build NFA from postfix
        return buildNfaFromPostfix(ShuntingYard.toPostfix(infixRegex));
    }

    /**
     * Builds an NFA from a postfix regular expression.
     *
     * @param postfixRegex The regular expression in postfix notation.
     * @return The constructed NFA.
     */
    private NFA buildNfaFromPostfix(String postfixRegex) {
    // TODO: Implement buildNfaFromPostfix
    // Pseudocode: For each char in postfix, handle operators and operands using a stack
        Stack<NFA> pila = new Stack<>();

            for (char c: postfixRegex.toCharArray()){
                if(isOperand(c)){
                    NFA automata = createNfaForCharacter(c);
                    pila.push(automata);
                }else{
                    switch (c) {
                       case '|' -> handleUnion(pila);
                        case '*' -> handleKleeneStar(pila);
                        case '?' -> handleOptional(pila);
                        case '+' -> handlePlus(pila);
                        case '·' -> handleConcatenation(pila);
                        default -> throw new IllegalArgumentException("Operador no válido: " + c);
                    }
                 }
                
            }
            return pila.pop();
    }

    /**
     * Handles the '?' operator (zero or one occurrence).
     * Pops an NFA from the stack and creates a new NFA that accepts zero or one occurrence.
     * @param stack The NFA stack.
     */
    private void handleOptional(Stack<NFA> stack) {
    // TODO: Implement handleOptional
    // Pseudocode: Pop NFA, create new start/end, add epsilon transitions for zero/one occurrence
        if (stack.isEmpty()) 
            throw new IllegalStateException("No hay nada");
        
        State inicio = new State();
        State finalEstado = new State();
        NFA automata = stack.pop();
        
        
        inicio.transitions.add(new Transition(null, automata.startState));
        inicio.transitions.add(new Transition(null, finalEstado));
        
        automata.endState.transitions.add(new Transition(null, finalEstado));
        automata.endState.isFinal = false;
        
        stack.push(new NFA(inicio, finalEstado));

    }

    /**
     * Handles the '+' operator (one or more occurrences).
     * Pops an NFA from the stack and creates a new NFA that accepts one or more occurrences.
     * @param stack The NFA stack.
     */
    private void handlePlus(Stack<NFA> stack) {
    // TODO: Implement handlePlus
    // Pseudocode: Pop NFA, create new start/end, add transitions for one or more occurrence
        if (stack.isEmpty()) 
            throw new IllegalStateException("No hay +");
        
        State inicio = new State();
        State finalEstado = new State();
        NFA automata = stack.pop();
        
        
        inicio.transitions.add(new Transition(null, automata.startState));         
        automata.endState.transitions.add(new Transition(null, finalEstado));
        automata.endState.transitions.add(new Transition(null, automata.startState));

        automata.endState.isFinal = false;
        
        stack.push(new NFA(inicio, finalEstado));

    }
    
    /**
     * Creates an NFA for a single character.
     * @param c The character to create an NFA for.
     * @return The constructed NFA.
     */
    private NFA createNfaForCharacter(char c) {
    // TODO: Implement createNfaForCharacter
    // Pseudocode: Create start/end state, add transition for character
        State start = new State();
        State end = new State();
        
        start.transitions.add(new Transition(c, end));
        
        return new NFA(start, end);
    }

    /**
     * Handles the concatenation operator (·).
     * Pops two NFAs from the stack and connects them in sequence.
     * @param stack The NFA stack.
     */
    private void handleConcatenation(Stack<NFA> stack) {
    // TODO: Implement handleConcatenation
    // Pseudocode: Pop two NFAs, connect end of first to start of second
        if (stack.size() < 2)
            throw new IllegalStateException("Not enough NFAs for concatenation");
        
        NFA finalEstado = stack.pop();
        NFA inicio = stack.pop();

        inicio.endState.transitions.add(new Transition(null, finalEstado.startState));
        inicio.endState.isFinal=false;
        stack.push(new NFA(inicio.startState, finalEstado.endState));

    }

    /**
     * Handles the union operator (|).
     * Pops two NFAs from the stack and creates a new NFA that accepts either.
     * @param stack The NFA stack.
     */
    private void handleUnion(Stack<NFA> stack) {
    // TODO: Implement handleUnion
    // Pseudocode: Pop two NFAs, create new start/end, add epsilon transitions for union
        if (stack.size() < 2)
            throw new IllegalStateException("Not enough NFAs for concatenation");
        

        NFA finalEstado = stack.pop();
        NFA inicio = stack.pop();
        
        State estadoInicio = new State();
        State estadoFinal = new State();

        estadoInicio.transitions.add(new Transition(null, inicio.startState));
        estadoInicio.transitions.add(new Transition(null, finalEstado.startState));
        
        inicio.endState.transitions.add(new Transition(null, estadoFinal));
        finalEstado.endState.transitions.add(new Transition(null, estadoFinal));
        
        inicio.endState.isFinal = false;
        finalEstado.endState.isFinal = false;
        
        stack.push(new NFA(estadoInicio, estadoFinal));

    }

    /**
     * Handles the Kleene star operator (*).
     * Pops an NFA from the stack and creates a new NFA that accepts zero or more repetitions.
     * @param stack The NFA stack.
     */
    private void handleKleeneStar(Stack<NFA> stack) {
    // TODO: Implement handleKleeneStar
    // Pseudocode: Pop NFA, create new start/end, add transitions for zero or more repetitions
        if (stack.isEmpty()) 
            throw new IllegalStateException("Stack is empty for Kleene star operation");
        

        if (stack.isEmpty()) 
            throw new IllegalStateException("No hay +");
        
        State inicio = new State();
        State finalEstado = new State();
        NFA automata = stack.pop();
        
        
        inicio.transitions.add(new Transition(null, automata.startState));
        inicio.transitions.add(new Transition(null, finalEstado));     
        automata.endState.transitions.add(new Transition(null, finalEstado));
        automata.endState.transitions.add(new Transition(null, automata.startState));

        automata.endState.isFinal = false;
        
        stack.push(new NFA(inicio, finalEstado));
    }

    /**
     * Checks if a character is an operand (not an operator).
     * @param c The character to check.
     * @return True if the character is an operand, false if it is an operator.
     */
    private boolean isOperand(char c) {
    // TODO: Implement isOperand
    // Pseudocode: Return true if c is not an operator
        if(c =='|' || c =='*'|| c =='?'|| c =='+'|| c =='('||c == ')'||c == '·' ){
            return false;
        }
        return true;
    }
}