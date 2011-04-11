/* Copyright (C) 2009, 2010, 2011  Olga Yakovleva <yakovleva.o.v@gmail.com> */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifdef WIN32
#include <windows.h>

typedef CRITICAL_SECTION MUTEX;
#define INIT_MUTEX(m) InitializeCriticalSection(m)
#define DESTROY_MUTEX(m) DeleteCriticalSection(m)
#define LOCK_MUTEX(m) EnterCriticalSection(m)
#define UNLOCK_MUTEX(m) LeaveCriticalSection(m)
#else
#include <pthread.h>
typedef pthread_mutex_t MUTEX;
#define INIT_MUTEX(m) pthread_mutex_init(m,NULL)
#define DESTROY_MUTEX(m) pthread_mutex_destroy(m)
#define LOCK_MUTEX(m) pthread_mutex_lock(m)
#define UNLOCK_MUTEX(m) pthread_mutex_unlock(m)
#endif