  #include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <sys/time.h>
#include <algorithm>
using namespace std;
using namespace std ::chrono;
struct organization
{
    string Index, Founder;
    int numberEmploy;
    string Organize, Name, Website, Country, Description, Industry;
};

long getTime()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

class Organization
{
public:
    vector<organization> data;
    organization input(string Index, string Founder, int numberEmploy, string Organize, string Name, string Website, string Country, string Description, string Industry)
    {
        organization object;
        object.Index = Index;
        object.Founder = Founder;
        object.numberEmploy = numberEmploy;
        object.Organize = Organize;
        object.Name = Name;
        object.Website = Website;
        object.Country = Country;
        object.Description = Description;
        object.Industry = Industry;
        return object;
    }
    void insertData(organization object)
    {
        data.push_back(object);
    }

    string getParse(string data, int field)
    {
        int commaCount = 1;
        string line;
        for (int x = 0; x < data.size(); x++)
        {
            if (data[x] == ',')
            {
                commaCount = commaCount + 1;
            }
            else if (commaCount == field)
            {
                line = line + data[x];
            }
        }
        return line;
    }

    int convert_to_int(string var)
    {
        stringstream ss;
        int num;
        ss << var;
        ss >> num;
        return num;
    }

    bool putDataIntoCVS(string path)
    {
        fstream file;
        file.open(path, ios::out);
        if (file.is_open())
        {
            file << "Index"
                 << ","
                 << "Organization"
                 << ","
                 << "Name"
                 << ","
                 << "Website"
                 << ","
                 << "Country"
                 << ","
                 << "Description"
                 << ","
                 << "Founder"
                 << ","
                 << "Industry"
                 << ","
                 << "Number Of Employee" << endl;
            for (int i = 0; i < data.size(); i++)
            {
                file << data[i].Index << "," << data[i].Organize << "," << data[i].Name << "," << data[i].Website << "," << data[i].Country << "," << data[i].Description << "," << data[i].Founder << "," << data[i].Industry << "," << data[i].numberEmploy << endl;
            }
            file.close();
            return true;
        }
        else
        {
            return false;
        }
    }

    bool loadData(string path)
    {
        string Index, Founder, numberEmploy;
        string Organize, Name, Website, Country, Description, Industry;
        int count = 0;
        fstream file;
        file.open(path, ios::in);
        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {
                if (count == 0)
                {
                    count = 1;
                    continue;
                }
                else if (count >= 1)
                {
                    // getline(file, line);
                    Index = getParse(line, 1);
                    Organize = getParse(line, 2);
                    Name = getParse(line, 3);
                    Website = getParse(line, 4);
                    Country = getParse(line, 5);
                    Description = getParse(line, 6);
                    Founder = getParse(line, 7);
                    Industry = getParse(line, 8);
                    numberEmploy = getParse(line, 9);
                    int number_of_employee = convert_to_int(numberEmploy);
                    organization object = input(Index, Founder, number_of_employee, Organize, Name, Website, Country, Description, Industry);
                    insertData(object);
                    count++;
                }
            }
            return true;
        }
        else
            return false;
    }

    void display(vector<organization> data)
    {
        cout << "Index"
             << ","
             << "Organization"
             << ","
             << "Name"
             << ","
             << "Website"
             << ","
             << "Country"
             << ","
             << "Description"
             << ","
             << "Founder"
             << ","
             << "Industry"
             << ","
             << "Number Of Employee" << endl;

        cout << "=====================================================================================================================================================================================================" << endl;
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i].Index << "," << data[i].Organize << "," << data[i].Name << "," << data[i].Website << "," << data[i].Country << "," << data[i].Description << "," << data[i].Founder << "," << data[i].Industry << "," << data[i].numberEmploy << endl;
        }
    }

    bool isUnique()
    {
        int num1, num2;
        stringstream ss1, ss2;
        for (int i = 0; i < data.size(); i++)
        {
            ss1 << data[i].Founder;
            ss1 >> num1;
            ss2 << data[i + 1].Founder;
            ss2 >> num2;
            if (num1 == num2)
                return false;
        }
        return true;
    }

    void bubble_sort()
    {
        for (int x = 0; x < data.size() - 1; x++)
        {
            for (int y = 0; y < data.size() - x - 1; y++)
            {
                if (data[y].numberEmploy > data[y + 1].numberEmploy)
                {
                    swap(data[y], data[y + 1]);
                }
            }
        }
    }

    int findMinimum(vector<organization> &arr, int start, int end)
    {
        int min = arr[start].numberEmploy;
        int minIndex = start;
        for (int i = start; i < end; i++)
        {
            if (min > arr[i].numberEmploy)
            {
                min = arr[i].numberEmploy;
                minIndex = i;
            }
        }
        return minIndex;
    }

    void Selection_sort()
    {
        for (int x = 0; x < data.size() - 1; x++)
        {
            int minIndex = findMinimum(data, x, data.size());
            swap(data[x], data[minIndex]);
        }
    }

    void Insertion_sort()
    {
        for (int i = 1; i < data.size(); i++)
        {
            int key = data[i].numberEmploy;
            int j = i - 1;
            while (j >= 0 && data[j].numberEmploy > key)
            {
                swap(data[j + 1], data[j]);
                j--;
            }
            data[j + 1].numberEmploy = key;
        }
    }
};

