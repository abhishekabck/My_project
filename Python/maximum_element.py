def getMax(operations):
    result = []
    stack = []
    max_stack = []

    for operation in operations:
        op = operation.split()
        if op[0] == '1':  # Push operation
            value = int(op[1])
            stack.append(value)
            if not max_stack or value >= max_stack[-1]:
                max_stack.append(value)
        elif op[0] == '2':  # Pop operation
            if stack:
                removed = stack.pop()
                if removed == max_stack[-1]:
                    max_stack.pop()
        elif op[0] == '3':  # Max operation
            if max_stack:
                result.append(max_stack[-1])

    return result