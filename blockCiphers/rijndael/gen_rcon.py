def xtime(a):
    if a >> 7:
        return (a << 1) ^ 0x11B
    else:
        return a << 1

print('0x00, ', end='')
a = 1
for i in range(1, 256):
    print('0x%02x, '%(a), end='')
    if i % 16 == 15:
        print('')    
    a = xtime(a)        