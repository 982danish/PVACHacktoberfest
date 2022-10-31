// C# program to compute factorial of big numbers
using System;

class GFG {

	static void factorial(int n)
	{
		int[] res = new int[500];

		res[0] = 1;
		int res_size = 1;

		for (int x = 2; x <= n; x++)
			res_size = multiply(x, res, res_size);

		Console.WriteLine("Factorial of "
						+ "given number is ");
		for (int i = res_size - 1; i >= 0; i--)
			Console.Write(res[i]);
	}

	static int multiply(int x, int[] res, int res_size)
	{
		int carry = 0; // Initialize carry

		for (int i = 0; i < res_size; i++) {
			int prod = res[i] * x + carry;
			res[i] = prod % 10; // Store last digit of
			carry = prod / 10; // Put rest in carry
		}

		while (carry != 0) {
			res[res_size] = carry % 10;
			carry = carry / 10;
			res_size++;
		}
		return res_size;
	}

	static public void Main() { factorial(100); }
}

