class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // s = '1' + s + '1'; 
        int n = s.size();
        int currZ = 0, prevZ = 0, oneCnt = 0, mxOne = 0, zeroSeg = 0;

        for (int i = 0; i < n ; i++) {
            if (s[i] == '0') {
                currZ++;
            } else {
                oneCnt++;
                mxOne = max(mxOne, prevZ + currZ); 
                if (currZ != 0) {
                    prevZ = currZ;
                    zeroSeg++;
                }
                currZ = 0;
            }
        }   
        if(currZ != 0 )zeroSeg++;
        mxOne= max(mxOne , prevZ+currZ);
        return oneCnt + ((zeroSeg > 1) ? mxOne : 0);
    }
};
