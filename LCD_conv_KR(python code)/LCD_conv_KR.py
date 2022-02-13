##################################### how to use #####################################
# 1. input file : Input should be multiple kr words seperated by whitespace.
#                 Linechange can be added for visibility 
#
# 2. output files: Will be printed with list of words with LCD code on the side.
#                 LCD code will consist of the 2 hex code for each korean
#                 jamo letters given by HLCD Manual from 'COMFILE TECHNOLOGY'.
#
# 3. jamo library should be installed(github.com/JDongian/python-jamo)
#######################################################################################

from jamo import h2j, j2hcj

cho = "  ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ"
jung = "   ㅏㅐㅑㅒㅓ  ㅔㅕㅖㅗㅘㅙ  ㅚㅛㅜㅝㅞㅟ  ㅠㅡㅢㅣ"
jong = "  ㄱㄲ ㄴㄵㄶㄷㄹㄺㄻㄼㄽ  ㅀㅁ ㅂㅄㅅㅆㅇㅈㅊㅋㅌㅍㅎ"

infile = open("in_kr_list.txt", 'r')
outfile = open("out_kr_LCDcode.txt", 'w')
text = infile.read()

text = text.replace('\n', ' \n ')
jamo_list = text.split(' ')

def outprint(msg, f):
    print(msg, end='')
    f.write(msg)

for word in jamo_list:
  outprint(' {0:<10}  '.format(word), outfile)
  if word!='\n':
    for letter in word:
      j=j2hcj(h2j(letter))
      front = 128 + cho.find(j[0]) * 4 + jung.find(j[1]) // 8
      back = (jung.find(j[1]) % 8) * 32 + (1 if len(j) == 2 else(jong.find(j[2])))
      outprint('{0}, {1}, '.format(hex(front), hex(back)), outfile)
  outprint('\n', outfile)


infile.close()
outfile.close()
