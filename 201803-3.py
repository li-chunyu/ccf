def map_func(maps, uri):
    uri = uri.lstrip('/').split('/')
    ret_inf = None
    ret_param = None
    for m in maps:
        flag = True
        rules, intf = m
        rules_idx = 0
        uri_idx = 0
        params = []
        while rules_idx < len(rules):
            if uri_idx >= len(uri):
                flag = False
                break
            if rules[rules_idx].find('<') == -1:
                if uri[uri_idx] != rules[rules_idx]:
                    flag = False
                    break
            elif rules[rules_idx] == '<int>':
                if not uri[uri_idx].isdigit():
                    flag = False
                    break
                else:
                    params.append(str(int(uri[uri_idx])))
            elif rules[rules_idx] == '<str>':
                params.append(uri[uri_idx])
            elif rules[rules_idx] == '<path>':
                params.append('/'.join(uri[uri_idx:]))
                flag = True
                break
            rules_idx += 1
            uri_idx += 1
        if flag:
            ret_inf = intf
            ret_param = params
    return ret_inf, ret_param

n, m = map(int, input().rstrip().split())
maps = []
for _ in range(n):
    rulestr, interface = input().rstrip().split()
    rulestr = rulestr.lstrip('/')
    maps.append([rulestr.split('/'), interface])

for _ in range(m):
    uri = input().rstrip()
    intf, params = map_func(maps, uri)
    if intf == None:
        print('404')
    else:
        print(intf, ' '.join(params))