// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef SERVICES_I_LOOPED_SERVICE_H
#define SERVICES_I_LOOPED_SERVICE_H

namespace Services {

class ILoopedService {
  public:
      virtual ~ILoopedService() {};
      virtual void loop() = 0;
};

}

#endif /* end of include guard: SERVICES_I_LOOPED_SERVICE_H */
