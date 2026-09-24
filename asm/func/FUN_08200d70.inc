	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov sl, r1
	mov r4, sp
	movs r0, #0x1c
	add r0, sl
	mov r8, r0
	mov r7, sb
	adds r7, #0x1c
	ldrh r0, [r1, #0x1c]
	mov r3, sb
	ldrh r1, [r3, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	mov r3, r8
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08200E4C @ =0x085AE7C8
	lsls r2, r2, #1
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r1, r0
	ble _08200E3C
	ldr r0, _08200E50 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08200E1C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	mov r1, sp
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r3, #4
	ldrsh r0, [r4, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_08200E1C:
	mov r0, sp
	ldrh r0, [r0]
	mov r1, sb
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, sl
	strh r0, [r2, #0x1c]
	ldrh r0, [r4, #2]
	ldrh r3, [r7, #2]
	adds r0, r0, r3
	mov r1, r8
	strh r0, [r1, #2]
	ldrh r0, [r4, #4]
	ldrh r7, [r7, #4]
	adds r0, r0, r7
	strh r0, [r1, #4]
_08200E3C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200E4C: .4byte 0x085AE7C8
_08200E50: .4byte 0x085AE7B8
