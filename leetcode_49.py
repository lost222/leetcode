#list 是不可hash的， tuple可哈希， 具体是因为tuple不可变
import collections
class Solution(object):
    def groupAnagrams(self, strs):
        ans = collections.defaultdict(list)  # 创建一个每一项value都是一个list的dict
        for s in strs:
            ss = sorted(s)   #ss是一个按照字母顺序排列的list，每个元素是一个字母
            ans[tuple(ss)].append(s)  # tuple(str)能构建一个str的每一个字符为元素构成的tuple.
        return ans.values()


