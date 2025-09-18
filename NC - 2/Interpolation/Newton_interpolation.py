import random

class Newton_interpolation:
    #--------------------------
    #Constructor for the class
    #---------------------------
    def __init__(self, filename):
        self.x , self.y = self.read_from_file(filename)
        self.n = len(self.x)
        self.h = self.calculate_h()
        self.table = self.build_difference_table()

    #------------------------------
    #Reads Data from the file     
    #------------------------------
    def read_from_file(self , filename):
        x,y = [],[]
        with open(filename,"r") as f:
           for line in f:
               parts = line.strip().split()
               if len(parts) == 2:
                   x.append(float(parts[0]))
                   y.append(float(parts[1]))
        return x, y
    

    #---------------------------------
    # Show Data
    #---------------------------------
    def show_data(self):
        print("X values:",self.x)
        print("Y values:",self.y)

    #-------------------------------
    #Calculates factorial 
    #-------------------------------
    def factorial(self ,n):
        return 1 if n == 0 else n * self.factorial(n - 1)
    
    #-----------------------------------
    #Calculate h for equally spaced data
    # ----------------------------------- 
    def calculate_h(self):
        if self.n > 1:
            return self.x[1] - self.x[0]
        return None
    
    #----------------------------------
    #Build difference Table
    #----------------------------------- 
    def build_difference_table(self):
        n = self.n
        table = [[0]*(n+1) for _ in range(n)]
        for i in range(n):
            table[i][0] = self.x[i]
            table[i][1] = self.y[i]

        for j in range(2,n + 1):
            for i in range(n - j + 1):
                table[i][j] = table[i + 1][j - 1] - table[i][j - 1]
        return table
    
    #--------------------------------------
    #Prints calculated difference table 
    #--------------------------------------
    def show_Difference_table(self):
        table = self.build_difference_table()
        n = self.n
        result = []
        for i in range(n):
            row = ""
            for j in range(1,n+1):
                if j <= n- i:
                    row += f"{table[i][j]:>8}"
            result.append(row.strip())
        return "\n".join(result)

    def get_Difference_table(self):
        return self.build_difference_table()


#--------------------------------------
# Newton's_Forward interpolation 
#--------------------------------------
class Forward_Newton_interpolation:
    def __init__(self,base:Newton_interpolation):
        self.base = base 

    def interpolate(self,value):
        h = self.base.h
        n = self.base.n
        p = (value - self.base.x[0])/h
        result = self.base.y[0]

        for i in range(1,n):
            term = self.base.table[0][i+1]
            for j in range(i):
                term *= (p-j)
            term /= self.base.factorial(i)
            result +=term
        return result 
    
#-------------------------------------
# Newton's_Backward interpolation
#-------------------------------------
class Backward_Newton_interpolation:
    def __init__(self,base:Newton_interpolation):
        self.base = base

    def interpolate(self,value):
        h = self.base.h
        n = self.base.n
        p = (value - self.base.x[-1])/h
        result = self.base.y[-1]

        for i in range(1,n):
            term = self.base.table[n-i-1][i+1]
            for j in range(i):
                term *=(p+j)
            term /= self.base.factorial(i)
            result +=term
        return result

#--------------------------------
# Stirling's Interpolation 
#--------------------------------
class Stirling_interpolation:
    def __init__(self,base:Newton_interpolation):
        self.base = base

    def interpolate(self,value):
        h = self.base.h
        n = self.base.n
        mid = n//2
        p = (value - self.base.x[mid])/h
        result = self.base.y[mid]

        for i in range(1,n):
            if i% 2 == 0:
                k = i// 2
                term = self.base.table[mid-k][i+1]
                for j in range(1,i+1):
                    term *= (p**j)
                term /= self.base.factorial(i)
                result +=term
        return result

#-------------------------------------
# Divided Difference (Unequal Spacing)
#-------------------------------------
class Divided_Difference_interpolation(Newton_interpolation):
    def build_difference_table(self):
       n = self.n
       table = [[0] * n for _ in range(n)]
       for i in range(n):
           table[i][0] = self.y[i]
           
       for j in range(1,n):
            for i in range(n-j):
                table[i][j] = (table[i+1][j-1] - table[i][j-1])/(self.x[i+j]-self.x[i])

       return table
    
    def interpolate(self,value):
        n = self.n
        result = self.table[0][0]
        product = 1.0

        for i in range(1,n):
            product *= (value - self.x[i-1])
            result += self.table[0][i]*product
        return result 

#-------------------------------------------
# wrapper Class
#------------------------------------------
class InterpolationSelector:
    def __init__(self,filename,equal_spacing = True):
        self.equal_spacing = equal_spacing
        self.base = Newton_interpolation(filename)
        
        if equal_spacing:
            self.forward = Forward_Newton_interpolation(self.base)
            self.backward =Backward_Newton_interpolation(self.base)
            self.stirling =Stirling_interpolation(self.base)
        self.divided = Divided_Difference_interpolation(filename)

    def show_table(self):
        if not self.equal_spacing:
            return self.divided.get_Difference_table()
        else:
            return self.base.show_Difference_table()

    def interpolate(self,value):
        if not self.equal_spacing:
            return self.divided.interpolate(value),"Divided Difference"
        
        n = self.base.n
        x = self.base.x

        if value in x:
           methods = [
               ("Forward Newton",self.forward.interpolate),
               ("Backward Newton",self.backward.interpolate),
               ("Stirling",self.stirling.interpolate)]
           method_name , method_func = random.choice(methods)
           return method_func(value),method_name
        
        if(abs(value - x[0]) < abs(value - x[-1]) and abs(value - x[0]) < abs(value - x[n//2])):
            return self.forward.interpolate(value) , "Forward Newton Interpolation"
        elif(abs(value - x[-1]) < abs(value - x[0]) and abs(value - x[-1]) < abs(value - x[n//2])):
            return self.backward.interpolate(value) , "Backward Newton Interpolation"
        else:
            return self.stirling.interpolate(value), "stirling Newton Interpolation"

# -----------------------------
# Main function
# -----------------------------
def main():
        filename = "C:/Users/Sakshi Ladkat/Desktop/Git/Numerical-Computing/NC - 2/Interpolation/data.txt"

        value = float(input("\n Enter value to interpolate :"))

        selector = InterpolationSelector(filename,equal_spacing=True)

        selector.base.show_data()
        
        print("Difference Table\n")
        print(selector.show_table())

        result , method = selector.interpolate(value)
        print(f"\nInterpolated value using {method}:{result}")

if __name__ == "__main__":
    main()
        