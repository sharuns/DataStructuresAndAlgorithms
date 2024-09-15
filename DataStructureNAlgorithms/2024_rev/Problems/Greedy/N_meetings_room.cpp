 #include<iostream>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 
 static bool cmp(pair<int,int> a, pair<int,int> b)
 {
        return a.second < b.second;
     
 }
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> meetings;
        for(int i = 0 ; i < n; i++)
        {
            pair<int,int> p = make_pair(start[i],end[i]);
            meetings.push_back(p);
        }
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        int mCount = 1;
        
        int ansEnd = meetings[0].second;
        for(int i = 1; i <n ; i++)
        {
            if(meetings[i].first > ansEnd)
            {
                mCount++;
                ansEnd = meetings[i].second;
            }
        }
        
        return mCount;
    }
    
    int main()
    {
        int n = 6;
        int start[] = {1, 3, 0, 5, 8, 5};
        int end[] =  {2, 4, 6, 7, 9, 9};
        cout << "max: " << maxMeetings(n,start,end) << endl;
        
    }
    }