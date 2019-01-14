// Direction class.
class Direction {
    int varCount;
    double coords[];

    Direction(int n) {
	varCount = n;
	coords = new double[varCount];
	makeDirection();
    }

    void makeDirection() {
	for(int i = 0; i < varCount; i++)
	    coords[i] = newValue();
    }

    double newValue() {
	return Math.random() * 2 - 1;
    }
}

// Specimen of a hive class.
class Agent {
    private double coordinates[];
    private int varCount;
    private double currentValue;
    private Direction agentDirection;
    
    Agent(int n, double coords[], double valueFunction[]) {
	varCount = n;
	coordinates = new double[varCount];
	for(int i = 0; i < varCount; i++)
	    coordinates[i] = coords[i];
	currentValue = calcValue(valueFunction);
	agentDirection = new Direction(varCount);
    }

    void printCoordinates() {
	for(int i = 0; i < varCount; i++)
	    System.out.println("x[" + i + "]: " + coordinates[i]);
    }

    double calcValue(double valueFunction[]) {
	double result = valueFunction[0];
	for(int i = 1; i < varCount; i++) {
	    result -= valueFunction[i] * coordinates[i-1];
	}
	return result;
    }

    double getCurrentValue() { return currentValue; }

    void improve(double equations[][], int rows, int columns) {
	double tempCoords[] = new double[varCount];

	improveLoop:
	for(int k = 1; k < 100; k++) {

	    // Get new coordinates.
	    for(int i = 0; i < varCount; i++) {
		tempCoords[i] = coordinates[i] + agentDirection.coords[i];
		if(tempCoords[i] < 0) {
		    agentDirection.makeDirection();
		    continue improveLoop;
		}
	    }
	    
	    // Minimizing function check.
	    double newMin = equations[0][0];
	    for(int i = 1; i < columns; i++)
		newMin -= equations[0][i] * tempCoords[i - 1];
	    if(newMin > currentValue) {
		agentDirection.makeDirection();
		continue improveLoop;
	    }
	    
	    // Constraints check.
	    for(int i = 1; i < rows; i++) {
		double y = equations[i][0];
		for(int j = 1; j < columns; j++)
		    y -= equations[i][j] * tempCoords[j - 1];
		if(y < 0) {
		    agentDirection.makeDirection();
		    continue improveLoop;
		}
	    }
	    
	    // If all checks pass then update current state.
	    for(int i = 0; i < varCount; i++)
		coordinates[i] = tempCoords[i];
	    currentValue = newMin;
	    break improveLoop;
	}
    }
}

// Starting class.
class Hivemind {
    public static void main(String args[]) {
	double equations[][] = {
	    {0, -1, 2, 1},
	    {2, 1, 1, -2},
	    {1, 1, -1, 1},
	    {5, 0, 1, 1},
	    {2, 2, -1, 0}
	};
	double coords[] = {0, 0, 0};
	int agentsNum = 100;
	int stepsNum = 500;
	
	Agent myAgents[] = new Agent[agentsNum];
	for(int i = 0; i < agentsNum; i++)
	    myAgents[i] = new Agent(3, coords, equations[0]);

	for(int j = 0; j < stepsNum; j++)
	    for(int i = 0; i < agentsNum; i++) {
		myAgents[i].improve(equations, 5, 4);
	    }

	int best = 0;
	for(int i = 1; i < agentsNum; i++) {
	    if(myAgents[i].getCurrentValue() < myAgents[0].getCurrentValue())
		best = i;
	}

	myAgents[best].printCoordinates();
	System.out.println("Value: " + myAgents[best].getCurrentValue());
    }
}
