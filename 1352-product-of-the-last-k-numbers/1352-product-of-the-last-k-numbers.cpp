class ProductOfNumbers {
    vector<int> pro;
public:
    ProductOfNumbers() {
        pro.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            pro.clear();
            pro.push_back(1);
        }else{
            int back = pro.back();
            pro.push_back(back * num);
        }
        return;
    }
    
    int getProduct(int k) {
        int size = pro.size();
        if(size <= k){
            return 0;
        }
        int val = pro[size-1]/pro[size-k-1];
        return val;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */