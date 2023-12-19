class Solution
{
private:
    vector<int> nextSmallerElement(int n, vector<int> &heights)
    {
        vector<int> next(n);
        stack<int> elements;
        elements.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (elements.top() != -1 && heights[elements.top()] >= curr)
            {
                elements.pop();
            }
            next[i] = elements.top();
            elements.push(i);
        }

        return next;
    }

private:
    vector<int> prevSmallerElement(int n, vector<int> &heights)
    {
        vector<int> prev(n);
        stack<int> elements;
        elements.push(-1);
        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while (elements.top() != -1 && heights[elements.top()] >= curr)
            {
                elements.pop();
            }
            prev[i] = elements.top();
            elements.push(i);
        }

        return prev;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(n, heights);
        vector<int> prev(n);
        prev = prevSmallerElement(n, heights);
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            cout << l << b << endl;
            int area = l * b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
        // Fixed Error
    }
};