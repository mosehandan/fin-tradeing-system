

lines = []
condit = False

with open('CtpMessage.proto','r') as f:

    for line in f:
        temp_line = line
        if line.find('{') != -1 :
            count = 1
            condit = True
            lines.append(temp_line)
            continue

        if line.find('}') != -1:
            condit = False
            lines.append(temp_line)
            continue

        if condit == True and line.find(';') != -1:
            temp_line = line[:-2] + ' = ' + str(count) + ';\n'
            count = count + 1


        lines.append(temp_line)


with open('temp.proto','w') as f:
    for line in lines:
        f.write(line)
