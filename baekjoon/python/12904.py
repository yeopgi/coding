import sys

def run():
    src_str = input()
    dst_str = input()

    for i in range(0, len(dst_str)):
        if (src_str == dst_str):
            print(1)
            return
        
        if dst_str[len(dst_str) - 1]   ==  'A':
            dst_str = dst_str[0:len(dst_str) - 1]
        else:
            dst_str = dst_str[0:len(dst_str) - 1]
            dst_str = dst_str[::-1]

    print(0)

run()
            

            
            



