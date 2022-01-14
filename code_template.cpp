//快速排序
void quick_sort(int a[],int l,int r) //对数组a的下标[l,r]区间排序
{
    if(l>=r) return; //递归结束+错误判断
    int x=a[l+r>>1],i=l-1,j=r+1; //mid为本轮对比点的下标,i和j是双指针
    while(i<j){
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    quick_sort(a,l,j); //递归操作下去,最终j比i小,区间划分为了[l,j]和[j+1,r];
    quick_sort(a,j+1,r);
}

//利用快速排序，有序序列求第k大元素
int quick_choose(int a[],int l,int r,int k) //对数组a的下标[l,r]范围内求第k大的数(第k小/中位数)
{
    if(l>=r) return a[l];
    int x=a[l+r>>1],i=l-1,j=r+1;
    while(i<j){
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    //始终把j当作哨兵
    if(k<=j-l+1) return quick_choose(a,l,j,k); //为什么是k<=j-l+1,因为区间划分为[l,j]和[j+1,r]后，第一个区间有j-l+1个数
    else return quick_choose(a,j+1,r,k-(j-l+1));
}

//归并排序
int b[N]; //临时存储中间序列
void merge_sort(int a[],int l,int r) //对数组a的下标[l,r]区间排序
{
    if(l>=r) return; //递归结束+错误判断
    int mid=l+r>>1;
    merge_sort(a,l,mid),merge_sort(a,mid+1,r);

    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(int i=l,k=0;i<=r;i++,k++) a[i]=b[k];
}

//归并排序求逆序对
typedef long long LL;
int b[N]; //存储中间序列
LL merge_sort(int a[],int l,int r)
{
    if(l>=r) return;
    int mid=l+r>>1;
    LL res=merge_sort(a,l,mid)+merge_sort(a,mid+1,r);

    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) b[k++]=a[i++];
        else {
            res+=mid-i+1;
            b[k++]=a[j++];
        }
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(int i=l,k=0;i<=r;i++,k++) a[i]=b[k];

    return res;
} 

//整数二分
int l=???,r=???;//初始化为答案所在范围
while(l<r){
    int mid=l+r>>1;
    if(check(mid)) r=mid; //或者l=mid;
    else l=mid+1; //对应r=mid-1; 视问题而定
}
bool check(int mid);//把mid当已知条件，判断可行性。

//浮点数二分
const int eps=1e-7;//经验上，一般比所求精度多2位即可
double l=???,r=???;//初始化为答案所在范围
while(r-l>eps){
    double mid=(l+r)/2;
    if(check(mid)) r=mid; //或者l=mid;
    else l=mid;//对应r=mid;视问题而定
}
bool check(double mid);//把mid当已知条件，判断可行性。

//高精度加法 倒序vector实现
string A,B;//被加数，一般先用字符串存储
vector<int> a,b,c;//c=a+b;
//倒序存储到vector中
for(int i=A.size()-1;i>=0;i--) a.push_back(A[i]-'0');
for(int i=B.size()-1;i>=0;i--) b.push_back(B[i]-'0');
c=add(a,b); //最后c也是倒序的

vector<int> add(vector<int>& a,vector<int>& b)//引用不需要再复制
{
    int t=0;//循环开始前表示进位，进入循环表示过程中求和变量
    vector<int> c;//表示答案
    for(int i=0;i<a.size()||i<b.size();i++)//只要a,b有一个位置上不空就行
    {
        if(i<a.size()) t+=a[i]; //谁有加谁
        if(i<b.size()) t+=b[i];
        c.push_back(t%10);//这一位答案是mod10结果
        t/=10;//更新t为进位
    }
    if(t) c.push_back(t);//如果最后有进位，进上去
    return c;
}

//高精度加法 stirng实现
string a,b,c; //string实现中,a,b都是中序的
c=add(a,b);//最后c是正序的

string add(string& a,string& b)//引用不需要再复制
{
    reverse(a.begin(),a.end()),reverse(b.begin(),b.end());//倒序处理

    int t=0;//循环开始前表示进位，进入循环表示过程中求和变量
    string c;//表示答案
    for(int i=0;i<a.size()||i<b.size();i++)//只要a,b有一个位置上不空就行
    {
        if(i<a.size()) t+=a[i]-'0'; //谁有加谁
        if(i<b.size()) t+=b[i]-'0';
        c.push_back(t%10);//这一位答案是mod10结果
        t/=10;//更新t为进位
    }
    if(t) c.push_back(t);//如果最后有进位，加上去
    reverse(c.begin(),c.end());
    return c;
}

//高精度减法 倒序vector实现
string A,B;//一般先用字符串存储
vector<int> a,b,c;//c=a+b;
//倒序存储到vector中
for(int i=A.size()-1;i>=0;i--) a.push_back(A[i]-'0');
for(int i=B.size()-1;i>=0;i--) b.push_back(B[i]-'0');
c=sub(a,b); //最后c也是倒序的

vector<int> sub(vector<int>& a,vector<int>& b){
    if(check(a,b)) return sub(b,a); //check函数确定被减数>减数，如果确定就不需要了
    int t=0;//标志是否被借位
    vector<int> c;//答案
    for(int i=0;i<a.size();i++){
        t+=a[i];
        if(i<b.size())t-=b[i];
        c.push_back((t+10)%10);
        if(t<0) t=-1;
        else t=0;
    }
    while(c.size()>1&&c.back()==0) c.pop_back(); //除掉前导0
    return c;
}

//高精度乘法 倒序vector实现 大数乘小数
string A;
int b;
vector<int> a,c;//c=a+b;
//倒序存储到vector中
for(int i=A.size()-1;i>=0;i--) a.push_back(A[i]-'0');
c=mul(a,b); //最后c也是倒序的

vector<int> mul(vector<int>& a,int b)//引用不需要再复制
{
    int t=0;//循环开始前表示进位，进入循环表示过程中的变量
    vector<int> c;//表示答案
    for(int i=0;i<a.size();i++)//枚举a的每个位置去乘b
    {
        t+=a[i]*b;
        c.push_back(t%10);//这一位答案是mod10结果
        t/=10;//更新t为进位
    }
    while(t) c.push_back(t%10),t/=10;//如果最后有进位，进上去
    return c;
}

//高精度除法 倒序vector实现 大数除以小数
string A;
int b;
int r;//余数
vector<int> a,c;//c=a+b;
//倒序存储到vector中
for(int i=A.size()-1;i>=0;i--) a.push_back(A[i]-'0');
c=div(a,b,r); //最后c也是倒序的

vector<int> div(vector<int>& a,int b,int& r)
{
    vector<int> c;//答案
    r=0;//余数
    for(int i=a.size()-1;i>=0;i--) //倒序的a的最后是最大的，从最大处开始,其实就是模拟除法算式
    {
        r=r*10+a[i];
        c.push_back(r/b);
        r%=b;
    } //最后求出的c是正序的
    reverse(c.begin(),c.end());//变成逆序
    while(c.size()>1&&c.back()==0) c.pop_back(); 
    return c;
}

//一维前缀和
int a[N],s[N];//原数组a，前缀和数组s
for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];//用a初始化s，O(n)
for(int i=1;i<=n;i++) a[i]+=a[i-1];//技巧：把a自己覆盖为a的前缀和
s[r]-s[l-1];//求[l,r]的区间和,O(1)

