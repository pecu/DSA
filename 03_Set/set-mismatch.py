class Solution:
   def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        holder = [0] * len(nums)
        repeated_num = 0
        for i in range(0, len(nums)):
            if holder[nums[i] - 1] != 0:
                repeated_num = nums[i]
            holder[nums[i] - 1] = nums[i]
        return [repeated_num, holder.index(0) + 1]