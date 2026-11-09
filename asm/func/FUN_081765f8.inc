	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	movs r1, #0x10
	ldr r2, _08176618 @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817661C
	movs r0, #1
	b _0817661E
	.align 2, 0
_08176618: .4byte 0x00001008
_0817661C:
	movs r0, #0
_0817661E:
	cmp r0, #0
	beq _08176682
	mov r3, sp
	adds r2, r5, #0
	adds r2, #8
	ldr r0, _0817668C @ =0x00000F8C
	adds r4, r4, r0
	ldrh r0, [r4]
	ldrh r1, [r5, #8]
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
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08176690 @ =0x00002EE0
	cmp r1, r0
	ble _08176682
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, _08176694 @ =0x00000472
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r3, #2]
	mov r0, sp
	movs r1, #0xc
	bl Entity081f7974_Spawn
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
_08176682:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817668C: .4byte 0x00000F8C
_08176690: .4byte 0x00002EE0
_08176694: .4byte 0x00000472
