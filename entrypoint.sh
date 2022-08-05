#!/bin/bash

trap "exit" TERM 

"$@"
