#include <ilcplex/ilocplex.h>

ILOSTLBEGIN

int main() {
    IloEnv env;
    try {
        IloModel model(env);

        IloNumVar x(env, 0.0, IloInfinity, "x");
        IloNumVar y(env, 0.0, 5, "y");

        // maximize x + 2y
        model.add(IloMaximize(env, x + 2 * y));

        // subject to: x + y <= 10, x <= 6
        model.add(x + y <= 10);
        model.add(x <= 6);

        IloCplex cplex(model);
        cplex.setOut(env.getNullStream()); // suppress solver log

        if (!cplex.solve()) {
            env.error() << "Failed to optimize." << std::endl;
            throw(-1);
        }

        cout << "Status: " << cplex.getStatus() << std::endl;
        std::cout << "Objective value: " << cplex.getObjValue() << std::endl;
        std::cout << "x = " << cplex.getValue(x) << std::endl;
        std::cout << "y = " << cplex.getValue(y) << std::endl;
    }
    catch (IloException& e) {
        std::cerr << "Concert exception: " << e << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception" << std::endl;
    }

    env.end();
    return 0;
}