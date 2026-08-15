class Trie:
    def __init__(self):
        self.node = [None]*26
        self.isleaf = False

class PrefixTree:

    def __init__(self):
        self.root = Trie()

    def insert(self, word: str) -> None:
        cur = self.root
        for c in word:
            if cur.node[ord(c)-ord('a')] is None:
                cur.node[ord(c)-ord('a')] = Trie()
            cur = cur.node[ord(c)-ord('a')]
        cur.isleaf = True

    def search(self, word: str) -> bool:
        cur = self.root
        for c in word:
            if cur.node[ord(c)-ord('a')] is None:
                return False
            cur = cur.node[ord(c)-ord('a')]
        return cur.isleaf

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for c in prefix:
            if cur.node[ord(c)-ord('a')] is None:
                return False
            cur = cur.node[ord(c)-ord('a')]
        return True
        