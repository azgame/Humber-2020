// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickUp.h"
AHealthPickUp::AHealthPickUp() {
	
	key = "health";
	val = 5;
	pickup = new FStatPickUp(val, key);
}


