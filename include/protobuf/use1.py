def get_in_line(s1,s2):
    '''
    get the req message
    '''
    out_line = []
    out_line.append("guosen::msg::ctp::"+s1+" req")

    out_line.append(s1+" myreq;")
    out_line.append("memset(&myreq,0,sizeof(myreq));")

    icon1 = lines.find(s1)
    icon2 = lines.find('{',icon1)
    icon3 = lines.find('}',icon2)

    #  print(icon1," ",icon2," ",icon3)
    temp_str = lines[icon2:icon3]
    #  print(temp_str)

    need_line = temp_str.split('\n')
    
    for line in need_line:
        #  line = line.strip('\t')
        line = line.strip()
        word = line.split(' ')
        #  print(word)
        #  print('string' in word)

        if len(word) < 3:
            continue

        if 'bool' in word:
           index1 = word.index('bool')
           temp_field = word[index1+1]
           out_line.append("myreq."+temp_field+" = req."+temp_field.lower()+"();")
           #  print(word)
           continue

        if 'int32' in word:
           index1 = word.index('int32')
           temp_field = word[index1+1]
           out_line.append("myreq."+temp_field+" = req."+temp_field.lower()+"();")
           #  print(word)
           continue
       
        if 'double' in word:
           index1 = word.index('double')
           temp_field = word[index1+1]
           out_line.append("myreq."+temp_field+" = req."+temp_field.lower()+"();")
           #  print(word)
           continue

        if 'string' in word:
           index1 = word.index('string')
           temp_field = word[index1+1]
           out_line.append("strcpy(myreq."+temp_field+", req."+temp_field.lower()+".c_str());") 
           #  print(word)
           continue
    
    #  out_line.append('')

    #  for line in out_line:
    #      print(line)

    return out_line

def get_out_line(s1,s2):
    '''
    get the need out line
    '''
    out_line = []
    out_line.append("guosen::msg::ctp::"+s1+" body_message;")

    icon1 = lines.find(s1)
    icon2 = lines.find('{',icon1)
    icon3 = lines.find('}',icon2)
    
    temp_str = lines[icon2:icon3]

    #  print(icon1," ",icon2," ",icon3)
    #  print(temp_str)
    need_line = temp_str.split('\n')

    for line in need_line:
        line = line.strip()
        word = line.split(' ')

        if len(word) < 3:
            continue

        if 'bool' in word:
           index1 = word.index('bool')
           out_line.append("body_message.set_"+word[index1+1].lower()+'('+s2+"->"+word[index1+1]+');') 
           #  print(word)
           continue

        if 'int32' in word:
           index1 = word.index('int32')
           out_line.append("body_message.set_"+word[index1+1].lower()+'('+s2+"->"+word[index1+1]+');') 
           #  print(word)
           continue

        if 'double' in word:
           index1 = word.index('double')
           out_line.append("body_message.set_"+word[index1+1].lower()+'('+s2+"->"+word[index1+1]+');') 
           #  print(word)
           continue

        if 'string' in word:
           index1 = word.index('string')
           out_line.append("body_message.set_"+word[index1+1].lower()+'('+s2+"->"+word[index1+1]+');') 
           #  print(word)
           continue

    out_line.append("guosen::msg::ProtoMsg proto_message;")
    out_line.append("proto_message.set_head(guosen::msg::MsgType::"+s1+");")
    out_line.append("body_message.SerializeToString(proto_message.mutable_body());")
    out_line.append("do_publish(proto_message);")

    #  for line in out_line:
    #      print(line)

    return out_line

def cal_req():
    final_line = []
    with open("req.cpp",'r') as f:
        cpp_lines = f.readlines()

    for line in cpp_lines:
        final_line.append(line) 
        index1 = line.find('(')
        if index1 == -1:
            continue
        index2 = line.find('*',index1)
        #  index3 = line.find(',',index1)
        
        s1 = line[index1+1:index2].strip()
        #  s2 = line[index2+2:index3].strip(") ")

        final_line.append('{\n')

        for temp_line in get_in_line(s1,""):
            final_line.append(temp_line+'\n')

        #  final_line.append(get_out_line(s1,s2))
        final_line.append('}\n')
    
    with open("out_req.cpp",'w') as f:
        for line in final_line:
            f.write(line)

