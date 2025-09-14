class Newton_interpolation:
    def __init__(self, filename):
        self.x , self.y = self.read_from_file(filename)
        self.n = len(self.x)
        self.h = self.calculate_h()
        self.table = self.build_difference_table()
    
    def 

    def read_from_file(self , filename):
        x,y = [],[]
        with open(filename,"r") as f:
           for line in f:
               parts = line.strip().split()
               if len(parts) == 2:
                   x.append(float(parts[0]))
                   y.append(float(parts[1]))
        return x, y
    
    def factorial(self ,n):
        return 1 if n == 0 else n * self.factorial(n - 1)
    
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


class Forward_Newton_interpolation(Newton_interpolation):
    def __init__(self,)

# -----------------------------
# Main function
# -----------------------------
def main():
        filename = "Data.txt"
        nf = Newton_interpolation(filename)

        print("Difference Table:")
        print(nf.show_Difference_table())

if __name__ == "__main__":
    main()
        