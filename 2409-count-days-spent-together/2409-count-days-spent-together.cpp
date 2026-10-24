class Solution {
    int dateToDayNumber (string date) {
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3, 2));

        vector<int> dayInMonth = {31, 28,31,30, 31, 30, 31, 31, 30, 31, 30, 31};
        int dayOfYear = day;
        for(int i = 0; i< month -1; i++){
            dayOfYear += dayInMonth[i];
        }
        return dayOfYear;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrAlice = dateToDayNumber(arriveAlice);
        int depAlice = dateToDayNumber(leaveAlice);
        int arrBob = dateToDayNumber(arriveBob);
        int depBob = dateToDayNumber(leaveBob);

        int latestArrival = max(arrAlice, arrBob);
        int earliestDeparture = min(depAlice, depBob);

        if (latestArrival <= earliestDeparture) {
            return earliestDeparture - latestArrival + 1;
        }
        return 0;
    }
};