//二维前缀和
int g[N][N],s[N][N];
//用g初始化s,O(nm)
for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]=g[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1]
//技巧：把g自己覆盖为g的前缀和
for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
//求左上角(x1,y1)到右下角(x2,y2)的矩阵和
int query(int x1,int y1,int x2,int y2){
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

//一维差分
int a[N],b[N];//原数组a,差分数组b
for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];//初始化差分数组
b[r+1]-=c,b[l]+=c;//[l,r]区间每个数+c
for(int i=1;i<=n;i++) a[i]=a[i-1]+b[i]; //最后把修改更新到原数组

//二维差分
int g[N][N],b[N][N];
void modify(int x1,int y1,int x2,int y2,int c)//(x1,y1)和(x2,y2)之间每个数都+c
{
    b[x1][y1]+=c;
    b[x2+1][y2+1]+=c;
    b[x1][y2+1]-=c;
    b[x2+1][y1]-=c;
}
mddify(x1,y1,x1,y1,c);//在某个点处+c，可以用来读入g的同时初始化b
//最后把修改更新到原数组（回到了二维差分数组的定义
for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]=b[i][j]+g[i-1][j]+g[i][j-1]-g[i-1][j-1];


//返回x的二进制表示的第k位数字（从第0位开始）
return x>>k&1;

//lowbit
int lowbit(int x){ //返回x的二进制表示下，第一位1所对应的二进制数
    return x&-x;
}

//双指针
int i=???,j=???; //i,j地位相等的写法
while(i<j){
    if(/*具体逻辑*/) //更新i
    else //更新j
}

for(int i=0,j=0;i<=r;i++) //i为主动指针，j为伴随指针，为了某个某个条件而维护
{
    if(/*触发某个条件，要更新j了*/) //更新j
    //操作
}

