//
// Created by olga on 28.05.19.
//

#include <iostream>

int main(){

	int number_rolls;
	int finish_summ;
	std::cin >> number_rolls >> finish_summ;

	double cur_summ[finish_summ+1];
	double prev_summ[finish_summ+1];

	for (int i = 0; i < finish_summ + 1; ++i) {
		cur_summ[i] = 0;
		prev_summ[i] = 0;
	}
	prev_summ[0] = 1;


	for (int roll = 0; roll < number_rolls; ++roll) {
		for (int summ_i = 0; summ_i < finish_summ + 1; ++summ_i) {
			if (prev_summ[summ_i] == 0)
				continue;
			for (int res_roll = 1; res_roll < 7; ++res_roll) {
				if (res_roll + summ_i < finish_summ+1)
					cur_summ[summ_i+res_roll] += 1.0/6*prev_summ[summ_i];
			}
		}
		for (int i = 0; i < finish_summ+1; ++i) {
			prev_summ[i] = cur_summ[i];
			cur_summ[i] = 0;
		}
	}

	std::cout << prev_summ[finish_summ];

	return 0;
}

