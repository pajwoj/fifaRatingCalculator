#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

void pause() {
    cin.clear();
    cin.ignore(10000, '\n');
    cout<<"Results saved in result.txt..";
    getchar();
}

void cinNewInt(int &value, int min, int max) {
    cin>>value;

    while(!cin.good() || value>max || value<min) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Wrong value (min rating is 81, max rating is 90): ";
        cin>>value;
    }
}

int main() {
    vector<int> ratings;
    ratings.resize(11);
    int price81=600, price82=800, price83=900, price84=3600, price85=7700, price86=13500, price87=21000, price88=28500, price89=37000, price90=50000;
    int price=0;
    int min, max;
    int goalRating;
    cout<<"Input goal rating: ";
    cinNewInt(goalRating, 81, 90);
    cout<<"Input min rating: ";
    cinNewInt(min, 81, 90);
    cout<<"Input max rating: ";
    cinNewInt(max, 81, 90);
    ofstream file("result.txt");

    double sumRating=0;
    double dividedSum=0;
    double totalExcess=0;
    double teamTotal=0;
    double roundedTotal=0;
    double dividedTotal=0;
    double useless=0;
    int roundedDown=0;

    for(int i=0; i<ratings.size(); i++) ratings[i]=min;

    do {
        sumRating=0;
        dividedSum=0;
        totalExcess=0;
        teamTotal=0;
        roundedTotal=0;
        dividedTotal=0;
        useless=0;
        roundedDown=0;
        price=0;

        if(ratings[10]==max) {
            ratings[9]++;
            ratings[10]=min;
        }

        if(ratings[9]==max) {
            ratings[8]++;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[8]==max) {
            ratings[7]++;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[7]==max) {
            ratings[6]++;
            ratings[7]=min;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[6]==max) {
            ratings[5]++;
            ratings[6]=min;
            ratings[7]=min;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[5]==max) {
            ratings[4]++;
            ratings[5]=min;
            ratings[6]=min;
            ratings[7]=min;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[4]==max) {
            ratings[3]++;
            ratings[4]=min;
            ratings[5]=min;
            ratings[6]=min;
            ratings[7]=min;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[3]==max) {
            ratings[2]++;
            ratings[3]=min;
            ratings[4]=min;
            ratings[5]=min;
            ratings[6]=min;
            ratings[7]=min;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[2]==max) {
            ratings[1]++;
            ratings[2]=min;
            ratings[3]=min;
            ratings[4]=min;
            ratings[5]=min;
            ratings[6]=min;
            ratings[7]=min;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        if(ratings[1]==max) {
            ratings[0]++;
            ratings[1]=min;
            ratings[2]=min;
            ratings[3]=min;
            ratings[4]=min;
            ratings[5]=min;
            ratings[6]=min;
            ratings[7]=min;
            ratings[8]=min;
            ratings[9]=min;
            ratings[10]=min;
        }

        for(int i=0; i<ratings.size(); i++) sumRating+=ratings[i];
        dividedSum = sumRating / 11;
        for(int i=0; i<ratings.size(); i++) if(ratings[i]>dividedSum) totalExcess+=ratings[i]-dividedSum;
        teamTotal = totalExcess + sumRating;
        roundedTotal = round(teamTotal);
        dividedTotal = roundedTotal / 11;
        if(modf(dividedTotal, &useless) < 0.5) roundedDown=floor(dividedTotal);
        else roundedDown=0;

        if(roundedDown==goalRating) {
            for(int i=0; i<ratings.size(); i++) {
                file<<ratings[i]<<" ";
                if(ratings[i]==81) price+=price81;
                if(ratings[i]==82) price+=price82;
                if(ratings[i]==83) price+=price83;
                if(ratings[i]==84) price+=price84;
                if(ratings[i]==85) price+=price85;
                if(ratings[i]==86) price+=price86;
                if(ratings[i]==87) price+=price87;
                if(ratings[i]==88) price+=price88;
                if(ratings[i]==89) price+=price89;
                if(ratings[i]==90) price+=price90;
            }
            file<<price<<endl;
        }

        ratings[10]++;

    } while(ratings[0]!=max+1);

    pause();
    file.close();
    return 0;
}