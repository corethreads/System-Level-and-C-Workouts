#include <stdio.h>


int main(void){
	float score;
	char grade;
	

	printf("Enter Score Sir: ");
	scanf("%f", &score);

	//Error handling
	if(score < 0.00f || score > 100.00f){
		printf("Score must be between(0-100)\n");
		return 1;
	}

	if(score >= 80.00)
		grade = 'A';
	else if(score >= 60.00)
		grade = 'B';
	else if(score >= 40)
		grade = 'C';
	else if(score >= 20)
		grade = 'D';
	else 
		grade = 'E';


	if (grade == 'A')
		printf("You Passed.Wow!!\n");
	else if(grade == 'B')
		printf("Average\n");
	else if(grade == 'C')
		printf("Below Average");
	else if(grade == 'D')
		printf("Failed!");
	else 
		printf("Get out of this School");

}
