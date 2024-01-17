import random
import ctypes

ops = ctypes.CDLL('./100-operations.so')

a = random.randint(-111, 111)
b = random.randint(-111, 111)

print(f"{a} + {b} = {ops.add(a, b)}")
print(f"{a} - {b} = {ops.sub(a, b)}")
print(f"{a} x {b} = {ops.mul(a, b)}")
print(f"{a} / {b} = {ops.div(a, b)}")
print(f"{a} % {b} = {ops.mod(a, b)}")
