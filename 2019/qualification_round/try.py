n = None
imgs = []

with open('input_data/a_example.txt','r') as file:
    d = file.read().split('\n')
    n = int(d[0])
    imgs = d[1:]

print(n)    
print(imgs)

def findInterestFactor(a,b):
    a_img_data = a.split()
    b_img_data = b.split()

    common = 0

    a_tags = a_img_data[2:]
    b_tags = b_img_data[2:]

    for i in a_tags:
        for j in b_tags:
            if(i == j):
                common += 1

    uncommon_a = len(a_img_data) - 2 - common
    uncommon_b = len(b_img_data) - 2 - common

    return min([common, uncommon_a, uncommon_b])

print(findInterestFactor(imgs[0], imgs[3]))