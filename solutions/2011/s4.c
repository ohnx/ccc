#include <stdio.h>

char *lookup[] = {"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"};

enum blood_type {
    BT_O_NEG = 0,
    BT_O_POS,
    BT_A_NEG,
    BT_A_POS,
    BT_B_NEG,
    BT_B_POS,
    BT_AB_NEG,
    BT_AB_POS,
    _BT_END
};

// notice the ordering for this... this is the order we will take blood from.
enum blood_type acceptedTypes[_BT_END][_BT_END+1] = {
    // o neg        o pos
    {1, BT_O_NEG}, {2, BT_O_POS, BT_O_NEG},
    //   a neg                    a pos
    {2, BT_A_NEG, BT_O_NEG}, {4, BT_A_POS, BT_A_NEG, BT_O_POS, BT_O_NEG}, 
    //   b neg                    b pos
    {2, BT_B_NEG, BT_O_NEG}, {4, BT_B_POS, BT_B_NEG, BT_O_POS, BT_O_NEG}, 
    // ab neg
    {4, BT_AB_NEG, BT_B_NEG, BT_A_NEG, BT_O_NEG},
    // ab pos
    {8, BT_AB_POS, BT_AB_NEG, BT_B_POS, BT_B_NEG, BT_A_NEG, BT_A_POS, BT_O_NEG, BT_O_POS}
};

// glad this isn't a functional programming language... lol globals
int donors[_BT_END];
int recipients[_BT_END];
int total = 0;

int numDonors(enum blood_type bt) {
    // simple switch case to matchup all the blood types
    switch(bt) {
    case BT_O_NEG:
        return donors[BT_O_NEG];
    case BT_O_POS:
        return donors[BT_O_NEG] + donors[BT_O_POS];
    case BT_A_NEG:
        return donors[BT_O_NEG] + donors[BT_A_NEG];
    case BT_A_POS:
        return donors[BT_O_NEG] + donors[BT_O_POS] + donors[BT_A_NEG] + donors[BT_A_POS];
    case BT_B_NEG:
        return donors[BT_O_NEG] + donors[BT_B_NEG];
    case BT_B_POS:
        return donors[BT_O_NEG] + donors[BT_O_POS] + donors[BT_B_NEG] + donors[BT_B_POS];
    case BT_AB_NEG:
        return donors[BT_O_NEG] + donors[BT_A_NEG] + donors[BT_B_NEG] + donors[BT_AB_NEG];
    case BT_AB_POS:
        return donors[BT_O_NEG] + donors[BT_A_NEG] + donors[BT_B_NEG] + donors[BT_A_POS] + donors[BT_B_POS] + donors[BT_AB_NEG] + donors[BT_AB_POS];
    default:
        return -1;
    }
}

void getBlood(enum blood_type bt, int units) {
    // check enough donors for all the recipients
    int dCount, i;
    dCount = numDonors(bt);
    units = dCount >= units ? units : dCount;
    
    //printf("%s needs %d units of blood\n", lookup[bt], units);

    for (i = 1; i <= acceptedTypes[bt][0]; i++) {
        // take as many as possible from here
        dCount = donors[acceptedTypes[bt][i]];
        
        if (dCount >= units) {
            // completely satisfied
            donors[acceptedTypes[bt][i]] -= units;
            total += units;
            units = 0;
        } else {
            // not completely satisfied yet
            donors[acceptedTypes[bt][i]] = 0; // used all
            total += dCount;
            units -= dCount;
            
        }
        
        //printf("%s got %d units from %s, needs now only %d\n", lookup[bt], dCount, lookup[acceptedTypes[bt][i]], units);
        
        // no more units needed
        if (units == 0) return;
    }
    // we haven't satisfied the demand, sorry :(
}

int main() {
    int i;
    
    // read in donors
    for (i = 0; i < _BT_END; i++) {
        scanf("%d", &donors[i]);
    }
    
    // read in recipients
    for (i = 0; i < _BT_END; i++) {
        scanf("%d", &recipients[i]);
    }
    
    // use this order instead when giving blood
    enum blood_type rOrder[] = {BT_O_NEG, BT_O_POS, BT_A_NEG, BT_B_NEG, BT_A_POS, BT_B_POS, BT_AB_NEG, BT_AB_POS};
    for (i = 0; i < _BT_END; i++) {
        getBlood(rOrder[i], recipients[rOrder[i]]);
    }
    
    printf("%d\n", total);
    return 0;
}
