class StockSpanner {
public:
    vector<int> list;
    stack<pair<int,int>> st;
    int index=-1;
    StockSpanner() {
    }
    int next(int price) {
        // list.push_back(price);
        // int cnt = 0;
        // for (int i = list.size() - 1; i >= 0; i--) {
        //     if (list[i] <= price) {
        //         cnt++;
        //     } else {
        //         break;
        //     }
        // }
        // return cnt;
        index++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        return ans;
    }
};