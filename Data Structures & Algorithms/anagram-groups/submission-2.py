class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list);

        for string in strs:
            key = tuple(sorted(string))
            hashmap[key].append(string);
        
        return list(hashmap.values())
        