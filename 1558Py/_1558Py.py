def find_period(sequence):
    first_occurrence = (sequence + sequence).find(sequence, 1, -1)
    if first_occurrence == -1:
        return 0
    else:
        return sequence[:first_occurrence]


term1, term2 = input(), input()

term1 = term1[1:term1.find(')')]
term2 = term2[1:term2.find(')')]

shift = 0
triple_term1 = term1 * 3
triple_term2 = term2 * 3
summa = str(int(triple_term1) + int(triple_term2))

if len(summa) == len(triple_term1):
    print('(' + str(find_period(summa)) + ')')
elif len(summa) > len(triple_term1):
    part_of_sequence = summa[len(term1):-1]
    if find_period(part_of_sequence) == 0:
        while find_period(part_of_sequence) == 0:
            shift += 1
            part_of_sequence = summa[len(term1) - shift:-1 - shift]
            if find_period(part_of_sequence) != 0:
                print('(' + str(find_period(part_of_sequence)) + ')' + summa[-1 - shift:])
    else:
        print('(' + str(find_period(part_of_sequence)) + ')' + summa[-1])
else:
    print('(' + str(find_period('0' * (len(triple_term1) - len(summa)) + summa)) + ')')