//离散化
/*解释：当只用到大区间上的一个小区间时，例如[-1e8,1e8]的区间我们只需要用[-1e4,1e4]时，可以进行离散化*/
vector<int> alls;//所有待离散化的值 包括操作，查询等等涉及到的数字
sort(alls.begin(),alls.end());//排序
alls.erase(unique(alls.begin(),alls.end()),alls.end()); //去重
int find(int x) //求原序列中某个数在新序列中的“排位”
{
    int l=0,r=alls.size()-1;
    while(l<r){
        int mid=l+r>>1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return r+1; //映射到1,2,3,4,....
    //return r;映射到0,1,2,3,....
}
//
typedef pair<int,int> PII
void merge_segs(vector<PII>& segs) //传入segs引用，修改结果体现在segs
{
    vector<PII> res;
    sort(segs.begin(),segs.end()); //默认按照左端点排序
    int st=-2e9,ed=-2e9;//维护的区间，初始值设为负无穷
    for(auto seg:segs){
        int l=seg.first,r=seg.second;
        if(ed<l){ //不相交了
            res.push_back(seg);
            st=l,ed=r;
        }
        else ed=max(ed,r);
    }
    if(st!=-2e9) res.push_back({st,ed}); //如果segs非空的话，把最后的也加上
    segs=res;
}
/*搜索*/
//dfs
//bfs
//双端队列bfs：用于求边权只有0和1的最短路问题，本质为dijkstra

//模拟退火
//单链表
int head,e[N],ne[N],idx;
void init() //初始化
{
    head=-1,idx=0;
}
void insert(int x) //链表头插入值为x的节点
{
    e[idx]=x,ne[x]=head,head=idx++;
}
void remove() //删除头节点（头节点存在时
{
    head=ne[head];
}

//双向链表
int e[N],l[N],r[N],idx;
void init(){ //0和1两个下标的点不用来存信息，来作为哨兵
    r[0]=1,l[1]=0;
    idx=2;
}
void insert(int a,int x){ //在节点a的右边插入一个值为x的节点
    e[idx]=x;
    l[idx]=a,r[idx]=r[a];
    l[r[idx]]=idx,r[a]=idx++;
}
void remove(int a){//删除节点a
    l[r[a]]=l[a];
    r[l[a]]=r[a];
}

//栈
int stk[N],top=-1;
inline int push(int x){stk[++top]=x} //x压栈
inline void pop(){top--;}//弹出一个元素
inline int gettop(){return stk[top];} //求栈顶元素
inline bool empty(){return top==-1;} //判空

//单调栈
int top=-1;
for(int i=1;i<=n;i++){ //常见模型：找出每个数左边离它最近的比它大/小的数
    while(top!=-1&&check(stk[top],i)) top--; //check函数判断的是stk[top]和i这俩坐标所对应数的关系
    stk[++top]=i; //存的是下标
}

//队列
int q[N],front=0,back=-1;
void push(int x){q[++back]=x;} //x加入队列
void pop(){front++;}//队头弹出队列
int getfront(){return q[front];} //求队头元素
bool empty(){return front<=back;} //判空

//循环队列
int q[N],front=0,back=-1;
void push(int x)//x加入队列
{
    q[++back]=x;
    if(back==N) back=0;
} 
void pop(){
    front++;
    if(front==N) front=0;
}
int getfront(){
    return q[front];
}
bool empty(){
    return front==back
}

//KMP 
int n=s.size(),m=p.size();
int ne[N];//next数组：i没匹配应该回到ne[i]位置继续匹配
void getNext(){
    for(int i=2,j=0;i<=m;i++){
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
}
void KMP(string s,string p){ //KMP从1开始会更好写
    for(int i=1,j=0;i<=n;i++){
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==m){
            j=ne[j];
            //匹配成功后的操作
        }
    }
}

//Trie
int son[N][26],cnt[N],idx;//son[i][j]表示节点i的第j个儿子 cnt存储每个节点结尾的词的个数
void insert(string s)//插入字符串s
{
    int p=0;
    for(int i=0;i<s.size();i++){ 
        int u=s[i]-'a';//求出这个儿子的序号
        if(!son[p][u]) son[p][u]=++idx;//如果没有这个儿子就分配一个从1开始的节点编号，如果有那就不用了
        p=son[p][u];
    }
    cnt[p]++;
}
int query(string s)//查询s的出现次数
{
    int p=0;
    for(int i=0;i<=s.size();i++){
        int u=s[i]-'a';
        if(!son[p][u]) return 0;
        p=som[p][u];
    }
    return cnt[p];
}

//Manacher 马拉车算法 O(n)求最长回文子串
//核心：通过构造，使得原串中每个长度为s的回文串 和 新串中长度为奇数的半径为s+1的回文串

int p[N];
char a[N],b[N];
int n;
void init()  // a[]为原串，b[]为插入'#'后的新串
{
    int k = 0;
    b[k ++ ] = '$', b[k ++ ] = '#';
    for (int i = 0; i < n; i ++ ) b[k ++ ] = a[i], b[k ++ ] = '#';
    b[k ++ ] = '^';
    n = k;
}
n=strlen(a);
void manacher()  // 马拉车算法，b[]为插入'#'后的新串
{
    int mr = 0, mid; //维护mr和mid
    for (int i = 1; i < n; i ++ ) //枚举以i为中心的回文串
    {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i); //1.递推
        else p[i] = 1;
        while (b[i - p[i]] == b[i + p[i]]) p[i] ++ ; //2.再扩展
        if (i + p[i] > mr) //3.更新mr和mid
        {
            mr = i + p[i];
            mid = i;
        }
    }
}

