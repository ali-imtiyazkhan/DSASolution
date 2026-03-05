class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        
        int leftSum = 0;
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }

        int maxPoint = leftSum;
        int rightSum = 0;

        for(int i = 0; i < k; i++){
            leftSum -= cardPoints[k - 1 - i];
            rightSum += cardPoints[n - 1 - i];
            
            maxPoint = max(maxPoint, leftSum + rightSum);
        }

        return maxPoint;
    }
};