def cal_rtn():
    final_line = []
    with open("rtn.cpp",'r') as f:
        cpp_lines = f.readlines()

    for line in cpp_lines:
        final_line.append(line) 
        index1 = line.find('(')
        if index1 == -1:
            continue
        index2 = line.find('*',index1)
        index3 = line.find(',',index1)
        
        s1 = line[index1+1:index2].strip()
        s2 = line[index2+2:index3].strip(") ")

        final_line.append('{\n')

        for temp_line in get_out_line(s1,s2):
            final_line.append(temp_line+'\n')

        #  final_line.append(get_out_line(s1,s2))
        final_line.append('}\n')
    
    with open("out_rtn.cpp",'w') as f:
        for line in final_line:
            f.write(line)

def cal_msgtype():
    final_line = []
    
    s1 = 'message'

    with open("ctpmessage.proto",'r') as f:
        lines = f.readlines()

    ncount = 0
    for line in lines:
        line = line.strip()

        index1 = line.find(s1)
        if index1 == -1:
            continue

        word = line.split(' ')

        if len(word) != 2:
            print(word)
            continue

        final_line.append(word[1] + ' = '+str(ncount)+';\n')
        ncount+=1

    with open('out_msgtype.proto','w') as f:
        for line in final_line:
            f.write(line)

def cal_char():
    final_line = []

    with open('aaa.h','r') as f:
        lines = f.readlines()


    for line in lines:
        index1 = line.find('typedef char')

        if index1 == -1:
            continue

        index2 = line.find('[')

        if index2 == -1:
            final_line.append(line)

    with open('out_char.cpp','w') as f:
        for line in final_line:
            f.write(line)

def get_char():
    final_line = []

    with open('out_char.cpp','r') as f:
        lines = f.readlines()

    for line in lines:
        index1 = line.find('TT')

        final_line.append(line[index1:-2])

    #  print(final_line)
    return final_line

def get_word():

    final_line = get_char()
    final_word = []
    with open('bbb.h','r') as f:
        lines = f.readlines()

    for line in lines:
        line = line.strip(' ;')
        words = line.split()

        if len(words) != 2:
            continue;

        if words[0] in final_line:
            final_word.append(words[1][:-1])
    
    #  print(final_word)

    #  with open('func2.cpp','w') as f:
    #      for line in final_word:
    #          f.write(line+'\n')
    return final_word

def get_ctp():
    final_num = []
    final_word = get_word()
    with open('ctpmessage.proto','r') as f:
        lines = f.readlines()

    for i in range(len(lines)):
        line = lines[i]
        line = line.strip()
        index1 = line.find('string')

        if index1 == -1:
            continue

        words = line.split()
        
        if len(words) != 4:
            print(words)
            continue
        
        if words[1] in final_word:
            final_num.append(i)

        #  line.replace('string','int32')

    #  print(final_num)

    return final_num

def get_final_ctp():

    final_num = get_ctp()

    with open('ctpmessage.proto','r') as f:
        lines = f.readlines()

    for i in final_num:
        lines[i] = lines[i].replace('string','int32')

    with open('out_msg.proto','w') as f:
        for line in lines:
            f.write(line)

def func1():
    '''
    traderspi.cpp  char2int
    '''
    final_num = []
    final_word = get_word()

    with open('TraderSpi.cpp','r') as f:
        lines = f.readlines()

    for i in range(len(lines)):
        line = lines[i]
        index1 = line.find('->')

        if index1 == -1:
            continue

        index2 = line.find('(')
        index3 = line.find(')')

        if index3 == -1:
            continue

        line_word = line[index1+2:index3]
        #  print(line_word)
        if line_word in final_word:
            line = line[:index2+1] + "char2int(" + line[index2+1:index3] + ")" + line[index3:]
            lines[i] = line
            #  final_num.append(line)

    #  with open('func1.cpp','w') as f:
    #      for line in final_num:
    #          f.write(line)

    with open('func1.cpp','w') as f:
        for line in lines:
            f.write(line)


if __name__ == '__main__':
    #  s1 = "MsgType"
    #  s1 = "CtpRtnConnect"
    #  s1 = "CThostFtdcReqUserLoginField"

    #  s1 = "CThostFtdcRspInfoField"
    #  s2 = "pRspInfo"

    #  with open("ctpmessage.proto",'r') as f:
    #      lines = f.read()

    #  print(get_out_line(s1,s2))
    #  print(get_in_line(s1,s2))

    #  cal_rtn()
    #  cal_req()
    #  cal_msgtype()
    #  cal_char()
    #  get_char()
    #  get_word()
    #  get_ctp()
    #  get_final_ctp()

    func1()

