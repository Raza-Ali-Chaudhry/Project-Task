#pragma once
template <class T>
class Matrix
{
private:
	 int row;
	 int col;
	 T **data;
public:
	Matrix();
	Matrix(int r, int c);
	void add(T);
	void add(int, int, T);
	void add(Matrix<T> &);
	void subtract(T);
	void subtract(int, int, T);
	void subtract(Matrix<T> &);
	void multiply(T);
	void multiply(int, int, T);
	void multiply(Matrix<T> &);
	void divide(T);
	void divide(int, int, T);
	void set(int, int, T);
	int get(int, int);
	void print();
	Matrix operator+(T);
	Matrix operator-(T);
	Matrix operator*(T);
	Matrix operator/(T);
	Matrix  operator+(Matrix<T> &);
	Matrix operator-(Matrix<T> &);
	Matrix operator*(Matrix<T> &);
	void operator+=(T);
	void operator-=(T);
	void  operator*=(T);
	void operator/=(T);
	void operator++(T);
	void operator--(T);
	void operator=(Matrix<T> &);
	bool operator==(Matrix<T> &);
	friend Matrix<T> operator+(T x, Matrix<T> & m);
	friend Matrix<T> operator-(T x, Matrix<T> & m);
	friend Matrix<T> operator*(T x, Matrix<T> & m);
	friend Matrix<T> operator/(T x, Matrix<T> & m);
    friend stream& operator<<(ostream & out, Matrix<T> & m)
	{
		for (int i = 0; i < m.row; i++)
		{
			for (int j = 0; j < m.col; j++)
				out << m.data[i][j] << "   ";
			out << endl;
		}
		return out;
	}
};
template <class T>
void Matrix<T>::operator=(Matrix<T> & m)
{
	if (col != m.col || row != m.row)
	{
		cout << "invalid!" << endl;
		return;
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] = m.data[i][j];
}
template <class T>
bool Matrix<T>::operator==(Matrix<T> & m)
{
	if (row != m.row || col != m.col)
		return 0;
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			if (m.data[i][j] == data[i][j])
				;
			else
				return 0;
		}
	}
	return 1;
}
template <class T>
void Matrix<T>::operator++(T)
{
	add(1);
}
template <class T>
void Matrix<T>::operator--(T)
{
	subtract(1);
}
template <class T>
Matrix<T> operator+(T x, Matrix<T> & m)
{
	Matrix<T> temp(m.row, m.col);
	for (int i = 0; i < m.row; i++)
		for (int j = 0; j < m.col; j++)
			temp.data[i][j] = m.data[i][j] + x;
	return temp;
}
template <class T>
Matrix<T> operator-(T x, Matrix<T> & m)
{
	Matrix<T> temp(m.row, m.col);
	for (int i = 0; i < m.row; i++)
		for (int j = 0; j < m.col; j++)
			temp.data[i][j] = m.data[i][j] - x;
	return temp;
}
template <class T>
Matrix<T> operator*(T x, Matrix<T> & m)
{
	Matrix<T> temp(m.row, m.col);
	for (int i = 0; i < m.row; i++)
		for (int j = 0; j < m.col; j++)
			temp.data[i][j] = m.data[i][j] * x;
	return temp;
}
template <class T>
Matrix<T> operator/(T x, Matrix<T> & m)
{
	Matrix<T> temp(m.row, m.col);
	for (int i = 0; i < m.row; i++)
		for (int j = 0; j < m.col; j++)
			temp.data[i][j] = m.data[i][j] / x;
	return temp;
}
template <class T>
Matrix<T> Matrix<T>::operator+(T n)
{
	Matrix temp(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = data[i][j] + n;
	
	return temp;
}
template <class T>
Matrix<T> Matrix<T>::operator-(T n)
{
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = data[i][j] - n;
	return temp;
}
template <class T>
Matrix<T> Matrix<T>::operator*(T n)
{
	Matrix<T> temp;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = data[i][j] * n;

	return temp;
}
template <class T>
Matrix<T> Matrix<T>::operator/(T n)
{
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = data[i][j] / n;
	return temp;
}
template <class T>
Matrix<T>  Matrix<T>::operator+(Matrix & input)
{
	if (col != input.col || row != input.row)
	{
		cout << "invalid no. of rows or columns!" << endl;
		return input;
	}
	Matrix<T> temp(col,row);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = data[i][j] + input.data[i][j];
	return temp;
}
template <class T>
Matrix<T>  Matrix<T>::operator-(Matrix<T> & input)
{
	if (col != input.col || row != input.row)
	{
		cout << "invalid no. of rows or columns!" << endl;
		return input;
	}
	Matrix<T> temp(col, row);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = data[i][j] - input.data[i][j];
	return temp;
}

template <class T>
Matrix<T>  Matrix<T>::operator*(Matrix<T> & in)
{
	if (col != in.row)
	{
		cout << "invalid no. of rows or columns!" << endl;
		return in;
	}
	Matrix<T> temp(row, in.col);
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < in.col; j++)
		{
			sum = 0;
			for (int k = 0; k < col; k++)
				sum += data[i][k] * in.data[k][j];

			temp.data[i][j] = sum;
		}
	}
	return temp;
}
template <class T>
void Matrix<T>::operator+=(T n)
{
	add(n);
}
template <class T>
void Matrix<T>::operator-=(T n)
{
	subtract(n);
}
template <class T>
void  Matrix<T>::operator*=(T n)
{
	multiply(n);
}
template <class T>
void Matrix<T>::operator/=(T n)
{
	divide(n);
}
template <class T>
void Matrix<T>::set(int x, int y, T v)
{
	data[x][y] = v;
}
template <class T>
int Matrix<T>::get(int x, int y)
{
	return data[x][y];
}
template <class T>
void Matrix<T>::multiply(Matrix<T> & in)
{
	Matrix<T> temp(row, in.col);
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < in.col; j++)
		{
			sum = 0;
			for (int k = 0; k < col; k++)
				sum += data[i][k] * in.data[k][j];

			temp.data[i][j] = sum;
		}
	}
	delete data;
	row = row;
	col = in.col;
	data = new int*[row];
	for (int i = 0; i < row; i++)
		data[i] = new int[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < in.col; j++)
			data[i][j] = temp.data[i][j];
}
template <class T>
Matrix<T>::Matrix()
{
	row = 2;
	col = 2;
	data = new int*[row];
	for (int i = 0; i < row; i++)
		data[i] = new int[col];
}
template <class T>
Matrix<T>::Matrix(int r, int c)
{
	if (r < 0 || c < 0)
	{
		cout << "invalid no. of rows or columns!" << endl;
		return;
	}
	row = r;
	col = c;

	data = new int*[r];

	for (int i = 0; i < r; i++)
		data[i] = new int[c];
}
template <class T>
void Matrix<T>::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << data[i][j] << "   ";
		cout << endl;
	}
}
template <class T>
void Matrix<T>::add(T x)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] += x;
}
template <class T>
void Matrix<T>::add(Matrix<T> &input)
{
	if (row != input.row || col != input.col)
	{
		cout << "invalid!" << endl;
		return;
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] += input.data[i][j];
}
template <class T>
void Matrix<T>::subtract(Matrix<T> &input)
{
	if (row != input.row || col != input.col)
	{	
		cout << "invalid!" << endl;
		return;
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] -= input.data[i][j];
}
template <class T>
void Matrix<T>::add(int r, int c, T val)
{
	if (r < 0 || c < 0)
	{
		cout << "invalid!" << endl;
		return;
	}
	data[r][c] += val;
}
template <class T>
void Matrix<T>::subtract(int r, int c, T val)
{
	if (r < 0 || c < 0)
	{
		cout << "invalid!" << endl;
		return;
	}

	data[r][c] -= val;
}
template <class T>
void Matrix<T>::multiply(int r, int c, T val)
{
	if (r < 0 || c < 0)
	{
		cout << "invalid!" << endl;
		return;
	}
	data[r][c] *= val;
}
template <class T>
void Matrix<T>::divide(int r, int c, T val)
{
	if (r < 0 || c < 0 || val == 0)
	{
		cout << "invalid!" << endl;
		return;
	}
	data[r][c] /= val;
}
template <class T>
void Matrix<T>::subtract(T x)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] -= x;
}
template <class T>
void Matrix<T>::multiply(T x)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] *= x;
}
template <class T>
void Matrix<T>::divide(T x)
{
	if (x == 0)
	{
		cout << "invalid" << endl;
		return;
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] /= x;
}
