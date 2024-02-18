class Solution {
public:
    typedef long long int ll;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        unordered_map<ll,ll>usedRoom;
        priority_queue<ll,vector<ll>,greater<ll>>roomAvail;

        // pair<int,int> => pair<endTime,roomNo> 
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>roomMeetExce;

        for(int i=0;i<n;i++){
            roomAvail.push(i);
        }

        for(auto it:meetings){
            ll st = it[0];
            ll ed = it[1];

            while(!roomMeetExce.empty() && roomMeetExce.top().first <=st){ // If any exisiting metting room can be end up before starting this current meeting
                roomAvail.push(roomMeetExce.top().second);
                roomMeetExce.pop();
            }

            // Room Available 
            if(!roomAvail.empty()){ // If room availabe choose, smallest one from the group
                roomMeetExce.push({ed,roomAvail.top()});
                usedRoom[roomAvail.top()]++;
                roomAvail.pop();
            }
            else{ // If not room available 
                auto exRoom = roomMeetExce.top();roomMeetExce.pop();
                ll roomId = exRoom.second;
                ll endTime = exRoom.first;
                ll currExTime = ed-st;

                roomMeetExce.push({endTime+currExTime,roomId});
                usedRoom[roomId]++;
            }   
            
        }

        ll ans =0;
        ll maxiOccur = 0;

        for(auto it:usedRoom){
            if(it.second>maxiOccur){
                maxiOccur = it.second;
                ans = it.first;
            }
            else if(it.second==maxiOccur){
                ans = min(ans,it.first);
            }
        }

        return ans;
    }
};