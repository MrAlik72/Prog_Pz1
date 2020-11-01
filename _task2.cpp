/*Задание 1____Создать класс для работы с динамическим массивом типа int, хран\ить в совойствах указатель на данные и размер массива, 
реализовать конструктор, получающий на вход размер массива, и деструктор.   
Задание 2______Реализовать сеттер, проверяющий входящее значение на принадлежность к промежутку от -100 до 100 включительно 
и проверяющий выход за границы массива, и геттер, проверяющий выход за границы массива.
Задание 3______Реализовать конструктор копирования.
Задание 4______Реализовать операцию сложения и вычитания для массивов(сложение и вычитание всех элементов).*/
#include<iostream>

using namespace std;


class dynamic_array
{
 private:
    int m_size;//размер массива
    int m_capacity;//вместимость
   int * m_data;//указатель на данные

 public:
    dynamic_array()
    {
        m_size = 0;
        m_capacity = 0;
        m_data = NULL;
    }
    dynamic_array(dynamic_array  &a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = NULL;
        if (m_size != 0)
            m_data = new int[m_size];
        else
            m_data = 0;
        for (int i = 0; i < m_size; ++i)
            m_data[i] = a.m_data[i];
    }
 /*   dynamic_array(const dynamic_array& copy)
{
	m_data = new int[copy.m_size];
	for (int i = 0; i < copy.m_size; i++)
		m_data[i] = copy.m_data[i];
	m_size = copy.m_size;
}*/

    dynamic_array(int size)
    {
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new int[size];
        else
            m_data = 0;
    }

    ~dynamic_array()
    {
        if (m_data)
            delete[] m_data;
    }

    int resize(int size)
    {
        if (size > m_capacity)
        {
            int new_capacity = max(size, m_size * 2);
           int * new_data = new int[new_capacity];
            for (int i = 0; i < m_size; ++i)
                new_data[i] = m_data[i];
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = size;
    }

    void push_back(int val)
    {
        resize(m_size + 1);
        m_data[m_size - 1] = val;
    }
    int size() const
    {
        return m_size;
    }
   int & operator[] (int i)
    {
        return m_data[i];
    }

/* VL*/int getarr(int i)
{
	if (i < m_size) 
		return m_data[i];
	return -1;
}

/* VL*/void setarr(int i, int value)
{
	if (i < m_size && value > 0 && value <= 100)
		m_data[i] = value;
	else
		cout << "wrong " << endl;
}

/* VL*/void sum(dynamic_array& stream)
{
	int tempm_size = (m_size > stream.m_size ? stream.m_size : m_size);
	for (int i = 0; i < tempm_size; i++)
		m_data[i] += stream.m_data[i];
}

/* VL*/void sub(dynamic_array& stream)
{
	int tempm_size = (m_size > stream.m_size ? stream.m_size : m_size);
	for (int i = 0; i < tempm_size; i++)
		m_data[i] -= stream.m_data[i];
}
/* VL*/void show()

{	for (int i = 0; i < m_size; i++)
		cout << m_data[i] << " ";
	cout << endl;
}
};
int main(){
    int a_i;
    int b_i;
    cin >> a_i >> b_i;
    dynamic_array a(a_i);
    dynamic_array b(b_i);
    
   /* cout << a.getarr(0) << endl;
	a.setarr(0, 32);
  cout<<a.size()<<" "<< b.size()<<endl;  
    b.show();
    a.show();
    a.sum(b); 
    b.sub(a);
    a.show();*/
    a.show();
    cout<<'43'<<endl;
    a.push_back(3);
    cout<<'28'<<endl;
     a.show();
}


