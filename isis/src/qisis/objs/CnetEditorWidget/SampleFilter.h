#ifndef SampleFilter_H
#define SampleFilter_H

#include "AbstractNumberFilter.h"

template< typename U, typename V > class QPair;
class QString;

namespace Isis {
  class ControlMeasure;
  class ControlNet;
  class ControlPoint;

  /**
   * @brief Allows filtering by a control measure's sample
   *
   * This class allows the user to filter control measures by their sample
   * (i.e. which sample they are positioned at in the image). This allows the
   * user to make a list of control measures that are too close to the edge of
   * an image after pointreg adjustment.
   *
   * @author 2012-01-05 Jai Rideout
   *
   * @internal
   *   @history 2017-07-25 Summer Stapleton - Removed the CnetViz namespace. Fixes #5054.
   *   @history 2018-06-01 Jesse Mapel - Changed ControlCubeGraphNode to image serial number.
   *                           References #5434.
   */
  class SampleFilter : public AbstractNumberFilter {
      Q_OBJECT

    public:
      SampleFilter(AbstractFilter::FilterEffectivenessFlag flag,
            int minimumForSuccess = -1);
      SampleFilter(const SampleFilter &other);
      virtual ~SampleFilter();

      bool evaluate(const QPair<QString, ControlNet *> *) const;
      bool evaluate(const ControlPoint *) const;
      bool evaluate(const ControlMeasure *) const;

      AbstractFilter *clone() const;

      QString getImageDescription() const;
      QString getPointDescription() const;
      QString getMeasureDescription() const;
  };
}

#endif
