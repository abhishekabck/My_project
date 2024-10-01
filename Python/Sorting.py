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
    
    def partition(self, array, low, high):
        if low<high:
            i,j = high, high
            pivot = array[low]
            while low<i:
                if array[i] >= pivot:
                    array[i], array[j] = array[j], array[i]
                    j -= 1
                i -= 1
            array[low], array[j] = array[j], array[low]
            return j

    def quick_sort(self, array, low, high):
        if high > low:
            point = self.partition(array, low, high)
            self.quick_sort(array, low, point - 1)
            self.quick_sort(array, point+1, high)

arr = [4,5,5,4,3,54,6,5,64,32,4,5,4,23,32]
s = Sorting()
s.count_sort(arr)