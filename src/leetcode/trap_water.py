class Solution:
    def trap(self, height, volume=0):
        """
        :type height: List[int]
        :rtype: int
        """

        if len(height) <= 2:
            return volume

        left_peak_ind, right_peak_ind = self.find_top2_bar_index(height)
        print("left:%d, right:%d" % (left_peak_ind, right_peak_ind))
        if not ((left_peak_ind - 0) * (left_peak_ind - len(height) + 1) +
                (right_peak_ind - 0) * (right_peak_ind - len(height) + 1)):
            return volume + self.calculate_volume(height)

        print('=============')
        print(height[:left_peak_ind+1])
        print(height[left_peak_ind:right_peak_ind+1])
        print(height[right_peak_ind:])
        print('=============')

        return (self.trap(height[:left_peak_ind+1], volume) +
                self.trap(height[left_peak_ind:right_peak_ind+1], volume) +
                self.trap(height[right_peak_ind:], volume))


    def find_top2_bar_index(self, height):
        indexes = sorted(range(len(height)),
                         key=lambda k: height[k],
                         reverse=True)
        top1_ind, top2_ind = indexes[0:2]
        return min(top1_ind, top2_ind), max(top1_ind, top2_ind)


    def calculate_volume(self, height):
        """
        Calculate traped water volume of this combination of bars represented
        by list height.
        """
        if len(height) <= 2:
            return 0
        print("cal volume:"+'|'.join(str(height)))
        low_bar = min(height[0], height[-1])
        volume = 0
        for i in height[1:-1]:
            volume += low_bar - i
        print("caled volume:%d" % volume)
        return max(volume, 0)

solo = Solution()
height = [1,2,5,2,3,3,9,0,1]
height.sort()
height.sort(reverse=True)
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(height)
print(solo.trap(height))
