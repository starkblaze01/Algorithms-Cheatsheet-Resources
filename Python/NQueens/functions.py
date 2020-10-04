def dev(q, pos, n, sols, solpos):

    for g in range(1, n+1):
        check = 0

        if g in [row[1] for row in pos] or pos[-1][0]+1+g in [row[1] + row[0] for row in pos]\
            or pos[-1][0]+1-g in [row[0] - row[1] for row in pos]:
            check = check +1

        if check == 0:
            l = pos[-1][0] +1
            pos.append([l, g])
            q = q +1

            if q == n:
                sols = sols+1
                solpos[sols] = pos.copy()
                [q, pos] = rej(q, pos)

            else:
                [q, pos, n, sols, solpos] = dev(q, pos, n, sols, solpos)

    [q, pos] = rej(q, pos)

    return q, pos, n, sols, solpos

def rej(q, pos):
    q = q -1
    pos.pop()

    return q, pos
