class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)

    def update(self, index, value):
        while index <= self.size:
            self.tree[index] = (self.tree[index] + value) % MOD
            index += index & -index

    def query(self, index):
        total = 0
        while index > 0:
            total = (total + self.tree[index]) % MOD
            index -= index & -index
        return total


MOD = 10 ** 9 + 7


def count_strictly_decreasing_subsequences(n, arr):
    max_value = max(arr)
    fenwick_tree = FenwickTree(max_value)
    result = 0

    for num in arr:
        # 查询小于当前元素的递减子序列数量
        total = fenwick_tree.query(num - 1)  # 只查询严格小于 num 的
        total = (total + 1) % MOD  # 包含自身
        result = (result + total) % MOD

        print(f"当前元素: {num}, 查询到的递减子序列数量: {total}, 累加结果: {result}")

        fenwick_tree.update(num, total)

    return result


# 输入
n = int(input())  # 输入数组的长度
arr = list(map(int, input().split()))  # 输入数组元素

# 输出结果
print("最终结果:", count_strictly_decreasing_subsequences(n, arr))
