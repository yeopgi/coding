import sys

MAX = 1000
def main():
    T = int(input())
    while (T > 0) :
        T = T - 1
        start_x, start_y, end_x, end_y = map(int, input().split())
        in_out_cnt = 0
        planet_cnt = int(input())
        for i in range(0, planet_cnt) :
            planet_x, planet_y, radius = map(int, input().split())
            if ((start_x - planet_x) * (start_x - planet_x) + (start_y - planet_y) * (start_y - planet_y) < radius * radius):
                if ((end_x - planet_x) * (end_x - planet_x) + (end_y - planet_y) * (end_y - planet_y) > radius * radius):
                    in_out_cnt = in_out_cnt + 1
                    continue

            if ((end_x - planet_x) * (end_x - planet_x) + (end_y - planet_y) * (end_y - planet_y) < radius * radius):
                if ((start_x - planet_x) * (start_x - planet_x) + (start_y - planet_y) * (start_y - planet_y) > radius * radius):
                    in_out_cnt = in_out_cnt + 1
                    continue

        print(in_out_cnt)

main()                    