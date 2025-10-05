from interpolation import InterpolationSelector
from scipy.integrate import quad
from Integration import Trapezoidal,SimpsonOneThird,SimpsonThreeEight
import math 

# -----------------------------
# Main function
# -----------------------------
def main():

        print("\n ------------ Numerical Interpolation ---------- ")

        filename = "C:/Users/Sakshi Ladkat/Desktop/Git/Numerical-Computing/NC - 2/data.txt"

        value = float(input("\n Enter value to interpolate :"))

        selector = InterpolationSelector(filename,equal_spacing=True)

        selector.base.show_data()
        
        print("Difference Table\n")
        print(selector.show_table())

        result , method = selector.interpolate(value)
        print(f"\nInterpolated value using {method}:{result}")
       
        print("\n ------------ Numerical Integration ---------- ")
        a = float(input("Enter lower limit a :"))
        b = float(input("Enter upper limit b :"))

        def func(x):
              return math.sin(x) + x**2
        
        exact,_ = quad(func,a,b)

        methods = [Trapezoidal(func,a,b),
                   SimpsonOneThird(func,a,b),
                   SimpsonThreeEight(func,a,b)]
        
        print("\n Choode Mode : \n1.Enter number of intervals(n)\n2.Enter tolerance(precision)")
        choice = int(input("Enter choice (1/2):"))

        results = []
        if choice == 1:
              n=int(input("Enter number of intervals n:"))
              for method in methods:
                    approx = method.integrate(n)
                    est_err = method.error_bound(n)
                    true_err = abs(exact - approx)
                    results.append((method.statement(),n,approx,est_err,true_err))

        elif choice == 2:
              tol = float(input("Enter tolerance ( e.g,1e-4)"))
              for method in methods:
                    n_auto,approx_auto,est_err = method.auto_integrate(tol)
                    true_err = abs(exact - approx_auto)
                    results.append((method.statement(),n_auto,approx_auto,est_err))

        else:
              print("Invalid choice ")

# Result table 

        print("\n Comparison Table")
        print(f"{'Method':<25}{'n':<10}{'Approx':<15}{'Est.Error Bound':<20}{'True Error':<15}")
        print("-"*85)
        for r in results:
              print(f"{r[0]:<25}{r[1]:<10}{r[2]:<15.8f}{r[3]:<20.8f}{r[4]:<15.8f}")
      

if __name__ == "__main__":
    main()
        