//并查集
int p[N];//每个节点的祖宗节点
for(int i=1;i<=n;i++) p[i]=i;//初始化自己指向自己
inline int find(int x){return x==p[x]?x:p[x]=find(p[x]);} //含路径压缩的查找祖宗节点编号，祖宗节点编号唯一确定一个集合
p[find(a)]=find(b);//a和b所在的集合合并
/*维护集合属性size*/
int size[N];//只有祖宗节点的size才有意义
for(int i=1;i<=n;i++) size[i]=1; //初始化，根据题意而定
//查询操作，find函数不变
//合并操作，额外维护size域，size[find(b)]+=size[find(a)];
/*维护每个元素到祖宗节点的距离*/
int d[N];//d[i]:i节点到p[i]的距离
int find(int x)//重写find函数
{
    if(p[x]!=x){
        int u=find(p[x]);
        d[x]+=d[p[x]];
        p[x]=u;
    }
    return p[x];
}
p[find(a)]=find(b);
d[find(a)]=distance;//distance视题目而定，初始化a的偏移量

//堆 的实现
int h[N];//存储堆中的值,h[1]为堆顶，左儿子h[2*i],右儿子h[2*i+1]
int ph[N],hp[N];//ph[k]:第k个插入的点在堆中的位置，hp[k]:堆中下标为k的点是第几个插入的
int size;
void heap_swap(int a,int b)//交换堆中两点及其映射关系
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void down(int u)//down操作
{
    int t=u;
    if(u*2<=size&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=size&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t){
        heap_swap(u,t);
        down(t);
    }
}
/*
BST 二叉搜索树 
定义：左子树任意权值<根节点<右子树任意权值
性质：中序遍历单增
用途（包括平衡树）：动态维护有序序列（有序集合）
BST和平衡树的常见操作：
1.插入——
2.删除——删叶节点
3.找最大/最小——一直往右走、一直往左走
4.找前驱/后继（默认是中序遍历）——也不常用
这四个操作 set中都实现了，对应insert,erase,begin,end-1,++,--等等
5.求某个值的排名
6.求排名为k的数是哪个
7.比某个数小的最大值
8.比某个数大的最小值

平衡树是一种特殊的BST，平衡树有红黑书，treap,splay等等
treap = bst + heap 一种平衡树
下边实现下treap
*/
struct Node{
    int l,r; //左右儿子
    int key; //bst的要求
    int val; //heap的要求 一个随机值
    int cnt; //出现次数
    int size; //子树中点的个数
}tr[N];
int root;//根节点
int idx;//分配到的节点

void pushup(int p){
    tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+tr[p].cnt;
}
int get_node(int key){ //创建一个新节点
    tr[++idx].key=key;
    tr[idx].val=rand();
    tr[idx].cnt=tr[idx].size=1;
    return idx;
}
void build(){ //创建treap
    get_node(-INF),get_node(INF);
    root=1,tr[1].r=2;
}
void zig(int &p){ //右旋
    int q=tr[p].l;
    tr[p].l=tr[q].r;
    tr[q].r=p;
    p=q;
    pushup(tr[p].r);
    pushup(p);
}
void zag(int &p){ //左旋
    int q=tr[p].r;
    tr[p].r=tr[q].l;
    tr[q].l=p;
    p=q;
    pushup(p);
    pushup(tr[p].l)
}
void insert(int &p,int key){
    if(!p) p=get_node(key);
    else if(tr[p].key==key) tr[p].cnt++;
    else if(tr[p].key>key) {
        insert(tr[p].l,key);
        if(tr[tr[p].l].val>tr[p].val) zig(p);
    }
    else{
        insert(tr[p].r,key);
        if(tr[tr[p].r].val>tr[p].val) zag(p);
    }
    pushup(p);
}
void remove(int &p,int key){
    if(!p) return;
    else if(tr[p].key==key){
        if(tr[p].cnt>1) tr[p].cnt--;
        else if(tr[p].l||tr[p].r){
            if(!tr[p].r||tr[tr[p].l].val>tr[tr[p].r].val){
                zig(p);
                remove(tr[p].r,key);
            }
            else {
                zag(p);
                remove(tr[p].l,key);
            }
        }
        else p=0;
    }
    else if(tr[p].key>key) remove(tr[p].l,key);
    else remove(tr[p].r,key);
    pushup(p);
}
int get_rank_by_key(int &p,int key){ //通过数值找排名
    if(!p) return 0;
    if(tr[p].key==key) return tr[tr[p].l].size+1;
    if(tr[p].key>key) return get_rank_by_key(tr[p].l,key);
    else return get_rank_by_key(tr[p].r,key)+tr[tr[p].l].size+tr[p].cnt;
}
int get_key_by_rank(int &p,int rank){ //通过排名找数值
    if(!p) return INF;
    if(tr[tr[p].l].size>=rank) return get_key_by_rank(tr[p].l,rank);
    if(tr[tr[p].l].size+tr[p].cnt>=rank) return tr[p].key;
    else return get_key_by_rank(tr[p].r,rank-tr[tr[p].l].size-tr[p].cnt);
}
int get_prev(int &p,int key){ //找严格小于key的最大数
    if(!p) return -INF;
    if(tr[p].key>=key) return get_prev(tr[p].l,key);
    return max(tr[p].key,get_prev(tr[p].r,key));
}
int get_next(int &p,int key){ //找到严格大于key的最小数
    if(!p) return INF;
    if(tr[p].key<=key) return get_next(tr[p].r,key);
    return min(tr[p].key,get_next(tr[p].l,key));

}

