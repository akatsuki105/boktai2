	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x5c]
	cmp r0, #0
	beq _08054D1C
	movs r4, #1
	ldr r0, _08054D24 @ =0x00001850
	adds r1, r3, r0
	movs r2, #3
_08054CB6:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CB6
	movs r4, #1
	ldr r0, _08054D28 @ =0x000019D0
	adds r1, r3, r0
	movs r2, #3
_08054CCC:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CCC
	movs r4, #1
	ldr r0, _08054D2C @ =0x00001B50
	adds r1, r3, r0
	movs r2, #2
_08054CE2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CE2
	movs r4, #1
	ldr r0, _08054D30 @ =0x00001C84
	adds r1, r3, r0
	movs r2, #5
_08054CF8:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08054CF8
	movs r4, #1
	ldr r0, _08054D34 @ =0x00001DA8
	adds r1, r3, r0
	movs r2, #1
_08054D0E:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08054D0E
_08054D1C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054D24: .4byte 0x00001850
_08054D28: .4byte 0x000019D0
_08054D2C: .4byte 0x00001B50
_08054D30: .4byte 0x00001C84
_08054D34: .4byte 0x00001DA8
