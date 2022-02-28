'''
implement the "Median Maintenance" algorithm (covered in the Week 3 lecture on heap applications). 

Letting x_i denote the ith number of the file, the kth median m_k is defined as the median of the nubers x_1, ... , x_k

100000개의 median의 합을 구해서 입력하라.

H_low, H_high를 만든다. 절반은 H_low, H_high에 넣는다. H_low에서 min을 i/2번 뽑아내면 끝.

array를 이용한다. parent(i) = i/2 if even, (i - 1)/2 if odd
children(i) = 2i, 2i + 1

insert:
k를 맨 마지막에 붙인다.
k를 최대한 위쪽 parent와 교환한다. 더 이상 안되면 stop

Extract Min:
root 삭제
last leaf를 root로
root를 양쪽 모두와 비교해서 최대한 아래의 child와 교환한다.

기존 중간값보다 작으면 H_low, 크면 H_high로 들어간다.
일단 구현하고, unbalnce하면 최대/최소 꺼내서 반대쪽에 넣어준다.
'''

import copy

with open('Median.txt', 'r') as fd:
    text_file = fd.readlines()
    num_array = [int(text.strip('\n')) for text in text_file]

def swap(arr, a, b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp
    return arr

class Heap():
    def __init__(self):
        self.heap_array = [0] # idx 0는 비워둔다.
        self.heap_size = 0
        
    def bubble_up(self, idx_child):
        while True:
            idx_parent = idx_child // 2 if (idx_child % 2 == 0) else (idx_child - 1) // 2
            if idx_parent == 0: # 경계조건
                break
            if self.heap_array[idx_parent] > self.heap_array[idx_child]:
                self.heap_array = swap(self.heap_array, idx_parent, idx_child)
            else:
                break
            idx_child = idx_parent
        
    def bubble_down(self, idx_parent):
        while True:
            idx_child = (2 * idx_parent) if (idx_parent % 2 == 0 or idx_parent == 1) else (2 * idx_parent + 1)
            if idx_child > self.heap_size:
                break
            if self.heap_array[idx_parent] > self.heap_array[idx_child]:
                self.heap_array = swap(self.heap_array, idx_parent, idx_child)
            else:
                break
            idx_parent = idx_child

    def insert(self, x):
        self.heap_array.append(x)
        self.heap_size += 1
        self.bubble_up(self.heap_size)
        
    
    def extract_min(self):
        extract = self.heap_array[1]
        self.heap_array[1] = self.heap_array[-1]
        del(self.heap_array[-1])
        self.heap_size -= 1
        self.bubble_down(1)
        return extract


# num_array = [6331,2793,1640,9290,225,625,6195,2303,5685,1354,4292,7600,6447,4479,9046,7293,5147,1260,1386,6193,4135,3611,8583,1446,3480,2022,961,7123,7262,2261] # test case
median = 0
median_array = []
for idx in range(len(num_array)):
    if idx == 0: # initial state
        median = num_array[0]
        median_array.append(median)
        continue
        
    heap_low = Heap()
    heap_high = Heap()
    this_turn_array = num_array[:idx + 1]
    for i in range(idx + 1):
        if this_turn_array[i] > median:
            heap_high.insert(-this_turn_array[i]) # high 값 보관은 음수 처리를 해야 max heap을 따로 안만들 수 있다.
        else:
            heap_low.insert(this_turn_array[i])
    
    # 밸런스 맞춰주기
    # while abs(heap_high.heap_size - heap_low.heap_size) > 1:
    #     if heap_high.heap_size > heap_low.heap_size:
    #         heap_copy = copy.deepcopy(heap_high)
    #         while True:
    #             if heap_copy.heap_size == 1:
    #                 heap_low.insert(-heap_copy.extract_min())
    #                 heap_high.heap_size -= 1
    #                 del(heap_high.heap_array[-1]) # 이게 아닌데? 맨 마지막에 뽑힌 게 없어져야하는 건데?
    #                 break
    #             _ = heap_copy.extract_min()
    #     else:
    #         heap_copy = copy.deepcopy(heap_low)
    #         while True:
    #             if heap_copy.heap_size == 1:
    #                 heap_high.insert(-heap_copy.extract_min())
    #                 heap_low.heap_size -= 1
    #                 del(heap_low.heap_array[-1]) # 이게 아닌데? 맨 마지막에 뽑힌 게 없어져야하는 건데?
    #                 break
    #             _ = heap_copy.extract_min()
    
    # 밸런스 맞춰주기
    while abs(heap_high.heap_size - heap_low.heap_size) > 1:
        heap_temp = Heap()
        if heap_high.heap_size > heap_low.heap_size:
            while True:
                if heap_high.heap_size == 1:
                    heap_low.insert(-heap_high.extract_min())
                    heap_high = copy.deepcopy(heap_temp)
                    break
                heap_temp.insert(heap_high.extract_min())
        else:
            while True:
                if heap_low.heap_size == 1:
                    heap_high.insert(-heap_low.extract_min())
                    heap_low = copy.deepcopy(heap_temp)
                    break
                heap_temp.insert(heap_low.extract_min())
    
    # heap_low에서 끝까지 뽑아서 median 구하기
    while True:
        if heap_low.heap_size == 1:
            median = heap_low.extract_min()
            median_array.append(median)
            break
        _ = heap_low.extract_min()
print(median_array)