	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	ldr r5, _08137824 @ =0x00000B3A
	adds r2, r1, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r3, r0
	bge _08137850
	movs r7, #1
	movs r0, #3
	rsbs r0, r0, #0
	mov ip, r0
	adds r5, r2, #0
	ldr r0, _08137828 @ =0x00000755
	adds r2, r1, r0
	movs r6, #0x90
	lsls r6, r6, #1
_08137818:
	ldrb r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _0813782C
	movs r0, #1
	b _0813782E
	.align 2, 0
_08137824: .4byte 0x00000B3A
_08137828: .4byte 0x00000755
_0813782C:
	movs r0, #0
_0813782E:
	cmp r0, #0
	bne _08137844
	cmp r4, #1
	bne _0813783A
	movs r4, #0
	b _08137844
_0813783A:
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
	adds r4, #1
_08137844:
	adds r2, r2, r6
	adds r3, #1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r3, r0
	blt _08137818
_08137850:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
