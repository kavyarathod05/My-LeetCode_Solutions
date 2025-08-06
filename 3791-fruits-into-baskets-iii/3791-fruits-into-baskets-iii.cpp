class Segment{
  vector<int>seg;
  public:
  Segment(int n){
    seg.resize(4*n);
  } 
  void build(int ind,int low,int high,vector<int>&nums){
    if(low==high){
        seg[ind]=nums[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid,nums);
    build(2*ind+2,mid+1,high,nums);
    seg[ind]= max(seg[2*ind+1],seg[2*ind+2]);
  } 
  void update(int ind,int low,int high,int i,int val){
    if(low==high){
        if(low==i) seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid) update(2*ind+1,low,mid,i,val);
    else update(2*ind+2,mid+1,high,i,val);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
  }
  int leftavailable(int ind,int low,int high,int val){
    if(seg[ind]<val) return -1;
    if(low==high) return low;
    int mid = (low+high)/2;
    int left = leftavailable(2*ind+1,low,mid,val);
    if(left!=-1) return left;
    else return leftavailable(2*ind+2,mid+1,high,val);
  }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        Segment sg(n);
        sg.build(0,0,n-1,baskets);
        int unplace=0;
        for(int i=0;i<n;i++){
             int val = fruits[i];
            int ind =  sg.leftavailable(0,0,n-1,val);
            if(ind==-1) unplace++;
            else sg.update(0,0,n-1,ind,0);
        }
        return unplace;
    }
};