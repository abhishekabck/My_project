class Sorting:
    def count_sort(self, array: list):
        m = min(array)
        freq_size = max(array) - m + 1
        # Creating frequency array
        freq = [0]*freq_size
        # Updating the Frequency array
        for i in array:
            freq[i - m] += 1
        
        k = 0
        for i in range(len(freq)):
            while freq[i]>0:
                array[k] = i+m
                freq[i] -= 1
                k += 1
        
        print(array)

arr = [4,5,5,4,3,54,6,5,64,32,4,5,4,23,32]
s = Sorting()
s.count_sort(arr)