from abc import ABC , abstractmethod
import math 

# Abstract Base Class 
class Integration(ABC):

    def __init__(self,func,a,b):
        self.a = a
        self.b = b
        self.func = func
        
    @abstractmethod
    def integrate(self):
        """ Perform numerical integration """
        pass

    @abstractmethod
    def error_bound(self,f_derivative):
        """Compute theoratical error bound"""
        pass
    
    @abstractmethod
    def statement(self):
        """Prints description of method"""
        pass

    @abstractmethod
    def auto_integrate(self,tol):
        pass


    # Trapezoidal Rule 

class Trapezoidal(Integration):
        def integrate(self,n):
            h = (self.b - self.a)/n
            result = 0.5 * (self.func(self.a) + self.func(self.b))
            for i in range(1,n):
                result += self.func(self.a + i*h)
            return result * h
        
        def error_bound(self,n):
            h=(self.b - self.a)/n

            def f2(x,delta=1e-5):
                return ( self.func(x+delta) - 2*self.func(x)+self.func(x-delta))/delta**2
            
            max_f2=max(abs(f2(self.a + i*h)) for i in range(n+1))
            return ((self.b-self.a)* h**2 /12)*max_f2
        
        def statement(self):
            return "Trapezoidal Rule"
        
        def auto_integrate(self,tol):
            n = 1
            while True:
                err = self.error_bound(n)
                if err < tol:
                    approx = self.integrate(n)
                    return n , approx,err
                
                n += 1

# Simpson's 1/3 Rule 

class SimpsonOneThird(Integration):
    def integrate(self,n):
        if n % 2 !=0:
            raise ValueError("n must be even for Simpson's 1/3 Rule")
        h = (self.b - self.a)/n
        result = self.func(self.a) + self.func(self.b)
        for i in range(1,n):
            coeff = 4 if i % 2 != 0 else 2 
            result += coeff * self.func(self.a + i*h)
        return result * h /3

    def error_bound(self, n):
        h = (self.b - self.a)/n

        def f4(x,delta=1e-3):
            return (self.func(x-2*delta)-4*self.func(x-delta)+6*self.func(x) - 4*self.func(x+delta)+ self.func(x+2*delta)) / delta**4
        
        max_f4 = max(abs(f4(self.a + i*h)) for i in range(n+1))
        return ((self.b-self.a)*h**4/180)*max_f4
    
    def statement(self):
        return "Simpson's 1/3 Rule"

    def auto_integrate(self, tol):
        n = 2
        while True:
            err = self.error_bound(n)
            if err < tol:
                approx = self.integrate(n)
                return n,approx,err
            n +=2

# Simpson's 3/8 Rule 

class SimpsonThreeEight(Integration):
    def integrate(self,n):
        if n % 3!=0:
            raise ValueError("n must be multiple of 3 for Simpson's 3/8 Rule")
        h = (self.b - self.a)/n
        result = self.func(self.a) + self.func(self.b)
        for i in range(1,n):
            coeff = 3 if i % 3 !=0 else 2 
            result += coeff * self.func(self.a + i*h)
        return result * 3*h / 8
    
    def error_bound(self, n):
        h = (self.b - self.a)/n
        
        def f4(x,delta = 1e-3):
            return(self.func(x-2*delta)-4*self.func(x-delta)+6*self.func(x)-4*self.func(x-delta)+self.func(x+2*delta))/delta**4
        
        max_f4 = max(abs(f4(self.a + i*h)) for i in range(n+1))
        return ((self.b - self.a)*h**4/80)*max_f4
    
    def statement(self):
        return "Simspons's 3/8  Rule"
    
    def auto_integrate(self,tol):
        n = 3 
        while True:
            err = self.error_bound(n)
            if err < tol:
                approx = self.integrate(n)
                return n,approx,err
            n += 3





        
    