//splay 竞赛中最常用的一种平衡树(可以替代treap)
/*
核心:每次插入、查询后，均将该节点旋转到树根
操作:splay(x,k)把x旋转到k下边
其他操作都是围绕着splay操作展开的
*/
struct Node{  //可能还会维护其他信息
    int s[2],p,v;//儿子和父亲
    int size;//子树大小
    int flag;//懒标记，是否反转
    void init(int _v,int _p){
        v=_v,p=_p;
        size=1;
    }
}tr[N];
int root,idx;
void pushup(int x){
    tr[x].size=tr[tr[x].s[0]].size+tr[tr[u].s[1]].size+1;
}
void pushdown(int x){
    if(tr[x].flag){
        swap(tr[x].s[0],tr[x].s[1]);
        tr[tr[x].s[0]].flag^=1;
        tr[tr[x].s[1]].flag^=1;
        tr[x].flag=0;
    }
}
void rotate(int x){  //综合了四种情况的旋转函数
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x; //k=0表示x是y的左儿子，k=1表示x是y的右儿子
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}
void splay(int x,int k){ //将节点x旋转到节点k下边
    while(tr[x].p!=k){
        int y=tr[x].p,z=tr[y].p;
        if(z!=k){
            if(tr[y].s[1]==x)^(tr[z].s[1]==y))rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k) root=x;
}
void insert(int x){
    int u=root,p=0;
    while(u) p=u,u=tr[u].s[v>tr[u].v];
    u=++idx;
    if(p) tr[p].s[v>tr[p].v]=u;
    tr[u].init(v,p);
    splay(u,0);
}
int get_k(int k){ //找第k大
    int u=root;
    while(1){
        pushdown(u);
        if(tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if(tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]]+1,u=tr[u].s[1];
    }
    return -1;
}
void output(int u){ //输出中序遍历
    pushdown(u);
    if(tr[u].s[0]) output(tr[u].s[0]);
    if(tr[u].v>=1&&tr[u]<=n) printf("$d ",tr[u].v);
    if(tr[u].s[1]) output(tr[u].s[1]);
}

//红黑树 一种很复杂的平衡树，工程中常用，算法竞赛中很少见
//B树，B+树

//哈希表


//字符串哈希


//邻接表
int h[N],e[M],ne[M],idx;//h存链表头，e存值，ne存next指针，idx是当前分配的序号
void add(int a,int b)//添加一条边a->b
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
//初始化
idx=0;
memset(h,-1,sizeof h);

//树与图的深度优先遍历dfs
void dfs(int u){
    st[u]=true;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!st[j]) dfs(j);
    }
}
//树与图的广度优先遍历bfs
queue<int> q;
st[1]=true;//1号点已经入队
q.push(1);
while(q.size()){
    int t=q.front();
    q.pop();
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            q.push(j);
        }
    }
}

//拓扑排序
int q[N],front=0,back=-1;//队列
int d[N];//d[i]:i号节点的入度
bool toposort(){
    for(int i=1;i<=n;i++){ //度为0的先入队
        if(!d[i]) q[++back]=i;
    }
    while(front<=back){
        int t=q[front++];
        for(int i=h[t];~i;i=ne[i]){ //把这个点的出度对应点的入度减1
            int j=e[i];
            if(--d[i]==0) q[++back]=j; //减到0了就把它入队
        }
    }
    return back==n-1;//[0,n-1] n个节点都入队了,说明有拓扑排序，且队列q即为拓扑序列
}

