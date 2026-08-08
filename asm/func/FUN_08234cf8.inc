	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r1, r0, #0
	cmp r1, #0
	beq _08234D1C
	ldrh r0, [r1]
	strh r0, [r4]
	ldrb r0, [r1, #8]
	lsls r0, r0, #4
	strh r0, [r4, #2]
	ldrh r0, [r1, #2]
	strh r0, [r4, #4]
_08234D1C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
