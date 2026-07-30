msg = input("Enter Message: ")

block = 8

padding = block - (len(msg) % block)

if padding == block:
    padding = block

msg += '1'
msg += '0' * (padding - 1)

print("Padded Message =", msg)
