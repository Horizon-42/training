class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        bridge = {}
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                key = nums[i] + nums[j]
                if key in bridge:
                    bridge[key].append([i, j])
                else:
                    bridge.update({nums[i]+nums[j]: [[i, j]]})
        # print(bridge)
        res = []
        res = set(res)
        for i in range(len(nums)):
            if(-nums[i] in bridge):
                for pair in bridge[-nums[i]]:
                    x = [xe for xe in pair]
                    if i not in x:
                        x += i,
                        value = [nums[x[0]], nums[x[1]], nums[x[2]]]
                        value.sort()
                        value = tuple(value)
                        # print(pair)
                        # print(x)
                        res.add(value)

                    # res.append(tmp.append(i))

        return list(res)


def main():
    nums = [-1, 0, 1, 2, -1, -4]
    s = Solution()
    s.threeSum(nums)


if __name__ == '__main__':
    main()
