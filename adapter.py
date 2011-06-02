import hplusbnb

def copyTaskToAdapter(task):
    aTask = hplusbnb.Task()
    aTask.variables.extend(task.variables)
    assert len(task.initial_state) == 1, "Task not in canonical form"
    aTask.init = list(task.initial_state)[0]
    assert len(task.goal) == 1, "Task not in canonical form"
    aTask.goal = list(task.goal)[0]
    for op in task.operators:
        aOp = hplusbnb.Operator()
        aOp.name = op.name
        aOp.cost = op.cost
        aOp.preconditions.extend(op.precondition)
        aOp.effects.extend(op.effect)
        aTask.operators.extend([aOp])
    return aTask

def hmax(task):
    h = hplusbnb.hmax(copyTaskToAdapter(task))
    # for consistency
    if h == -1:
        h = float("inf")
    return h  