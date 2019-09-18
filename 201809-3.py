from collections import namedtuple
import sys

class Sentence:
    line = 0
    label = ''
    level = 0
    id = 0
    def __init__(self, line, label, level, id):
        self.line = line
        self.label = label
        self.level = level
        self.id = id

def id_select(sentence, id, level):
    if sentence.id == id and sentence.level < level:
        return True
    else:
        return False

def label_select(sentence, label, level):
    if sentence.label == label.upper() and sentence.level < level:
        return True
    else:
        return False

# Sentence = namedtuple('Sentence', ['line', 'label', 'level', 'id'])
n, m = map(int, input().rstrip().split())
sentences = []
for i in range(1, n+1):
    Se = Sentence(line=i, label='', level=0, id='')
    s = input().rstrip()
    ndot = s.count('.')
    Se.level = ndot // 2
    sharp_pos = s.find('#')
    if sharp_pos == -1:
        Se.label = s[ndot:].upper()
        Se.id = ''
    else:
        Se.label = s[ndot:sharp_pos-1].upper()
        Se.id = s[sharp_pos+1:]
    sentences.append(Se)

for _ in range(m):
    selectors = input().rstrip().split()
    if len(selectors) == 0:
        print(0)
        continue
    resualt = []
    select_func = None
    select_cond = ''
    if selectors[-1].find('#') == -1:
        select_func = label_select
        select_cond = selectors[-1]
    else:
        select_func = id_select
        select_cond = selectors[-1][1:]
    for sentence in sentences[::-1]:
        if select_func(sentence, select_cond, sys.maxsize):
            resualt.append(sentence.line)
    if len(selectors) == 1:
        resualt.sort()
        print(str(len(resualt)) + ' ' + ' '.join(map(str, resualt)))
    else:
        final = []
        for line in resualt:
            lev = sentences[line-1].level
            li = line
            is_selected = True
            for selector in selectors[len(selectors)-2::-1]:
                flag = 0
                select_func = None
                select_cond = ''
                if selector.find('#') == -1:
                    select_func = label_select
                    select_cond = selector
                else:
                    select_func = id_select
                    select_cond = selector[1:]
                for sentence in sentences[li-2::-1]:
                    if select_func(sentence, select_cond, lev):
                        li = sentence.line
                        lev = sentence.level
                        flag = 1
                        break
                    else:
                        flag = 0
                if flag == 0:
                    is_selected = False
                    break
            if is_selected:
                final.append(line)
        final.sort()
        print(str(len(final)) + ' ' + ' '.join(map(str, final)))
                
                

                