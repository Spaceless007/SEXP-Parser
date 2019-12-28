# taken from https://rosettacode.org/wiki/S-Expressions

import re
 
term_regex = r'''(?mx)
    \s*(?:
        (?P<brackl>\()|
        (?P<brackr>\))|
        (?P<num>\-?\d+\.\d+|\-?\d+)|
        (?P<sq>"[^"]*")|
        (?P<s>[^(^)\s]+)
       )'''
 
def parse_sexp(sexp):
    stack = []
    out = []
    for termtypes in re.finditer(term_regex, sexp):
        term, value = [(t,v) for t,v in termtypes.groupdict().items() if v][0]
        if term == 'brackl':
            stack.append(out)
            out = []
        elif term == 'brackr':
            assert stack, "Trouble with nesting of brackets"
            tmpout, out = out, stack.pop(-1)
            out.append(tmpout)
        elif term == 'num':
            v = float(value)
            if v.is_integer(): v = int(v)
            out.append(v)
        elif term == 'sq':
            out.append(value[1:-1])
        elif term == 's':
            out.append(value)
        else:
            raise NotImplementedError("Error: %r" % (term, value))
    assert not stack, "Trouble with nesting of brackets"
    return out[0]
 
def print_sexp(exp):
    out = ''
    if type(exp) == type([]):
        out += '(' + ' '.join(print_sexp(x) for x in exp) + ')'
    elif type(exp) == type('') and re.search(r'[\s()]', exp):
        out += '"%s"' % repr(exp)[1:-1].replace('"', '\"')
    else:
        out += '%s' % exp
    return out
 
 
if __name__ == '__main__':

    # sexp = '''(
    #             (Capture image-01.raw
    #                 (id 6zlQW000LK) (name 1KDVQwb) (timestamp 2019-10-23T11:50:04-04:00)
    #                 (capture_settings
    #                     ((mode idle) (frequency 2400) (fps 33)
    #                     (exposure 9750) (gain_r  250) (gain_g 50.2) (gain_b 5876.123))
    #                 )
    #                 (coordinates
    #                     ((latitude 45.5169557) (longitude -73.580725) (altitude -6300000))
    #                 )
    #             )
    #         )'''
   
    sexp = ''' ( ( data "quoted data" 123 4.5)
        (data (123 (4.5) "(more" "data)")))'''
 
    print('Input S-expression: %r' % (sexp, ))
    parsed = parse_sexp(sexp)
    print("\nParsed to Python:", parsed)
 
    print("\nThen back to: '%s'" % print_sexp(parsed))
