class Solution:
    def prefixesDivBy5(self, a: List[int]) -> List[bool]:
        return [*map(not_,accumulate(a,lambda q,v:(q*2+v)%5))]