'''
The 2-SUM Problem을 풀어라
x + y = t가 되는 combination을 찾는 문제이다.
해시 테이블을 활용해서 풀어라

소수는 이 사이트에서 검색
http://www.primos.mat.br/2T_en.html

최대값 : 99999662302
최소값 : -99999887310
'''

with open('algo1-programming_prob-2sum.txt', 'r') as fd:
	text_file = fd.readlines()
	num_array = [int(text.strip('\n')) for text in text_file]
# print(max(num_array))
# print(min(num_array))

# num_array = [68037543430, -21123414637, 56619844751, 59688006695, 82329471587, -60489726142, -32955448858, 53645,
#              -71679488929, 21393775251, -96739885676, -51422645875, -72553684643, 60835350845, -68664182150, -138013,
#              -1283402602, 94555004776, -41496643118, 54271539558, 5348995842, 53982767255, -19954275582, 75385401,
#              78046520509, -30221412951, -87165735843, -95995390228, -8459652546, -87380832335, -52344009143931330,
#              -12472480682, 86367011250, 86161959071, 44190468613, -43141319390, 47706862980, 2799576330, 37333981663,
#              91293650582, 17728026638, 31460807906, 71735265185, -12088016101, 84793957781, -203163, -13609316347, 23919296788,
#              -43788117517, 57200419603, -38508425252, -10593284160, -54778674969, 950333005, 87000797310, 36889003374, -23362333758,
#              49954176484, -26267291665, -41167927600]

class HashTable:
  def __init__(self):
    self.N_prime = 179424673
    # self.N_prime = 101
    self.hash_table = [[] for i in range(self.N_prime)]

    # insert to hash table
    for num in num_array:
      self.hash_table[num % self.N_prime].append(num)
    
  # Lookup for hash table
  def look_up(self, num_lookup):
    self.boolean = True if num_lookup in self.hash_table[num_lookup % self.N_prime] else False
    return self.boolean

  # delete from hash table
  def delete(self, num_lookup):
    pass

hash = HashTable()
# print(hash.hash_table)
# print(hash.look_up(-41167927600))
counting = 0
done = []

# check x  y = t
for t in range(-10000, 10000 + 1):
  for x in num_array:
    if x in done: # 중복처리
      continue
    y = t - x
    if hash.look_up(y) == True:
      done.append(y)
      counting += 1
      
print(counting)