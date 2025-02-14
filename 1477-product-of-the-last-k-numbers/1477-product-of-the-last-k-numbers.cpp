class ProductOfNumbers {
public:
    vector<int> prods={1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
       if(num==0){
        prods={1};
       }
       else{
        prods.push_back(prods.back()*num);
       }
    }
    
    int getProduct(int k) {
        int n = prods.size();
        if(k>=n) return 0;
        return prods[n-1]/prods[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */