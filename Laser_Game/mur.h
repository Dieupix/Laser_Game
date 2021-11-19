#ifndef MUR_H
#define MUR_H

#include "objet.h"
class laser;

class mur : public objet
{
public:
    mur(const point& p);
    virtual ~mur() = default;
    mur getMur() const;
    void moveMur(const point& p);
    void moveMur(double x, double y);
    bool isAffected(const laser& l) const;
    void changeAffected() ;
    virtual void print(std::ostream& ost) const override;
    //Operateurs ?
private:
    bool d_affected;
};
#endif // MUR_H
