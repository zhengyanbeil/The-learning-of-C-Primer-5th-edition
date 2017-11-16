#include <iostream>
#include <vector>


using namespace std;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

typedef int (*eventFunc)(int, int);

typedef struct Event_Func
{
    eventFunc e_f;
    int event_id;
} Event_Func;

int call(int a, int b, eventFunc event)
{
    int t = event(a, b);
    return t;
}

extern void testStaticFunc();

class TestUtils
{
    public:

        int overload_t(int) const {}
        int overload_t(int) {}

        static int calcSeriesNum(int n)
        {
            double rtl = 0;
            constructArray(n);
            for (auto it = v.begin(); it != v.end(); it++)
                rtl = rtl + *it;
            return rtl;
        }

        static void constructArray(int n)
        {
            double val = 0;
            val = construct_val(n);
            v.push_back(val);
        }

        static double construct_val(int n)
        {
        }
    private:
        static vector<double> v;
};
vector<double> TestUtils::v;

class AA
{
        friend istream& read(istream& is, AA& a);
        friend ostream& print(ostream& os, AA& a);
        friend int test();
    public:
        AA() = default;
        AA(string t_s, int t_i): s(t_s), i(t_i), arr(nullptr) {cout << "constructor" << endl;}
        void set_s(const string& t_s) {s = t_s;}
        const string& get_s() const {return s;}
        void set_i(const int t_i) {i = t_i;}
        int get_i() const {return i;}
        void malloc_arr(unsigned int size)
        {
            arr = (int*)malloc(sizeof(int) * size);
            if (NULL == arr)
                cerr << "malloc error...";
        }

        int* get_arr() const {return arr;}

        static const unsigned int arr_size = 10;
    private:
        string s = "";
        int i = 0;
        int* arr = nullptr;
};

istream& read(istream& is, AA& a)
{
    is >> a.s >> a.i;
    return is;
}

ostream& print(ostream& os, AA& a)
{
    os << a.s << "..." << a.i;
    return os;
}

int main()
{
    /*
    constexpr unsigned long int N = 100000;
    thread arr[N];
    for (auto& t : arr)
        t = thread(Singleton::getInstance);
    for (auto& t : arr)
        t.join();
    */
    int a[2][3] = {0, 2, 4, 6, 8, 10};
    int (*p)[3] = *(&a + 1);
    printf("%d\n",
           p[-1]);//直接跳过整个二维数组，反求最后一个，TODO
    return EXIT_SUCCESS;
    //    List* head = MyHelper::createList(20);
    //    MyHelper::travelList(head);
    //    cout << "-------------" << endl;
    //    head = MyHelper::reverseList(head);
    //    MyHelper::travelList(head);
//    int a[10] = {76,91,24,75,2};
//    srand(time(NULL));
//    for (auto it = begin(a); it != end(a); it++)
//    {
//        *it = rand() % 100 + 1;
//        cout << *it << " ";
//    }
//    cout << endl << endl;
//    MyHelper::heap_sort(a, sizeof(a) / sizeof(int));
//    for (auto it = begin(a); it != end(a); it++)
//        cout << *it << endl;
//    return 0;
//    char *s = "ajshfluahsaskghabdvashashukashkhshwe";
//    char *t = "as";
//    int cnt = MyHelper::substring_count(s,t,0);
//    cout << cnt <<endl;
//    Event_Func event;
//    event.event_id = 1;
//    event.e_f = add;
//    cout << event.e_f(1,99) << endl;
//    cout << call(1, 99, add) << endl;
//    testStaticFunc();
    /*
    int a[3][3];

    int n, m, k, p, q;
    n = 3;
    m = 4 * n - 4;
    k = 2 + m;
    p = 0;
    q = 0;
    for (int i = 0; i < n; i++)
    {
            for (int j = 0; j < n; j++)
            {
                a[i][j]=0;
            }
    }
    for (int i = 1; i <= m ; i++)
    {
        if ((p == 0) && (q == 0) || (p == n - 1) && (q == n - 1))
        {
            a[p][q] = i;
            if (p == 0)
                q++;
            else if (p == n - 1)
                break;
        }
        else
        {
            if (q < n)
            {
                a[p][q] = i;
                a[q][p] = k - i;
                q++;
                continue;
            }
            q--;
            if (p < n)
            {
                a[p][q] = i;
                a[q][p] = k - i;
                p++;
                continue;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "    ";
        }
        cout << endl;
    }

    */
    /*
    // simplify UNIX path.
    string s;
    bool root_flag;
    while (cin >> s)
    {
        stack<string> stk;
        string cur;
        auto pos_h = s.find('/');
        auto pos_t = pos_h;
        if (pos_h == 0)
            stk.push(string((char*)&s[pos_h], 1));
        while (1)
        {
            pos_t = s.find('/', pos_h + 1);
            if (pos_t == string::npos)
                break;
            ++pos_h;
            string t((char*)&s[pos_h], pos_t - pos_h);
            if (t.compare("..") == 0)
            {
                stk.pop();
            }
            else
            {
                stk.push(t);
            }
            pos_h = pos_t;
        }
        cur = stk.top();
        stk.pop();
        while (stk.size())
        {
            if (stk.top() != "/")
            {
                cur =  "/" + cur;
            }
            cur = stk.top() + cur;
            stk.pop();
        }
        cout << cur << endl;
    }
    */
}

/*
int cnt;
while (cin >> cnt)
{
    vector<int> v;
    for (int i = 0; i < cnt; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    int begin = 0;
    int sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (v[i] == 0)
        {
            sum++;
            begin = i + 1;
            continue;
        }
        for (int j = begin; j < i; j++)
        {
            int flag = 0;
            for (int k = j; k <= i; k++)
            {
                flag ^= v[k];
            }
            if (flag == 0)
            {
                sum++;
                begin = i + 1;
                continue;
            }
        }
    }
    cout << sum << endl;
}
return 0 ;
*/

/*
int n, factor_two, factor_three, factor_five, rlt = 1;
queue<int> queue_two;
queue<int> queue_three;
queue<int> queue_five;
queue_two.push(2);
queue_three.push(3);
queue_five.push(5);

cin >> n;
n--;
while (n--)
{
    factor_two = queue_two.front();
    factor_three = queue_three.front();
    factor_five = queue_five.front();
    int t = min(factor_two, min(factor_three, factor_five));
    if (t == factor_two)
    {
        queue_two.pop();
        queue_two.push(factor_two * 2);
        queue_three.push(factor_two * 3);
        queue_five.push(factor_two * 5);
    }
    else if (t == factor_three)
    {
        queue_three.pop();
        queue_five.push(factor_three * 5);
        queue_three.push(factor_three * 3);
    }
    else
    {
        queue_five.pop();
        queue_five.push(factor_five * 5);
    }
    rlt = t;
}
cout << rlt << endl;
return 0 ;
*/
