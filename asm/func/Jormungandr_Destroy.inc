	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r5, #4
_080CACD4:
	adds r0, r4, #0
	bl FUN_08055d7c
	adds r4, #0x98
	subs r5, #1
	cmp r5, #0
	bge _080CACD4
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r4, r6, r1
	movs r5, #2
_080CACEA:
	adds r0, r4, #0
	bl FUN_08055d7c
	adds r4, #0x98
	subs r5, #1
	cmp r5, #0
	bge _080CACEA
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08055d7c
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08055d7c
	adds r0, r6, #0
	bl FUN_080c592c
	adds r0, r6, #0
	bl FUN_080c311c
	adds r0, r6, #0
	bl FUN_080c3764
	adds r0, r6, #0
	bl FUN_080c2b60
	adds r0, r6, #0
	bl FUN_080c3fa0
	adds r0, r6, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
