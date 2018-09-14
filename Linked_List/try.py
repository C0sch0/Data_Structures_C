with open('output.txt', 'r') as file1:
    with open('./tests/soluciones/sol_00.txt', 'r') as file2:
        a = file1.readlines()
        b = file2.readlines()
        if len(a) != len(b):
            print("Distinto largo!")
        else:
            for line in range(len(a)):
                if a[line]!= b[line]:
                    print("distinto en linea: " + str(line))

