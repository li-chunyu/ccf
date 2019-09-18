def insert(s, pos, c):
    l = list(s)
    l.insert(pos, c)
    return ''.join(l)

if __name__ == "__main__":
    n = int(input().rstrip())
    for _ in range(n):
        expr = input().rstrip()
        expr = insert(expr, len(expr), ')')
        expr = insert(expr, 0, '(')
        op_pos = 0
        while op_pos != -1:
            op_pos1 = expr.find('/', op_pos)
            op_pos2 = expr.find('x', op_pos)
            if op_pos1 > 0 and op_pos2 > 0:
                op_pos = min(op_pos1, op_pos2)
            else:
                op_pos = max(op_pos1, op_pos2)
            if op_pos != -1:
                expr = insert(expr, op_pos+2, ')')
                expr = insert(expr, op_pos-1, '(')
                op_pos = op_pos+2
        print(expr)
        oprand_stack = []
        op_stack = []
        for i in range(len(expr)):
            if expr[i] == ')':
                oprand2 = oprand_stack.pop()
                oprand1 = oprand_stack.pop()
                op = op_stack.pop()
                if op == 'x':
                    oprand_stack.append(oprand1*oprand2)
                elif op == '/':
                    oprand_stack.append(oprand1//oprand2)
                elif op == '-':
                    oprand_stack.append(oprand1-oprand2)
                elif op == '+':
                    oprand_stack.append(oprand1+oprand2)
                else:
                    print('unkown op') # should never be here
            elif expr[i] in ['+', '-', 'x', '/']:
                op_stack.append(expr[i])
            elif expr[i] == '(':
                continue
            else:
                oprand_stack.append(int(expr[i]))
        # print(op_stack)
        # print(oprand_stack)