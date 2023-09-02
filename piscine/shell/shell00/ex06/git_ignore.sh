#!/bin/bash
find . -not -path './.git/*' -print | git check-ignore *
