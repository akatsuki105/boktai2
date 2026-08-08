	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080EDCD8 @ =0x03002C60
	ldr r6, [r0]
	ldr r4, [r6, #4]
	ldr r3, _080EDCDC @ =0x00989680
	movs r0, #0
	mov r8, r0
	cmp r4, #0
	beq _080EDCC8
	mov r5, sp
_080EDC5C:
	adds r0, r4, #0
	str r3, [sp, #8]
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	ldr r3, [sp, #8]
	cmp r0, #0
	bne _080EDCC0
	ldr r1, _080EDCE0 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080EDC7E
	cmp r0, #1
	beq _080EDC7E
	cmp r0, #3
	bne _080EDCC0
_080EDC7E:
	ldr r2, _080EDCE4 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _080EDCC0
	adds r2, r4, #0
	adds r2, #8
	ldrh r0, [r7]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r3, r1
	ble _080EDCC0
	adds r3, r1, #0
	mov r8, r4
_080EDCC0:
	ldr r6, [r6]
	ldr r4, [r6, #4]
	cmp r4, #0
	bne _080EDC5C
_080EDCC8:
	mov r0, r8
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080EDCD8: .4byte 0x03002C60
_080EDCDC: .4byte 0x00989680
_080EDCE0: .4byte 0x000001DF
_080EDCE4: .4byte 0x00000553
