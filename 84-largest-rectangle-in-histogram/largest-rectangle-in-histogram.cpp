class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> PSE(n);
        vector<int> NSE(n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                PSE[i] = -1;
            else
                PSE[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                NSE[i] = n;
            else
                NSE[i] = st.top();

            st.push(i);
        }

        // Calculate maximum area
        int largest = 0;

        for (int i = 0; i < n; i++) {

            int width = NSE[i] - PSE[i] - 1;

            int area = heights[i] * width;

            largest = max(largest, area);
        }

        return largest;
    }
};