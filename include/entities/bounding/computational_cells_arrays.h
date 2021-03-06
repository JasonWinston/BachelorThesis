//==============================================================================
// The header may hold different computational grids' descriptors for various
// models. It is nothing more that a bunch of 2D arrays filled with
// per-cell coordinates. Currently only grid with medium accuracy is supported.
//==============================================================================
// author: dybisz
//------------------------------------------------------------------------------

#ifndef COMPUTATIONAL_CELLS_H
#define COMPUTATIONAL_CELLS_H

#include "vector"

using namespace std;

static const vector<vec3> mediumAccuracyFishingBoat{
                                         vec3(0.0, 4.0, 3.0),
                                         vec3(0.0, 3.0, 3.0),
                                         vec3(0.0, 3.0, 4.0),
                                         vec3(0.0, 4.0, 4.0),
                                         vec3(0.0, 4.0, 2.0),
                                         vec3(0.0, 3.0, 2.0),
                                         vec3(1.0, 4.0, 2.0),
                                         vec3(1.0, 4.0, 4.0),
                                         vec3(1.0, 3.0, 3.0),
                                         vec3(1.0, 3.0, 5.0),
                                         vec3(1.0, 4.0, 5.0),
                                         vec3(1.0, 4.0, 1.0),
                                         vec3(2.0, 3.0, 5.0),
                                         vec3(2.0, 3.0, 2.0),
                                         vec3(2.0, 3.0, 4.0),
                                         vec3(2.0, 3.0, 3.0),
                                         vec3(2.0, 4.0, 1.0),
                                         vec3(2.0, 3.0, 1.0),
                                         vec3(1.0, 3.0, 1.0),
                                         vec3(2.0, 4.0, 5.0),
                                         vec3(1.0, 2.0, 3.0),
                                         vec3(3.0, 4.0, 1.0),
                                         vec3(3.0, 3.0, 1.0),
                                         vec3(3.0, 3.0, 4.0),
                                         vec3(1.0, 2.0, 2.0),
                                         vec3(2.0, 2.0, 2.0),
                                         vec3(2.0, 1.0, 3.0),
                                         vec3(1.0, 2.0, 4.0),
                                         vec3(3.0, 4.0, 5.0),
                                         vec3(3.0, 3.0, 3.0),
                                         vec3(3.0, 3.0, 2.0),
                                         vec3(4.0, 4.0, 1.0),
                                         vec3(4.0, 3.0, 1.0),
                                         vec3(3.0, 1.0, 3.0),
                                         vec3(3.0, 1.0, 4.0),
                                         vec3(2.0, 1.0, 4.0),
                                         vec3(4.0, 3.0, 6.0),
                                         vec3(4.0, 3.0, 4.0),
                                         vec3(4.0, 3.0, 5.0),
                                         vec3(4.0, 0.0, 3.0),
                                         vec3(2.0, 2.0, 1.0),
                                         vec3(3.0, 2.0, 1.0),
                                         vec3(4.0, 2.0, 1.0),
                                         vec3(4.0, 4.0, 6.0),
                                         vec3(4.0, 3.0, 3.0),
                                         vec3(4.0, 3.0, 2.0),
                                         vec3(6.0, 4.0, 0.0),
                                         vec3(5.0, 4.0, 1.0),
                                         vec3(5.0, 4.0, 0.0),
                                         vec3(5.0, 3.0, 1.0),
                                         vec3(6.0, 3.0, 0.0),
                                         vec3(6.0, 3.0, 1.0),
                                         vec3(3.0, 1.0, 2.0),
                                         vec3(5.0, 2.0, 1.0),
                                         vec3(5.0, 4.0, 6.0),
                                         vec3(6.0, 3.0, 6.0),
                                         vec3(5.0, 3.0, 6.0),
                                         vec3(6.0, 3.0, 3.0),
                                         vec3(5.0, 3.0, 3.0),
                                         vec3(5.0, 3.0, 4.0),
                                         vec3(5.0, 3.0, 5.0),
                                         vec3(4.0, 1.0, 2.0),
                                         vec3(4.0, 0.0, 4.0),
                                         vec3(5.0, 1.0, 1.0),
                                         vec3(3.0, 4.0, 6.0),
                                         vec3(6.0, 4.0, 6.0),
                                         vec3(6.0, 3.0, 4.0),
                                         vec3(6.0, 3.0, 5.0),
                                         vec3(5.0, 3.0, 2.0),
                                         vec3(7.0, 4.0, 0.0),
                                         vec3(7.0, 3.0, 0.0),
                                         vec3(6.0, 2.0, 1.0),
                                         vec3(5.0, 0.0, 3.0),
                                         vec3(7.0, 1.0, 1.0),
                                         vec3(6.0, 1.0, 1.0),
                                         vec3(7.0, 3.0, 6.0),
                                         vec3(6.0, 3.0, 2.0),
                                         vec3(7.0, 2.0, 1.0),
                                         vec3(8.0, 2.0, 1.0),
                                         vec3(5.0, 0.0, 2.0),
                                         vec3(2.0, 2.0, 5.0),
                                         vec3(6.0, 0.0, 2.0),
                                         vec3(7.0, 4.0, 6.0),
                                         vec3(7.0, 3.0, 5.0),
                                         vec3(7.0, 3.0, 4.0),
                                         vec3(7.0, 3.0, 3.0),
                                         vec3(7.0, 3.0, 1.0),
                                         vec3(10.0, 4.0, 0.0),
                                         vec3(9.0, 4.0, 0.0),
                                         vec3(8.0, 4.0, 0.0),
                                         vec3(8.0, 3.0, 0.0),
                                         vec3(9.0, 3.0, 0.0),
                                         vec3(10.0, 3.0, 0.0),
                                         vec3(9.0, 2.0, 1.0),
                                         vec3(8.0, 1.0, 1.0),
                                         vec3(5.0, 0.0, 4.0),
                                         vec3(3.0, 2.0, 5.0),
                                         vec3(8.0, 0.0, 2.0),
                                         vec3(9.0, 3.0, 5.0),
                                         vec3(9.0, 3.0, 6.0),
                                         vec3(10.0, 3.0, 6.0),
                                         vec3(8.0, 3.0, 4.0),
                                         vec3(8.0, 3.0, 5.0),
                                         vec3(8.0, 3.0, 6.0),
                                         vec3(7.0, 3.0, 2.0),
                                         vec3(10.0, 2.0, 0.0),
                                         vec3(9.0, 1.0, 1.0),
                                         vec3(10.0, 1.0, 1.0),
                                         vec3(9.0, 0.0, 2.0),
                                         vec3(6.0, 0.0, 3.0),
                                         vec3(7.0, 0.0, 3.0),
                                         vec3(7.0, 1.0, 2.0),
                                         vec3(8.0, 3.0, 1.0),
                                         vec3(8.0, 3.0, 2.0),
                                         vec3(12.0, 4.0, 0.0),
                                         vec3(11.0, 4.0, 0.0),
                                         vec3(12.0, 3.0, 0.0),
                                         vec3(11.0, 3.0, 0.0),
                                         vec3(11.0, 2.0, 0.0),
                                         vec3(11.0, 1.0, 1.0),
                                         vec3(4.0, 1.0, 5.0),
                                         vec3(9.0, 0.0, 3.0),
                                         vec3(8.0, 0.0, 3.0),
                                         vec3(8.0, 3.0, 3.0),
                                         vec3(10.0, 3.0, 5.0),
                                         vec3(9.0, 3.0, 1.0),
                                         vec3(12.0, 2.0, 0.0),
                                         vec3(12.0, 1.0, 1.0),
                                         vec3(11.0, 0.0, 2.0),
                                         vec3(6.0, 0.0, 4.0),
                                         vec3(10.0, 0.0, 3.0),
                                         vec3(10.0, 0.0, 2.0),
                                         vec3(7.0, 0.0, 4.0),
                                         vec3(10.0, 3.0, 1.0),
                                         vec3(14.0, 4.0, 0.0),
                                         vec3(13.0, 4.0, 0.0),
                                         vec3(14.0, 3.0, 0.0),
                                         vec3(13.0, 3.0, 0.0),
                                         vec3(13.0, 2.0, 0.0),
                                         vec3(14.0, 2.0, 1.0),
                                         vec3(14.0, 1.0, 1.0),
                                         vec3(13.0, 1.0, 1.0),
                                         vec3(5.0, 1.0, 5.0),
                                         vec3(3.0, 3.0, 6.0),
                                         vec3(9.0, 0.0, 4.0),
                                         vec3(11.0, 0.0, 3.0),
                                         vec3(8.0, 0.0, 4.0),
                                         vec3(12.0, 3.0, 6.0),
                                         vec3(11.0, 3.0, 6.0),
                                         vec3(12.0, 0.0, 2.0),
                                         vec3(14.0, 0.0, 2.0),
                                         vec3(6.0, 1.0, 5.0),
                                         vec3(10.0, 0.0, 4.0),
                                         vec3(7.0, 1.0, 5.0),
                                         vec3(12.0, 3.0, 5.0),
                                         vec3(12.0, 3.0, 3.0),
                                         vec3(12.0, 3.0, 2.0),
                                         vec3(12.0, 3.0, 1.0),
                                         vec3(11.0, 3.0, 1.0),
                                         vec3(15.0, 4.0, 0.0),
                                         vec3(15.0, 3.0, 0.0),
                                         vec3(15.0, 2.0, 1.0),
                                         vec3(15.0, 1.0, 1.0),
                                         vec3(13.0, 0.0, 2.0),
                                         vec3(15.0, 0.0, 2.0),
                                         vec3(4.0, 2.0, 5.0),
                                         vec3(8.0, 1.0, 5.0),
                                         vec3(11.0, 0.0, 4.0),
                                         vec3(12.0, 0.0, 3.0),
                                         vec3(14.0, 3.0, 6.0),
                                         vec3(13.0, 3.0, 5.0),
                                         vec3(13.0, 3.0, 6.0),
                                         vec3(13.0, 3.0, 4.0),
                                         vec3(12.0, 3.0, 4.0),
                                         vec3(13.0, 3.0, 1.0),
                                         vec3(13.0, 0.0, 3.0),
                                         vec3(14.0, 0.0, 3.0),
                                         vec3(15.0, 0.0, 3.0),
                                         vec3(9.0, 1.0, 5.0),
                                         vec3(9.0, 0.0, 5.0),
                                         vec3(10.0, 0.0, 5.0),
                                         vec3(11.0, 4.0, 6.0),
                                         vec3(12.0, 4.0, 6.0),
                                         vec3(10.0, 4.0, 6.0),
                                         vec3(17.0, 4.0, 0.0),
                                         vec3(16.0, 4.0, 0.0),
                                         vec3(17.0, 3.0, 0.0),
                                         vec3(16.0, 3.0, 0.0),
                                         vec3(16.0, 2.0, 1.0),
                                         vec3(16.0, 1.0, 1.0),
                                         vec3(16.0, 0.0, 2.0),
                                         vec3(16.0, 0.0, 3.0),
                                         vec3(5.0, 2.0, 6.0),
                                         vec3(8.0, 2.0, 6.0),
                                         vec3(10.0, 1.0, 5.0),
                                         vec3(11.0, 0.0, 5.0),
                                         vec3(12.0, 0.0, 4.0),
                                         vec3(13.0, 0.0, 4.0),
                                         vec3(14.0, 0.0, 4.0),
                                         vec3(7.0, 2.0, 6.0),
                                         vec3(9.0, 2.0, 6.0),
                                         vec3(13.0, 4.0, 6.0),
                                         vec3(14.0, 4.0, 5.0),
                                         vec3(14.0, 4.0, 4.0),
                                         vec3(14.0, 4.0, 3.0),
                                         vec3(13.0, 4.0, 2.0),
                                         vec3(14.0, 4.0, 1.0),
                                         vec3(15.0, 0.0, 4.0),
                                         vec3(16.0, 0.0, 4.0),
                                         vec3(6.0, 2.0, 6.0),
                                         vec3(10.0, 2.0, 6.0),
                                         vec3(11.0, 1.0, 5.0),
                                         vec3(15.0, 3.0, 6.0),
                                         vec3(14.0, 4.0, 6.0),
                                         vec3(15.0, 4.0, 5.0),
                                         vec3(14.0, 4.0, 2.0),
                                         vec3(16.0, 4.0, 1.0),
                                         vec3(15.0, 4.0, 1.0),
                                         vec3(18.0, 4.0, 1.0),
                                         vec3(18.0, 4.0, 0.0),
                                         vec3(18.0, 3.0, 1.0),
                                         vec3(17.0, 2.0, 1.0),
                                         vec3(17.0, 1.0, 2.0),
                                         vec3(17.0, 0.0, 2.0),
                                         vec3(17.0, 0.0, 3.0),
                                         vec3(17.0, 0.0, 4.0),
                                         vec3(12.0, 1.0, 5.0),
                                         vec3(13.0, 1.0, 5.0),
                                         vec3(14.0, 1.0, 5.0),
                                         vec3(15.0, 1.0, 5.0),
                                         vec3(11.0, 2.0, 6.0),
                                         vec3(16.0, 4.0, 5.0),
                                         vec3(16.0, 1.0, 5.0),
                                         vec3(17.0, 1.0, 5.0),
                                         vec3(12.0, 2.0, 6.0),
                                         vec3(17.0, 3.0, 6.0),
                                         vec3(16.0, 3.0, 6.0),
                                         vec3(15.0, 4.0, 6.0),
                                         vec3(18.0, 2.0, 1.0),
                                         vec3(18.0, 1.0, 2.0),
                                         vec3(18.0, 0.0, 2.0),
                                         vec3(18.0, 0.0, 4.0),
                                         vec3(18.0, 1.0, 5.0),
                                         vec3(14.0, 2.0, 6.0),
                                         vec3(13.0, 2.0, 6.0),
                                         vec3(15.0, 2.0, 6.0),
                                         vec3(16.0, 2.0, 6.0),
                                         vec3(16.0, 4.0, 6.0),
                                         vec3(17.0, 4.0, 5.0),
                                         vec3(17.0, 4.0, 1.0),
                                         vec3(18.0, 4.0, 6.0),
                                         vec3(17.0, 4.0, 6.0),
                                         vec3(18.0, 4.0, 5.0),
                                         vec3(19.0, 4.0, 1.0),
                                         vec3(19.0, 3.0, 1.0),
                                         vec3(19.0, 2.0, 1.0),
                                         vec3(18.0, 0.0, 3.0),
                                         vec3(19.0, 2.0, 5.0),
                                         vec3(17.0, 2.0, 6.0),
                                         vec3(18.0, 2.0, 6.0),
                                         vec3(18.0, 3.0, 6.0),
                                         vec3(19.0, 3.0, 6.0),
                                         vec3(13.0, 4.0, 3.0),
                                         vec3(19.0, 1.0, 2.0),
                                         vec3(19.0, 0.0, 2.0),
                                         vec3(19.0, 0.0, 4.0),
                                         vec3(19.0, 1.0, 5.0),
                                         vec3(19.0, 4.0, 5.0),
                                         vec3(19.0, 4.0, 6.0),
                                         vec3(20.0, 4.0, 1.0),
                                         vec3(20.0, 3.0, 1.0),
                                         vec3(20.0, 2.0, 1.0),
                                         vec3(19.0, 0.0, 3.0),
                                         vec3(20.0, 2.0, 5.0),
                                         vec3(20.0, 3.0, 5.0),
                                         vec3(20.0, 4.0, 5.0),
                                         vec3(19.0, 4.0, 2.0),
                                         vec3(20.0, 1.0, 2.0),
                                         vec3(20.0, 1.0, 4.0),
                                         vec3(20.0, 4.0, 2.0),
                                         vec3(20.0, 4.0, 4.0),
                                         vec3(21.0, 4.0, 1.0),
                                         vec3(21.0, 3.0, 1.0),
                                         vec3(20.0, 0.0, 2.0),
                                         vec3(20.0, 0.0, 4.0),
                                         vec3(21.0, 3.0, 5.0),
                                         vec3(21.0, 4.0, 5.0),
                                         vec3(20.0, 4.0, 3.0),
                                         vec3(21.0, 4.0, 2.0),
                                         vec3(21.0, 2.0, 2.0),
                                         vec3(21.0, 1.0, 2.0),
                                         vec3(20.0, 0.0, 3.0),
                                         vec3(21.0, 1.0, 4.0),
                                         vec3(21.0, 2.0, 5.0),
                                         vec3(21.0, 4.0, 3.0),
                                         vec3(21.0, 4.0, 4.0),
                                         vec3(22.0, 4.0, 2.0),
                                         vec3(22.0, 3.0, 2.0),
                                         vec3(21.0, 0.0, 3.0),
                                         vec3(21.0, 0.0, 4.0),
                                         vec3(22.0, 3.0, 5.0),
                                         vec3(22.0, 4.0, 5.0),
                                         vec3(22.0, 2.0, 4.0),
                                         vec3(22.0, 4.0, 4.0),
                                         vec3(22.0, 2.0, 2.0),
                                         vec3(22.0, 4.0, 3.0),
                                         vec3(22.0, 1.0, 2.0),
                                         vec3(22.0, 1.0, 4.0),
                                         vec3(23.0, 4.0, 4.0),
                                         vec3(23.0, 4.0, 2.0),
                                         vec3(22.0, 0.0, 3.0),
                                         vec3(22.0, 0.0, 4.0),
                                         vec3(23.0, 3.0, 2.0),
                                         vec3(23.0, 3.0, 4.0),
                                         vec3(23.0, 4.0, 3.0),
                                         vec3(23.0, 2.0, 4.0),
                                         vec3(23.0, 2.0, 2.0),
                                         vec3(23.0, 1.0, 3.0),
                                         vec3(24.0, 4.0, 4.0),
                                         vec3(24.0, 4.0, 3.0),
                                         vec3(24.0, 3.0, 3.0),
                                         vec3(24.0, 2.0, 3.0),
                                         vec3(23.0, 0.0, 3.0),
                                         vec3(9.0, 4.0, 2.0),
                                         vec3(10.0, 4.0, 2.0),
                                         vec3(11.0, 4.0, 2.0),
                                         vec3(11.0, 4.0, 3.0),
                                         vec3(11.0, 4.0, 4.0),
                                         vec3(9.0, 4.0, 4.0),
                                         vec3(9.0, 4.0, 3.0),
                                         vec3(10.0, 4.0, 3.0),
                                         vec3(10.0, 4.0, 4.0),
                                         vec3(11.0, 3.0, 5.0),
                                         vec3(18.0, 4.0, 4.0),
                                         vec3(19.0, 4.0, 4.0),
                                         vec3(18.0, 4.0, 3.0),
                                         vec3(19.0, 4.0, 3.0),
                                         vec3(18.0, 4.0, 2.0),
                                         vec3(17.0, 4.0, 4.0),
                                         vec3(17.0, 4.0, 3.0),
                                         vec3(17.0, 4.0, 2.0),
                                         vec3(16.0, 4.0, 4.0),
                                         vec3(16.0, 4.0, 3.0),
                                         vec3(16.0, 4.0, 2.0),
                                         vec3(15.0, 4.0, 4.0),
                                         vec3(15.0, 4.0, 2.0),
                                         vec3(15.0, 4.0, 3.0),
                                         vec3(8.0, 4.0, 6.0),
};
#endif
