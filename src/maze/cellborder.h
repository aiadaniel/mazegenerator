#ifndef CELLBORDER_H
#define CELLBORDER_H

#include <string>

class CellBorder {
 public:
  virtual std::string GnuplotPrintString(const std::string&) const = 0;
  virtual std::string SVGPrintString(const std::string&) const = 0;
};

class LineBorder : public CellBorder {
 public:
  virtual std::string GnuplotPrintString(const std::string&) const;
  virtual std::string SVGPrintString(const std::string&) const;
  LineBorder(double, double, double, double);
  LineBorder(std::tuple<double, double, double, double>);

 public:
  double x1_, y1_, x2_, y2_;
};

class ArcBorder : public CellBorder {
 public:
  virtual std::string GnuplotPrintString(const std::string&) const;
  virtual std::string SVGPrintString(const std::string&) const;
  ArcBorder(double, double, double, double, double);

 public:
  double cx_, cy_, r_, theta1_, theta2_; // theta 角度
};

#endif /* end of include guard: CELLBORDER_H */
