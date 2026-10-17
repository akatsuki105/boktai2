	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DACC6
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da5d0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DACDA
_081DACC6:
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DACD8
	adds r0, r4, #0
	bl _call_via_r1
_081DACD8:
	movs r0, #1
_081DACDA:
	pop {r4}
	pop {r1}
	bx r1