//朴素dijkstra 基于贪心
//时间复杂度O(n^2+m) 常用于稠密图，故用邻接矩阵存储
int g[N][N];
int dist[N];//1号点到i号点的最短距离
bool st[N];//每个点的最短路是否确定，也即dijkstra算法中所谓的S集合中的元素
int dijkstra(){
    memset(dist,0x3f,sizeof dist);//初始化为正无穷
    dist[1]=0;//1->1距离为0
    for(int i=0;i<n-1;i++){ //除了1号点还有n-1个点，每次循环把一个点加入S,循环n-1次即可
        int t=-1;
        for(int j=1;j<=n;j++) if(!st[j]&&(t==-1||dist[t]>dist[j])) t=j;//找在集合S(确定集)外的dist最小的点
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],dist[t]+g[t][j]);//把t当中转站更新其他点
        st[t]=true;
   
    if(dist[n]==0x3f3f3f3f) return -1;//1-n无最短路
    return dist[n]; 
}
//堆优化dijkstra 
//时间复杂度O(mlogn),常用于稀疏图，故用邻接表存储
typedef pair<int,int> PII;
int n;//点数
int h[N],w[N],e[N],ne[N];//邻接表那一套东西（数组w存权值
int dist[N];//距离数组
bool st[N];//是否入集合S
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});//first是距离，second是点编号
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second,distance=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

//Bellman-Ford 基于dp
//O(nm) 可以直接结构体存
int n,m;//点数和边数
int dist[N];//dist[i]存储1到i的最短距离
struct Edge{
    int a,b,w;
}edges[M];//边，直接结构体存
int bellman_ford(){
    memset(dist,0x3f,sizeof dist);//dist初始化为正无穷
    dist[1]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            if(dist[b]>dist[a]+w) dist[b]=dist[a]+w;
        }
    }

    if(dist[n]>0x3f3f3f3f/2) return -1;
    return dist[n];
}

//spfa(可以看成队列优化的bellman_ford算法)
//平均O(m),最坏O(nm) 邻接表存储
int n;//总点数
int h[N],ne[N],e[N],w[N],idx;//邻接表
int dist[N];//存储1-x的最短距离
bool st[N];//存储每个点是否在队列中

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    queue<int> q;
    q.push(1); 
    st[1]=true; //初始化队列1号点入队

    while(q.size()){
        auto t=q.front();
        q.pop();
        st[t]=false;

        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
}
//spfs判负环
int n;
int h[N],e[N],w[N],ne[N],idx;
int dist[N];
int cnt[N];//cnt[i]存储1-i的最短路途径的点的个数
bool st[N];
int spfa[N];

bool spfa(){  //和spfa只有两点不同，1是不需要初始化dist数组，二是对cnt数组的维护和判断
    // 不需要初始化dist数组
    // 原理：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环。
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
        st[i]=true;
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
}

//floyd 基于dp
//O(n^3)
const int INF=1e9;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==j) d[i][j]=0;
        else d[i][j]=INF;
    }
}
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                d[i][j]=d[i][k]+d[k][j];
            }
}

//LCA 最近公共祖先 可以求树上两点的最短路
//两种写法:倍增或者tarjan算法


//朴素prim 
//O(n^2+m)
int n;//点数
int g[N][N];//邻接矩阵
int dist[N][N]; //存储其他点到当前最小生成树的距离
bool st[N];//是否在最小生成树中

int prim(){ //如果不连通，返回正无穷，否则返回最小生成树的权值和
    memset(dist,0x3f,sizeof dist);
    int res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;i++){ //找一个不在树中的最小的dist
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t=j; 
        }
        if(i&&dist[t]==INF) return INF; //不是第一次循环且最小距离都是正无穷
        if(i) res+=dist[t]; //如果不是第一次循环，加入
        st[t]=true;
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],g[t][j]);
    }
    return res;
}

//二分图 《=》 二分图 《=》 无奇数环
//染色法 判二分图
int n;//点数
int h[N],e[N],ne[M],idx; //邻接表
int color[N];//颜色
bool dfs(int u,int c){ //节点u的颜色为c
    color[u]=c;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(color[j]==-1){ //j这个点还没染色
            if(!dfs(j,!c)) return false; //对j染另一种颜色
        }
        else if(color[j]==c) return false; //j这个点已经有颜色，且与我相同，直接false
    }
    return true; //最后没false就是true
}

