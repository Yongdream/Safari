import random

# 设置随机种子以便重现
random.seed(0)

# 生成包含20000个随机数字的数组，范围从1到100
n = 20000
arr = [random.randint(1, 100) for _ in range(n)]

# 打印数组
print(n)
print(" ".join(map(str, arr)))
