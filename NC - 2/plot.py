# plot.py
import matplotlib.pyplot as plt

def plot_error_vs_h(methods, h_list, xn, exact_func):
    errors = { method.__class__.__name__: [] for method in methods }

    for h in h_list:
        for method in methods:
            method.h = h
            method.xn = xn
            method.exact_func = exact_func
            points = method.solve()
            y_num = points[-1][1]
            y_exact = exact_func(xn)
            err = abs(y_num - y_exact)
            errors[method.__class__.__name__].append(err)

    plt.figure(figsize=(8,6))
    for method_name, err_list in errors.items():
        plt.plot(h_list, err_list, marker='o', label=method_name)

    plt.xscale('log')
    plt.yscale('log')
    plt.xlabel("Step size h")
    plt.ylabel("Error at x = xn")
    plt.title("Step Size vs Error for ODE Methods")
    plt.legend()
    plt.grid(True, which="both", ls="--")
    plt.show()
