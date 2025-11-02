from abc import ABC, abstractmethod

class ODE(ABC):
    def __init__(self, func, x0, y0, h, xn, exact_func=None):
        self.func = func
        self.x0 = x0
        self.y0 = y0
        self.h = h
        self.xn = xn
        self.exact_func = exact_func  # exact solution for error

    @abstractmethod
    def solve(self):
        pass

    def show_result(self, points):
        print(f"{'x':<10}{'y':<15}{'error':<15}")
        print("-"*40)
        for x, y in points:
            err = abs(y - self.exact_func(x)) if self.exact_func else '-'
            print(f"{x:<10.4f}{y:<15.6f}{err:<15}")


class SimpleEuler(ODE):
    def solve(self):
        x, y, h, xn = self.x0, self.y0, self.h, self.xn
        points = [(x, y)]
        while x < xn:
            y += h * self.func(x, y)
            x += h
            err = abs(y - self.exact_func(x)) if self.exact_func else None
            points.append((x, y))
        return points


class ModifiedEuler(ODE):
    def solve(self):
        x, y, h, xn = self.x0, self.y0, self.h, self.xn
        points = [(x, y)]
        while x < xn:
            k1 = self.func(x, y)
            k2 = self.func(x + h, y + h*k1)
            y += (h/2)*(k1 + k2)
            x += h
            err = abs(y - self.exact_func(x)) if self.exact_func else None
            points.append((x, y))
        return points


class RK2(ODE):
    def solve(self):
        x, y, h, xn = self.x0, self.y0, self.h, self.xn
        points = [(x, y)]
        while x < xn:
            k1 = self.func(x, y)
            k2 = self.func(x + h/2, y + h/2*k1)
            y += h * k2
            x += h
            err = abs(y - self.exact_func(x)) if self.exact_func else None
            points.append((x, y))
        return points


class RK4(ODE):
    def solve(self):
        x, y, h, xn = self.x0, self.y0, self.h, self.xn
        points = [(x, y)]
        while x < xn:
            k1 = self.func(x, y)
            k2 = self.func(x + h/2, y + h/2*k1)
            k3 = self.func(x + h/2, y + h/2*k2)
            k4 = self.func(x + h, y + h*k3)
            y += (h/6)*(k1 + 2*k2 + 2*k3 + k4)
            x += h
            err = abs(y - self.exact_func(x)) if self.exact_func else None
            points.append((x, y))
        return points
