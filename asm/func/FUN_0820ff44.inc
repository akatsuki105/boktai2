	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0820fedc
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_0820feec
	adds r7, r0, #0
	movs r6, #0
	movs r4, #0
	cmp r6, r5
	bge _0820FF70
_0820FF5E:
	adds r0, r7, r4
	bl IsWeaponAlreadyFound
	cmp r0, #0
	beq _0820FF6A
	adds r6, #1
_0820FF6A:
	adds r4, #1
	cmp r4, r5
	blt _0820FF5E
_0820FF70:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