bool check(){ 
    memset(color,-1,sizeof color); //初始化color
    bool flag=true; //返回答案
    for(int i=1;i<=n;i++){  //遍历所有点，如果还没染色就对其染色
        if(color[i]==-1){
            if(!dfs(i,0)){
                flag=false;
                break;
            }
        }
    }
    return flag;
}

//匈牙利算法
//O(nm)
int n1,n2;//n1表示第一个集合中的点数，n2表示第二个集合中的点数
int h[N],e[M],ne[M],idx;//邻接表
int match[N];//存储第二个集合中每个点匹配的第一个集合中的点
bool st[N];//第二个集合中的点是否遍历过
bool find(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(match[j]==0||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
//求最大匹配数，依次枚举第一个集合中每个点能否匹配第二个集合中的点
int res=0;
for(int i=1;i<=n1;i++){
    memset(st,false,sizeof st);
    if(find(i)) res++;
}


//进制转换，秦九韶算法
int get(string s,int b) //b进制的字符串s转化为十进制数
{
    int res=0;
    for(auto c:s) res=res*b+c-'0';
    //return to_string(res);
    return res;
}
stirng get(string s,int b) //十进制的s转化为b进制字符串
{
    stirng res="";
    int n=atoi(s);
    while(n){
        int cur=n%b;
        if(cur>=10) res+=cur-10+'A';
        else res+=cur-'0';
        n/=b;
    }
    reverse(res.begin(),res.end());
    return res;
}

//判定质数 试除法
bool is_prime(int x){
    if(x<2) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }    
    return true;
}

//分解质因数 试除法
void divide(int x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0){
            int s=0;
            while(x%i==0) x/=i,s++;
            //cout<<"质因数"<<i<<"的个数是"<<s<<endl;
        }
    }
    if(x>1) //cout<<"质因数"<<x<<"的个数是"<<1<<endl;
}

//筛素数 朴素法
int primes[N],cnt;//存储所有质数
bool st[N];//st[i]:i是否被筛掉
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(st[i]) continue;
        primes[cnt++]=i;
        for(int j=i+i;j<=n;j+=i){
            st[j]=true;
        }
    }
}
//筛素数 线性筛
int primes[N],cnt;//存储所有质数
bool st[N];//st[i]:i是否被筛掉
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]*i<=n;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }    
}

//求约数 试除法
vector<int> get_divisors(int x){
    vector<int> res;
    for(int i=1;i<=x/i;i++){
        if(x%i){
            res.push_back(i);
            if(i!=x/i) res.push_back(x/i); //如果不是平方，把俩数都加进去
        }
    }
    sort(res.begin(),res.end());
    return res;
}
//求约数个数
/*
如果 N = p1^c1 * p2^c2 * ... * pk^ck
约数个数：(c1+1)*(c2+1)*...*(ck+1);
*/
//求约数之和
/*
如果 N = p1^c1 * p2^c2 * ... * pk^ck
约数个数：(p1^0+p1^2+...p1^c1)*...*(pk^0*pk^1*...*pk^k);
*/

//求最大公约数 欧几里得算法
typedef long long LL;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;} 
//优美的递归，类似的还有并查集的find函数

//求欧拉函数 定义法
int phi(int x){
    int res=x;
    for(int i=2;i<=x/i;i++){
        if(x%i==0){
            res=res/i*(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res=res/x*(x-1);
    return res;
}
//求欧拉函数 筛法
int primes[N],cnt;
bool st[N];//线性筛
int phi[N];//存储每个数的欧拉函数

void get_eulers(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++]=i;
            phi[i]=i-1;  //质数i的欧拉函数就是i-1
        }
        for(int j=0;primes[j]*i<=n;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0){
                phi[primes[j]*i]=primes[j]*phi[i]; 
                break;
            }
        }
        phi[primes[j]*i]=phi[i]*(primes[j]-1);
    }
}

