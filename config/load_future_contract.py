import requests
import re

url = "http://finance.sina.com.cn/iframe/futures_info_cff.js"

if __name__ == '__main__':
    r = requests.get(url)
    model = 'new Array\\("(.+)","(.+)"\\);'
    model = re.compile(model)

    all_text = r.text

    all_list = all_text.split('\r\n')

    all_contract = set()
    for line in all_list:
        m = model.search(line)
        #  print(line)

        if m:
            #  print(m.group(2))
            all_contract.add(m.group(2))

    with open('future_contract.txt','w') as f:
        for i in all_contract:
            temp_line = str(i)

            if temp_line.find('IF') != -1 :
                f.write(temp_line+'\n')
                continue

            if temp_line.find('IC') != -1 :
                f.write(temp_line+'\n')
                continue

            if temp_line.find('IH') != -1 :
                f.write(temp_line+'\n')
                continue

            if temp_line.find('TF') != -1 :
                f.write(temp_line+'\n')
                continue

            temp_line = temp_line.lower()
            f.write(temp_line+'\n')
            

    print(str( len(all_contract) ) + " future contract load complete...")

    

    
