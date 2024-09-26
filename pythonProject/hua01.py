import re

def parse_expression(expr, data):
    # 将字段名替换为对应的值
    for key, value in data.items():
        expr = re.sub(rf"\b{key}\b", f"'{value}'", expr)
    # 将 = 替换为 Python 的 == 比较操作符
    expr = expr.replace('=', '==')
    # 将 AND 和 OR 替换为 Python 运算符
    expr = expr.replace('AND', ' and ').replace('OR', ' or ')
    return expr

def evaluate_expression(expr):
    # 输出替换后的表达式进行调试
    # print(f"Evaluating expression: {expr}")
    try:
        return eval(expr)
    except Exception as e:
        # print(f"Error evaluating expression: {e}")
        return False

def network_health(n, m, expressions, fields):
    results = []

    # 解析字段数据
    field_data = {key: value for key, value in fields}

    # 评估每个表达式
    for expr in expressions:
        parsed_expr = parse_expression(expr, field_data)
        result = evaluate_expression(parsed_expr)
        results.append(0 if result else 1)

    return results

# 输入处理
n, m = map(int, input().split())
expressions = [input().strip() for _ in range(n)]
fields = [tuple(input().strip().split()) for _ in range(m)]

# 计算网络健康状态
results = network_health(n, m, expressions, fields)

for result in results:
    print(result)
