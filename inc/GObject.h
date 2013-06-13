#ifndef GOBJECT_H

#define GOBJECT_H
#include "GVector3.h"
#include "Ray.h"

enum INTERSECTION_TYPE {INTERSECTED_IN=-1,MISS=0,INTERSECTED_OUT=1};

class GObject {
  private:
    GVector3 m_Ka;//ambient material
    GVector3 m_Kd;//diffuse material
    GVector3 m_Ks;//specular material
    double m_Shininess;
    double m_Reflectivity;
  public:
    GObject();
    GObject(const GVector3&,const GVector3&,const GVector3&,double,double);
    void setKa(const GVector3&);
    void setKd(const GVector3&);
    void setKs(const GVector3&);
    void setShininess(double);
    void setReflectivity(double);
    GVector3 getKa() const;
    GVector3 getKd() const;
    GVector3 getKs() const;
    double getShininess() const;
    double getReflectivity() const;
    virtual GVector3 getNormal(const GVector3&) const=0;
    virtual INTERSECTION_TYPE isIntersected(const Ray&,double&) const=0;

};

#endif /* end of include guard: GOBJECT_H */
