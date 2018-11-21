// Lab7-tdine.h
// Trevor Dine
// COSC 2030
// 17 November 2018
// Lab 7

#include "Lab7-tdine.h";

int main()
{
	vector<int> testVec;

	for (int i = 1; i <= 2000000; i++)
	{
		testVec.push_back(randInt(1, 500));
	}
	/*
	cout << "Starting vector for the sort: ";

	for (int i = 0; i < testVec.size(); i++)
	{
		cout << testVec[i] << " ";
	}

	cout << endl;
	*/
	cout << "Sorting..." << endl;
	Timer time;

	time.start();
	mergeSort(testVec, 0, testVec.size() - 1);
	time.stop();
	/*
	cout << "Vector after the sort: ";

	for (int i = 0; i < testVec.size(); i++)
	{
		cout << testVec[i] << " ";
	}

	cout << endl;*/
	cout << "Sorted in " << time() << " seconds" << endl;

	system("pause");
	return 0;
}