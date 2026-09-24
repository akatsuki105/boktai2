	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #1
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D6C9E
	ldr r0, _081D6CA8 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r0, r5, r3
	str r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	bge _081D6C9E
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d6ae8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081d5820
	ldr r0, _081D6CAC @ =0x000003C7
	bl PlaySound_082406e0
_081D6C9E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6CA8: .4byte 0x03002BE0
_081D6CAC: .4byte 0x000003C7
