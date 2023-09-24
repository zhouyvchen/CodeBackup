import random
import os

# 创建文件
file = open("test.txt", "w")

# 生成10M大小的数据
data = bytearray(random.getrandbits(8) for _ in range(100 * 1024 * 1024))

# 写入文件
file.write(data)

# 检查文件大小
file_size = os.path.getsize("test.txt")

# 关闭文件
file.close()