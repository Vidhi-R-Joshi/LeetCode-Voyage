class Solution(object):
    def countOfAtoms(self, formula):
        import collections
        
        def parse_formula(formula):
            n = len(formula)
            stack = [collections.defaultdict(int)]
            i = 0
            while i < n:
                if formula[i] == '(':
                    stack.append(collections.defaultdict(int))
                    i += 1
                elif formula[i] == ')':
                    top = stack.pop()
                    i += 1
                    i_start = i
                    while i < n and formula[i].isdigit():
                        i += 1
                    multiplier = int(formula[i_start:i] or 1)
                    for element, count in top.items():
                        stack[-1][element] += count * multiplier
                else:
                    i_start = i
                    i += 1
                    while i < n and formula[i].islower():
                        i += 1
                    element = formula[i_start:i]
                    i_start = i
                    while i < n and formula[i].isdigit():
                        i += 1
                    count = int(formula[i_start:i] or 1)
                    stack[-1][element] += count
            return stack.pop()
        
        counts = parse_formula(formula)
        elements = sorted(counts.keys())
        result = []
        for element in elements:
            result.append(element)
            if counts[element] > 1:
                result.append(str(counts[element]))
        return ''.join(result)

