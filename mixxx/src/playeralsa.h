/***************************************************************************
                          playeralsa.h  -  description
                             -------------------
    begin                : Wed Feb 20 2002
    copyright            : (C) 2002 by Tue and Ken Haste Andersen
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef PLAYERALSA_H
#define PLAYERALSA_H

#include <qthread.h>
#include "player.h"
#include <alsa/asoundlib.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "engineobject.h"

/**
  *@author Tue and Ken Haste Andersen
  */

class PlayerALSA : public Player, public QThread  {
public:
	PlayerALSA(int size, vector<EngineObject *> *, QString device);
	~PlayerALSA();
	void start(EngineObject *);
	void stop();
	void wait();
	/** Main loop of player. Executed in a separate thread by QT */
	void run();
	void rt_priority();
	CSAMPLE *process(const CSAMPLE *, const int);
protected:
	snd_pcm_t *handle;  // ALSA handle
	snd_pcm_channel_params_t *params;
	snd_pcm_channel_setup_t *setup;
private:
	QSemaphore *requestStop;

};

#endif
