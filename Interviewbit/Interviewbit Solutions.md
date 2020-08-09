# My submissions on interviewbit .

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
