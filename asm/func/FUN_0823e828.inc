	push {r4, r5, lr}
	bl FUN_0823d904
	bl RtcPowerOnCheck
	lsls r5, r0, #0x18
	lsrs r4, r5, #0x18
	bl FUN_0823d910
	movs r0, #0xf
	ands r4, r0
	cmp r4, #1
	beq _0823E846
	subs r0, #0x10
	b _0823E848
_0823E846:
	movs r0, #1
_0823E848:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