void systemCLS()
{
    cout << "\n\n";
    cout << "\t\tPress Any Key To Continue...." << endl;
    char x;
    cin >> x;
    cout << "\n\n";
    cout << "\t\t\tLoding..." << endl;
    Sleep(1000);
    system("cls");
}

void display_array(vector<organization> data)
{
    cout << "Index"
         << ","
         << "Organization"
         << ","
         << "Name"
         << ","
         << "Website"
         << ","
         << "Country"
         << ","
         << "Description"
         << ","
         << "Founder"
         << ","
         << "Industry"
         << ","
         << "Number Of Employee" << endl;

    cout << "=====================================================================================================================================================================================================" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].Index << "," << data[i].Organize << "," << data[i].Name << "," << data[i].Website << "," << data[i].Country << "," << data[i].Description << "," << data[i].Founder << "," << data[i].Industry << "," << data[i].numberEmploy << endl;
    }
}

void merge(vector<organization> &arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    queue<organization> temp;
    while (i <= mid && j <= end)
    {
        if (arr[i].numberEmploy < arr[j].numberEmploy)
        {
            temp.push(arr[i]);
            i++;
        }
        else
        {
            temp.push(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push(arr[j]);
        j++;
    }
    for (int x = start; x <= end; x++)
    {
        arr[x] = temp.front();
        temp.pop();
    }
}

void Merge_sort(vector<organization> &data, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        Merge_sort(data, start, mid);
        Merge_sort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}
bool putDataIntoCVS(string path, vector<organization> data)
{
    fstream file;
    file.open(path, ios::out);
    if (file.is_open())
    {
        file << "Index"
             << ","
             << "Organization"
             << ","
             << "Name"
             << ","
             << "Website"
             << ","
             << "Country"
             << ","
             << "Description"
             << ","
             << "Founder"
             << ","
             << "Industry"
             << ","
             << "Number Of Employee" << endl;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].numberEmploy != 0)
                file << data[i].Index << "," << data[i].Organize << "," << data[i].Name << "," << data[i].Website << "," << data[i].Country << "," << data[i].Description << "," << data[i].Founder << "," << data[i].Industry << "," << data[i].numberEmploy << endl;
            else
                break;
        }

        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

int main_menu()
{
    cout << "\n\n";
    cout << "\t\t\t1. Bubble Sort" << endl;
    cout << "\t\t\t2. Selection Sort" << endl;
    cout << "\t\t\t3. Insertion Sort" << endl;
    cout << "\t\t\t4. Merge Sort" << endl;
    cout << "\t\t\t5. Quick sort" << endl;
    cout << "\t\t\t6. Heap Sort" << endl;
    cout << "\t\t\t7. Counting Sort" << endl;
    cout << "\t\t\t8. Redix Sort" << endl;
    cout << "\t\t\t9. Bucket Sort" << endl;
    cout << "\t\t\t0. Exit" << endl;
    int opt;
    cout << "\n\tYour Option : ";
    cin >> opt;
    return opt;
}

// ------------------------- Quick Sort ---------------------------------
int partition(vector<organization> &arr, int start, int end, int pivot)
{
    int left = start;
    int right = end;
    while (left <= right)
    {
        while (arr[left].numberEmploy < arr[pivot].numberEmploy && left <= end)
            left++;
        while (arr[right].numberEmploy >= arr[pivot].numberEmploy && right >= start)
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[right], arr[pivot]);
    return right;
}

void quickSort(vector<organization> &arr, int start, int end)
{
    if (start < end)
    {
        int pivot = start;
        int mid = partition(arr, start + 1, end, pivot);
        cout << endl;
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
}

// ------------------------- Quick Sort ---------------------------------

// ------------------------- Heap Sort ----------------------------------

int parentIndex(int i)
{
    return (i - 1) / 2;
}
int leftChildIndex(int i)
{
    return (2 * i) + 1;
}
int rightChildIndex(int i)
{
    return (2 * i) + 2;
}

void heapify(vector<organization> &heapArr, int size, int index)
{
    int maxIndex;
    while (true)
    {
        int lIdx = leftChildIndex(index);
        int rIdx = rightChildIndex(index);
        if (rIdx >= size)
        {
            if (lIdx >= size)
                return;
            else
                maxIndex = lIdx;
        }
        else
        {
            if (heapArr[lIdx].numberEmploy >= heapArr[rIdx].numberEmploy)
                maxIndex = lIdx;
            else
                maxIndex = rIdx;
        }
        if (heapArr[index].numberEmploy < heapArr[maxIndex].numberEmploy)
        {
            swap(heapArr[index], heapArr[maxIndex]);
            index = maxIndex;
        }
        else
            return;
    }
}

int heapSort(vector<organization> &heapArr, int size)
{
    for (int x = (size / 2) - 1; x >= 0; x--)
    {
        heapify(heapArr, size, x);
    }
    for (int x = size - 1; x > 0; x--)
    {
        swap(heapArr[0], heapArr[x]);
        heapify(heapArr, x, 0);
    }
}

// ------------------------- Heap Sort ----------------------------------

// ------------------------- Counting Sort ------------------------------

int findMaximium(vector<organization> arr)
{
    double min = arr[0].numberEmploy;
    for (int i = 0; i < arr.size(); i++)
    {
        if (min < arr[i].numberEmploy)
        {
            min = arr[i].numberEmploy;
        }
    }
    return min;
}

vector<organization> countSort(vector<organization> &arr)
{
    int max = findMaximium(arr);
    vector<int> count(max + 1);
    vector<organization> output(count.size());
    for (int x = 0; x < arr.size(); x++)
    {
        count[arr[x].numberEmploy]++;
    }
    for (int x = 1; x < count.size(); x++)
    {
        count[x] = count[x - 1] + count[x];
    }
    for (int x = arr.size() - 1; x >= 0; x--)
    {
        int index = count[arr[x].numberEmploy] - 1;
        count[arr[x].numberEmploy]--;
        output[index] = arr[x];
    }
    return output;
}
// ------------------------- Counting Sort ------------------------------

// ------------------------- Redix Sort ---------------------------------

void countingSort(vector<organization> &arr, int place)

{

    vector<int> count(10);
    vector<organization> output(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        count[(arr[i].numberEmploy / place) % 10]++;
    }
    for (int x = 1; x < count.size(); x++)
    {
        count[x] = count[x - 1] + count[x];
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int index = count[(arr[i].numberEmploy / place) % 10] - 1;
        count[(arr[i].numberEmploy / place) % 10]--;
        output[index] = arr[i];
    }
    for (int i = 0; i < output.size(); i++)
    {
        arr[i] = output[i];
    }
}

void redixSort(vector<organization> &arr)
{
    int max = findMaximium(arr);
    int place = 1;
    while ((max / place) > 0)
    {
        countingSort(arr, place);
        place = place * 10;
    }
}

// ------------------------- Redix Sort ---------------------------------

// ------------------------ Bucket Sort --------------------------------

void bubbleSort(vector<organization> data)
    {
        for (int x = 0; x < data.size() - 1; x++)
        {
            for (int y = 0; y < data.size() - x - 1; y++)
            {
                if (data[y].numberEmploy > data[y + 1].numberEmploy)
                {
                    swap(data[y], data[y + 1]);
                }
            }
        }
    }

void bucketSort(vector<organization> arr)
{

    int const n = arr.size();
    vector<organization> b[n];
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i].numberEmploy; // Index in bucket
        try
        {
            b[bi].push_back(arr[i]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    for (int i = 0; i < n; i++)
        bubbleSort(b[i]);
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
//===============================================================

}

//==================================================================

int main()
{

    Organization obj;
    int menu;
    if (obj.loadData("organizations-100.csv"))
    {
        //        obj.display();

        do
        {
            menu = main_menu();
            if (menu == 1)
            {
                long start = getTime();
                obj.bubble_sort();
                long end = getTime();
                obj.putDataIntoCVS("New_OrganizationReport_100_BUBBLE_SORT.csv") ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "Bubble Sort Takes"
                     << " " << end - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
            if (menu == 2)
            {
                long start = getTime();
                obj.Selection_sort();
                long end = getTime();
                obj.putDataIntoCVS("New_OrganizationReport_100_SELECTION_SORT.csv") ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "Selection Sort Takes"
                     << " " << end - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
            if (menu == 3)
            {
                long start = getTime();
                obj.Insertion_sort();
                long end = getTime();
                obj.putDataIntoCVS("New_OrganizationReport_100_INSERTION_SORT.csv") ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "Insersion Sort Takes"
                     << " " << end - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
            if (menu == 4)
            {
                vector<organization> array = obj.data;
                int start = 0;
                int end = obj.data.size() - 1;
                long start1 = getTime();
                Merge_sort(array, start, end);
                long end1 = getTime();
                putDataIntoCVS("New_OrganizationReport_100_MERGE_SORT.csv", array) ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "Merge Sort Takes"
                     << " " << end1 - start1 << " "
                     << "milliseconds in execution" << endl;

                systemCLS();
            }
            if (menu == 5)
            {
                // Quick sort
                vector<organization> array = obj.data;
                long start = getTime();
                quickSort(array, 0, array.size() - 1);
                long end1 = getTime();
                putDataIntoCVS("New_OrganizationReport_100_Quick_SORT.csv", array) ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "\tQuick Sort Takes"
                     << " " << end1 - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
            if (menu == 6)
            {
                // heap sort
                vector<organization> array = obj.data;
                long start = getTime();
                heapSort(array, array.size());
                long end1 = getTime();
                putDataIntoCVS("New_OrganizationReport_100_Heap_SORT.csv", array) ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "\tHeap Sort Takes"
                     << " " << end1 - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
            if (menu == 7)
            {
                // Counting sort
                vector<organization> array = obj.data;
                long start = getTime();
                vector<organization> temp = countSort(array);
                long end1 = getTime();
                putDataIntoCVS("New_OrganizationReport_100_countSOrt_SORT.csv", temp) ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "\tcount Sort Takes"
                     << " " << end1 - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
            if (menu == 8)
            {
                // Redix sort
                vector<organization> array = obj.data;
                long start = getTime();
                redixSort(array);
                long end1 = getTime();
                putDataIntoCVS("New_OrganizationReport_100_redix_SORT.csv", array) ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "\tRedix Sort Takes"
                     << " " << end1 - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
            if (menu == 9)
            {
                // Bucket sort
                vector<organization> array = obj.data;
                long start = getTime();
                bucketSort(array);
                long end1 = getTime();
                putDataIntoCVS("New_OrganizationReport_100_Bucket_SORT.csv", array) ? cout << "New Data Has Been Inserted" : cout << "Sorry" << endl;
                cout << "\tBucket Sort Takes"
                     << " " << end1 - start << " "
                     << "milliseconds in execution" << endl;
                systemCLS();
            }
        } while (menu != 0);
    }
    else
        cout << "NOT OK";

    return 0;
}