//
//  main.cpp
//  ur
//
//  Created by paul blazhko on 30.09.2024.
//

#include <iostream>
#include <list>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


struct Car
{
    string name;
    int year;
    double price;
    double volume;
    
    void print() const
    {
        cout<<"Название: "<<name<<endl;
        cout<<"Год выпуска: "<<year<<endl;
        cout<<"Обьем"<<volume<<endl;
        cout<<"Цена: "<<price<<endl;
    }
};
class Dealer
{
private:
    vector<Car> cars;
    
public:
    void addCar(const string& name, int year, double volume, double price)
    {
        cars.push_back({name, year, volume, price});
    }
    void deletecar(int index)
    {
        if(index>=0&&index<cars.size())
        {
            cars.erase(cars.begin()+index);
            cout<<"Машина удалена"<<endl;
        }
    }
    void printcars() const
    {
        if(cars.empty())
        {
            cout<<"доступных машин нету"<<endl;
        }
        else
        {
            for(auto& car:cars)
            {
                car.print();
            }
        }
    }
    void sortyear()
    {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b)
        {
            return a.year < b.year;
        });
        cout << "Сортировка по году" << endl;
    }
    void searchname(const string& name) const
    {
        for (const auto& car : cars)
        {
            if (car.name == name)
            {
                car.print();
                return;
            }
        }
        cout << "Машина не нашлась" << endl;
    }
    void sortprice()
    {
        sort(cars.begin(),cars.end(),[](const Car& a, const Car& b)
        {
            return a.price<b.price;
        });
        cout<<"cортировка по цене"<< endl;
    }
    void sortvolume()
    {
        sort(cars.begin(),cars.end(),[](const Car& a,const Car& b)
        {
            return a.volume< b.volume;
        });
        cout<<"сортировка по объему"<<endl;
    }

};

int main()
{
    Dealer dealer;
    int choice;
    
    cout << "Меню: "<<endl;
    cout << "Добавить машину: "<<endl;
    cout << "Удалить машину: "<<endl;
    cout << "Показать машины: "<<endl;
    cout << "Сортировать: "<<endl;
    cout << "Сортировать по цене: "<<endl;
    cout << "Сортировать по объему: "<<endl;
    cout << "Найти по названию: "<<endl;
    cout << "Выберите действие: ";
    cin >> choice;
    
    switch (choice)
    {
        case 1:
        {
            string name;
            int year;
            double volume, price;
            cout << "Hазвание машины: ";
            cin >> name;
            cout << "Год выпуска: ";
            cin >> year;
            cout << "Обьем: ";
            cin >> volume;
            cout << "Цена: ";
            cin >> price;
            dealer.addCar(name, year, volume, price);
            cout << "Машина добавлена" << endl;
            break;
        }
        case 2:
        {
            int index;
            cout << "Введите индекс машины для удаления: ";
            cin >> index;
            dealer.deletecar(index);
            break;
        }
        case 3:
        {
            dealer.printcars();
            break;
        }
        case 4:
        {
            dealer.sortyear();
            dealer.printcars();
            break;
        }
        case 5:
        {
            dealer.sortprice();
            dealer.printcars();
            break;
        }
        case 6:
        {
            dealer.sortvolume();
            dealer.printcars();
            break;
        }
        case 7:
        {
            string name;
            cout << "Название машины для поиска: ";
            cin >> name;
            dealer.searchname(name);
            break;
        }
        default:
            cout<<"Ошибка"<<endl;
            
    }
}
