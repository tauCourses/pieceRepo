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
    print "{{",
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
                print "free_space ",
        print "}"
    print "};"



#left,top,right,bottom, front, back
rotates2 = [[1,2,3,4],[4,1,2,3],[3,4,1,2],[2,3,4,1]]
rotates3 = [[1,2,3,4,5,6],[4,1,2,3,5,6],[3,4,1,2,5,6],[2,3,4,1,5,6],
     [1,4,3,2,6,5],[2,1,4,3,6,5],[3,2,1,4,6,5],[4,3,2,1,6,5],
     [6,2,5,4,3,1],[4,6,2,5,3,1],[5,4,6,2,3,1],[2,5,4,6,3,1],
     [5,2,6,4,1,3],[4,5,2,6,1,3],[6,4,5,2,1,3],[2,6,4,5,1,3],
     [1,5,3,6,4,2],[6,1,5,3,4,2],[3,6,1,5,4,2],[5,3,6,1,4,2],
     [1,6,3,5,2,4],[5,1,6,3,2,4],[3,5,1,6,2,4],[6,3,5,1,2,4]]


def is_piece_respect_constain(piece, constrain):
    if len(piece) == 6:
        rotates = rotates3
    else:
        rotates = rotates2
    #print("piece " + str(piece))
    for rotate in rotates:
        #(rotate)
        rotate_piece = [piece[i-1] for i in rotate]
        if all([constrain[i] == 'a' or index == constrain[i] for i, index in enumerate(rotate_piece)]):
            return True

    return False


def get_pieces_with_respect_to_constrain(pool, constrain):
    return [piece for piece in pool if is_piece_respect_constain(piece,constrain)]
#

K=5
D=3
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