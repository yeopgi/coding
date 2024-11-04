while True:
    i_str = input()

    scp_st = []
    if i_str == '.':
        break

    is_correct = True
    for i_chr in i_str:
        if i_chr == '(':
            scp_st.append(i_chr)
            continue

        if i_chr == '[':
            scp_st.append(i_chr)
            continue

        if i_chr == ')':
            if len(scp_st) != 0:
                pop_chr = scp_st.pop()
                if (pop_chr != '('):
                    is_correct = False
                    break
                else:
                    is_correct = True
                    continue
            else:
                is_correct = False
                break

        if i_chr == ']':
            if len(scp_st) != 0:
                pop_chr = scp_st.pop()
                if (pop_chr != '['):
                    is_correct = False
                    break
                else:
                    is_correct = True
                    continue
            else:
                is_correct = False
                break
    
    if len(scp_st) != 0: 
       is_correct = False 
    if is_correct == False:
        print("no")
    else:
        print("yes")



    