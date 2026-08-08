	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r1, r0, #0
	cmp r1, #0
	beq _08234D48
	ldrh r0, [r1, #4]
	strh r0, [r4]
	ldrb r0, [r1, #9]
	lsls r0, r0, #4
	strh r0, [r4, #2]
	ldrh r0, [r1, #6]
	strh r0, [r4, #4]
_08234D48:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
