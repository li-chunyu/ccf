import sys
from collections import deque

#sys.stdin = open('test', 'r')

def tokenize(json_str):
    tokens = []
    idx = 0
    while idx != len(json_str):
        if json_str[idx] == '{':
            tokens.append('{')
            idx +=1
        elif json_str[idx] == '}':
            tokens.append('}')
            idx += 1
        elif json_str[idx] == ',':
            tokens.append(',')
            idx += 1
        elif json_str[idx] == ':':
            tokens.append(':')
            idx += 1
        elif json_str[idx] == '\"':
            right_brack = json_str.find('}', idx+1)
            if right_brack == -1:
                right_brack = float('inf')
            coma = json_str.find(',', idx+1)
            if coma == -1:
                coma = float('inf')
            sep = json_str.find(':', idx+1)
            if sep == -1:
                sep = float('inf')
            right_string = min(right_brack, min(coma, sep)) - 1
            string = json_str[idx+1:right_string]
            slash_idx = string.find('\\')
            while slash_idx != -1:
                string = string[0:slash_idx] + string[slash_idx+1:]
                slash_idx = string.find('\\', slash_idx+1)
            tokens.append(string)
            idx = right_string + 1

        else: 
            idx += 1
    return tokens

def parse(tokens):
    obj_stack = deque([])
    string_stack = deque([])
    idx = 0
    while idx != len(tokens):
        if tokens[idx] == '{':
            obj = {}
            obj_stack.append(obj)
            idx += 1
            continue
        elif tokens[idx] == ',':
            idx += 1
            continue
        elif tokens[idx] == '}':
            if len(obj_stack) == 1:
                idx += 1
                continue
            else:
                cur_obj = obj_stack.pop()
                parent_obj = obj_stack.pop()
                parent_obj[string_stack.pop()] = cur_obj
                obj_stack.append(parent_obj)
                idx += 1
                continue
        elif tokens[idx] == ':':
            string_stack.append(tokens[idx-1]) 
            if tokens[idx+1] != '{':
                cur_obj = obj_stack.pop()
                cur_obj[string_stack.pop()] = tokens[idx+1]
                obj_stack.append(cur_obj)
                idx += 2
            else:
                idx += 1
        else:
            idx += 1
    return obj_stack.pop()


json_str = ''
n, m = list(map(int, input().rstrip().split()))
for _ in range(n):
    line = input().rstrip()
    json_str += line
if json_str[0] != '{':
    json_str = '{' + json_str
if json_str[len(json_str)-1] != '}':
    json_str = json_str + '}'

tokens = tokenize(json_str)
obj = parse(tokens)

for _ in range(m):
    qurys = input().rstrip().split('.')
    fix_qurys = []
    for q in qurys:
        """
        dot_idx = q.find('\"')
        while dot_idx != -1:
            q = q[0:dot_idx] + '\\' + q[dot_idx:]
            dot_idx = q.find('\"', dot_idx+2)

        slash_idx = q.find('\\')
        while slash_idx != -1:
            q = q[0:slash_idx] + '\\' + q[slash_idx:]
            slash_idx = q.find('\\', slash_idx+2)
        """
        fix_qurys.append(q)

    ret = obj.setdefault(fix_qurys[0], None)
    idx = 1
    while ret != None and idx < len(fix_qurys):
        if type(ret) is dict:
            ret = ret.setdefault(fix_qurys[idx], None)
        else:
            ret = None
            break
        idx += 1
    if not ret:
        print('NOTEXIST')
    else:
        if type(ret) is dict:
            print('OBJECT')
        else:
            print("STRING", ret)