//快速幂
int qmi(int a,int b,int p){
    int res=1%p;
    while(b){
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}

//扩展欧几里得算法 
//ax+by=gcd(a,b) 求解x,y
int exgcd(int a,int b,int& x,int& y){
    if(!b){
        x=1;y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}

//高斯消元
int a[N][N];//增广矩阵
int gauss(){
    int c,r;
    for(c=0,r=0;c<n;c++){
        int t=r;
        for(int i=r;i<n;i++) //找到绝对值最大的衣阿华那个
            if(fabs(a[i][c])>fabs(a[t][c])) t=i;
        if(fabs(a[t][c])<eps) continue;//==0

        for(int i=c;i<=n;i++) swap(a[t][i],a[r][i]);//把最大的行交换到顶部
        for(int i=n;i>=c;i--) a[r][i]/=a[r][c];//顶端行首位变成1
        for(int i=r+1;i<n;i++){
            if(fabs(a[i][c])>eps){ //如果不等于0,需要减掉
                for(int j=n;j>=c;j--){
                    a[i][j]-=a[r][j]*a[i][c];
                }
            }
        }
        r++;
    }
    if(r<n){
        for(int i=r;i<n;i++)
            if(fabs(a[i][n])>eps) return -1;//无解
        return 2;//有无穷多组解
    }
    for(int i=n-1;i>=0;i--)
        for(int j=i+1;j<n;j++)
            a[i][n]-=a[i][j]*a[j][n];
    return 1;//有唯一解
}

//求组合数 递推法
int C[a][b];
for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
        if(!j) C[i][j]=1;
        else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
}
//求组合数 预处理逆元法
int qmi(int a,int b,int p){
    int res=1%p;
    while(b){
        res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
LL fact[N],infact[N];
fact[0]=infact[0]=1;
for(int i=1;i<N;i++){
    fact[i]=(LL)fact[i-1]*i%mod;
    infact[i]=(LL)infact[i-1]*qmi(i,mod-2,mod)%mod;
}
//求组合数 Lucas定理
//若p为质数，则对于任意的整数1<=m<=n,C(n,m)=C(n%p,m%p)*C(n/p,m/p)(mod p)
int qmi(int a,int b,int p){
    int res=1%p;
    while(b){
        res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
int C(int a,int b,int p){
    if(a<b) return 0;
    LL x=1,y=1;//分子x，分母y
    for(int i=a,j=1;j<=b;i--,j++){
        x=(LL)x*i%p;
        y=(LL)y*j%p;
    }
    return x*(LL)qmi(y,p-2,p)%p;
}
int lucas(LL a,LL b,int p){
    if(a<b&&b<p) return C(a,b,p);
    else return (LL)C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}
//求组合数 分解质因数法
// 当我们需要求出组合数的真实值，而非对某个数的余数时，分解质因数的方式比较好用：
//     1. 筛法求出范围内的所有质数
//     2. 通过 C(a, b) = a! / b! / (a - b)! 这个公式求出每个质因子的次数。 n! 中p的次数是 n / p + n / p^2 + n / p^3 + ...
//     3. 用高精度乘法将所有质因子相乘
int primes[N],cnt;
bool st[N];//线性筛
int sum[N];//每个质数出现的次数
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]*i<=n;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}
int get(int n,int p)//求n!中的p次数
{
    int res=0;
    while(n){
        res+=n/p;
        n/=p;
    }
    return res;
}
vector<int> mul(vector<int> a,int b)// 高精度乘低精度模板
{
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size();i++)
    {
        t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(t)
    {
        c.push_back(t%10);
        t/=10;
    }
    return c;
}
get_primes(a);//预处理范围内的所有质数
for(int i=0;i<cnt;i++){ //求每个质数出现的次数
    int p=primes[i];
    sum[i]=get(a,p)-get(b,p)-get(a-b,p);
}
vector<int> res; //高精度乘法把所有质因子相乘
res.push_back(1);
for(int i=0;i<cnt;i++)
    for(int j=0;j<sum[i];j++){
        res=mul(res,primes[i]);
    }

//斐波那契数
//f[i]=f[i-1]+f[i-2](i>=3),f[1]=f[2]=1;

//卡特兰数
// 给定n个0和n个1，它们按照某种顺序排成长度为2n的序列，满足任意前缀中0的个数都不少于1的个数的序列的数量为： Cat(n) = C(2n, n) / (n + 1)

//斯特林数
/* 
第一类斯特林数：s(n,m):表示将n个不同元素构成m个圆排列的方案数（我们讨论无符号第一类斯特林数）
dp求法:s[n][m]=s[n-1][m-1]+(n-1)s[n-1][m];
第一类斯特林数的性质：https://baike.baidu.com/item/%E6%96%AF%E7%89%B9%E6%9E%97%E6%95%B0/4938529?fr=aladdin
*/
s[0][0]=1;for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= m; j ++ ) s[i][j] = (s[i - 1][j - 1] + (LL)(i-1) * s[i - 1][j]) % MOD;
/*
第二类斯特林数：S(n,m):表示将n个不同的元素分成m个集合的方案数
dp求法:S[n][m]=S[n-1][m-1]+k*S[n-1][m];
第二类斯特林数的性质：https://baike.baidu.com/item/%E6%96%AF%E7%89%B9%E6%9E%97%E6%95%B0/4938529?fr=aladdin
*/
S[0][0]=1;for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= m; j ++ ) S[i][j] = (S[i - 1][j - 1] + (LL)j * S[i - 1][j]) % MOD;

//博弈论
//Nim游戏：先手必胜《=》 A1^A2^...^An!=0


//线性基：核心是一个向量组所构成的“空间”中的“基”
/*
算法中常用于异或：
*/



 


