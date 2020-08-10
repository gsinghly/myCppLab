# My submissions on interviewbit .

## Binary Search

### Matrix Median

```
int func(vector<vector<int> > &A, int mid){
    int ans = 0;
    for(int i =0 ; i <A.size(); i++){
        ans += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
    }
    return ans;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int l = INT_MAX, r = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        l = min(l, A[i][0]);
        r = max(r, A[i][A[0].size()-1]);
    }
    int ans = 0, num = (A.size()*A[0].size()+1)/2;
    while(l < r){
        int mid = l + (r-l)/2;
        int pk = func(A, mid);
        if(pk < num){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return l;
}
```

### Implement Power Function

```
#define ll long long int
int Solution::pow(int base, int expo, int m) {
    if(m == 1) return 0;
    ll ans = 1, y = base%m;
    while(expo > 0){
        if(expo&1)  ans = ((ans)*y)%m;
        y = (y * y)%m;
        if(y<0) y += m;
        expo = expo >> 1;
    }
    if(ans<0)   ans=(m-abs(ans)%m);
    return ans%m;
}
```

### Square Root of Integer

```
int Solution::sqrt(int A) {
    int l = 1,  r = A, ans = 0;
    while(l <= r){
        int mid = (l+(r-l)/2);
        if(mid <= A/mid){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}

```

### Rotated Sorted Array Search

```
int findPivot(const vector<int> &A){
    int start = 0, end = A.size()-1;
    int mid, n = A.size();
    while(start <= end){
        mid = start + (end-start)/2;
        int next = (mid+1)%n, prev = (mid-1+n)%n;
        if(A[start] <= A[end])  return start;
        else if((A[mid] <= A[prev]) && (A[mid] <= A[next])) return mid;
        else if(A[mid] <= A[end])   end = mid-1;
        else    start = mid+1;
    }
    return -1;
}
int binarySearch(const vector<int> &A, int l, int r, int k){
    int mid;
    while(l <= r){
        mid = l + (r-l)/2;
        if(A[mid] == k) return mid;
        else if(A[mid] > k) r = mid-1;
        else    l = mid+1;
    }
    return -1;
}
int Solution::search(const vector<int> &A, int B) {
    int pivot = findPivot(A);
    if(B == A[pivot])   return pivot;
    int ans = binarySearch(A, 0, pivot-1, B);
    if(ans == -1)    return binarySearch(A, pivot+1, A.size()-1, B);    
    return ans;
}
```

### Allocate Books
```
#define ll long long int
bool isPossible(vector<int> &A,long long int X,int B){
    int n = A.size();
    ll sum = X;
    int stdcnt = 1, i = 0;
    while(i < n){
        if(sum - A[i] < 0){
            stdcnt++;
            sum = X;
        }
        else {
            sum -= A[i];
            i++;
        }
        if(stdcnt>B) return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(n < B) return -1;
    ll pages = 0;
    for(int i = 0; i < n; i++)    pages+=A[i];
    ll l = 0, r = pages, mid, ans = -1;
    while(l <= r){
        mid = l + (r-l)/2;
        if(isPossible(A,mid,B)){
         ans = mid;
         r = mid-1;
        }
        else
         l = mid+1;
    }
    return ans;
}
```

### Painter's Partition Problem

```
//Variation of Painter Problem - Allocate Books - Contiguous partitioning
#define ll long long int
const int mod = 10000003;
bool isPossible(vector<int> &C,ll mid,int paint){
    int maxi = 0;
    for(int i = 0; i < C.size(); i++){
        if(C[i] > maxi) maxi = C[i];
    }
    if(maxi > mid)  return false;
    ll sum = 0, count = 1;
    for(int i = 0; i < C.size();){
        if((sum + C[i]) > mid){
            count++;
            sum = 0;
        }
        else{
            sum += C[i];
            i++;
        }
    }
    if(count > paint)  return false;
    return true;
}

int Solution::paint(int B, int C, vector<int> &A) {
    int n = A.size();
    ll pages = 0;
    for(int i = 0; i < n; i++) pages += A[i];
    ll l = 0, r = pages;
    ll mid, ans = -1;
    while(l <= r){
        mid = l + (r-l)/2;
        if(isPossible(A, mid, B)){
            ans=mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return (ans*C)%mod;
}

```

### Matrix Search

```
bool  bs(vector<int> A, int l, int r, int B){
    while(l <= r){
        int mid = l + (r-l)/2;
        if(A[mid] == B){
            return 1;
        }
        else if(A[mid] < B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return 0;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int i, j, n, m;
    for(int i = 0; i < A.size(); i++){
        if(A[i][0] <= B && A[i][A[0].size()-1] >= B){
            if(bs(A[i], 0, A[0].size()-1, B)){
                return 1;
            }
        }
    }
    return 0;
}
```

### Search for a Range

```
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int l = 0, r = A.size()-1, f = -1, g = -1;
    while(l <= r){
        int mid = (l + (r-l)/2);
        if(A[mid] == B){
            f = mid;
            r = mid - 1;
        }
        else if(A[mid] > B){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    l = 0, r = A.size() - 1;
    while(l <= r){
        int mid = (l + (r-l)/2);
        if(A[mid] == B){
            g = mid;
            l = mid + 1;
        }
        else if(A[mid] > B){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return {f, g};
}

```

### Sorted Insert Position

```
int Solution::searchInsert(vector<int> &A, int B) {
    int l = 0, r = A.size()-1, ans = A.size();
    while(l <= r){
        int mid = (l+(r-l)/2);
        if(A[mid]-B >= 0){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

```
### Median of Array

```
double Solution::findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
    }
    return -1;
}
```

### Simple Queries

```
    TLE
```

##  Stack

### Evaluate Expression

```
int Solution::evalRPN(vector<string> &A) {
    stack <int> s;
    if(A.size() == 1){
        return stoi(A[0]);
    }
    for(int i = 0; i < A.size(); i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int d = s.top();
            s.pop();
            int c = s.top();
            s.pop();
            if(A[i] == "+")     c += d;
            if(A[i] == "-")     c -= d;
            if(A[i] == "*")     c *= d;
            if(A[i] == "/")     c /= d;
            s.push(c);
        }
        else{
            int c = 0, f = 0;
            if(A[i][0] == '-'){
                f = 1;
            }
            for(int j = f; j < A[i].size(); j++){
                c = c*10 + (A[i][j] - '0');
            }
            if(f){
                c *= -1;
            }
            s.push(c);
        }
    }
    return s.top();
}

```

### Nearest Smaller Element

```
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector < int > ans;
    stack < int > s;
    for(int i = 0; i < A.size(); i++){
        while(!s.empty() && A[i] <= A[s.top()]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(A[s.top()]);
        }
        s.push(i);
    }
    return ans;
}

```

### Rain Water Trapped


```
//used spaced; need to optimise on space
int Solution::trap(const vector<int> &A) {
    int left[A.size()] = {0}, right[A.size()] = {0};
    left[0] = A[0];
    right[A.size()-1] = A[A.size()-1];
    for(int i = 1; i < A.size(); i++){
        left[i] = max(left[i-1], A[i]);
    }
    for(int i = A.size()-2; i>= 0; i--){
        right[i] = max(right[i+1], A[i]);
    }
    int ans = 0;
    for(int i = 0 ; i < A.size(); i++){
        ans += (min(left[i], right[i]) - A[i]);
    }
    return ans;
}
```



