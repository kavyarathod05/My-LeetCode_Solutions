#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto it : tasks) {
            mp[it]++;
        }

        // Your exact Min-Heap: sorts primarily by available_time ascending
        priority_queue<
            pair<int, pair<int, char>>, 
            vector<pair<int, pair<int, char>>>, 
            greater<pair<int, pair<int, char>>>
        > pq;

        for(auto it : mp) {
            // Push {available_time, {frequency, task}}
            pq.push({0, {it.second, it.first}}); 
        }

        int cnt = 0;

        while(!pq.empty()) {
            // 1. Fast-forward time if the earliest task isn't ready yet
            if(cnt < pq.top().first) {
                cnt = pq.top().first;
            }

            // 2. Pull OUT all tasks that are ready to run right now (available_time <= cnt)
            vector<pair<int, pair<int, char>>> ready_tasks;
            while(!pq.empty() && pq.top().first <= cnt) {
                ready_tasks.push_back(pq.top());
                pq.pop();
            }

            // 3. Find the task with the MAXIMUM frequency among the ready ones
            int best_idx = 0;
            for(int i = 1; i < ready_tasks.size(); i++) {
                if(ready_tasks[i].second.first > ready_tasks[best_idx].second.first) {
                    best_idx = i;
                }
            }

            // 4. Execute the best task
            auto best_task = ready_tasks[best_idx];
            cnt++; // Time moves forward
            int freq = best_task.second.first - 1; // Decrease frequency
            char task = best_task.second.second;

            // If it still has executions left, schedule it for the future
            if(freq > 0) {
                pq.push({cnt + n, {freq, task}});
            }

            // 5. Put the OTHER ready tasks back into the heap untouched
            for(int i = 0; i < ready_tasks.size(); i++) {
                if(i != best_idx) {
                    pq.push(ready_tasks[i]);
                }
            }
        }

        return cnt;
    }
};