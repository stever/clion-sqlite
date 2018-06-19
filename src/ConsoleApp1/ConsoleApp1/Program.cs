using System;
using System.Runtime.InteropServices;

namespace ConsoleApp1
{
    internal static class Program
    {
        [DllImport(@"..\..\..\..\..\..\libs\libCLionSQLite.dll")]
        private static extern void hello_library();

        [DllImport(@"..\..\..\..\..\..\libs\libCLionSQLite.dll")]
        private static extern void hello(string s);

        [DllImport(@"..\..\..\..\..\..\libs\libCLionSQLite.dll")]
        private static extern int calc_double(int x);

        private static void Main()
        {
            Console.WriteLine("Calling library function");
            try
            {
                hello_library();
                hello("test");
                Console.WriteLine($"calc_double(3) = {calc_double(3)}");
            }
            catch (Exception ex)
            {
                Console.Error.WriteLine($"Exception: {ex.Message}\n{ex.StackTrace}");
            }
        }
    }
}
