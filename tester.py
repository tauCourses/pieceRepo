from random import randint
from random import sample


def create_piece_pool(K,D,n):
    return [[randint(-K, K) for _ in range(2*D)] for _ in range(n)]

def random_constrain(K,D,t):
    randoms = sample(set([i for i in range(2*D)]), t)
    constrain = [randint(-K, K) for _ in range(2*D)]
    for random in randoms:
        constrain[random] = 'a'
    return constrain

def create_constrain_pool(K,D, n):
    return [random_constrain(K,D,randint(0, 2*D)) for _ in range(n)]

def print_pool(piece_pool):
    print "{",
    first_piece = True
    for piece in piece_pool:
        if not first_piece:
            print ",{",
        first_piece = False
        first_index= True
        for index in piece:
            if not first_index:
                print ",",
            first_index = False
            if isinstance(index, int):
                print "%d " % index,
            else:
                print "numeric_limits<int>::min() ",
        print "}"
    print "}"

def get_pieces_with_respect_to_constrain(pool, constrain):
    return [piece for piece in pool if all([constrain[i] == 'a' or index ==  constrain[i] for i, index in enumerate(piece)])]

K=5
D=2
number_of_pieces = 10
number_of_constrains = 5

pool = create_piece_pool(K,D,number_of_pieces)
print "piece pool:"
print_pool(pool)
constrain_pool = create_constrain_pool(K,D,number_of_constrains)
print "piece pool:"
print_pool(constrain_pool)

print "\n\n"
for constrain in constrain_pool:
    print(constrain)

    constrain_pieces = get_pieces_with_respect_to_constrain(pool, constrain)
    for piece in constrain_pieces:
        print(piece)

    print()