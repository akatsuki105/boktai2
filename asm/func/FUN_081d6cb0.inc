	push {r4, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D6D18 @ =0x03002BE0
	mov r3, sp
	movs r2, #0x8a
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0x96
	lsls r1, r1, #1
	add r1, ip
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	str r0, [r1]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [r2]
	movs r0, #0x9a
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	cmp r1, r0
	blt _081D6D1C
	movs r0, #0
	b _081D6D1E
	.align 2, 0
_081D6D18: .4byte 0x03002BE0
_081D6D1C:
	movs r0, #1
_081D6D1E:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
