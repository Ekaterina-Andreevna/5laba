#include <iostream>
using namespace std;

// Дан массив размера N. Определить количество участков, на которых его элементы 
// монотонно убывают.Участок должен состоять из не менее, чем трех элементов.

int main()

{
    setlocale(LC_ALL, "");
    unsigned int size;



    cout << "Введите размер массива" << endl;
    cin >> size;


    int* array = new int[size];

    for (int i = 0; i < size; i++) {

        array[i] = rand() % 100;


        cout << "array[" << i << "] = " << array[i] << "\n";
    }

    //работа с массивом


    unsigned int count = 0; //кол-во подряд убывающих значений
    unsigned int segments = 0; //кол-во участков убывания

    bool Flag = true; // заходили ли мы в условие (1)



    unsigned int start = 0;
    for (unsigned int i = 1; i < size; ++i) {



        if (array[i] < array[i - 1]) {
            if (count == 0) {
                start = i;
            }

            ++count;

            //условие (1)
            if (count > 2 && Flag) {
                ++segments;
                Flag = false;
            }
        }
        else {
            if (!Flag) {
                for (int j = start; j < start + count; ++j) {
                    cout << array[j] << " ";
                }
                cout << endl;
            }



            count = 0;
            Flag = true;
        }


    }

    if (count > 2) {
        for (int i = start; i < start + count; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }


    cout << "Кол-во сегментов: " << segments << endl;





    delete[] array;

}