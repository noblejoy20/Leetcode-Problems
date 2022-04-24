class UndergroundSystem {
private:
    unordered_map <int,pair<string,int>> entry;
    unordered_map <string,pair<int,int>>exit;
public:
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        if(exit.count(entry[id].first+"_"+stationName)){
            exit[entry[id].first+"_"+stationName].first+=(t-entry[id].second);
            exit[entry[id].first+"_"+stationName].second++;
        }else{
            exit[entry[id].first+"_"+stationName]=make_pair((t-entry[id].second),1);
        }
        entry.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)exit[startStation+"_"+endStation].first/exit[startStation+"_"+endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */