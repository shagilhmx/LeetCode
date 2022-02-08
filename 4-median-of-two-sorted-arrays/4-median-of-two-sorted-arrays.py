class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1 = nums1 + nums2
        n1.sort()
        if(len(n1) % 2 == 0):
            return ((n1[(len(n1)//2)-1]) + (n1[len(n1)//2]))/2.0
        else:
            return (n1[len(n1)//2])