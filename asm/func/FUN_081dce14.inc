	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sl, r1
	movs r0, #0
	mov sb, r0
	movs r1, #0xf
	str r1, [sp]
_081DCE2C:
	ldr r2, _081DCE40 @ =0x00000828
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081DCE44
	movs r3, #0xe5
	lsls r3, r3, #3
	adds r0, r7, r3
	b _081DCE4A
	.align 2, 0
_081DCE40: .4byte 0x00000828
_081DCE44:
	movs r5, #0xe9
	lsls r5, r5, #3
	adds r0, r7, r5
_081DCE4A:
	add r0, sb
	ldrh r1, [r0]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	ldrh r4, [r0]
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r2, r7, r3
	add r2, sb
	adds r0, r1, #0
	movs r5, #0x1f
	ands r0, r5
	mov r8, r4
	mov r3, r8
	ands r3, r5
	mov r8, r3
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r2]
	movs r5, #0xfd
	lsls r5, r5, #3
	adds r6, r7, r5
	add r6, sb
	asrs r0, r1, #5
	movs r3, #0x1f
	ands r0, r3
	asrs r3, r4, #5
	movs r5, #0x1f
	ands r3, r5
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r6]
	ldr r0, _081DCF28 @ =0x00000808
	adds r5, r7, r0
	add r5, sb
	asrs r0, r1, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r4, r4, #0xa
	ands r4, r1
	subs r0, r0, r4
	lsls r0, r0, #5
	strh r0, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, sl
	str r2, [sp, #4]
	str r3, [sp, #8]
	bl Div
	ldr r2, [sp, #4]
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r6, r2]
	mov r1, sl
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	strh r0, [r5]
	movs r2, #0xed
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	mov r5, r8
	lsls r5, r5, #5
	strh r5, [r0]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r7, r1
	add r0, sb
	ldr r3, [sp, #8]
	lsls r3, r3, #5
	strh r3, [r0]
	adds r2, #0x40
	adds r0, r7, r2
	add r0, sb
	lsls r4, r4, #5
	strh r4, [r0]
	movs r3, #2
	add sb, r3
	ldr r5, [sp]
	subs r5, #1
	str r5, [sp]
	cmp r5, #0
	bge _081DCE2C
	ldr r0, _081DCF2C @ =0x00000828
	adds r2, r7, r0
	ldrh r0, [r2]
	movs r1, #1
	eors r0, r1
	strh r0, [r2]
	ldr r1, _081DCF30 @ =0x00000706
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCF28: .4byte 0x00000808
_081DCF2C: .4byte 0x00000828
_081DCF30: .4byte 0x00000706
