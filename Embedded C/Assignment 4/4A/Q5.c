//convert the give time from hh:mm:ss to seconds or vice versa
// PRN: 260240130005 and 260240130032

#include <stdio.h>

long toSeconds(int h, int m, int s){
	return (h*3600)+(m*60)+(s); //multiply each with respective multiplier for how many seconds in an hour minute then ass the seconds variable
}

void toStandardFormat(long sec){
	int h, m, s;
	h = sec / 3600; //how many hours sum up from the input seconds
	m = (sec - (h*3600)) / 60; //total seconds - number of seconds in the hours we just calculated 
	s = sec - (h*3600) - (m*60);
	printf("hh:mm:ss -> %d : %d : %d\n",h, m, s);
}


int main(){
	int choice;
	printf("Choose how you wish to proceed...\n(Press 1) hh:mm:ss format to total seconds\nOR\n(Press 2) total seconds to hh:mm:ss format\n");
	scanf("%d",&choice);

	if(choice == 1){
		int h,m,s;

		printf("Enter time is this specific format (hh:mm:ss): ");
		scanf("%d:%d:%d",&h,&m,&s);

		printf("Total seconds = %ld\n",toSeconds(h,m,s));
	} else if(choice == 2){
		long sec;

		printf("Enter time is seconds: \n");
		scanf("%ld", &sec);

		toStandardFormat(sec);
	}else {
		printf("Wrong Choice!!\n");
		return 0;
	}

	return 0;
}
